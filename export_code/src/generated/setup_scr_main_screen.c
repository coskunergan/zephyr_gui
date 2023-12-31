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

	//Write codes main_screen_pan_5
	ui->main_screen_pan_5 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_pan_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_pivot(ui->main_screen_pan_5, 50,50);
	lv_img_set_angle(ui->main_screen_pan_5, 0);
	lv_obj_set_pos(ui->main_screen_pan_5, 422, 165);
	lv_obj_set_size(ui->main_screen_pan_5, 200, 194);

	//Write style for main_screen_pan_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_pan_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_pan_4
	ui->main_screen_pan_4 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_pan_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_pivot(ui->main_screen_pan_4, 50,50);
	lv_img_set_angle(ui->main_screen_pan_4, 0);
	lv_obj_set_pos(ui->main_screen_pan_4, 157, 165);
	lv_obj_set_size(ui->main_screen_pan_4, 200, 194);

	//Write style for main_screen_pan_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_pan_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_pan_3
	ui->main_screen_pan_3 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_pan_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_pivot(ui->main_screen_pan_3, 50,50);
	lv_img_set_angle(ui->main_screen_pan_3, 0);
	lv_obj_set_pos(ui->main_screen_pan_3, 568, 6);
	lv_obj_set_size(ui->main_screen_pan_3, 200, 194);

	//Write style for main_screen_pan_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_pan_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

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

	//Write codes main_screen_no_level_0
	ui->main_screen_no_level_0 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_no_level_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_no_level_0, &_NoHob_0_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_no_level_0, 50,50);
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
	lv_img_set_pivot(ui->main_screen_no_level_1, 50,50);
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
	lv_img_set_pivot(ui->main_screen_no_level_2, 50,50);
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
	lv_img_set_pivot(ui->main_screen_no_level_3, 50,50);
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
	lv_img_set_pivot(ui->main_screen_no_level_4, 50,50);
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
	lv_img_set_pivot(ui->main_screen_no_level_5, 50,50);
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
	lv_img_set_pivot(ui->main_screen_no_level_6, 50,50);
	lv_img_set_angle(ui->main_screen_no_level_6, 0);
	lv_obj_set_pos(ui->main_screen_no_level_6, 300, 143);
	lv_obj_set_size(ui->main_screen_no_level_6, 200, 194);
	lv_obj_add_flag(ui->main_screen_no_level_6, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_no_level_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_no_level_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_level_0
	ui->main_screen_level_0 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_level_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_level_0, &_Sv0_Ver2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_level_0, 50,50);
	lv_img_set_angle(ui->main_screen_level_0, 0);
	lv_obj_set_pos(ui->main_screen_level_0, 300, 143);
	lv_obj_set_size(ui->main_screen_level_0, 200, 194);
	lv_obj_add_flag(ui->main_screen_level_0, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_level_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_level_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_level_1
	ui->main_screen_level_1 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_level_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_level_1, &_Sv1_Ver2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_level_1, 50,50);
	lv_img_set_angle(ui->main_screen_level_1, 0);
	lv_obj_set_pos(ui->main_screen_level_1, 300, 143);
	lv_obj_set_size(ui->main_screen_level_1, 200, 194);
	lv_obj_add_flag(ui->main_screen_level_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_level_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_level_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_level_2
	ui->main_screen_level_2 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_level_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_level_2, &_Sv2_Ver2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_level_2, 50,50);
	lv_img_set_angle(ui->main_screen_level_2, 0);
	lv_obj_set_pos(ui->main_screen_level_2, 300, 143);
	lv_obj_set_size(ui->main_screen_level_2, 200, 194);
	lv_obj_add_flag(ui->main_screen_level_2, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_level_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_level_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_level_3
	ui->main_screen_level_3 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_level_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_level_3, &_Sv3_Ver2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_level_3, 50,50);
	lv_img_set_angle(ui->main_screen_level_3, 0);
	lv_obj_set_pos(ui->main_screen_level_3, 300, 143);
	lv_obj_set_size(ui->main_screen_level_3, 200, 194);
	lv_obj_add_flag(ui->main_screen_level_3, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_level_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_level_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_cont_1
	ui->main_screen_cont_1 = lv_obj_create(ui->main_screen);
	lv_obj_set_pos(ui->main_screen_cont_1, 15, 38);
	lv_obj_set_size(ui->main_screen_cont_1, 200, 194);
	lv_obj_set_scrollbar_mode(ui->main_screen_cont_1, LV_SCROLLBAR_MODE_OFF);

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
	lv_img_set_src(ui->main_screen_pan_1, &_NoHob_0_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_pan_1, 50,50);
	lv_img_set_angle(ui->main_screen_pan_1, 0);
	lv_obj_set_pos(ui->main_screen_pan_1, 0, 0);
	lv_obj_set_size(ui->main_screen_pan_1, 200, 194);

	//Write style for main_screen_pan_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_pan_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_select_ring_h1
	ui->main_screen_select_ring_h1 = lv_img_create(ui->main_screen_cont_1);
	lv_obj_add_flag(ui->main_screen_select_ring_h1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_select_ring_h1, &_Secim_Ver2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_select_ring_h1, 50,50);
	lv_img_set_angle(ui->main_screen_select_ring_h1, 0);
	lv_obj_set_pos(ui->main_screen_select_ring_h1, 0, 0);
	lv_obj_set_size(ui->main_screen_select_ring_h1, 200, 194);
	lv_obj_add_flag(ui->main_screen_select_ring_h1, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_select_ring_h1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_select_ring_h1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_cont_2
	ui->main_screen_cont_2 = lv_obj_create(ui->main_screen);
	lv_obj_set_pos(ui->main_screen_cont_2, 300, 50);
	lv_obj_set_size(ui->main_screen_cont_2, 200, 194);
	lv_obj_set_scrollbar_mode(ui->main_screen_cont_2, LV_SCROLLBAR_MODE_OFF);

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
	lv_img_set_src(ui->main_screen_pan_2, &_NoHob_0_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_pan_2, 50,50);
	lv_img_set_angle(ui->main_screen_pan_2, 0);
	lv_obj_set_pos(ui->main_screen_pan_2, 0, 0);
	lv_obj_set_size(ui->main_screen_pan_2, 200, 194);

	//Write style for main_screen_pan_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_pan_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_select_ring_h2
	ui->main_screen_select_ring_h2 = lv_img_create(ui->main_screen_cont_2);
	lv_obj_add_flag(ui->main_screen_select_ring_h2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_select_ring_h2, &_Secim_Ver2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_select_ring_h2, 50,50);
	lv_img_set_angle(ui->main_screen_select_ring_h2, 0);
	lv_obj_set_pos(ui->main_screen_select_ring_h2, 0, 0);
	lv_obj_set_size(ui->main_screen_select_ring_h2, 200, 194);
	lv_obj_add_flag(ui->main_screen_select_ring_h2, LV_OBJ_FLAG_HIDDEN);

	//Write style for main_screen_select_ring_h2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_select_ring_h2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->main_screen);

	
	//Init events for screen.
	events_init_main_screen(ui);
}
