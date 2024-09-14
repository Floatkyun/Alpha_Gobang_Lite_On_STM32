#ifndef __APP_H
#define __APP_H

#include "main.h"
#include "usart.h"
#include "touch_800x480.h"
#include "chess_board.h"
#include "math.h"
#include "stdio.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"

#include "network.h"//调用网络推理所需的各种函数
#include "network_data.h"//包含网络权重参数
#include "ai_platform.h"//包含各种定义和宏

#define HUMAN_FIRST 0
#define ALPHA_FIRST 1

static ai_handle network=AI_HANDLE_NULL;
static float aiInData[AI_NETWORK_IN_1_SIZE]={0};
static float aiOutData_1[AI_NETWORK_OUT_1_SIZE];
static float aiOutData_2;
static ai_u8 activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];

static ai_buffer * ai_input;
static ai_buffer * ai_output;


static int first_hand=HUMAN_FIRST;

void init_dclock();//重置LVGL数字时钟空间
void chessboard_screen_init();//重置棋盘显示
void game_init();//初始化一局游戏

void app_init();//应用全局初始化
void app_mainloop();//应用主循环

void AI_Init(void);//神经网络初始化
void AI_Run(void);//神经网络推理
void AI_Predict(Chess_Board *chess_board_,float **p,float*value);//根据当前棋盘的特征平面 获取模型输出
void value_update(float value_);//显示模型的输出值 value 
int AI_get_action(Chess_Board* chess_board_);//获取Alpha Go的下一步行动
static void Alpha_act();//Alpha Go 落子

void touched_chessboard();//落子回调函数
void play_again();//重新开始游戏回调函数
void get_config();//获取设置值回调函数


#endif 