/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *main_screen;
	bool main_screen_del;
	lv_obj_t *main_screen_img_1;
	lv_obj_t *main_screen_img_3;
	lv_obj_t *main_screen_img_2;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_main_screen(lv_ui *ui);
LV_IMG_DECLARE(_NoHob_0_alpha_200x194);
LV_IMG_DECLARE(_empty_alpha_800x80);
LV_IMG_DECLARE(_SvP_Ver2_alpha_200x194);



#ifdef __cplusplus
}
#endif
#endif
