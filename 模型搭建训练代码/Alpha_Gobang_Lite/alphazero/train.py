# coding:utf-8
import json
import os
import time
import traceback

#import multiprocessing
from multiprocessing import Process, Queue, set_start_method

import torch
import torch.nn.functional as F
from torch import nn, optim, cuda
from torch.optim.lr_scheduler import MultiStepLR
from torch.utils.data import DataLoader

from .alpha_zero_mcts import AlphaZeroMCTS
from .chess_board import ChessBoard
from .policy_value_net import PolicyValueNet
from .self_play_dataset import SelfPlayData, SelfPlayDataSet



def exception_handler(train_func):
    def wrapper(train_pipe_line, *args, **kwargs):
        try:
            train_func(train_pipe_line)
        except BaseException as e:
            if not isinstance(e, KeyboardInterrupt):
                traceback.print_exc()

            t = time.strftime('%Y-%m-%d_%H-%M-%S',
                              time.localtime(time.time()))
            train_pipe_line.save_model(
                f'last_policy_value_net_{t}.pth', 'train_losses', 'games')

    return wrapper


class PolicyValueLoss(nn.Module):


    def __init__(self):
        super().__init__()

    def forward(self, p_hat, pi, value, z):

        value_loss = F.mse_loss(value, z)
        policy_loss = -torch.sum(pi*p_hat, dim=1).mean()
        loss = value_loss + policy_loss
        return loss


