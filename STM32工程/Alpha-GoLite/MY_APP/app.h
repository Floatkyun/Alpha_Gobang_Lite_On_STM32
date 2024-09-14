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

#include "network.h"//����������������ĸ��ֺ���
#include "network_data.h"//��������Ȩ�ز���
#include "ai_platform.h"//�������ֶ���ͺ�

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

void init_dclock();//����LVGL����ʱ�ӿռ�
void chessboard_screen_init();//����������ʾ
void game_init();//��ʼ��һ����Ϸ

void app_init();//Ӧ��ȫ�ֳ�ʼ��
void app_mainloop();//Ӧ����ѭ��

void AI_Init(void);//�������ʼ��
void AI_Run(void);//����������
void AI_Predict(Chess_Board *chess_board_,float **p,float*value);//���ݵ�ǰ���̵�����ƽ�� ��ȡģ�����
void value_update(float value_);//��ʾģ�͵����ֵ value 
int AI_get_action(Chess_Board* chess_board_);//��ȡAlpha Go����һ���ж�
static void Alpha_act();//Alpha Go ����

void touched_chessboard();//���ӻص�����
void play_again();//���¿�ʼ��Ϸ�ص�����
void get_config();//��ȡ����ֵ�ص�����


#endif 