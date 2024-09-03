# coding: utf-8
from typing import Tuple
from copy import deepcopy
from collections import OrderedDict

import torch
import numpy as np


class ChessBoard:
    

    EMPTY = -1
    WHITE = 0
    BLACK = 1

    def __init__(self, board_len=9, n_feature_planes=7):

        self.board_len = board_len
        self.current_player = self.BLACK
        self.n_feature_planes = n_feature_planes
        self.available_actions = list(range(self.board_len**2))
        # 棋盘状态字典，key �?action，value �?current_player
        self.state = OrderedDict()
        # 上一个落�?        
        self.previous_action = None

    def copy(self):
        
        return deepcopy(self)

    def clear_board(self):
        
        self.state.clear()
        self.previous_action = None
        self.current_player = self.BLACK
        self.available_actions = list(range(self.board_len**2))

    def do_action(self, action: int):
        
        self.previous_action = action
        self.available_actions.remove(action)
        self.state[action] = self.current_player
        self.current_player = self.WHITE + self.BLACK - self.current_player

    def do_action_(self, pos: tuple) -> bool:
        
        action = pos[0]*self.board_len + pos[1]
        if action in self.available_actions:
            self.do_action(action)
            return True
        return False

    def is_game_over(self) -> Tuple[bool, int]:

        # 如果下的棋子不到 9 个，就直接判断游戏还没结�?        
        if len(self.state) < 9:
            return False, None

        n = self.board_len
        act = self.previous_action
        player = self.state[act]
        row, col = act//n, act % n

        # 搜索方向
        directions = [[(0, -1),  (0, 1)],   # 水平搜索
                      [(-1, 0),  (1, 0)],   # 竖直搜索
                      [(-1, -1), (1, 1)],   # 主对角线搜索
                      [(1, -1),  (-1, 1)]]  # 副对角线搜索

        for i in range(4):
            count = 1
            for j in range(2):
                flag = True
                row_t, col_t = row, col
                while flag:
                    row_t = row_t + directions[i][j][0]
                    col_t = col_t + directions[i][j][1]
                    if 0 <= row_t < n and 0 <= col_t < n and self.state.get(row_t*n+col_t, self.EMPTY) == player:
                        # 遇到相同颜色�?count+1
                        count += 1
                    else:
                        flag = False
            # 分出胜负
            if count >= 5:
                return True, player

        # 平局
        if not self.available_actions:
            return True, None

        return False, None

    def get_feature_planes(self) -> torch.Tensor:

        n = self.board_len
        feature_planes = torch.zeros((self.n_feature_planes, n**2))
        # 最后一张图像代表当前玩家颜�?        # feature_planes[-1] = self.current_player
        # 添加历史信息
        if self.state:
            actions = np.array(list(self.state.keys()))[::-1]
            players = np.array(list(self.state.values()))[::-1]
            Xt = actions[players == self.current_player]
            Yt = actions[players != self.current_player]
            for i in range((self.n_feature_planes)//2):
                if i < len(Xt):
                    feature_planes[2*i, Xt[i:]] = 1
                if i < len(Yt):
                    feature_planes[2*i+1, Yt[i:]] = 1

        return feature_planes.view(self.n_feature_planes, n, n)


class ColorError(ValueError):

    def __init__(self, *args: object) -> None:
        super().__init__(*args)
