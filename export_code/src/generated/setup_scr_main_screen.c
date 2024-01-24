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
	lv_obj_set_style_bg_color(ui->main_screen, lv_color_hex(0x0f0f0f), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_slider
	ui->main_screen_slider = lv_btnmatrix_create(ui->main_screen);
	static const char *main_screen_slider_text_map[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "P", "",};
	lv_btnmatrix_set_map(ui->main_screen_slider, main_screen_slider_text_map);
	lv_obj_set_pos(ui->main_screen_slider, 0, 395);
	lv_obj_set_size(ui->main_screen_slider, 800, 80);

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
	lv_obj_set_pos(ui->main_screen_select_ring_h3, 1, 0);
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

	//Update current screen layout.
	lv_obj_update_layout(ui->main_screen);

	
	//Init events for screen.
	events_init_main_screen(ui);
}