class TrainModel:
    """ 训练模型 """

    def __init__(self, board_len=9, lr=0.01, n_self_plays=1500, n_mcts_iters=500,
                 n_feature_planes=4, batch_size=500, start_train_size=5000, check_frequency=100,
                 n_test_games=10, c_puct=4, is_use_gpu=True, is_save_game=False, **kwargs):

        self.c_puct = c_puct
        self.is_use_gpu = is_use_gpu
        self.batch_size = batch_size
        self.n_self_plays = n_self_plays
        self.n_test_games = n_test_games
        self.n_mcts_iters = n_mcts_iters
        self.is_save_game = is_save_game
        self.check_frequency = check_frequency
        self.start_train_size = start_train_size
        self.device = torch.device(
            'cuda:1' if is_use_gpu and cuda.is_available() else 'cpu')
        self.chess_board = ChessBoard(board_len, n_feature_planes)

        # 创建策略-价值网络和蒙特卡洛搜索�?        
        self.policy_value_net = self.__get_policy_value_net(board_len)
        self.mcts = AlphaZeroMCTS(
            self.policy_value_net, c_puct=c_puct, n_iters=n_mcts_iters, is_self_play=True)

        # 创建优化器和损失函数
        self.optimizer = optim.Adam(
            self.policy_value_net.parameters(), lr=lr, weight_decay=1e-4)
        self.criterion = PolicyValueLoss()
        self.lr_scheduler = MultiStepLR(
            self.optimizer, [20000, 40000,60000,80000], gamma=0.316)

        # 创建数据�?        
        self.dataset = SelfPlayDataSet(board_len)

        # 记录数据
        self.train_losses = self.__load_data('log/train_losses.json')
        self.games = self.__load_data('log/games.json')
        
        self.queue=Queue()

    def self_play(self):

        # 初始化棋盘和数据容器
        self.policy_value_net.eval()
        self.chess_board.clear_board()
        pi_list, feature_planes_list, players = [], [], []
        action_list = []

        # 开始一局游戏
        while True:
            action, pi = self.mcts.get_action(self.chess_board)

            # 保存每一步的数据
            feature_planes_list.append(self.chess_board.get_feature_planes())
            players.append(self.chess_board.current_player)
            action_list.append(action)
            pi_list.append(pi)
            self.chess_board.do_action(action)

            # 判断游戏是否结束
            is_over, winner = self.chess_board.is_game_over()
            if is_over:
                if winner is not None:
                    z_list = [1 if i == winner else -1 for i in players]
                else:
                    z_list = [0]*len(players)
                break

        # 重置根节�?        
        self.mcts.reset_root()

        # 返回数据
        if self.is_save_game:
            self.games.append(action_list)

        self_play_data = SelfPlayData(
            pi_list=pi_list, z_list=z_list, feature_planes_list=feature_planes_list)
            
        #self.queue.put_nowait(self_play_data)
        self.dataset.append(self_play_data)
        return 
    
    def self_play_process(self,i):
        print(f"self_play_process{i}")
        self.self_play()
        #self.dataset.append(temp)
        
        #self.dataset.append(self.self_play())
        return 
    
    def __self_play_start(self):
        process = [Process(target=self.self_play_process,args=(i,)) for i in range(1)]
        for p in process:
            p.daemon = True
        [p.start() for p in process]
        print(f"all_play_process start")
        [p.join() for p in process]
        print(f"all_play_process end")
        while not self.queue.empty():
            #pi_list, z_list, feature_planes_list=self.queue.get()
            #self_play_data = SelfPlayData(
            #pi_list=pi_list, z_list=z_list, feature_planes_list=feature_planes_list)
            print("getting")
            self.dataset.append(self.queue.get_nowait())

    @exception_handler
    def train(self):

        for i in range(self.n_self_plays):
            print(f'''Runing Game{i+1}''')
            #self.dataset.append(self.__self_play())
            self.self_play()

            # 如果数据集中的数据量大于 start_train_size 就进行一次训�?    
            print(f"""{len(self.dataset)},{self.start_train_size}""")      
            if len(self.dataset) >= self.start_train_size:
                data_loader = iter(DataLoader(self.dataset, self.batch_size, shuffle=True, drop_last=False))  
                for j in range(10):
                    print('Training...')
    
                    self.policy_value_net.train()
                    # 随机选出一批数据来训练，防止过拟合
                    try:
                        feature_planes, pi, z = next(data_loader)
                    except StopIteration:
                        data_loader = iter(DataLoader(self.dataset, self.batch_size, shuffle=True, drop_last=False))  
                        feature_planes, pi, z = next(data_loader)
                    feature_planes = feature_planes.to(self.device)
                    pi, z = pi.to(self.device), z.to(self.device)
                    for _ in range(1):
                        # 前馈
                        p_hat, value = self.policy_value_net(feature_planes)
                        # 梯度清零
                        self.optimizer.zero_grad()
                        # 计算损失
                        loss = self.criterion(p_hat, pi, value.flatten(), z)
                        # 误差反向传播
                        loss.backward()
                        # 更新参数
                        self.optimizer.step()
                        # 学习率退�?                    
                        self.lr_scheduler.step()
    
                    # 记录误差
                    self.train_losses.append([i, loss.item()])
                    print(f"🚩 train_loss = {loss.item():<10.5f}\n")
    
                # 测试模型
                if (i+1) % self.check_frequency == 0:
                    self.__test_model()

    def __test_model(self):
        os.makedirs('model', exist_ok=True)

        model_path = 'model/best_policy_value_net.pth'

        # 如果最佳模型不存在保存当前模型为最佳模�?        
        if not os.path.exists(model_path):
            torch.save(self.policy_value_net, model_path)
            return

        # 载入历史最优模�?        
        best_model = torch.load(model_path)  # type:PolicyValueNet
        best_model.eval()
        best_model.set_device(self.is_use_gpu)
        mcts = AlphaZeroMCTS(best_model, self.c_puct, self.n_mcts_iters)
        self.mcts.set_self_play(False)
        self.policy_value_net.eval()

        # 开始比�?        
        print('🩺 正在测试当前模型...')
        n_wins = 0
        for i in range(self.n_test_games):
            self.chess_board.clear_board()
            self.mcts.reset_root()
            mcts.reset_root()
            while True:
                # 当前模型走一�?                
                is_over, winner = self.__do_mcts_action(self.mcts)
                if is_over:
                    n_wins += int(winner == ChessBoard.BLACK)
                    break
                # 历史最优模型走一�?                
                is_over, winner = self.__do_mcts_action(mcts)
                if is_over:
                    break

        # 如果胜率大于 55%，就保存当前模型为最优模�?        
        win_prob = n_wins/self.n_test_games
        if win_prob > 0.55:
            torch.save(self.mcts.policy_value_net, model_path)
            print(f'🥇 保存当前模型为最优模型，当前模型胜率为：{win_prob:.1%}\n')
        else:
            print(f'🎃 保持历史最优模型不变，当前模型胜率为：{win_prob:.1%}\n')

        self.mcts.set_self_play(True)

    def save_model(self, model_name: str, loss_name: str, game_name: str):

        os.makedirs('model', exist_ok=True)

        path = f'model/{model_name}.pth'
        self.policy_value_net.eval()
        torch.save(self.policy_value_net, path)
        print(f'🎉 Model Saved:?{os.path.join(os.getcwd(), path)}')

        # 保存数据
        with open(f'log/{loss_name}.json', 'w', encoding='utf-8') as f:
            json.dump(self.train_losses, f)

        if self.is_save_game:
            with open(f'log/{game_name}.json', 'w', encoding='utf-8') as f:
                json.dump(self.games, f)


    def __do_mcts_action(self, mcts):

        action = mcts.get_action(self.chess_board)
        self.chess_board.do_action(action)
        is_over, winner = self.chess_board.is_game_over()
        return is_over, winner

    def __get_policy_value_net(self, board_len=9):

        os.makedirs('model', exist_ok=True)

        best_model = 'best_policy_value_net.pth'
        history_models = sorted(
            [i for i in os.listdir('model') if i.startswith('last')])

        # 从历史模型中选取最新模�?        
        model = history_models[-1] if history_models else best_model
        model = f'model/{model}'
        if os.path.exists(model):
            print(f'💎 载入模型 {model} ...\n')
            net = torch.load(model).to(self.device)  # type:PolicyValueNet
            net.set_device(self.is_use_gpu)
        else:
            net = PolicyValueNet(n_feature_planes=self.chess_board.n_feature_planes,
                                 is_use_gpu=self.is_use_gpu, board_len=board_len).to(self.device)

        return net

    def __load_data(self, path: str):

        data = []
        try:
            with open(path, encoding='utf-8') as f:
                data = json.load(f)
        except:
            os.makedirs('log', exist_ok=True)

        return data
