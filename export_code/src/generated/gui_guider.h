/*
* Copyright 2024 NXP
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
  
	lv_obj_t *logo_screen;
	bool logo_screen_del;
	lv_obj_t *logo_screen_img_1;
	lv_obj_t *logo_screen_label_1;
	lv_obj_t *main_screen;
	bool main_screen_del;
	lv_obj_t *main_screen_slider;
	lv_obj_t *main_screen_slider_0;
	lv_obj_t *main_screen_slider_1;
	lv_obj_t *main_screen_slider_2;
	lv_obj_t *main_screen_slider_3;
	lv_obj_t *main_screen_slider_4;
	lv_obj_t *main_screen_slider_5;
	lv_obj_t *main_screen_slider_6;
	lv_obj_t *main_screen_slider_7;
	lv_obj_t *main_screen_slider_8;
	lv_obj_t *main_screen_slider_9;
	lv_obj_t *main_screen_slider_P;
	lv_obj_t *main_screen_no_level_0;
	lv_obj_t *main_screen_no_level_1;
	lv_obj_t *main_screen_no_level_2;
	lv_obj_t *main_screen_no_level_3;
	lv_obj_t *main_screen_no_level_4;
	lv_obj_t *main_screen_no_level_5;
	lv_obj_t *main_screen_no_level_6;
	lv_obj_t *main_screen_no_level_7;
	lv_obj_t *main_screen_no_level_8;
	lv_obj_t *main_screen_no_level_9;
	lv_obj_t *main_screen_no_level_P;
	lv_obj_t *main_screen_cont_1;
	lv_obj_t *main_screen_pan_1;
	lv_obj_t *main_screen_select_ring_h1;
	lv_obj_t *main_screen_select_ring_l1;
	lv_obj_t *main_screen_cont_2;
	lv_obj_t *main_screen_pan_2;
	lv_obj_t *main_screen_select_ring_h2;
	lv_obj_t *main_screen_select_ring_l2;
	lv_obj_t *main_screen_cont_3;
	lv_obj_t *main_screen_pan_3;
	lv_obj_t *main_screen_select_ring_h3;
	lv_obj_t *main_screen_select_ring_l3;
	lv_obj_t *main_screen_cont_4;
	lv_obj_t *main_screen_pan_4;
	lv_obj_t *main_screen_select_ring_h4;
	lv_obj_t *main_screen_select_ring_l4;
	lv_obj_t *main_screen_cont_5;
	lv_obj_t *main_screen_pan_5;
	lv_obj_t *main_screen_select_ring_h5;
	lv_obj_t *main_screen_select_ring_l5;
	lv_obj_t *main_screen_img_pan_0;
	lv_obj_t *main_screen_img_pan_1;
	lv_obj_t *main_screen_img_pan_2;
	lv_obj_t *main_screen_img_pan_3;
	lv_obj_t *main_screen_img_pan_4;
	lv_obj_t *main_screen_img_pan_5;
	lv_obj_t *main_screen_img_pan_6;
	lv_obj_t *main_screen_img_pan_7;
	lv_obj_t *main_screen_img_pan_8;
	lv_obj_t *main_screen_img_pan_9;
	lv_obj_t *main_screen_img_pan_P;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_logo_screen(lv_ui *ui);
void setup_scr_main_screen(lv_ui *ui);
LV_IMG_DECLARE(_logo_alpha_394x163);

LV_IMG_DECLARE(_empty_800x80);
LV_IMG_DECLARE(_slider_0_alpha_800x80);
LV_IMG_DECLARE(_slider_1_alpha_800x80);
LV_IMG_DECLARE(_slider_2_alpha_800x80);
LV_IMG_DECLARE(_slider_3_alpha_800x80);
LV_IMG_DECLARE(_slider_4_alpha_800x80);
LV_IMG_DECLARE(_slider_5_alpha_800x80);
LV_IMG_DECLARE(_slider_6_alpha_800x80);
LV_IMG_DECLARE(_slider_7_alpha_800x80);
LV_IMG_DECLARE(_slider_8_alpha_800x80);
LV_IMG_DECLARE(_slider_9_alpha_800x80);
LV_IMG_DECLARE(_slider_P_alpha_800x80);
LV_IMG_DECLARE(_NoHob_0_alpha_200x194);
LV_IMG_DECLARE(_NoHob_1_alpha_200x194);
LV_IMG_DECLARE(_NoHob_2_alpha_200x194);
LV_IMG_DECLARE(_NoHob_3_alpha_200x194);
LV_IMG_DECLARE(_NoHob_4_alpha_200x194);
LV_IMG_DECLARE(_NoHob_5_alpha_200x194);
LV_IMG_DECLARE(_NoHob_6_alpha_200x194);
LV_IMG_DECLARE(_NoHob_7_alpha_200x194);
LV_IMG_DECLARE(_NoHob_8_alpha_200x194);
LV_IMG_DECLARE(_NoHob_9_alpha_200x194);
LV_IMG_DECLARE(_NoHob_P_alpha_200x194);
LV_IMG_DECLARE(_img_pan_0_alpha_200x194);
LV_IMG_DECLARE(_Secim_Ver2_alpha_200x194);
LV_IMG_DECLARE(_Secim_Ver3_alpha_200x194);
LV_IMG_DECLARE(_img_pan_0_alpha_200x194);
LV_IMG_DECLARE(_Secim_Ver2_alpha_200x194);
LV_IMG_DECLARE(_Secim_Ver3_alpha_200x194);
LV_IMG_DECLARE(_img_pan_0_alpha_200x194);
LV_IMG_DECLARE(_Secim_Ver2_alpha_200x194);
LV_IMG_DECLARE(_Secim_Ver3_alpha_200x194);
LV_IMG_DECLARE(_img_pan_0_alpha_200x194);
LV_IMG_DECLARE(_Secim_Ver2_alpha_200x194);
LV_IMG_DECLARE(_Secim_Ver3_alpha_200x194);
LV_IMG_DECLARE(_img_pan_0_alpha_200x194);
LV_IMG_DECLARE(_Secim_Ver2_alpha_200x194);
LV_IMG_DECLARE(_Secim_Ver3_alpha_200x194);
LV_IMG_DECLARE(_img_pan_0_alpha_200x194);
LV_IMG_DECLARE(_img_pan_1_alpha_200x194);
LV_IMG_DECLARE(_img_pan_2_alpha_200x194);
LV_IMG_DECLARE(_img_pan_3_alpha_200x194);
LV_IMG_DECLARE(_img_pan_4_alpha_200x194);
LV_IMG_DECLARE(_img_pan_5_alpha_200x194);
LV_IMG_DECLARE(_img_pan_6_alpha_200x194);
LV_IMG_DECLARE(_img_pan_7_alpha_200x194);
LV_IMG_DECLARE(_img_pan_8_alpha_200x194);
LV_IMG_DECLARE(_img_pan_9_alpha_200x194);
LV_IMG_DECLARE(_img_pan_P_alpha_200x194);

LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_1)


#ifdef __cplusplus
}
#endif
#endif
