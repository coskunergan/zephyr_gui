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


void setup_scr_logo_screen(lv_ui *ui)
{
	//Write codes logo_screen
	ui->logo_screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->logo_screen, 800, 480);

	//Write style for logo_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->logo_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->logo_screen, lv_color_hex(0x06090b), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes logo_screen_img_1
	ui->logo_screen_img_1 = lv_img_create(ui->logo_screen);
	lv_obj_add_flag(ui->logo_screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->logo_screen_img_1, &_logo_alpha_394x163);
	lv_img_set_pivot(ui->logo_screen_img_1, 50,50);
	lv_img_set_angle(ui->logo_screen_img_1, 0);
	lv_obj_set_pos(ui->logo_screen_img_1, 203, 159);
	lv_obj_set_size(ui->logo_screen_img_1, 394, 163);

	//Write style for logo_screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->logo_screen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->logo_screen);

	
	//Init events for screen.
	events_init_logo_screen(ui);
}
