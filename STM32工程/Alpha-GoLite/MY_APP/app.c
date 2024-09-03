#include "app.h"

lv_ui guider_ui;

void value_update(float value_)
{
	char temp_value_char[10];
	sprintf(temp_value_char,"%.3f", value_);
	lv_label_set_text(guider_ui.screen_label_3,temp_value_char);
}

void AI_Init(void)
{
  ai_error err;
  const ai_handle act_addr[] = { activations };
  err = ai_network_create_and_init(&network, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    printf("ai_network_create error - type=%d code=%d\r\n", err.type, err.code);
    Error_Handler();
  }
	else 
	{
		printf("AI init success!\r\n");
	}
  ai_input = ai_network_inputs_get(network, NULL);
  ai_output = ai_network_outputs_get(network, NULL);
}

void AI_Run(void)
{
	char logStr[100];
	int count = 0;
	float max = 0;
  ai_i32 batch;
  ai_error err;

  ai_input[0].data = AI_HANDLE_PTR(aiInData);
  ai_output[0].data = AI_HANDLE_PTR(aiOutData_1);
	ai_output[1].data = AI_HANDLE_PTR(&aiOutData_2);

  batch = ai_network_run(network, ai_input, ai_output);
  if (batch != 1) {
    err = ai_network_get_error(network);
    printf("AI ai_network_run error - type=%d code=%d\r\n", err.type, err.code);
    Error_Handler();
  }
	
  for (uint32_t i = 0; i < AI_NETWORK_OUT_1_SIZE; i++) {
printf("%f",aiOutData_1[i]);
  }
printf("\n");
	
printf("pOut_2:%f\n",aiOutData_2);

}

void AI_Predict(Chess_Board *chess_board_,float **p,float*value)
{
	get_feature_planes(chess_board_,aiInData);
	AI_Run();
	for(int i=0;i<81;i++)
{	
	aiOutData_1[i]=expf(aiOutData_1[i]);
}
	*p=aiOutData_1;
	*value=aiOutData_2;
}

int AI_get_action(Chess_Board* chess_board_)
{
	float *p;
	float value;
	printf("count:%d",chess_board_->chess_count);
	AI_Predict(chess_board_,&p,&value);
	//printf("value=%f",value);
	value_update(value);
	float max_p=-10;
	int action;
	for(int i=0;i<81;i++)
	{
		if((p[i]>max_p) && (is_act_available(chess_board_,i)==ACT_AVAILABLE))
		{
			action=i;
			max_p=p[i];
		}
	}
	return action;
}

void chessboard_screen_init()
{
	lv_canvas_fill_bg(guider_ui.screen_canvas_1, lv_color_hex(0xf1fb7f), 255);
	static lv_point_t screen_canvas_1_points_array_1[] ={{24, 24},{456, 24},{456, 456},{24, 456},{24, 24},};
	lv_draw_line_dsc_t screen_canvas_1_line_dsc_1;
	lv_draw_line_dsc_init(&screen_canvas_1_line_dsc_1);
	screen_canvas_1_line_dsc_1.color = lv_color_hex(0x000000);
	screen_canvas_1_line_dsc_1.opa = 255;
	screen_canvas_1_line_dsc_1.width = 2;
	screen_canvas_1_line_dsc_1.round_start = false;
	screen_canvas_1_line_dsc_1.round_end = false;
	lv_canvas_draw_line(guider_ui.screen_canvas_1, screen_canvas_1_points_array_1, 5, &screen_canvas_1_line_dsc_1);

	//Canvas draw line
	static lv_point_t screen_canvas_1_points_array_2[] ={{24, 78},{456, 78},{456, 402},{24, 402},{24, 348},{456, 348},{456, 294},{24, 294},{24, 240},{456, 240},{456, 186},{24, 186},{24, 132},{456, 132},};
	lv_draw_line_dsc_t screen_canvas_1_line_dsc_2;
	lv_draw_line_dsc_init(&screen_canvas_1_line_dsc_2);
	screen_canvas_1_line_dsc_2.color = lv_color_hex(0x000000);
	screen_canvas_1_line_dsc_2.opa = 255;
	screen_canvas_1_line_dsc_2.width = 1;
	screen_canvas_1_line_dsc_2.round_start = false;
	screen_canvas_1_line_dsc_2.round_end = false;
	lv_canvas_draw_line(guider_ui.screen_canvas_1, screen_canvas_1_points_array_2, 14, &screen_canvas_1_line_dsc_2);

	//Canvas draw line
	static lv_point_t screen_canvas_1_points_array_3[] ={{78, 24},{78, 456},{132, 456},{132, 24},{186, 24},{186, 456},{240, 456},{240, 24},{294, 24},{294, 456},{348, 456},{348, 24},{402, 24},{402, 456},};
	lv_draw_line_dsc_t screen_canvas_1_line_dsc_3;
	lv_draw_line_dsc_init(&screen_canvas_1_line_dsc_3);
	screen_canvas_1_line_dsc_3.color = lv_color_hex(0x000000);
	screen_canvas_1_line_dsc_3.opa = 255;
	screen_canvas_1_line_dsc_3.width = 1;
	screen_canvas_1_line_dsc_3.round_start = false;
	screen_canvas_1_line_dsc_3.round_end = false;
	lv_canvas_draw_line(guider_ui.screen_canvas_1, screen_canvas_1_points_array_3, 14, &screen_canvas_1_line_dsc_3);
}

