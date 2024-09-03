#ifndef __CHESS_BOARD_H
#define __CHESS_BOARD_H

#include "main.h"

#include "network.h"//调用网络推理所需的各种函数
#include "network_data.h"//包含网络权重参数
#include "ai_platform.h"//包含各种定义和宏

#include "usart.h"

#define BOARD_LEN				(9)
#define BOARD_POS_NUM 	(BOARD_LEN*BOARD_LEN)

#define WHITE_CHESS 		(0)
#define BLACK_CHESS 		(1)
#define EMPTY_CHESS 		(2)

#define ACT_AVAILABLE 	(0)
#define ACT_UNAVAILABLE (1)


#define GAME_WHITE_WIN 	(WHITE_CHESS)
#define GAME_BLACK_WIN 	(BLACK_CHESS)
#define GAME_NOT_OVER 	(2)
#define GAME_DRAW 			(3)

static int search_directions[4][2][2]={
{{0 ,-1},{0 ,1}},	//水平搜索
{{-1,0}, {1 ,0}},	//竖直搜索
{{-1,-1},{1 ,1}},	//主对角线搜索
{{1 ,-1},{-1,1}}};//副对角线搜索

typedef struct chess_board_
{
	uint8_t chess_count;
	uint8_t cur_player;
	uint8_t previous_action;
	
	uint8_t state[81];
	uint8_t order[81];
	
} Chess_Board;

static Chess_Board cur_chessboard;

void action2xy(int action ,int *row,int *col);
int xy2action(int row,int col);
int is_act_available(Chess_Board *chessboard_,int action);
void init_chess_board(Chess_Board *chessboard_);
void copy_chess_board(Chess_Board *from_,Chess_Board *to_);
int do_action(Chess_Board *chessboard_,uint16_t action);
int is_game_over(Chess_Board *chessboard_);
void get_feature_planes(Chess_Board *chessboard_,float *ai_indata);

#endif
