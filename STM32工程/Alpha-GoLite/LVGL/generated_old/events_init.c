/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "app.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void screen_canvas_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		//lv_obj_add_flag(guider_ui.screen_canvas_1, LV_OBJ_FLAG_HIDDEN);
		touched_chessboard();
		break;
	}
	default:
		break;
	}
}
static void screen_slider_search_num_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//lv_obj_clear_flag(guider_ui.screen_led, LV_OBJ_FLAG_HIDDEN);
		search_num_update();
		break;
	}
	default:
		break;
	}
}
static void screen_slider_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//lv_obj_clear_flag(guider_ui.screen_led, LV_OBJ_FLAG_HIDDEN);
		search_const_update();
		break;
	}
	default:
		break;
	}
}
static void screen_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//lv_obj_clear_flag(guider_ui.screen_led, LV_OBJ_FLAG_HIDDEN);
		get_config();
		break;
	}
	default:
		break;
	}
}
static void screen_msgbox_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * obj = lv_event_get_current_target(e);
		uint16_t id = lv_msgbox_get_active_btn(obj);
		switch(id) {
		case 0:
		{
			//lv_obj_clear_flag(guider_ui.screen_led, LV_OBJ_FLAG_HIDDEN);
			play_again();
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
void events_init_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_canvas_1, screen_canvas_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_slider_search_num, screen_slider_search_num_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_slider_1, screen_slider_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_btn_1, screen_btn_1_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_msgbox, screen_msgbox_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{

}
