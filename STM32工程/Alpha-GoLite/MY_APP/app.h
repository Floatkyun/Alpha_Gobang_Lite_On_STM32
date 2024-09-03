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

static int search_num=400;
static float search_const=0.5;
static int first_hand=HUMAN_FIRST;

void init_dclock();

void app_init();
void app_mainloop();

void AI_Init(void);
void AI_Run(void);

//uint8_t SDRAM_Test(void);

void touched_chessboard();
void play_again();
void get_config();

#endif 