static void Alpha_act()//Alpha 落子
{
	int action;
	int x,y;
	//action=mcts_get_action(&hmcts,&cur_chessboard);
	action=AI_get_action(&cur_chessboard);
	action2xy(action,&y,&x);
	y=24+y*54-24;
	x=24+x*54-24;
	if (cur_chessboard.cur_player==WHITE_CHESS)
	{
		lv_draw_img_dsc_t screen_canvas_1_img_dsc_0;
		lv_draw_img_dsc_init(&screen_canvas_1_img_dsc_0);
		lv_canvas_draw_img(guider_ui.screen_canvas_1, x, y, &_white_alpha_48x48, &screen_canvas_1_img_dsc_0);
	}
	else if (cur_chessboard.cur_player==BLACK_CHESS)
	{
		lv_draw_img_dsc_t screen_canvas_1_img_dsc_0;
		lv_draw_img_dsc_init(&screen_canvas_1_img_dsc_0);
		lv_canvas_draw_img(guider_ui.screen_canvas_1, x, y, &_black_alpha_48x48, &screen_canvas_1_img_dsc_0);
	}
	lv_obj_clear_flag(guider_ui.screen_led, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_pos(guider_ui.screen_led, x+320+22, y+22);
	
	do_action(&cur_chessboard,action);
	
	int game_flag=is_game_over(&cur_chessboard);
	if (game_flag!=GAME_NOT_OVER)
	{
		lv_obj_clear_flag(guider_ui.screen_msgbox, LV_OBJ_FLAG_HIDDEN);
	}
	if(game_flag==GAME_WHITE_WIN)
	{
		lv_label_set_text(((lv_msgbox_t *)(guider_ui.screen_msgbox))->text, "White Win!");
	}
	else if(game_flag==GAME_BLACK_WIN)
	{
		lv_label_set_text(((lv_msgbox_t *)(guider_ui.screen_msgbox))->text, "Black Win!");
	}
	else if(game_flag==GAME_DRAW)
	{
		lv_label_set_text(((lv_msgbox_t *)(guider_ui.screen_msgbox))->text, "Draw!");
	}
}

void touched_chessboard()
{

	long int x=touchInfo.x[0]-320;
	long int y=touchInfo.y[0];
//	long int x=touch_x;
//	long int y=touch_y;
//	//printf("x=%ld,y=%ld\n",x,y);
//	
	uint32_t min_dis=460800;
	int min_index=0;
	int final_x,final_y;
	int temp_x,temp_y;
	for(int i=0;i<BOARD_POS_NUM;i++)
	{
		action2xy(i,&temp_y,&temp_x);
		temp_x=24+temp_x*54;
		temp_y=24+temp_y*54;
		uint32_t temp_dis=(x-temp_x)*(x-temp_x)+(y-temp_y)*(y-temp_y);
		if (temp_dis<min_dis)
		{
			min_dis=temp_dis;
			final_x=temp_x-24;
			final_y=temp_y-24;
			min_index=i;
		}
	}
	
	if (is_act_available(&cur_chessboard,min_index)==ACT_AVAILABLE)
	{
		//printf("min_index=%d\n",min_index);
		if (cur_chessboard.cur_player==WHITE_CHESS)
		{
			lv_draw_img_dsc_t screen_canvas_1_img_dsc_0;
			lv_draw_img_dsc_init(&screen_canvas_1_img_dsc_0);
			lv_canvas_draw_img(guider_ui.screen_canvas_1, final_x, final_y, &_white_alpha_48x48, &screen_canvas_1_img_dsc_0);
		}
		else if (cur_chessboard.cur_player==BLACK_CHESS)
		{
			lv_draw_img_dsc_t screen_canvas_1_img_dsc_0;
			lv_draw_img_dsc_init(&screen_canvas_1_img_dsc_0);
			lv_canvas_draw_img(guider_ui.screen_canvas_1, final_x, final_y, &_black_alpha_48x48, &screen_canvas_1_img_dsc_0);
		}
		do_action(&cur_chessboard,min_index);
		
		lv_obj_clear_flag(guider_ui.screen_led, LV_OBJ_FLAG_HIDDEN);
		lv_obj_set_pos(guider_ui.screen_led, final_x+320+22, final_y+22);
		
		int game_flag=is_game_over(&cur_chessboard);
		if (game_flag!=GAME_NOT_OVER)
		{
			lv_obj_clear_flag(guider_ui.screen_msgbox, LV_OBJ_FLAG_HIDDEN);
		}
		else
		{
			Alpha_act();
		}
		if(game_flag==GAME_WHITE_WIN)
		{
			//((lv_msgbox_t *)(guider_ui.screen_msgbox))->text
			lv_label_set_text(((lv_msgbox_t *)(guider_ui.screen_msgbox))->text, "White Win!");

		}
		else if(game_flag==GAME_BLACK_WIN)
		{
			lv_label_set_text(((lv_msgbox_t *)(guider_ui.screen_msgbox))->text, "Black Win!");
			//lv_msgbox_set_text(guider_ui.screen_msgbox, constchar*txt);
		}
		else if(game_flag==GAME_DRAW)
		{
			lv_label_set_text(((lv_msgbox_t *)(guider_ui.screen_msgbox))->text, "Draw!");
			//lv_msgbox_set_text(guider_ui.screen_msgbox, constchar*txt);
		}
		printf("game_flag=%d\n",game_flag);
		
		
	}
	else{}
}



void get_config()
{
	lv_radiobtn_t * rb = (lv_radiobtn_t *)(guider_ui.screen_radiobtn);
	int first_hand_=rb->active_index;
	if (first_hand_==0)
	{
		first_hand=HUMAN_FIRST;
	}
	else if (first_hand_==1)
	{
		first_hand=ALPHA_FIRST;
	}
}

void game_init()
{
	chessboard_screen_init();
	init_chess_board(&cur_chessboard);
	if (first_hand==ALPHA_FIRST)
	{
		printf("first_hand:%d",first_hand);
		Alpha_act();
	}
}

void play_again()
{
	init_dclock();
	game_init();
	lv_obj_add_flag(guider_ui.screen_msgbox, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_led, LV_OBJ_FLAG_HIDDEN);
}


void app_init()
{
	AI_Init();
	lv_init();                          // lvgl初始化
  lv_port_disp_init();                // 显示设备初始化
  lv_port_indev_init();               // 输入设备初始化
	
	setup_ui(&guider_ui);
	events_init(&guider_ui);
	game_init();
}

void app_mainloop()
{
	//AI_Run();
	lv_task_handler();
}













//#define SDRAM_BANK_ADDR     ((uint32_t)0xC0000000) 				// FMC SDRAM 数据基地址
//#define SDRAM_Size 32*1024*1024  //32M字节
//uint8_t SDRAM_Test(void)
//{
//	uint32_t i = 0;			// 计数变量
//	uint16_t ReadData = 0; 	// 读取到的数据
//	uint8_t  ReadData_8b;

//	uint32_t ExecutionTime_Begin;		// 开始时间
//	uint32_t ExecutionTime_End;		// 结束时间
//	uint32_t ExecutionTime;				// 执行时间	
//	float    ExecutionSpeed;			// 执行速度
//	
//	printf("\r\n*****************************************************************************************************\r\n");		
//	printf("\r\n进行速度测试>>>\r\n");

//// 写入 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//	ExecutionTime_Begin 	= HAL_GetTick();	// 获取 systick 当前时间，单位ms
//	
//	for (i = 0; i < SDRAM_Size/2; i++)
//	{
// 		*(__IO uint16_t*) (SDRAM_BANK_ADDR + 2*i) = (uint16_t)i;		// 写入数据
//	}
//	ExecutionTime_End		= HAL_GetTick();											// 获取 systick 当前时间，单位ms
//	ExecutionTime  = ExecutionTime_End - ExecutionTime_Begin; 				// 计算擦除时间，单位ms
//	ExecutionSpeed = (float)SDRAM_Size /1024/1024 /ExecutionTime*1000 ; 	// 计算速度，单位 MB/S	
//	
//	printf("\r\n以16位数据宽度写入数据，大小：%d MB，耗时: %d ms, 写入速度：%.2f MB/s\r\n",SDRAM_Size/1024/1024,ExecutionTime,ExecutionSpeed);

//// 读取	>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 

//	ExecutionTime_Begin 	= HAL_GetTick();	// 获取 systick 当前时间，单位ms
//	
//	for(i = 0; i < SDRAM_Size/2;i++ )
//	{
//		ReadData = *(__IO uint16_t*)(SDRAM_BANK_ADDR + 2 * i );  // 从SDRAM读出数据	
//	}
//	ExecutionTime_End		= HAL_GetTick();											// 获取 systick 当前时间，单位ms
//	ExecutionTime  = ExecutionTime_End - ExecutionTime_Begin; 				// 计算擦除时间，单位ms
//	ExecutionSpeed = (float)SDRAM_Size /1024/1024 /ExecutionTime*1000 ; 	// 计算速度，单位 MB/S	
//	
//	printf("\r\n读取数据完毕，大小：%d MB，耗时: %d ms, 读取速度：%.2f MB/s\r\n",SDRAM_Size/1024/1024,ExecutionTime,ExecutionSpeed);
//	
//// 数据校验 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   
//		
//	printf("\r\n*****************************************************************************************************\r\n");		
//	printf("\r\n进行数据校验>>>\r\n");
//	
//	for(i = 0; i < SDRAM_Size/2;i++ )
//	{
//		ReadData = *(__IO uint16_t*)(SDRAM_BANK_ADDR + 2 * i );  // 从SDRAM读出数据	
//		if( ReadData != (uint16_t)i )      //检测数据，若不相等，跳出函数,返回检测失败结果。
//		{
//			printf("\r\nSDRAM测试失败！！\r\n");
//			return ERROR;	 // 返回失败标志
//		}
//	}
//	
//	printf("\r\n16位数据宽度读写通过，以8位数据宽度写入数据\r\n");
//	for (i = 0; i < 255; i++)
//	{
// 		*(__IO uint8_t*) (SDRAM_BANK_ADDR + i) =  (uint8_t)i;
//	}	
//	printf("写入完毕，读取数据并比较...\r\n");
//	for (i = 0; i < 255; i++)
//	{
//		ReadData_8b = *(__IO uint8_t*) (SDRAM_BANK_ADDR + i);
//		if( ReadData_8b != (uint8_t)i )      //检测数据，若不相等，跳出函数,返回检测失败结果。
//		{
//			printf("8位数据宽度读写测试失败！！\r\n");
//			printf("请检查NBL0和NBL1的连接\r\n");	
//			return ERROR;	 // 返回失败标志
//		}
//	}		
//	printf("8位数据宽度读写通过\r\n");
//	printf("SDRAM读写测试通过，系统正常\r\n");
//	return SUCCESS;	 // 返回成功标志
//}

