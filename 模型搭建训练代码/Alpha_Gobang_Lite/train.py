# coding: utf-8
import torch
from alphazero.train import TrainModel

if __name__=="__main__":

    torch.multiprocessing.set_start_method("spawn")

    train_config = {
    'lr': 1e-3,
    'c_puct': 4,
    'board_len': 9,
    'batch_size': 256,
    'is_use_gpu': True,
    'n_test_games': 10,
    'n_mcts_iters': 500,
    'n_self_plays': 10000,
    'is_save_game': False,
    'n_feature_planes': 6,
    'check_frequency': 100,
    'start_train_size': 500
}
    train_model = TrainModel(**train_config)
    train_model.train()
