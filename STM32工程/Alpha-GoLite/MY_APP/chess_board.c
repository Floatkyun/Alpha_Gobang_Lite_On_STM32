#include "chess_board.h"
//棋盘对象

//落子位置，范围为 `[0, BOARD_LEN^2 -1]`
//    EMPTY = 2
//    WHITE = 0
//    BLACK = 1

//row->y col->x
void action2xy(int action ,int *row,int *col)
{
	*row=action/BOARD_LEN;
	*col=action%BOARD_LEN;
}

int xy2action(int row,int col)
{
	int action=BOARD_LEN*row+col;
	return action;
}

int is_act_available(Chess_Board *chessboard_,int action)
{
		if (action<81 && chessboard_->state[action]==EMPTY_CHESS)
	{
		return ACT_AVAILABLE;
	}
		return ACT_UNAVAILABLE;
}

void init_chess_board(Chess_Board *chessboard_)
{
	chessboard_->cur_player=BLACK_CHESS;
	chessboard_->chess_count=0;
	chessboard_->previous_action=0;
	
	for(int i=0;i<BOARD_POS_NUM;i++)
	{
		chessboard_->state[i]=EMPTY_CHESS;
		chessboard_->order[i]=-1;
	}
}

void copy_chess_board(Chess_Board *from_,Chess_Board *to_)
{
	to_->cur_player=from_->cur_player;
	to_->chess_count=from_->chess_count;
	to_->previous_action=from_->previous_action;
	
	for(int i=0;i<BOARD_POS_NUM;i++)
	{
		to_->state[i]=from_->state[i];
		to_->order[i]=from_->order[i];
	}
}

int do_action(Chess_Board *chessboard_,uint16_t action)
{
	if (action<81 && chessboard_->state[action]!=EMPTY_CHESS)
	{
		return ACT_UNAVAILABLE;
	}

	chessboard_->previous_action=action;
	chessboard_->state[action]=chessboard_->cur_player;
	chessboard_->order[chessboard_->chess_count]=action;
	chessboard_->chess_count=chessboard_->chess_count+1;
	chessboard_->cur_player=WHITE_CHESS+BLACK_CHESS-chessboard_->cur_player;
		
	return ACT_AVAILABLE;
}

int is_game_over(Chess_Board *chessboard_)
{
	if (chessboard_->chess_count<9)
	{
		return GAME_NOT_OVER;
	}
	else if(chessboard_->chess_count==81)
	{
		return GAME_DRAW;
	}
	int action=chessboard_->previous_action;
	int cur_player=chessboard_->state[action];
	int row,col;
	action2xy(action,&row,&col);
	
	int count=0;
	int flag=1;
	int row_temp,col_temp;
	for(int i=0;i<4;i++)
	{
		count=1;
		for(int j=0;j<2;j++)
		{
			flag=1;
			row_temp=row;
			col_temp=col;
			while(flag)
			{
				row_temp=row_temp+search_directions[i][j][0];
				col_temp=col_temp+search_directions[i][j][1];
				if (0 <= row_temp && row_temp< BOARD_LEN && 0 <= col_temp && col_temp< BOARD_LEN && chessboard_->state[xy2action(row_temp, col_temp)] == cur_player)
				{
					count += 1;
				}
				else
				{
					flag =0;
				}
			}
		}
		if (count>=5)
		{
			if (cur_player==WHITE_CHESS)
			{
				return GAME_WHITE_WIN;
			}
			else if(cur_player==BLACK_CHESS)
			{
				return GAME_BLACK_WIN;
			}
		}
	}
	return GAME_NOT_OVER;
}

void get_feature_planes(Chess_Board *chessboard_,float *ai_indata)
{
	int cur_player=chessboard_->cur_player;
	
	for(int i=0;i<AI_NETWORK_IN_1_SIZE;i++)
	{
		ai_indata[i]=0;
	}
	
	for(int i=0;i<3;i++)
	{
		if(chessboard_->chess_count<2*i)
		{
			break;
		}

		for(int j=0;j<chessboard_->chess_count-2*i;j++)
		{
			uint8_t action=chessboard_->order[j];
			uint8_t player=chessboard_->state[action];
			if (player==cur_player)
			{
				ai_indata[2*i*81+action]=1;
				//printf("1place=%d",2*i*81+action);
				
			}
			else
			{
				ai_indata[(2*i+1)*81+action]=1;
				//printf("2place=%d",(2*i+1)*81+action);
			}
		}
		

	}
	
//	for(int i=0;i<6;i++)
//	{
//		for(int j=0;j<81;j++)
//		{
//			printf("%f",ai_indata[81*i+j]);
//		}
//		printf("\n");
//	}
	


}

