# coding: utf-8
from typing import Tuple, Union

import numpy as np

from .chess_board import ChessBoard
from .node import Node
from .policy_value_net import PolicyValueNet


class AlphaZeroMCTS:
    

    def __init__(self, policy_value_net: PolicyValueNet, c_puct: float = 4, n_iters=1200, is_self_play=False) -> None:

        self.c_puct = c_puct
        self.n_iters = n_iters
        self.is_self_play = is_self_play
        self.policy_value_net = policy_value_net
        self.root = Node(prior_prob=1, parent=None)

    def get_action(self, chess_board: ChessBoard) -> Union[Tuple[int, np.ndarray], int]:

        for i in range(self.n_iters):

            board = chess_board.copy()

            node = self.root
            while not node.is_leaf_node():
                action, node = node.select()
                board.do_action(action)

            is_over, winner = board.is_game_over()
            p, value = self.policy_value_net.predict(board)
            if not is_over:
                if self.is_self_play:
                    p = 0.75*p + 0.25*np.random.dirichlet(0.03*np.ones(len(p)))
                node.expand_(zip(board.available_actions, p))
                #node.expand(p,board.available_actions)
            elif winner is not None:
                value = 1 if winner == board.current_player else -1
            else:
                value = 0

            
            node.backup(-value)

      
        T = 1 if self.is_self_play and len(chess_board.state) <= 30 else 1e-3
        visits = np.array([i.N for i in self.root.children.values()])
        try:
            pi_ = self.__getPi(visits, T)
        except:
            print(visits)
        
        actions = list(self.root.children.keys())
        action = int(np.random.choice(actions, p=pi_))

        if self.is_self_play:
           
            pi = np.zeros(chess_board.board_len**2)
            pi[actions] = pi_
                      
            self.root = self.root.children[action]
            self.root.parent = None
            return action, pi
        else:
            self.reset_root()
            return action

    def __getPi(self, visits, T) -> np.ndarray:

        # pi = visits**(1/T) / np.sum(visits**(1/T))       
        x = 1/T * np.log(visits + 1e-11)
        x = np.exp(x - x.max())
        pi = x/x.sum()
        return pi

    def reset_root(self):

        self.root = Node(prior_prob=1, c_puct=self.c_puct, parent=None)

    def set_self_play(self, is_self_play: bool):
       
        self.is_self_play = is_self_play
