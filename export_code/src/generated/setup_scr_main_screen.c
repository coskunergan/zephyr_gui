/*
* Copyright 2023 NXP
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

	//Write codes main_screen_img_1
	ui->main_screen_img_1 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_1, &_NoHob_0_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_1, 50,50);
	lv_img_set_angle(ui->main_screen_img_1, 0);
	lv_obj_set_pos(ui->main_screen_img_1, 13, 6);
	lv_obj_set_size(ui->main_screen_img_1, 200, 194);

	//Write style for main_screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_3
	ui->main_screen_img_3 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_3, &_empty_alpha_800x80);
	lv_img_set_pivot(ui->main_screen_img_3, 50,50);
	lv_img_set_angle(ui->main_screen_img_3, 0);
	lv_obj_set_pos(ui->main_screen_img_3, 0, 400);
	lv_obj_set_size(ui->main_screen_img_3, 800, 80);

	//Write style for main_screen_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_screen_img_2
	ui->main_screen_img_2 = lv_img_create(ui->main_screen);
	lv_obj_add_flag(ui->main_screen_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->main_screen_img_2, &_SvP_Ver2_alpha_200x194);
	lv_img_set_pivot(ui->main_screen_img_2, 50,50);
	lv_img_set_angle(ui->main_screen_img_2, 0);
	lv_obj_set_pos(ui->main_screen_img_2, 593, 6);
	lv_obj_set_size(ui->main_screen_img_2, 200, 194);

	//Write style for main_screen_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->main_screen_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->main_screen);

	
	//Init events for screen.
	events_init_main_screen(ui);
}
