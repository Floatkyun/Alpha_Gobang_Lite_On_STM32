# coding: utf-8
import random
import numpy as np

from .chess_board import ChessBoard
from .node import Node


class RolloutMCTS:


    def __init__(self, c_puct: float = 5, n_iters=1000):

        self.c_puct = c_puct
        self.n_iters = n_iters
        self.root = Node(1, c_puct, parent=None)

    def get_action(self, chess_board: ChessBoard) -> int:

        for i in range(self.n_iters):
            # 拷贝一个棋盘用来模�?            
            board = chess_board.copy()

            # 如果没有遇到叶节点，就一直向下搜索并更新棋盘
            node = self.root
            while not node.is_leaf_node():
                action, node = node.select()
                board.do_action(action)

            # 判断游戏是否结束，如果没结束就拓展叶节点
            is_over, winner = board.is_game_over()
            if not is_over:
                node.expand(self.__default_policy(board))

            # 模拟
            value = self.__rollout(board)
            # 反向传播
            node.backup(-1*value)

        # 根据子节点的访问次数来选择动作
        action = max(self.root.children.items(), key=lambda i: i[1].N)[0]
        # 更新根节�?        
        self.root = Node(prior_prob=1)
        return action

    def __default_policy(self, chess_board: ChessBoard):

        n = len(chess_board.available_actions)
        probs = np.ones(n) / n
        return zip(chess_board.available_actions, probs)

    def __rollout(self, board: ChessBoard):

        current_player = board.current_player

        while True:
            is_over, winner = board.is_game_over()
            if is_over:
                break
            action = random.choice(board.available_actions)
            board.do_action(action)

        # 计算 Value，平局�?0，当前玩家胜利则�?1, 输为 -1
        if winner is not None:
            return 1 if winner == current_player else -1
        return 0
