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
#include "custom.h"


void setup_scr_main_screen(lv_ui *ui)
{
	//Write codes main_screen
	ui->main_screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->main_screen, 800, 480);

	//Write style for main_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_screen, lv_color_hex(0x06090b), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_slider_0
	ui->main_screen_slider_0 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_slider_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_slider_0, &_slider_0_alpha_800x80);
	lv_img_set_pivot(ui->main_screen_slider_0, 50,50);
	lv_img_set_angle(ui->main_screen_slider_0, 0);
	lv_obj_set_pos(ui->main_screen_slider_0, 0, 254);
	lv_obj_set_size(ui->main_screen_slider_0, 800, 80);
	lv_obj_add_flag(ui->main_screen_slider_0, LV_OBJ_FLAG_HIDDEN);

	//Write codes main_screen_slider_1
	ui->main_screen_slider_1 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_slider_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_slider_1, &_slider_1_alpha_800x80);
	lv_img_set_pivot(ui->main_screen_slider_1, 50,50);
	lv_img_set_angle(ui->main_screen_slider_1, 0);
	lv_obj_set_pos(ui->main_screen_slider_1, 0, 235);
	lv_obj_set_size(ui->main_screen_slider_1, 800, 80);
	lv_obj_add_flag(ui->main_screen_slider_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_slider_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_slider_2
	ui->main_screen_slider_2 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_slider_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_slider_2, &_slider_2_alpha_800x80);
	lv_img_set_pivot(ui->main_screen_slider_2, 50,50);
	lv_img_set_angle(ui->main_screen_slider_2, 0);
	lv_obj_set_pos(ui->main_screen_slider_2, 0, 190);
	lv_obj_set_size(ui->main_screen_slider_2, 800, 80);
	lv_obj_add_flag(ui->main_screen_slider_2, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_slider_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_slider_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_slider_3
	ui->main_screen_slider_3 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_slider_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_slider_3, &_slider_3_alpha_800x80);
	lv_img_set_pivot(ui->main_screen_slider_3, 50,50);
	lv_img_set_angle(ui->main_screen_slider_3, 0);
	lv_obj_set_pos(ui->main_screen_slider_3, 0, 226);
	lv_obj_set_size(ui->main_screen_slider_3, 800, 80);
	lv_obj_add_flag(ui->main_screen_slider_3, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_slider_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_slider_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_slider_4
	ui->main_screen_slider_4 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_slider_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_slider_4, &_slider_4_alpha_800x80);
	lv_img_set_pivot(ui->main_screen_slider_4, 50,50);
	lv_img_set_angle(ui->main_screen_slider_4, 0);
	lv_obj_set_pos(ui->main_screen_slider_4, 0, 214);
	lv_obj_set_size(ui->main_screen_slider_4, 800, 80);
	lv_obj_add_flag(ui->main_screen_slider_4, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_slider_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_slider_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_slider_5
	ui->main_screen_slider_5 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_slider_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_slider_5, &_slider_5_alpha_800x80);
	lv_img_set_pivot(ui->main_screen_slider_5, 50,50);
	lv_img_set_angle(ui->main_screen_slider_5, 0);
	lv_obj_set_pos(ui->main_screen_slider_5, 0, 260);
	lv_obj_set_size(ui->main_screen_slider_5, 800, 80);
	lv_obj_add_flag(ui->main_screen_slider_5, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_slider_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_slider_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_slider_6
	ui->main_screen_slider_6 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_slider_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_slider_6, &_slider_6_alpha_800x80);
	lv_img_set_pivot(ui->main_screen_slider_6, 50,50);
	lv_img_set_angle(ui->main_screen_slider_6, 0);
	lv_obj_set_pos(ui->main_screen_slider_6, 0, 256);
	lv_obj_set_size(ui->main_screen_slider_6, 800, 80);
	lv_obj_add_flag(ui->main_screen_slider_6, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_slider_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_slider_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_slider_7
	ui->main_screen_slider_7 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_slider_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_slider_7, &_slider_7_alpha_800x80);
	lv_img_set_pivot(ui->main_screen_slider_7, 50,50);
	lv_img_set_angle(ui->main_screen_slider_7, 0);
	lv_obj_set_pos(ui->main_screen_slider_7, 6, 244);
	lv_obj_set_size(ui->main_screen_slider_7, 800, 80);
	lv_obj_add_flag(ui->main_screen_slider_7, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_slider_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_slider_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_slider_8
	ui->main_screen_slider_8 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_slider_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_slider_8, &_slider_8_alpha_800x80);
	lv_img_set_pivot(ui->main_screen_slider_8, 50,50);
	lv_img_set_angle(ui->main_screen_slider_8, 0);
	lv_obj_set_pos(ui->main_screen_slider_8, 15, 222);
	lv_obj_set_size(ui->main_screen_slider_8, 800, 80);
	lv_obj_add_flag(ui->main_screen_slider_8, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_slider_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_slider_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_slider_9
	ui->main_screen_slider_9 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_slider_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_slider_9, &_slider_9_alpha_800x80);
	lv_img_set_pivot(ui->main_screen_slider_9, 50,50);
	lv_img_set_angle(ui->main_screen_slider_9, 0);
	lv_obj_set_pos(ui->main_screen_slider_9, 0, 269);
	lv_obj_set_size(ui->main_screen_slider_9, 800, 80);
	lv_obj_add_flag(ui->main_screen_slider_9, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_slider_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_slider_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_slider_P
	ui->main_screen_slider_P = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_slider_P, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_slider_P, &_slider_P_alpha_800x80);
	lv_img_set_pivot(ui->main_screen_slider_P, 50,50);
	lv_img_set_angle(ui->main_screen_slider_P, 0);
	lv_obj_set_pos(ui->main_screen_slider_P, 7, 258);
	lv_obj_set_size(ui->main_screen_slider_P, 800, 80);
	lv_obj_add_flag(ui->main_screen_slider_P, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_slider_P, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_slider_P, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_no_level_0
	ui->main_screen_no_level_0 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_no_level_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_no_level_0, &_NoHob_0_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_no_level_0, 100,5);
	lv_img_set_angle(ui->main_screen_no_level_0, 0);
	lv_obj_set_pos(ui->main_screen_no_level_0, 300, 143);
	lv_obj_set_size(ui->main_screen_no_level_0, 200, 194);
	lv_obj_add_flag(ui->main_screen_no_level_0, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_no_level_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_no_level_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_no_level_1
	ui->main_screen_no_level_1 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_no_level_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_no_level_1, &_NoHob_1_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_no_level_1, 100,5);
	lv_img_set_angle(ui->main_screen_no_level_1, 0);
	lv_obj_set_pos(ui->main_screen_no_level_1, 300, 143);
	lv_obj_set_size(ui->main_screen_no_level_1, 200, 194);
	lv_obj_add_flag(ui->main_screen_no_level_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_no_level_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_no_level_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_no_level_2
	ui->main_screen_no_level_2 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_no_level_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_no_level_2, &_NoHob_2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_no_level_2, 100,5);
	lv_img_set_angle(ui->main_screen_no_level_2, 0);
	lv_obj_set_pos(ui->main_screen_no_level_2, 300, 143);
	lv_obj_set_size(ui->main_screen_no_level_2, 200, 194);
	lv_obj_add_flag(ui->main_screen_no_level_2, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_no_level_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_no_level_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_no_level_3
	ui->main_screen_no_level_3 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_no_level_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_no_level_3, &_NoHob_3_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_no_level_3, 100,5);
	lv_img_set_angle(ui->main_screen_no_level_3, 0);
	lv_obj_set_pos(ui->main_screen_no_level_3, 300, 143);
	lv_obj_set_size(ui->main_screen_no_level_3, 200, 194);
	lv_obj_add_flag(ui->main_screen_no_level_3, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_no_level_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_no_level_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_no_level_4
	ui->main_screen_no_level_4 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_no_level_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_no_level_4, &_NoHob_4_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_no_level_4, 100,5);
	lv_img_set_angle(ui->main_screen_no_level_4, 0);
	lv_obj_set_pos(ui->main_screen_no_level_4, 300, 143);
	lv_obj_set_size(ui->main_screen_no_level_4, 200, 194);
	lv_obj_add_flag(ui->main_screen_no_level_4, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_no_level_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_no_level_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_no_level_5
	ui->main_screen_no_level_5 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_no_level_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_no_level_5, &_NoHob_5_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_no_level_5, 100,5);
	lv_img_set_angle(ui->main_screen_no_level_5, 0);
	lv_obj_set_pos(ui->main_screen_no_level_5, 300, 143);
	lv_obj_set_size(ui->main_screen_no_level_5, 200, 194);
	lv_obj_add_flag(ui->main_screen_no_level_5, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_no_level_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_no_level_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_no_level_6
	ui->main_screen_no_level_6 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_no_level_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_no_level_6, &_NoHob_6_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_no_level_6, 100,5);
	lv_img_set_angle(ui->main_screen_no_level_6, 0);
	lv_obj_set_pos(ui->main_screen_no_level_6, 300, 143);
	lv_obj_set_size(ui->main_screen_no_level_6, 200, 194);
	lv_obj_add_flag(ui->main_screen_no_level_6, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_no_level_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_no_level_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_no_level_7
	ui->main_screen_no_level_7 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_no_level_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_no_level_7, &_NoHob_7_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_no_level_7, 100,5);
	lv_img_set_angle(ui->main_screen_no_level_7, 0);
	lv_obj_set_pos(ui->main_screen_no_level_7, 308, 165);
	lv_obj_set_size(ui->main_screen_no_level_7, 200, 194);
	lv_obj_add_flag(ui->main_screen_no_level_7, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_no_level_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_no_level_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_no_level_8
	ui->main_screen_no_level_8 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_no_level_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_no_level_8, &_NoHob_8_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_no_level_8, 100,5);
	lv_img_set_angle(ui->main_screen_no_level_8, 0);
	lv_obj_set_pos(ui->main_screen_no_level_8, 318, 172);
	lv_obj_set_size(ui->main_screen_no_level_8, 200, 194);
	lv_obj_add_flag(ui->main_screen_no_level_8, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_no_level_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_no_level_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_no_level_9
	ui->main_screen_no_level_9 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_no_level_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_no_level_9, &_NoHob_9_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_no_level_9, 100,5);
	lv_img_set_angle(ui->main_screen_no_level_9, 0);
	lv_obj_set_pos(ui->main_screen_no_level_9, 350, 190);
	lv_obj_set_size(ui->main_screen_no_level_9, 200, 194);
	lv_obj_add_flag(ui->main_screen_no_level_9, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_no_level_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_no_level_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_no_level_P
	ui->main_screen_no_level_P = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_no_level_P, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_no_level_P, &_NoHob_P_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_no_level_P, 100,5);
	lv_img_set_angle(ui->main_screen_no_level_P, 0);
	lv_obj_set_pos(ui->main_screen_no_level_P, 300, 184);
	lv_obj_set_size(ui->main_screen_no_level_P, 200, 194);
	lv_obj_add_flag(ui->main_screen_no_level_P, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_no_level_P, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_no_level_P, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_cont_1
	ui->main_screen_cont_1 = lv_obj_create(ui->main_screen);
	lv_obj_set_pos(ui->main_screen_cont_1, 15, 38);
	lv_obj_set_size(ui->main_screen_cont_1, 200, 194);
	lv_obj_set_scrollbar_mode(ui->main_screen_cont_1, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->main_screen_cont_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_screen_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_screen_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_screen_cont_1, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_pan_1
	ui->main_screen_pan_1 = lv_img_create(ui->main_screen_cont_1);
	lv_obj_add_flag(ui->main_screen_pan_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_pan_1, &_img_pan_0_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_pan_1, 100,5);
	lv_img_set_angle(ui->main_screen_pan_1, 0);
	lv_obj_set_pos(ui->main_screen_pan_1, 0, 0);
	lv_obj_set_size(ui->main_screen_pan_1, 200, 194);

	//Write style for main_screen_pan_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_pan_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_select_ring_h1
	ui->main_screen_select_ring_h1 = lv_img_create(ui->main_screen_cont_1);
	lv_obj_add_flag(ui->main_screen_select_ring_h1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_select_ring_h1, &_Secim_Ver2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_select_ring_h1, 100,5);
	lv_img_set_angle(ui->main_screen_select_ring_h1, 0);
	lv_obj_set_pos(ui->main_screen_select_ring_h1, 0, 0);
	lv_obj_set_size(ui->main_screen_select_ring_h1, 200, 194);
	lv_obj_add_flag(ui->main_screen_select_ring_h1, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_select_ring_h1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_select_ring_h1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_select_ring_l1
	ui->main_screen_select_ring_l1 = lv_img_create(ui->main_screen_cont_1);
	lv_obj_add_flag(ui->main_screen_select_ring_l1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_select_ring_l1, &_Secim_Ver3_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_select_ring_l1, 100,5);
	lv_img_set_angle(ui->main_screen_select_ring_l1, 0);
	lv_obj_set_pos(ui->main_screen_select_ring_l1, 0, 0);
	lv_obj_set_size(ui->main_screen_select_ring_l1, 200, 194);
	lv_obj_add_flag(ui->main_screen_select_ring_l1, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_select_ring_l1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_select_ring_l1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_timer_label_1
	ui->main_screen_timer_label_1 = lv_label_create(ui->main_screen_cont_1);
	lv_label_set_text(ui->main_screen_timer_label_1, "00:00");
	lv_label_set_long_mode(ui->main_screen_timer_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_screen_timer_label_1, 51, 136);
	lv_obj_set_size(ui->main_screen_timer_label_1, 100, 32);
	lv_obj_add_flag(ui->main_screen_timer_label_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_timer_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_timer_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_timer_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_screen_timer_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_timer_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_screen_timer_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_screen_timer_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_timer_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_timer_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_timer_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_timer_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_timer_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_timer_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_timer_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_cont_2
	ui->main_screen_cont_2 = lv_obj_create(ui->main_screen);
	lv_obj_set_pos(ui->main_screen_cont_2, 300, 50);
	lv_obj_set_size(ui->main_screen_cont_2, 200, 194);
	lv_obj_set_scrollbar_mode(ui->main_screen_cont_2, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->main_screen_cont_2, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_screen_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_screen_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_screen_cont_2, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_pan_2
	ui->main_screen_pan_2 = lv_img_create(ui->main_screen_cont_2);
	lv_obj_add_flag(ui->main_screen_pan_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_pan_2, &_img_pan_0_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_pan_2, 100,5);
	lv_img_set_angle(ui->main_screen_pan_2, 0);
	lv_obj_set_pos(ui->main_screen_pan_2, 0, 0);
	lv_obj_set_size(ui->main_screen_pan_2, 200, 194);

	//Write style for main_screen_pan_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_pan_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_select_ring_h2
	ui->main_screen_select_ring_h2 = lv_img_create(ui->main_screen_cont_2);
	lv_obj_add_flag(ui->main_screen_select_ring_h2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_select_ring_h2, &_Secim_Ver2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_select_ring_h2, 100,5);
	lv_img_set_angle(ui->main_screen_select_ring_h2, 0);
	lv_obj_set_pos(ui->main_screen_select_ring_h2, 0, 0);
	lv_obj_set_size(ui->main_screen_select_ring_h2, 200, 194);
	lv_obj_add_flag(ui->main_screen_select_ring_h2, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_select_ring_h2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_select_ring_h2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_select_ring_l2
	ui->main_screen_select_ring_l2 = lv_img_create(ui->main_screen_cont_2);
	lv_obj_add_flag(ui->main_screen_select_ring_l2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_select_ring_l2, &_Secim_Ver3_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_select_ring_l2, 100,5);
	lv_img_set_angle(ui->main_screen_select_ring_l2, 0);
	lv_obj_set_pos(ui->main_screen_select_ring_l2, 0, 0);
	lv_obj_set_size(ui->main_screen_select_ring_l2, 200, 194);
	lv_obj_add_flag(ui->main_screen_select_ring_l2, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_select_ring_l2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_select_ring_l2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_timer_label_2
	ui->main_screen_timer_label_2 = lv_label_create(ui->main_screen_cont_2);
	lv_label_set_text(ui->main_screen_timer_label_2, "00:00");
	lv_label_set_long_mode(ui->main_screen_timer_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_screen_timer_label_2, 51, 136);
	lv_obj_set_size(ui->main_screen_timer_label_2, 100, 32);
	lv_obj_add_flag(ui->main_screen_timer_label_2, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_timer_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_timer_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_timer_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_screen_timer_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_timer_label_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_screen_timer_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_screen_timer_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_timer_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_timer_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_timer_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_timer_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_timer_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_timer_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_timer_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_cont_3
	ui->main_screen_cont_3 = lv_obj_create(ui->main_screen);
	lv_obj_set_pos(ui->main_screen_cont_3, 573, 56);
	lv_obj_set_size(ui->main_screen_cont_3, 200, 194);
	lv_obj_set_scrollbar_mode(ui->main_screen_cont_3, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->main_screen_cont_3, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_cont_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_screen_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_screen_cont_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_screen_cont_3, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_pan_3
	ui->main_screen_pan_3 = lv_img_create(ui->main_screen_cont_3);
	lv_obj_add_flag(ui->main_screen_pan_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_pan_3, &_img_pan_0_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_pan_3, 100,5);
	lv_img_set_angle(ui->main_screen_pan_3, 0);
	lv_obj_set_pos(ui->main_screen_pan_3, 0, 0);
	lv_obj_set_size(ui->main_screen_pan_3, 200, 194);

	//Write style for main_screen_pan_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_pan_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_select_ring_h3
	ui->main_screen_select_ring_h3 = lv_img_create(ui->main_screen_cont_3);
	lv_obj_add_flag(ui->main_screen_select_ring_h3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_select_ring_h3, &_Secim_Ver2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_select_ring_h3, 100,5);
	lv_img_set_angle(ui->main_screen_select_ring_h3, 0);
	lv_obj_set_pos(ui->main_screen_select_ring_h3, 0, 0);
	lv_obj_set_size(ui->main_screen_select_ring_h3, 200, 194);
	lv_obj_add_flag(ui->main_screen_select_ring_h3, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_select_ring_h3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_select_ring_h3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_select_ring_l3
	ui->main_screen_select_ring_l3 = lv_img_create(ui->main_screen_cont_3);
	lv_obj_add_flag(ui->main_screen_select_ring_l3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_select_ring_l3, &_Secim_Ver3_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_select_ring_l3, 100,5);
	lv_img_set_angle(ui->main_screen_select_ring_l3, 0);
	lv_obj_set_pos(ui->main_screen_select_ring_l3, 0, 0);
	lv_obj_set_size(ui->main_screen_select_ring_l3, 200, 194);
	lv_obj_add_flag(ui->main_screen_select_ring_l3, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_select_ring_l3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_select_ring_l3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_timer_label_3
	ui->main_screen_timer_label_3 = lv_label_create(ui->main_screen_cont_3);
	lv_label_set_text(ui->main_screen_timer_label_3, "00:00");
	lv_label_set_long_mode(ui->main_screen_timer_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_screen_timer_label_3, 53, 136);
	lv_obj_set_size(ui->main_screen_timer_label_3, 100, 32);
	lv_obj_add_flag(ui->main_screen_timer_label_3, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_timer_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_timer_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_timer_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_screen_timer_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_timer_label_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_screen_timer_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_screen_timer_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_timer_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_timer_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_timer_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_timer_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_timer_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_timer_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_timer_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_cont_4
	ui->main_screen_cont_4 = lv_obj_create(ui->main_screen);
	lv_obj_set_pos(ui->main_screen_cont_4, 145, 201);
	lv_obj_set_size(ui->main_screen_cont_4, 200, 194);
	lv_obj_set_scrollbar_mode(ui->main_screen_cont_4, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->main_screen_cont_4, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_cont_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_cont_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_screen_cont_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_screen_cont_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_screen_cont_4, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_pan_4
	ui->main_screen_pan_4 = lv_img_create(ui->main_screen_cont_4);
	lv_obj_add_flag(ui->main_screen_pan_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_pan_4, &_img_pan_0_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_pan_4, 100,5);
	lv_img_set_angle(ui->main_screen_pan_4, 0);
	lv_obj_set_pos(ui->main_screen_pan_4, 0, 0);
	lv_obj_set_size(ui->main_screen_pan_4, 200, 194);

	//Write style for main_screen_pan_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_pan_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_select_ring_h4
	ui->main_screen_select_ring_h4 = lv_img_create(ui->main_screen_cont_4);
	lv_obj_add_flag(ui->main_screen_select_ring_h4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_select_ring_h4, &_Secim_Ver2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_select_ring_h4, 100,5);
	lv_img_set_angle(ui->main_screen_select_ring_h4, 0);
	lv_obj_set_pos(ui->main_screen_select_ring_h4, 0, 0);
	lv_obj_set_size(ui->main_screen_select_ring_h4, 200, 194);
	lv_obj_add_flag(ui->main_screen_select_ring_h4, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_select_ring_h4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_select_ring_h4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_select_ring_l4
	ui->main_screen_select_ring_l4 = lv_img_create(ui->main_screen_cont_4);
	lv_obj_add_flag(ui->main_screen_select_ring_l4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_select_ring_l4, &_Secim_Ver3_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_select_ring_l4, 100,5);
	lv_img_set_angle(ui->main_screen_select_ring_l4, 0);
	lv_obj_set_pos(ui->main_screen_select_ring_l4, 0, 0);
	lv_obj_set_size(ui->main_screen_select_ring_l4, 200, 194);
	lv_obj_add_flag(ui->main_screen_select_ring_l4, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_select_ring_l4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_select_ring_l4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_timer_label_4
	ui->main_screen_timer_label_4 = lv_label_create(ui->main_screen_cont_4);
	lv_label_set_text(ui->main_screen_timer_label_4, "00:00");
	lv_label_set_long_mode(ui->main_screen_timer_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_screen_timer_label_4, 51, 136);
	lv_obj_set_size(ui->main_screen_timer_label_4, 100, 32);
	lv_obj_add_flag(ui->main_screen_timer_label_4, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_timer_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_timer_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_timer_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_screen_timer_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_timer_label_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_screen_timer_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_screen_timer_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_timer_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_timer_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_timer_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_timer_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_timer_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_timer_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_timer_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_cont_5
	ui->main_screen_cont_5 = lv_obj_create(ui->main_screen);
	lv_obj_set_pos(ui->main_screen_cont_5, 415, 201);
	lv_obj_set_size(ui->main_screen_cont_5, 200, 194);
	lv_obj_set_scrollbar_mode(ui->main_screen_cont_5, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->main_screen_cont_5, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_cont_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_cont_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_screen_cont_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_screen_cont_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_screen_cont_5, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_pan_5
	ui->main_screen_pan_5 = lv_img_create(ui->main_screen_cont_5);
	lv_obj_add_flag(ui->main_screen_pan_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_pan_5, &_img_pan_0_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_pan_5, 100,5);
	lv_img_set_angle(ui->main_screen_pan_5, 0);
	lv_obj_set_pos(ui->main_screen_pan_5, 0, 0);
	lv_obj_set_size(ui->main_screen_pan_5, 200, 194);

	//Write style for main_screen_pan_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_pan_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_select_ring_h5
	ui->main_screen_select_ring_h5 = lv_img_create(ui->main_screen_cont_5);
	lv_obj_add_flag(ui->main_screen_select_ring_h5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_select_ring_h5, &_Secim_Ver2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_select_ring_h5, 100,5);
	lv_img_set_angle(ui->main_screen_select_ring_h5, 0);
	lv_obj_set_pos(ui->main_screen_select_ring_h5, 0, 0);
	lv_obj_set_size(ui->main_screen_select_ring_h5, 200, 194);
	lv_obj_add_flag(ui->main_screen_select_ring_h5, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_select_ring_h5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_select_ring_h5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_select_ring_l5
	ui->main_screen_select_ring_l5 = lv_img_create(ui->main_screen_cont_5);
	lv_obj_add_flag(ui->main_screen_select_ring_l5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_select_ring_l5, &_Secim_Ver3_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_select_ring_l5, 100,5);
	lv_img_set_angle(ui->main_screen_select_ring_l5, 0);
	lv_obj_set_pos(ui->main_screen_select_ring_l5, 0, 0);
	lv_obj_set_size(ui->main_screen_select_ring_l5, 200, 194);
	lv_obj_add_flag(ui->main_screen_select_ring_l5, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_select_ring_l5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_select_ring_l5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_timer_label_5
	ui->main_screen_timer_label_5 = lv_label_create(ui->main_screen_cont_5);
	lv_label_set_text(ui->main_screen_timer_label_5, "00:00");
	lv_label_set_long_mode(ui->main_screen_timer_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_screen_timer_label_5, 51, 136);
	lv_obj_set_size(ui->main_screen_timer_label_5, 100, 32);
	lv_obj_add_flag(ui->main_screen_timer_label_5, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_timer_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_timer_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_timer_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_screen_timer_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_timer_label_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_screen_timer_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_screen_timer_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_timer_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_timer_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_timer_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_timer_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_timer_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_timer_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_timer_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_zone_timer_btn
	ui->main_screen_zone_timer_btn = lv_imgbtn_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_zone_timer_btn, LV_OBJ_FLAG_CHECKABLE);
	ui->main_screen_zone_timer_btn_label = lv_label_create(ui->main_screen_zone_timer_btn);
	lv_label_set_text(ui->main_screen_zone_timer_btn_label, "");
	lv_label_set_long_mode(ui->main_screen_zone_timer_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_screen_zone_timer_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_screen_zone_timer_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->main_screen_zone_timer_btn, 154, 175);
	lv_obj_set_size(ui->main_screen_zone_timer_btn, 50, 50);
	lv_obj_add_flag(ui->main_screen_zone_timer_btn, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_zone_timer_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->main_screen_zone_timer_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_zone_timer_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_zone_timer_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_zone_timer_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for main_screen_zone_timer_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->main_screen_zone_timer_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->main_screen_zone_timer_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->main_screen_zone_timer_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->main_screen_zone_timer_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for main_screen_zone_timer_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->main_screen_zone_timer_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->main_screen_zone_timer_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->main_screen_zone_timer_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->main_screen_zone_timer_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for main_screen_zone_timer_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->main_screen_zone_timer_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes main_screen_zone_warm_btn
	ui->main_screen_zone_warm_btn = lv_imgbtn_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_zone_warm_btn, LV_OBJ_FLAG_CHECKABLE);
	ui->main_screen_zone_warm_btn_label = lv_label_create(ui->main_screen_zone_warm_btn);
	lv_label_set_text(ui->main_screen_zone_warm_btn_label, "");
	lv_label_set_long_mode(ui->main_screen_zone_warm_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_screen_zone_warm_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_screen_zone_warm_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->main_screen_zone_warm_btn, 26, 175);
	lv_obj_set_size(ui->main_screen_zone_warm_btn, 50, 50);
	lv_obj_add_flag(ui->main_screen_zone_warm_btn, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_zone_warm_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->main_screen_zone_warm_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_zone_warm_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_zone_warm_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_zone_warm_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for main_screen_zone_warm_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->main_screen_zone_warm_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->main_screen_zone_warm_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->main_screen_zone_warm_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->main_screen_zone_warm_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for main_screen_zone_warm_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->main_screen_zone_warm_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->main_screen_zone_warm_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->main_screen_zone_warm_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->main_screen_zone_warm_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for main_screen_zone_warm_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->main_screen_zone_warm_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes main_screen_img_no_warm_3
	ui->main_screen_img_no_warm_3 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_no_warm_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_no_warm_3, &_img_no_warm_3_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_no_warm_3, 100,5);
	lv_img_set_angle(ui->main_screen_img_no_warm_3, 0);
	lv_obj_set_pos(ui->main_screen_img_no_warm_3, 215, 54);
	lv_obj_set_size(ui->main_screen_img_no_warm_3, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_no_warm_3, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_no_warm_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_no_warm_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_no_warm_2
	ui->main_screen_img_no_warm_2 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_no_warm_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_no_warm_2, &_img_no_warm_2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_no_warm_2, 100,5);
	lv_img_set_angle(ui->main_screen_img_no_warm_2, 0);
	lv_obj_set_pos(ui->main_screen_img_no_warm_2, 350, 190);
	lv_obj_set_size(ui->main_screen_img_no_warm_2, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_no_warm_2, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_no_warm_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_no_warm_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_no_warm_1
	ui->main_screen_img_no_warm_1 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_no_warm_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_no_warm_1, &_img_no_warm_1_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_no_warm_1, 100,5);
	lv_img_set_angle(ui->main_screen_img_no_warm_1, 0);
	lv_obj_set_pos(ui->main_screen_img_no_warm_1, 567, 153);
	lv_obj_set_size(ui->main_screen_img_no_warm_1, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_no_warm_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_no_warm_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_no_warm_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_warm_3
	ui->main_screen_img_warm_3 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_warm_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_warm_3, &_img_warm_3_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_warm_3, 100,5);
	lv_img_set_angle(ui->main_screen_img_warm_3, 0);
	lv_obj_set_pos(ui->main_screen_img_warm_3, 592, 10);
	lv_obj_set_size(ui->main_screen_img_warm_3, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_warm_3, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_warm_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_warm_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_warm_2
	ui->main_screen_img_warm_2 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_warm_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_warm_2, &_img_warm_2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_warm_2, 100,5);
	lv_img_set_angle(ui->main_screen_img_warm_2, 0);
	lv_obj_set_pos(ui->main_screen_img_warm_2, 392, 10);
	lv_obj_set_size(ui->main_screen_img_warm_2, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_warm_2, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_warm_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_warm_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_warm_1
	ui->main_screen_img_warm_1 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_warm_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_warm_1, &_img_warm_1_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_warm_1, 100,5);
	lv_img_set_angle(ui->main_screen_img_warm_1, 0);
	lv_obj_set_pos(ui->main_screen_img_warm_1, 192, 10);
	lv_obj_set_size(ui->main_screen_img_warm_1, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_warm_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_warm_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_warm_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_pan_0
	ui->main_screen_img_pan_0 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_pan_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_pan_0, &_img_pan_0_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_pan_0, 100,5);
	lv_img_set_angle(ui->main_screen_img_pan_0, 0);
	lv_obj_set_pos(ui->main_screen_img_pan_0, 300, 165);
	lv_obj_set_size(ui->main_screen_img_pan_0, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_pan_0, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_pan_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_pan_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_pan_1
	ui->main_screen_img_pan_1 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_pan_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_pan_1, &_img_pan_1_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_pan_1, 100,5);
	lv_img_set_angle(ui->main_screen_img_pan_1, 0);
	lv_obj_set_pos(ui->main_screen_img_pan_1, 300, 158);
	lv_obj_set_size(ui->main_screen_img_pan_1, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_pan_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_pan_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_pan_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_pan_2
	ui->main_screen_img_pan_2 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_pan_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_pan_2, &_img_pan_2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_pan_2, 100,5);
	lv_img_set_angle(ui->main_screen_img_pan_2, 0);
	lv_obj_set_pos(ui->main_screen_img_pan_2, 300, 165);
	lv_obj_set_size(ui->main_screen_img_pan_2, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_pan_2, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_pan_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_pan_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_pan_3
	ui->main_screen_img_pan_3 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_pan_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_pan_3, &_img_pan_3_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_pan_3, 100,5);
	lv_img_set_angle(ui->main_screen_img_pan_3, 0);
	lv_obj_set_pos(ui->main_screen_img_pan_3, 350, 190);
	lv_obj_set_size(ui->main_screen_img_pan_3, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_pan_3, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_pan_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_pan_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_pan_4
	ui->main_screen_img_pan_4 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_pan_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_pan_4, &_img_pan_4_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_pan_4, 100,5);
	lv_img_set_angle(ui->main_screen_img_pan_4, 0);
	lv_obj_set_pos(ui->main_screen_img_pan_4, 308, 165);
	lv_obj_set_size(ui->main_screen_img_pan_4, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_pan_4, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_pan_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_pan_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_pan_5
	ui->main_screen_img_pan_5 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_pan_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_pan_5, &_img_pan_5_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_pan_5, 100,5);
	lv_img_set_angle(ui->main_screen_img_pan_5, 0);
	lv_obj_set_pos(ui->main_screen_img_pan_5, 300, 143);
	lv_obj_set_size(ui->main_screen_img_pan_5, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_pan_5, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_pan_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_pan_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_pan_6
	ui->main_screen_img_pan_6 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_pan_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_pan_6, &_img_pan_6_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_pan_6, 100,5);
	lv_img_set_angle(ui->main_screen_img_pan_6, 0);
	lv_obj_set_pos(ui->main_screen_img_pan_6, 350, 190);
	lv_obj_set_size(ui->main_screen_img_pan_6, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_pan_6, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_pan_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_pan_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_pan_7
	ui->main_screen_img_pan_7 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_pan_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_pan_7, &_img_pan_7_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_pan_7, 100,5);
	lv_img_set_angle(ui->main_screen_img_pan_7, 0);
	lv_obj_set_pos(ui->main_screen_img_pan_7, 300, 165);
	lv_obj_set_size(ui->main_screen_img_pan_7, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_pan_7, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_pan_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_pan_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_pan_8
	ui->main_screen_img_pan_8 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_pan_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_pan_8, &_img_pan_8_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_pan_8, 100,5);
	lv_img_set_angle(ui->main_screen_img_pan_8, 0);
	lv_obj_set_pos(ui->main_screen_img_pan_8, 294, 143);
	lv_obj_set_size(ui->main_screen_img_pan_8, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_pan_8, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_pan_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_pan_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_pan_9
	ui->main_screen_img_pan_9 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_pan_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_pan_9, &_img_pan_9_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_pan_9, 100,5);
	lv_img_set_angle(ui->main_screen_img_pan_9, 0);
	lv_obj_set_pos(ui->main_screen_img_pan_9, 300, 143);
	lv_obj_set_size(ui->main_screen_img_pan_9, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_pan_9, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_pan_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_pan_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_pan_P
	ui->main_screen_img_pan_P = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_pan_P, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_pan_P, &_img_pan_P_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_pan_P, 100,5);
	lv_img_set_angle(ui->main_screen_img_pan_P, 0);
	lv_obj_set_pos(ui->main_screen_img_pan_P, 338, 190);
	lv_obj_set_size(ui->main_screen_img_pan_P, 200, 194);
	lv_obj_add_flag(ui->main_screen_img_pan_P, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_img_pan_P, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_pan_P, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_menu_cont
	ui->main_screen_menu_cont = lv_obj_create(ui->main_screen);
	lv_obj_set_pos(ui->main_screen_menu_cont, 0, 395);
	lv_obj_set_size(ui->main_screen_menu_cont, 800, 80);
	lv_obj_set_scrollbar_mode(ui->main_screen_menu_cont, LV_SCROLLBAR_MODE_OFF);

	//Write style for main_screen_menu_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_menu_cont, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_screen_menu_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_screen_menu_cont, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_screen_menu_cont, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_menu_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_menu_cont, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_screen_menu_cont, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_menu_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_menu_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_menu_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_menu_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->main_screen_menu_cont, &_empty_800x80, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->main_screen_menu_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_menu_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_timer_btn
	ui->main_screen_timer_btn = lv_imgbtn_create(ui->main_screen_menu_cont);
	lv_obj_add_flag(ui->main_screen_timer_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->main_screen_timer_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_Timer_alpha_57x57, NULL);
	lv_imgbtn_set_src(ui->main_screen_timer_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_ActiveTimer_alpha_57x57, NULL);
	ui->main_screen_timer_btn_label = lv_label_create(ui->main_screen_timer_btn);
	lv_label_set_text(ui->main_screen_timer_btn_label, "");
	lv_label_set_long_mode(ui->main_screen_timer_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_screen_timer_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_screen_timer_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->main_screen_timer_btn, 372, 10);
	lv_obj_set_size(ui->main_screen_timer_btn, 57, 57);

	//Write style for main_screen_timer_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->main_screen_timer_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_timer_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_timer_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_timer_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for main_screen_timer_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->main_screen_timer_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->main_screen_timer_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->main_screen_timer_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->main_screen_timer_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for main_screen_timer_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->main_screen_timer_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->main_screen_timer_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->main_screen_timer_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->main_screen_timer_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for main_screen_timer_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->main_screen_timer_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes main_screen_pause_btn
	ui->main_screen_pause_btn = lv_imgbtn_create(ui->main_screen_menu_cont);
	lv_obj_add_flag(ui->main_screen_pause_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->main_screen_pause_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_Pause_alpha_57x57, NULL);
	lv_imgbtn_set_src(ui->main_screen_pause_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_Play_alpha_57x57, NULL);
	ui->main_screen_pause_btn_label = lv_label_create(ui->main_screen_pause_btn);
	lv_label_set_text(ui->main_screen_pause_btn_label, "");
	lv_label_set_long_mode(ui->main_screen_pause_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_screen_pause_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_screen_pause_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->main_screen_pause_btn, 462, 11);
	lv_obj_set_size(ui->main_screen_pause_btn, 57, 57);

	//Write style for main_screen_pause_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->main_screen_pause_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_pause_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_pause_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_pause_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for main_screen_pause_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->main_screen_pause_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->main_screen_pause_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->main_screen_pause_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->main_screen_pause_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for main_screen_pause_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->main_screen_pause_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->main_screen_pause_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->main_screen_pause_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->main_screen_pause_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for main_screen_pause_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->main_screen_pause_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes main_screen_menu_btn
	ui->main_screen_menu_btn = lv_imgbtn_create(ui->main_screen_menu_cont);
	lv_obj_add_flag(ui->main_screen_menu_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->main_screen_menu_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_Menu_alpha_57x57, NULL);
	ui->main_screen_menu_btn_label = lv_label_create(ui->main_screen_menu_btn);
	lv_label_set_text(ui->main_screen_menu_btn_label, "");
	lv_label_set_long_mode(ui->main_screen_menu_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_screen_menu_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_screen_menu_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->main_screen_menu_btn, 18, 9);
	lv_obj_set_size(ui->main_screen_menu_btn, 57, 57);

	//Write style for main_screen_menu_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->main_screen_menu_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_menu_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_menu_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_menu_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for main_screen_menu_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->main_screen_menu_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->main_screen_menu_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->main_screen_menu_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->main_screen_menu_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for main_screen_menu_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->main_screen_menu_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->main_screen_menu_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->main_screen_menu_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->main_screen_menu_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for main_screen_menu_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->main_screen_menu_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes main_screen_lock_btn
	ui->main_screen_lock_btn = lv_imgbtn_create(ui->main_screen_menu_cont);
	lv_obj_add_flag(ui->main_screen_lock_btn, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->main_screen_lock_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_Lock_alpha_57x57, NULL);
	lv_imgbtn_set_src(ui->main_screen_lock_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_ActiveLock_alpha_57x57, NULL);
	ui->main_screen_lock_btn_label = lv_label_create(ui->main_screen_lock_btn);
	lv_label_set_text(ui->main_screen_lock_btn_label, "");
	lv_label_set_long_mode(ui->main_screen_lock_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->main_screen_lock_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->main_screen_lock_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->main_screen_lock_btn, 280, 11);
	lv_obj_set_size(ui->main_screen_lock_btn, 57, 57);

	//Write style for main_screen_lock_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->main_screen_lock_btn, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_lock_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_lock_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_lock_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for main_screen_lock_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->main_screen_lock_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->main_screen_lock_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->main_screen_lock_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->main_screen_lock_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for main_screen_lock_btn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->main_screen_lock_btn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->main_screen_lock_btn, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->main_screen_lock_btn, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->main_screen_lock_btn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for main_screen_lock_btn, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->main_screen_lock_btn, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes main_screen_clock_lbl
	ui->main_screen_clock_lbl = lv_label_create(ui->main_screen_menu_cont);
	lv_label_set_text(ui->main_screen_clock_lbl, "00:00");
	lv_label_set_long_mode(ui->main_screen_clock_lbl, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_screen_clock_lbl, 647, 23);
	lv_obj_set_size(ui->main_screen_clock_lbl, 140, 36);
	lv_obj_add_flag(ui->main_screen_clock_lbl, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_clock_lbl, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_screen_clock_lbl, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_clock_lbl, &lv_font_montserratMedium_34, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_screen_clock_lbl, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_clock_lbl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_timer_spinner
	ui->main_screen_timer_spinner = lv_spinner_create(ui->main_screen_menu_cont, 1000, 60);
	lv_obj_set_pos(ui->main_screen_timer_spinner, 370, 9);
	lv_obj_set_size(ui->main_screen_timer_spinner, 60, 60);
	lv_obj_add_flag(ui->main_screen_timer_spinner, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_timer_spinner, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_pad_top(ui->main_screen_timer_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_timer_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_timer_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_timer_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_timer_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->main_screen_timer_spinner, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->main_screen_timer_spinner, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->main_screen_timer_spinner, lv_color_hex(0x727272), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_timer_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for main_screen_timer_spinner, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->main_screen_timer_spinner, 5, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->main_screen_timer_spinner, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->main_screen_timer_spinner, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes main_screen_spinner_1
	ui->main_screen_spinner_1 = lv_spinner_create(ui->main_screen, 1000, 60);
	lv_obj_set_pos(ui->main_screen_spinner_1, 350, 190);
	lv_obj_set_size(ui->main_screen_spinner_1, 100, 100);
	lv_obj_add_flag(ui->main_screen_spinner_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_spinner_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_pad_top(ui->main_screen_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->main_screen_spinner_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->main_screen_spinner_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->main_screen_spinner_1, lv_color_hex(0x727272), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for main_screen_spinner_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->main_screen_spinner_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->main_screen_spinner_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->main_screen_spinner_1, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes main_screen_count_down_label
	ui->main_screen_count_down_label = lv_label_create(ui->main_screen);
	lv_label_set_text(ui->main_screen_count_down_label, "5");
	lv_label_set_long_mode(ui->main_screen_count_down_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_screen_count_down_label, 374, 217);
	lv_obj_set_size(ui->main_screen_count_down_label, 52, 46);
	lv_obj_add_flag(ui->main_screen_count_down_label, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_count_down_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_count_down_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_count_down_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_screen_count_down_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_count_down_label, &lv_font_montserratMedium_44, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_screen_count_down_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_screen_count_down_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_count_down_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_count_down_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_count_down_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_count_down_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_count_down_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_count_down_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_count_down_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_slider
	ui->main_screen_slider = lv_btnmatrix_create(ui->main_screen);
	static const char *main_screen_slider_text_map[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "P", "",};
	lv_btnmatrix_set_map(ui->main_screen_slider, main_screen_slider_text_map);
	lv_obj_set_pos(ui->main_screen_slider, 0, 395);
	lv_obj_set_size(ui->main_screen_slider, 800, 80);
	lv_obj_add_flag(ui->main_screen_slider, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_column(ui->main_screen_slider, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_src(ui->main_screen_slider, &_empty_800x80, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_img_opa(ui->main_screen_slider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_slider, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_slider, 221, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_screen_slider, lv_color_hex(0x221f1f), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for main_screen_slider, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_slider, 1, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_screen_slider, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_screen_slider, lv_color_hex(0xc9c9c9), LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_screen_slider, LV_BORDER_SIDE_NONE, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_screen_slider, lv_color_hex(0x000000), LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_slider, &lv_font_Alatsi_Regular_1, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_slider, 27, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_slider, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_slider, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style for main_screen_slider, Part: LV_PART_ITEMS, State: LV_STATE_PRESSED.
	lv_obj_set_style_border_width(ui->main_screen_slider, 1, LV_PART_ITEMS|LV_STATE_PRESSED);
	lv_obj_set_style_border_opa(ui->main_screen_slider, 255, LV_PART_ITEMS|LV_STATE_PRESSED);
	lv_obj_set_style_border_color(ui->main_screen_slider, lv_color_hex(0xc9c9c9), LV_PART_ITEMS|LV_STATE_PRESSED);
	lv_obj_set_style_border_side(ui->main_screen_slider, LV_BORDER_SIDE_NONE, LV_PART_ITEMS|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->main_screen_slider, lv_color_hex(0x000000), LV_PART_ITEMS|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->main_screen_slider, &lv_font_Alatsi_Regular_1, LV_PART_ITEMS|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->main_screen_slider, 4, LV_PART_ITEMS|LV_STATE_PRESSED);
	lv_obj_set_style_bg_opa(ui->main_screen_slider, 0, LV_PART_ITEMS|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->main_screen_slider, 0, LV_PART_ITEMS|LV_STATE_PRESSED);

	//Write codes main_screen_set_timer_cont
	ui->main_screen_set_timer_cont = lv_obj_create(ui->main_screen);
	lv_obj_set_pos(ui->main_screen_set_timer_cont, 200, 85);
	lv_obj_set_size(ui->main_screen_set_timer_cont, 400, 270);
	lv_obj_set_scrollbar_mode(ui->main_screen_set_timer_cont, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->main_screen_set_timer_cont, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_set_timer_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_set_timer_cont, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_screen_set_timer_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_screen_set_timer_cont, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_screen_set_timer_cont, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_set_timer_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_set_timer_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_set_timer_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_set_timer_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_set_timer_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_set_timer_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_set_timer_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_set_timer_win
	ui->main_screen_set_timer_win = lv_win_create(ui->main_screen_set_timer_cont, 50);
	lv_win_add_title(ui->main_screen_set_timer_win, "");
	ui->main_screen_set_timer_win_item0 = lv_win_add_btn(ui->main_screen_set_timer_win, LV_SYMBOL_OK, 70);
	ui->main_screen_set_timer_win_item1 = lv_win_add_btn(ui->main_screen_set_timer_win, LV_SYMBOL_CLOSE, 70);
	lv_obj_t *main_screen_set_timer_win_label = lv_label_create(lv_win_get_content(ui->main_screen_set_timer_win));
	lv_obj_set_scrollbar_mode(lv_win_get_content(ui->main_screen_set_timer_win), LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(main_screen_set_timer_win_label, "");
	lv_obj_set_pos(ui->main_screen_set_timer_win, 0, 0);
	lv_obj_set_size(ui->main_screen_set_timer_win, 400, 270);

	//Write style for main_screen_set_timer_win, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main_screen_set_timer_win, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_screen_set_timer_win, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->main_screen_set_timer_win, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_set_timer_win, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_main_screen_set_timer_win_extra_content_main_default
	static lv_style_t style_main_screen_set_timer_win_extra_content_main_default;
	ui_init_style(&style_main_screen_set_timer_win_extra_content_main_default);
	
	lv_style_set_bg_opa(&style_main_screen_set_timer_win_extra_content_main_default, 129);
	lv_style_set_bg_color(&style_main_screen_set_timer_win_extra_content_main_default, lv_color_hex(0x3b3b3b));
	lv_style_set_text_color(&style_main_screen_set_timer_win_extra_content_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_main_screen_set_timer_win_extra_content_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_letter_space(&style_main_screen_set_timer_win_extra_content_main_default, 0);
	lv_style_set_text_line_space(&style_main_screen_set_timer_win_extra_content_main_default, 2);
	lv_obj_add_style(lv_win_get_content(ui->main_screen_set_timer_win), &style_main_screen_set_timer_win_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_main_screen_set_timer_win_extra_header_main_default
	static lv_style_t style_main_screen_set_timer_win_extra_header_main_default;
	ui_init_style(&style_main_screen_set_timer_win_extra_header_main_default);
	
	lv_style_set_bg_opa(&style_main_screen_set_timer_win_extra_header_main_default, 255);
	lv_style_set_bg_color(&style_main_screen_set_timer_win_extra_header_main_default, lv_color_hex(0x626262));
	lv_style_set_text_color(&style_main_screen_set_timer_win_extra_header_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_main_screen_set_timer_win_extra_header_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_main_screen_set_timer_win_extra_header_main_default, 0);
	lv_style_set_text_line_space(&style_main_screen_set_timer_win_extra_header_main_default, 2);
	lv_obj_add_style(lv_win_get_header(ui->main_screen_set_timer_win), &style_main_screen_set_timer_win_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_main_screen_set_timer_win_extra_btns_main_default
	static lv_style_t style_main_screen_set_timer_win_extra_btns_main_default;
	ui_init_style(&style_main_screen_set_timer_win_extra_btns_main_default);
	
	lv_style_set_radius(&style_main_screen_set_timer_win_extra_btns_main_default, 8);
	lv_style_set_bg_opa(&style_main_screen_set_timer_win_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_main_screen_set_timer_win_extra_btns_main_default, lv_color_hex(0x393939));
	lv_style_set_shadow_width(&style_main_screen_set_timer_win_extra_btns_main_default, 0);
	lv_obj_add_style(ui->main_screen_set_timer_win_item1, &style_main_screen_set_timer_win_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->main_screen_set_timer_win_item0, &style_main_screen_set_timer_win_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_timer_min_roller
	ui->main_screen_timer_min_roller = lv_roller_create(ui->main_screen_set_timer_cont);
	lv_roller_set_options(ui->main_screen_timer_min_roller, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_INFINITE);
	lv_roller_set_visible_row_count(ui->main_screen_timer_min_roller, 5);
	lv_obj_set_pos(ui->main_screen_timer_min_roller, 220, 80);
	lv_obj_set_width(ui->main_screen_timer_min_roller, 100);

	//Write style for main_screen_timer_min_roller, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->main_screen_timer_min_roller, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_timer_min_roller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_screen_timer_min_roller, lv_color_hex(0xa9a9a9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_screen_timer_min_roller, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_timer_min_roller, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_timer_min_roller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->main_screen_timer_min_roller, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_screen_timer_min_roller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_screen_timer_min_roller, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_screen_timer_min_roller, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_timer_min_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for main_screen_timer_min_roller, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main_screen_timer_min_roller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_screen_timer_min_roller, lv_color_hex(0x636363), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_screen_timer_min_roller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_timer_min_roller, &lv_font_montserratMedium_24, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_timer_min_roller, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes main_screen_timer_10min_roller
	ui->main_screen_timer_10min_roller = lv_roller_create(ui->main_screen_set_timer_cont);
	lv_roller_set_options(ui->main_screen_timer_10min_roller, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_INFINITE);
	lv_roller_set_visible_row_count(ui->main_screen_timer_10min_roller, 5);
	lv_obj_set_pos(ui->main_screen_timer_10min_roller, 80, 80);
	lv_obj_set_width(ui->main_screen_timer_10min_roller, 100);

	//Write style for main_screen_timer_10min_roller, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->main_screen_timer_10min_roller, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_timer_10min_roller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_screen_timer_10min_roller, lv_color_hex(0xa9a9a9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_screen_timer_10min_roller, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_timer_10min_roller, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_timer_10min_roller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->main_screen_timer_10min_roller, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_screen_timer_10min_roller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_screen_timer_10min_roller, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_screen_timer_10min_roller, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_timer_10min_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for main_screen_timer_10min_roller, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main_screen_timer_10min_roller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_screen_timer_10min_roller, lv_color_hex(0x636363), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_screen_timer_10min_roller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_timer_10min_roller, &lv_font_montserratMedium_24, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_timer_10min_roller, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes main_screen_label_1
	ui->main_screen_label_1 = lv_label_create(ui->main_screen_set_timer_cont);
	lv_label_set_text(ui->main_screen_label_1, "min.");
	lv_label_set_long_mode(ui->main_screen_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->main_screen_label_1, 304, 153);
	lv_obj_set_size(ui->main_screen_label_1, 100, 32);

	//Write style for main_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->main_screen_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->main_screen_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->main_screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->main_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->main_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_1
	ui->main_screen_img_1 = lv_img_create(ui->main_screen_set_timer_cont);
	lv_obj_add_flag(ui->main_screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_1, &_clock_alpha_44x43);
	lv_img_set_pivot(ui->main_screen_img_1, 50,50);
	lv_img_set_angle(ui->main_screen_img_1, 0);
	lv_obj_set_pos(ui->main_screen_img_1, 10, 3);
	lv_obj_set_size(ui->main_screen_img_1, 44, 43);

	//Write style for main_screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_oops_cont
	ui->main_screen_oops_cont = lv_obj_create(ui->main_screen);
	lv_obj_set_pos(ui->main_screen_oops_cont, 211, 75);
	lv_obj_set_size(ui->main_screen_oops_cont, 386, 272);
	lv_obj_set_scrollbar_mode(ui->main_screen_oops_cont, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->main_screen_oops_cont, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_oops_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->main_screen_oops_cont, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->main_screen_oops_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->main_screen_oops_cont, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->main_screen_oops_cont, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->main_screen_oops_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->main_screen_oops_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_screen_oops_cont, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->main_screen_oops_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->main_screen_oops_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->main_screen_oops_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->main_screen_oops_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_oops_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_oops_win
	ui->main_screen_oops_win = lv_win_create(ui->main_screen_oops_cont, 50);
	lv_win_add_title(ui->main_screen_oops_win, "Oops !");
	ui->main_screen_oops_win_item0 = lv_win_add_btn(ui->main_screen_oops_win, LV_SYMBOL_CLOSE, 40);
	lv_obj_t *main_screen_oops_win_label = lv_label_create(lv_win_get_content(ui->main_screen_oops_win));
	lv_obj_set_scrollbar_mode(lv_win_get_content(ui->main_screen_oops_win), LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(main_screen_oops_win_label, "");
	lv_obj_set_pos(ui->main_screen_oops_win, -2, -2);
	lv_obj_set_size(ui->main_screen_oops_win, 387, 272);

	//Write style for main_screen_oops_win, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->main_screen_oops_win, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->main_screen_oops_win, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->main_screen_oops_win, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->main_screen_oops_win, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_main_screen_oops_win_extra_content_main_default
	static lv_style_t style_main_screen_oops_win_extra_content_main_default;
	ui_init_style(&style_main_screen_oops_win_extra_content_main_default);
	
	lv_style_set_bg_opa(&style_main_screen_oops_win_extra_content_main_default, 255);
	lv_style_set_bg_color(&style_main_screen_oops_win_extra_content_main_default, lv_color_hex(0x9a9a9a));
	lv_style_set_text_color(&style_main_screen_oops_win_extra_content_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_main_screen_oops_win_extra_content_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_letter_space(&style_main_screen_oops_win_extra_content_main_default, 0);
	lv_style_set_text_line_space(&style_main_screen_oops_win_extra_content_main_default, 2);
	lv_obj_add_style(lv_win_get_content(ui->main_screen_oops_win), &style_main_screen_oops_win_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_main_screen_oops_win_extra_header_main_default
	static lv_style_t style_main_screen_oops_win_extra_header_main_default;
	ui_init_style(&style_main_screen_oops_win_extra_header_main_default);
	
	lv_style_set_bg_opa(&style_main_screen_oops_win_extra_header_main_default, 255);
	lv_style_set_bg_color(&style_main_screen_oops_win_extra_header_main_default, lv_color_hex(0x626262));
	lv_style_set_text_color(&style_main_screen_oops_win_extra_header_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_main_screen_oops_win_extra_header_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_main_screen_oops_win_extra_header_main_default, 0);
	lv_style_set_text_line_space(&style_main_screen_oops_win_extra_header_main_default, 2);
	lv_obj_add_style(lv_win_get_header(ui->main_screen_oops_win), &style_main_screen_oops_win_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_main_screen_oops_win_extra_btns_main_default
	static lv_style_t style_main_screen_oops_win_extra_btns_main_default;
	ui_init_style(&style_main_screen_oops_win_extra_btns_main_default);
	
	lv_style_set_radius(&style_main_screen_oops_win_extra_btns_main_default, 8);
	lv_style_set_bg_opa(&style_main_screen_oops_win_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_main_screen_oops_win_extra_btns_main_default, lv_color_hex(0x393939));
	lv_style_set_shadow_width(&style_main_screen_oops_win_extra_btns_main_default, 0);
	lv_obj_add_style(ui->main_screen_oops_win_item0, &style_main_screen_oops_win_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_oops_img
	ui->main_screen_oops_img = lv_img_create(ui->main_screen_oops_cont);
	lv_obj_add_flag(ui->main_screen_oops_img, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_oops_img, &_oops_alpha_314x184);
	lv_img_set_pivot(ui->main_screen_oops_img, 50,50);
	lv_img_set_angle(ui->main_screen_oops_img, 0);
	lv_obj_set_pos(ui->main_screen_oops_img, 31, 68);
	lv_obj_set_size(ui->main_screen_oops_img, 314, 184);

	//Write style for main_screen_oops_img, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_oops_img, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->main_screen);

	
	//Init events for screen.
	events_init_main_screen(ui);
}
