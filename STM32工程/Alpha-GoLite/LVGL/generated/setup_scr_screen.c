/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "app.h"



int screen_digital_clock_1_min_value = 0;
int screen_digital_clock_1_hour_value = 0;
int screen_digital_clock_1_sec_value = 0;

void init_dclock()
{
	screen_digital_clock_1_min_value = 0;
	screen_digital_clock_1_hour_value = 0;
	screen_digital_clock_1_sec_value = 0;
}

void setup_scr_screen(lv_ui *ui)
{
	//Write codes screen
	ui->screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen, 800, 480);
	lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0xccd9ff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen, lv_color_hex(0xdaffb7), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen, 146, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_canvas_1
	ui->screen_canvas_1 = lv_canvas_create(ui->screen);
	static lv_color_t *buf_screen_canvas_1 = (lv_color_t * )(0xC0000000+0x800000);
	lv_canvas_set_buffer(ui->screen_canvas_1, buf_screen_canvas_1, 480, 480, LV_IMG_CF_TRUE_COLOR_ALPHA);
	lv_canvas_fill_bg(ui->screen_canvas_1, lv_color_hex(0xf1fb7f), 255);
	//Canvas draw image
	lv_draw_img_dsc_t screen_canvas_1_img_dsc_0;
	lv_draw_img_dsc_init(&screen_canvas_1_img_dsc_0);
	lv_canvas_draw_img(ui->screen_canvas_1, 0, 0, &_black_alpha_48x48, &screen_canvas_1_img_dsc_0);

	//Canvas draw line
	static lv_point_t screen_canvas_1_points_array_1[] ={{24, 24},{456, 24},{456, 456},{24, 456},{24, 24},};
	lv_draw_line_dsc_t screen_canvas_1_line_dsc_1;
	lv_draw_line_dsc_init(&screen_canvas_1_line_dsc_1);
	screen_canvas_1_line_dsc_1.color = lv_color_hex(0x000000);
	screen_canvas_1_line_dsc_1.opa = 255;
	screen_canvas_1_line_dsc_1.width = 2;
	screen_canvas_1_line_dsc_1.round_start = false;
	screen_canvas_1_line_dsc_1.round_end = false;
	lv_canvas_draw_line(ui->screen_canvas_1, screen_canvas_1_points_array_1, 5, &screen_canvas_1_line_dsc_1);

	//Canvas draw line
	static lv_point_t screen_canvas_1_points_array_2[] ={{24, 78},{456, 78},{456, 402},{24, 402},{24, 348},{456, 348},{456, 294},{24, 294},{24, 240},{456, 240},{456, 186},{24, 186},{24, 132},{456, 132},};
	lv_draw_line_dsc_t screen_canvas_1_line_dsc_2;
	lv_draw_line_dsc_init(&screen_canvas_1_line_dsc_2);
	screen_canvas_1_line_dsc_2.color = lv_color_hex(0x000000);
	screen_canvas_1_line_dsc_2.opa = 255;
	screen_canvas_1_line_dsc_2.width = 1;
	screen_canvas_1_line_dsc_2.round_start = false;
	screen_canvas_1_line_dsc_2.round_end = false;
	lv_canvas_draw_line(ui->screen_canvas_1, screen_canvas_1_points_array_2, 14, &screen_canvas_1_line_dsc_2);

	//Canvas draw line
	static lv_point_t screen_canvas_1_points_array_3[] ={{78, 24},{78, 456},{132, 456},{132, 24},{186, 24},{186, 456},{240, 456},{240, 24},{294, 24},{294, 456},{348, 456},{348, 24},{402, 24},{402, 456},};
	lv_draw_line_dsc_t screen_canvas_1_line_dsc_3;
	lv_draw_line_dsc_init(&screen_canvas_1_line_dsc_3);
	screen_canvas_1_line_dsc_3.color = lv_color_hex(0x000000);
	screen_canvas_1_line_dsc_3.opa = 255;
	screen_canvas_1_line_dsc_3.width = 1;
	screen_canvas_1_line_dsc_3.round_start = false;
	screen_canvas_1_line_dsc_3.round_end = false;
	lv_canvas_draw_line(ui->screen_canvas_1, screen_canvas_1_points_array_3, 14, &screen_canvas_1_line_dsc_3);

	//Canvas draw image
	lv_draw_img_dsc_t screen_canvas_1_img_dsc_4;
	lv_draw_img_dsc_init(&screen_canvas_1_img_dsc_4);
	lv_canvas_draw_img(ui->screen_canvas_1, 0, 0, &_white_alpha_48x48, &screen_canvas_1_img_dsc_4);

	lv_obj_set_pos(ui->screen_canvas_1, 320, 0);
	lv_obj_set_size(ui->screen_canvas_1, 480, 480);
	lv_obj_set_scrollbar_mode(ui->screen_canvas_1, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_canvas_1, LV_OBJ_FLAG_CLICKABLE);

	//Write codes screen_spinner_1
	ui->screen_spinner_1 = lv_spinner_create(ui->screen, 1000, 60);
	lv_obj_set_pos(ui->screen_spinner_1, 37, 25);
	lv_obj_set_size(ui->screen_spinner_1, 50, 50);

	//Write style for screen_spinner_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_pad_top(ui->screen_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->screen_spinner_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_spinner_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_spinner_1, lv_color_hex(0xd5d6de), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_spinner_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->screen_spinner_1, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_spinner_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_spinner_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_digital_clock_1
	static bool screen_digital_clock_1_timer_enabled = false;
	ui->screen_digital_clock_1 = lv_dclock_create(ui->screen, "0:00:00");
	if (!screen_digital_clock_1_timer_enabled) {
		lv_timer_create(screen_digital_clock_1_timer, 1000, NULL);
		screen_digital_clock_1_timer_enabled = true;
	}
	lv_obj_set_pos(ui->screen_digital_clock_1, 106, 27);
	lv_obj_set_size(ui->screen_digital_clock_1, 170, 48);

	//Write style for screen_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_digital_clock_1, lv_color_hex(0x191717), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_digital_clock_1, &lv_font_ArchitectsDaughter_32, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_digital_clock_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_digital_clock_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_digital_clock_1, 129, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_digital_clock_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_digital_clock_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_digital_clock_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_radiobtn
	ui->screen_radiobtn = lv_radiobtn_create(ui->screen);
	ui->screen_radiobtn_item0 =lv_radiobtn_add_item(ui->screen_radiobtn, "Human");
	ui->screen_radiobtn_item1 =lv_radiobtn_add_item(ui->screen_radiobtn, "Alpha Gobang Lite");
	lv_obj_set_pos(ui->screen_radiobtn, 25, 294);
	lv_obj_set_size(ui->screen_radiobtn, 270, 75);

	//Write style state: LV_STATE_DEFAULT for &style_screen_radiobtn_main_main_default
	static lv_style_t style_screen_radiobtn_main_main_default;
	ui_init_style(&style_screen_radiobtn_main_main_default);
	
	lv_style_set_pad_top(&style_screen_radiobtn_main_main_default, 5);
	lv_style_set_pad_left(&style_screen_radiobtn_main_main_default, 5);
	lv_style_set_pad_right(&style_screen_radiobtn_main_main_default, 5);
	lv_style_set_pad_bottom(&style_screen_radiobtn_main_main_default, 5);
	lv_style_set_border_width(&style_screen_radiobtn_main_main_default, 1);
	lv_style_set_border_opa(&style_screen_radiobtn_main_main_default, 0);
	lv_style_set_border_color(&style_screen_radiobtn_main_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_radiobtn_main_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_radiobtn_main_main_default, 6);
	lv_style_set_bg_opa(&style_screen_radiobtn_main_main_default, 0);
	lv_style_set_shadow_width(&style_screen_radiobtn_main_main_default, 0);
	lv_obj_add_style(ui->screen_radiobtn, &style_screen_radiobtn_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_radiobtn_extra_btns_main_default
	static lv_style_t style_screen_radiobtn_extra_btns_main_default;
	ui_init_style(&style_screen_radiobtn_extra_btns_main_default);
	
	lv_style_set_pad_top(&style_screen_radiobtn_extra_btns_main_default, 5);
	lv_style_set_pad_right(&style_screen_radiobtn_extra_btns_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_radiobtn_extra_btns_main_default, 5);
	lv_style_set_pad_left(&style_screen_radiobtn_extra_btns_main_default, 0);
	lv_style_set_text_color(&style_screen_radiobtn_extra_btns_main_default, lv_color_hex(0x000000));
	lv_style_set_text_font(&style_screen_radiobtn_extra_btns_main_default, &lv_font_ArchitectsDaughter_16);
	lv_style_set_text_opa(&style_screen_radiobtn_extra_btns_main_default, 255);
	lv_style_set_text_letter_space(&style_screen_radiobtn_extra_btns_main_default, 2);
	lv_style_set_radius(&style_screen_radiobtn_extra_btns_main_default, 6);
	lv_style_set_bg_opa(&style_screen_radiobtn_extra_btns_main_default, 0);
	lv_obj_add_style(ui->screen_radiobtn_item1, &style_screen_radiobtn_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_radiobtn_item0, &style_screen_radiobtn_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_radiobtn_extra_btns_indicator_default
	static lv_style_t style_screen_radiobtn_extra_btns_indicator_default;
	ui_init_style(&style_screen_radiobtn_extra_btns_indicator_default);
	
	lv_style_set_border_width(&style_screen_radiobtn_extra_btns_indicator_default, 2);
	lv_style_set_border_opa(&style_screen_radiobtn_extra_btns_indicator_default, 255);
	lv_style_set_border_color(&style_screen_radiobtn_extra_btns_indicator_default, lv_color_hex(0x000000));
	lv_style_set_border_side(&style_screen_radiobtn_extra_btns_indicator_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_radiobtn_extra_btns_indicator_default, 20);
	lv_style_set_bg_opa(&style_screen_radiobtn_extra_btns_indicator_default, 255);
	lv_style_set_bg_color(&style_screen_radiobtn_extra_btns_indicator_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_radiobtn_extra_btns_indicator_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->screen_radiobtn_item1, &style_screen_radiobtn_extra_btns_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_radiobtn_item0, &style_screen_radiobtn_extra_btns_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for &style_screen_radiobtn_extra_btns_indicator_pressed
	static lv_style_t style_screen_radiobtn_extra_btns_indicator_pressed;
	ui_init_style(&style_screen_radiobtn_extra_btns_indicator_pressed);
	
	lv_style_set_border_width(&style_screen_radiobtn_extra_btns_indicator_pressed, 2);
	lv_style_set_border_opa(&style_screen_radiobtn_extra_btns_indicator_pressed, 255);
	lv_style_set_border_color(&style_screen_radiobtn_extra_btns_indicator_pressed, lv_color_hex(0x000000));
	lv_style_set_border_side(&style_screen_radiobtn_extra_btns_indicator_pressed, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_radiobtn_extra_btns_indicator_pressed, 20);
	lv_style_set_bg_opa(&style_screen_radiobtn_extra_btns_indicator_pressed, 255);
	lv_style_set_bg_color(&style_screen_radiobtn_extra_btns_indicator_pressed, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_radiobtn_extra_btns_indicator_pressed, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->screen_radiobtn_item1, &style_screen_radiobtn_extra_btns_indicator_pressed, LV_PART_INDICATOR|LV_STATE_PRESSED);
	lv_obj_add_style(ui->screen_radiobtn_item0, &style_screen_radiobtn_extra_btns_indicator_pressed, LV_PART_INDICATOR|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for &style_screen_radiobtn_extra_btns_indicator_checked
	static lv_style_t style_screen_radiobtn_extra_btns_indicator_checked;
	ui_init_style(&style_screen_radiobtn_extra_btns_indicator_checked);
	
	lv_style_set_border_width(&style_screen_radiobtn_extra_btns_indicator_checked, 2);
	lv_style_set_border_opa(&style_screen_radiobtn_extra_btns_indicator_checked, 255);
	lv_style_set_border_color(&style_screen_radiobtn_extra_btns_indicator_checked, lv_color_hex(0x000000));
	lv_style_set_border_side(&style_screen_radiobtn_extra_btns_indicator_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_radiobtn_extra_btns_indicator_checked, 20);
	lv_style_set_bg_opa(&style_screen_radiobtn_extra_btns_indicator_checked, 255);
	lv_style_set_bg_color(&style_screen_radiobtn_extra_btns_indicator_checked, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_radiobtn_extra_btns_indicator_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->screen_radiobtn_item1, &style_screen_radiobtn_extra_btns_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_add_style(ui->screen_radiobtn_item0, &style_screen_radiobtn_extra_btns_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style state: LV_STATE_CHECKED | LV_STATE_PRESSED for &style_screen_radiobtn_extra_btns_indicator_checked_pressed
	static lv_style_t style_screen_radiobtn_extra_btns_indicator_checked_pressed;
	ui_init_style(&style_screen_radiobtn_extra_btns_indicator_checked_pressed);
	
	lv_style_set_border_width(&style_screen_radiobtn_extra_btns_indicator_checked_pressed, 2);
	lv_style_set_border_opa(&style_screen_radiobtn_extra_btns_indicator_checked_pressed, 255);
	lv_style_set_border_color(&style_screen_radiobtn_extra_btns_indicator_checked_pressed, lv_color_hex(0x000000));
	lv_style_set_border_side(&style_screen_radiobtn_extra_btns_indicator_checked_pressed, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_radiobtn_extra_btns_indicator_checked_pressed, 20);
	lv_style_set_bg_opa(&style_screen_radiobtn_extra_btns_indicator_checked_pressed, 255);
	lv_style_set_bg_color(&style_screen_radiobtn_extra_btns_indicator_checked_pressed, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_radiobtn_extra_btns_indicator_checked_pressed, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->screen_radiobtn_item1, &style_screen_radiobtn_extra_btns_indicator_checked_pressed, LV_PART_INDICATOR|LV_STATE_CHECKED | LV_STATE_PRESSED);
	lv_obj_add_style(ui->screen_radiobtn_item0, &style_screen_radiobtn_extra_btns_indicator_checked_pressed, LV_PART_INDICATOR|LV_STATE_CHECKED | LV_STATE_PRESSED);

	//Write style state: LV_STATE_DEFAULT for &style_screen_radiobtn_extra_btns_custom_default
	static lv_style_t style_screen_radiobtn_extra_btns_custom_default;
	ui_init_style(&style_screen_radiobtn_extra_btns_custom_default);
	
	lv_style_set_border_width(&style_screen_radiobtn_extra_btns_custom_default, 2);
	lv_style_set_border_opa(&style_screen_radiobtn_extra_btns_custom_default, 0);
	lv_style_set_border_color(&style_screen_radiobtn_extra_btns_custom_default, lv_color_hex(0xffffff));
	lv_style_set_border_side(&style_screen_radiobtn_extra_btns_custom_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_radiobtn_extra_btns_custom_default, 20);
	lv_style_set_bg_opa(&style_screen_radiobtn_extra_btns_custom_default, 0);
	lv_obj_add_style(ui->screen_radiobtn_item1, &style_screen_radiobtn_extra_btns_custom_default, LV_PART_CUSTOM_FIRST|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_radiobtn_item0, &style_screen_radiobtn_extra_btns_custom_default, LV_PART_CUSTOM_FIRST|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for &style_screen_radiobtn_extra_btns_custom_pressed
	static lv_style_t style_screen_radiobtn_extra_btns_custom_pressed;
	ui_init_style(&style_screen_radiobtn_extra_btns_custom_pressed);
	
	lv_style_set_border_width(&style_screen_radiobtn_extra_btns_custom_pressed, 2);
	lv_style_set_border_opa(&style_screen_radiobtn_extra_btns_custom_pressed, 0);
	lv_style_set_border_color(&style_screen_radiobtn_extra_btns_custom_pressed, lv_color_hex(0xffffff));
	lv_style_set_border_side(&style_screen_radiobtn_extra_btns_custom_pressed, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_radiobtn_extra_btns_custom_pressed, 20);
	lv_style_set_bg_opa(&style_screen_radiobtn_extra_btns_custom_pressed, 0);
	lv_obj_add_style(ui->screen_radiobtn_item1, &style_screen_radiobtn_extra_btns_custom_pressed, LV_PART_CUSTOM_FIRST|LV_STATE_PRESSED);
	lv_obj_add_style(ui->screen_radiobtn_item0, &style_screen_radiobtn_extra_btns_custom_pressed, LV_PART_CUSTOM_FIRST|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for &style_screen_radiobtn_extra_btns_custom_checked
	static lv_style_t style_screen_radiobtn_extra_btns_custom_checked;
	ui_init_style(&style_screen_radiobtn_extra_btns_custom_checked);
	
	lv_style_set_border_width(&style_screen_radiobtn_extra_btns_custom_checked, 2);
	lv_style_set_border_opa(&style_screen_radiobtn_extra_btns_custom_checked, 255);
	lv_style_set_border_color(&style_screen_radiobtn_extra_btns_custom_checked, lv_color_hex(0x000000));
	lv_style_set_border_side(&style_screen_radiobtn_extra_btns_custom_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_radiobtn_extra_btns_custom_checked, 20);
	lv_style_set_bg_opa(&style_screen_radiobtn_extra_btns_custom_checked, 255);
	lv_style_set_bg_color(&style_screen_radiobtn_extra_btns_custom_checked, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_screen_radiobtn_extra_btns_custom_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->screen_radiobtn_item1, &style_screen_radiobtn_extra_btns_custom_checked, LV_PART_CUSTOM_FIRST|LV_STATE_CHECKED);
	lv_obj_add_style(ui->screen_radiobtn_item0, &style_screen_radiobtn_extra_btns_custom_checked, LV_PART_CUSTOM_FIRST|LV_STATE_CHECKED);

	//Write style state: LV_STATE_CHECKED | LV_STATE_PRESSED for &style_screen_radiobtn_extra_btns_custom_checked_pressed
	static lv_style_t style_screen_radiobtn_extra_btns_custom_checked_pressed;
	ui_init_style(&style_screen_radiobtn_extra_btns_custom_checked_pressed);
	
	lv_style_set_border_width(&style_screen_radiobtn_extra_btns_custom_checked_pressed, 2);
	lv_style_set_border_opa(&style_screen_radiobtn_extra_btns_custom_checked_pressed, 255);
	lv_style_set_border_color(&style_screen_radiobtn_extra_btns_custom_checked_pressed, lv_color_hex(0x000000));
	lv_style_set_border_side(&style_screen_radiobtn_extra_btns_custom_checked_pressed, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_radiobtn_extra_btns_custom_checked_pressed, 20);
	lv_style_set_bg_opa(&style_screen_radiobtn_extra_btns_custom_checked_pressed, 255);
	lv_style_set_bg_color(&style_screen_radiobtn_extra_btns_custom_checked_pressed, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_screen_radiobtn_extra_btns_custom_checked_pressed, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->screen_radiobtn_item1, &style_screen_radiobtn_extra_btns_custom_checked_pressed, LV_PART_CUSTOM_FIRST|LV_STATE_CHECKED | LV_STATE_PRESSED);
	lv_obj_add_style(ui->screen_radiobtn_item0, &style_screen_radiobtn_extra_btns_custom_checked_pressed, LV_PART_CUSTOM_FIRST|LV_STATE_CHECKED | LV_STATE_PRESSED);

	//Write codes screen_btn_1
	ui->screen_btn_1 = lv_btn_create(ui->screen);
	ui->screen_btn_1_label = lv_label_create(ui->screen_btn_1);
	lv_label_set_text(ui->screen_btn_1_label, "APPLY");
	lv_label_set_long_mode(ui->screen_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_btn_1_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_btn_1, 90, 390);
	lv_obj_set_size(ui->screen_btn_1, 140, 28);

	//Write style for screen_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_btn_1, lv_color_hex(0xaae6ca), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_btn_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_btn_1, 103, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_btn_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_btn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_btn_1, &lv_font_shouxie_28, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_label_1, "先手:");
	lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_1, 25, 244);
	lv_obj_set_size(ui->screen_label_1, 79, 28);

	//Write style for screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_1, &lv_font_shouxie_28, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led
	ui->screen_led = lv_led_create(ui->screen);
	lv_led_set_brightness(ui->screen_led, 255);
	lv_led_set_color(ui->screen_led, lv_color_hex(0xff6500));
	lv_obj_set_pos(ui->screen_led, 380, 220);
	lv_obj_set_size(ui->screen_led, 5, 5);
	lv_obj_add_flag(ui->screen_led, LV_OBJ_FLAG_HIDDEN);

	//Write codes screen_msgbox
	static const char * screen_msgbox_btns[] = {"Try Again", ""};
	ui->screen_msgbox = lv_msgbox_create(ui->screen, "Game Over", "You Win!", screen_msgbox_btns, false);
	lv_obj_set_size(lv_msgbox_get_btns(ui->screen_msgbox), 100, 40);
	lv_obj_set_pos(ui->screen_msgbox, 260, 165);
	lv_obj_set_size(ui->screen_msgbox, 280, 150);
	lv_obj_add_flag(ui->screen_msgbox, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_msgbox, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_msgbox, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_msgbox, 251, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_msgbox, lv_color_hex(0xdbffbd), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_msgbox, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_msgbox, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_msgbox, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_msgbox, lv_color_hex(0x575757), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_msgbox, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_msgbox, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_msgbox, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_msgbox, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_msgbox, 103, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_msgbox, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_msgbox, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_msgbox, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_msgbox_extra_title_main_default
	static lv_style_t style_screen_msgbox_extra_title_main_default;
	ui_init_style(&style_screen_msgbox_extra_title_main_default);
	
	lv_style_set_text_color(&style_screen_msgbox_extra_title_main_default, lv_color_hex(0x31312d));
	lv_style_set_text_font(&style_screen_msgbox_extra_title_main_default, &lv_font_montserratMedium_19);
	lv_style_set_text_opa(&style_screen_msgbox_extra_title_main_default, 255);
	lv_style_set_text_letter_space(&style_screen_msgbox_extra_title_main_default, 0);
	lv_style_set_text_line_space(&style_screen_msgbox_extra_title_main_default, 30);
	lv_obj_add_style(lv_msgbox_get_title(ui->screen_msgbox), &style_screen_msgbox_extra_title_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_msgbox_extra_content_main_default
	static lv_style_t style_screen_msgbox_extra_content_main_default;
	ui_init_style(&style_screen_msgbox_extra_content_main_default);
	
	lv_style_set_text_color(&style_screen_msgbox_extra_content_main_default, lv_color_hex(0x383732));
	lv_style_set_text_font(&style_screen_msgbox_extra_content_main_default, &lv_font_montserratMedium_14);
	lv_style_set_text_opa(&style_screen_msgbox_extra_content_main_default, 255);
	lv_style_set_text_letter_space(&style_screen_msgbox_extra_content_main_default, 0);
	lv_style_set_text_line_space(&style_screen_msgbox_extra_content_main_default, 10);
	lv_obj_add_style(lv_msgbox_get_text(ui->screen_msgbox), &style_screen_msgbox_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_msgbox_extra_btns_items_default
	static lv_style_t style_screen_msgbox_extra_btns_items_default;
	ui_init_style(&style_screen_msgbox_extra_btns_items_default);
	
	lv_style_set_bg_opa(&style_screen_msgbox_extra_btns_items_default, 0);
	lv_style_set_border_width(&style_screen_msgbox_extra_btns_items_default, 2);
	lv_style_set_border_opa(&style_screen_msgbox_extra_btns_items_default, 255);
	lv_style_set_border_color(&style_screen_msgbox_extra_btns_items_default, lv_color_hex(0x299d9c));
	lv_style_set_border_side(&style_screen_msgbox_extra_btns_items_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_msgbox_extra_btns_items_default, 4);
	lv_style_set_text_color(&style_screen_msgbox_extra_btns_items_default, lv_color_hex(0x01798e));
	lv_style_set_text_font(&style_screen_msgbox_extra_btns_items_default, &lv_font_Alatsi_Regular_13);
	lv_style_set_text_opa(&style_screen_msgbox_extra_btns_items_default, 255);
	lv_obj_add_style(lv_msgbox_get_btns(ui->screen_msgbox), &style_screen_msgbox_extra_btns_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write codes screen_label_2
	ui->screen_label_2 = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_label_2, "AI Value:");
	lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_2, 25, 120);
	lv_obj_set_size(ui->screen_label_2, 135, 28);

	//Write style for screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_2, &lv_font_shouxie_28, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_3
	ui->screen_label_3 = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_label_3, "--.---");
	lv_label_set_long_mode(ui->screen_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_3, 68, 173);
	lv_obj_set_size(ui->screen_label_3, 185, 32);

	//Write style for screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_label_3, lv_color_hex(0xF1FB7F), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_label_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_3, &lv_font_shouxie_28, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_3, 142, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen);

	//Init events for screen.
	events_init_screen(ui);
}
