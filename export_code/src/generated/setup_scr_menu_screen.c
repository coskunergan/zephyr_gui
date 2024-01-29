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


void setup_scr_menu_screen(lv_ui *ui)
{
	//Write codes menu_screen
	ui->menu_screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->menu_screen, 800, 480);

	//Write style for menu_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen, lv_color_hex(0x06090b), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_screen_tabview_1
	ui->menu_screen_tabview_1 = lv_tabview_create(ui->menu_screen, LV_DIR_TOP, 50);
	lv_obj_set_pos(ui->menu_screen_tabview_1, 78, 17);
	lv_obj_set_size(ui->menu_screen_tabview_1, 645, 367);
	lv_obj_set_scrollbar_mode(ui->menu_screen_tabview_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for menu_screen_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_screen_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_tabview_1, lv_color_hex(0x9a9a9a), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_tabview_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_tabview_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->menu_screen_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->menu_screen_tabview_1, 43, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->menu_screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_menu_screen_tabview_1_extra_btnm_main_default
	static lv_style_t style_menu_screen_tabview_1_extra_btnm_main_default;
	ui_init_style(&style_menu_screen_tabview_1_extra_btnm_main_default);
	
	lv_style_set_bg_opa(&style_menu_screen_tabview_1_extra_btnm_main_default, 255);
	lv_style_set_bg_color(&style_menu_screen_tabview_1_extra_btnm_main_default, lv_color_hex(0x818181));
	lv_style_set_border_width(&style_menu_screen_tabview_1_extra_btnm_main_default, 0);
	lv_style_set_radius(&style_menu_screen_tabview_1_extra_btnm_main_default, 0);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->menu_screen_tabview_1), &style_menu_screen_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_menu_screen_tabview_1_extra_btnm_items_default
	static lv_style_t style_menu_screen_tabview_1_extra_btnm_items_default;
	ui_init_style(&style_menu_screen_tabview_1_extra_btnm_items_default);
	
	lv_style_set_text_color(&style_menu_screen_tabview_1_extra_btnm_items_default, lv_color_hex(0x818181));
	lv_style_set_text_font(&style_menu_screen_tabview_1_extra_btnm_items_default, &lv_font_Acme_Regular_16);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->menu_screen_tabview_1), &style_menu_screen_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_menu_screen_tabview_1_extra_btnm_items_checked
	static lv_style_t style_menu_screen_tabview_1_extra_btnm_items_checked;
	ui_init_style(&style_menu_screen_tabview_1_extra_btnm_items_checked);
	
	lv_style_set_text_color(&style_menu_screen_tabview_1_extra_btnm_items_checked, lv_color_hex(0x818181));
	lv_style_set_text_font(&style_menu_screen_tabview_1_extra_btnm_items_checked, &lv_font_Alatsi_Regular_18);
	lv_style_set_border_width(&style_menu_screen_tabview_1_extra_btnm_items_checked, 3);
	lv_style_set_border_opa(&style_menu_screen_tabview_1_extra_btnm_items_checked, 255);
	lv_style_set_border_color(&style_menu_screen_tabview_1_extra_btnm_items_checked, lv_color_hex(0x151515));
	lv_style_set_border_side(&style_menu_screen_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
	lv_style_set_radius(&style_menu_screen_tabview_1_extra_btnm_items_checked, 0);
	lv_style_set_bg_opa(&style_menu_screen_tabview_1_extra_btnm_items_checked, 0);
	lv_obj_add_style(lv_tabview_get_tab_btns(ui->menu_screen_tabview_1), &style_menu_screen_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

	//Write codes settings
	ui->menu_screen_tabview_1_tab_1 = lv_tabview_add_tab(ui->menu_screen_tabview_1,"settings");
	lv_obj_t * menu_screen_tabview_1_tab_1_label = lv_label_create(ui->menu_screen_tabview_1_tab_1);
	lv_label_set_text(menu_screen_tabview_1_tab_1_label, "");

	//Write codes menu_screen_power_roller
	ui->menu_screen_power_roller = lv_roller_create(ui->menu_screen_tabview_1_tab_1);
	lv_roller_set_options(ui->menu_screen_power_roller, "1500W\n2800W\n3600W\n7200W\n10800W", LV_ROLLER_MODE_INFINITE);
	lv_roller_set_visible_row_count(ui->menu_screen_power_roller, 3);
	lv_obj_set_pos(ui->menu_screen_power_roller, 177, 170);
	lv_obj_set_width(ui->menu_screen_power_roller, 260);

	//Write style for menu_screen_power_roller, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->menu_screen_power_roller, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->menu_screen_power_roller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_power_roller, lv_color_hex(0x9A9A9A), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_power_roller, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_power_roller, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_power_roller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->menu_screen_power_roller, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->menu_screen_power_roller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->menu_screen_power_roller, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->menu_screen_power_roller, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_power_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for menu_screen_power_roller, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_screen_power_roller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_power_roller, lv_color_hex(0x636363), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_power_roller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_power_roller, &lv_font_montserratMedium_16, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_power_roller, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes menu_screen_sound_switch
	ui->menu_screen_sound_switch = lv_switch_create(ui->menu_screen_tabview_1_tab_1);
	lv_obj_set_pos(ui->menu_screen_sound_switch, 257, 93);
	lv_obj_set_size(ui->menu_screen_sound_switch, 85, 42);

	//Write style for menu_screen_sound_switch, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_screen_sound_switch, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_sound_switch, lv_color_hex(0x636363), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->menu_screen_sound_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_screen_sound_switch, 21, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_sound_switch, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for menu_screen_sound_switch, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->menu_screen_sound_switch, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->menu_screen_sound_switch, lv_color_hex(0x636363), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->menu_screen_sound_switch, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for menu_screen_sound_switch, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_screen_sound_switch, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_sound_switch, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->menu_screen_sound_switch, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_screen_sound_switch, 21, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes menu_screen_slider_contrast
	ui->menu_screen_slider_contrast = lv_slider_create(ui->menu_screen_tabview_1_tab_1);
	lv_slider_set_range(ui->menu_screen_slider_contrast, 0, 100);
	lv_slider_set_mode(ui->menu_screen_slider_contrast, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->menu_screen_slider_contrast, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->menu_screen_slider_contrast, 138, 23);
	lv_obj_set_size(ui->menu_screen_slider_contrast, 325, 14);

	//Write style for menu_screen_slider_contrast, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_screen_slider_contrast, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_slider_contrast, lv_color_hex(0x636363), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_screen_slider_contrast, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->menu_screen_slider_contrast, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_slider_contrast, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for menu_screen_slider_contrast, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_screen_slider_contrast, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_slider_contrast, lv_color_hex(0x636363), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_screen_slider_contrast, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for menu_screen_slider_contrast, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_screen_slider_contrast, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_slider_contrast, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_screen_slider_contrast, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes menu_screen_img_2
	ui->menu_screen_img_2 = lv_img_create(ui->menu_screen_tabview_1_tab_1);
	lv_obj_add_flag(ui->menu_screen_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->menu_screen_img_2, &_speaker_alpha_50x50);
	lv_img_set_pivot(ui->menu_screen_img_2, 50,50);
	lv_img_set_angle(ui->menu_screen_img_2, 0);
	lv_obj_set_pos(ui->menu_screen_img_2, 59, 87);
	lv_obj_set_size(ui->menu_screen_img_2, 50, 50);

	//Write style for menu_screen_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->menu_screen_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_screen_img_4
	ui->menu_screen_img_4 = lv_img_create(ui->menu_screen_tabview_1_tab_1);
	lv_obj_add_flag(ui->menu_screen_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->menu_screen_img_4, &_power_alpha_50x50);
	lv_img_set_pivot(ui->menu_screen_img_4, 50,50);
	lv_img_set_angle(ui->menu_screen_img_4, 0);
	lv_obj_set_pos(ui->menu_screen_img_4, 60, 182);
	lv_obj_set_size(ui->menu_screen_img_4, 50, 50);

	//Write style for menu_screen_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->menu_screen_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_screen_img_3
	ui->menu_screen_img_3 = lv_img_create(ui->menu_screen_tabview_1_tab_1);
	lv_obj_add_flag(ui->menu_screen_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->menu_screen_img_3, &_contrast_alpha_50x50);
	lv_img_set_pivot(ui->menu_screen_img_3, 50,50);
	lv_img_set_angle(ui->menu_screen_img_3, 0);
	lv_obj_set_pos(ui->menu_screen_img_3, 59, 5);
	lv_obj_set_size(ui->menu_screen_img_3, 50, 50);

	//Write style for menu_screen_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->menu_screen_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_screen_settings_save_btn
	ui->menu_screen_settings_save_btn = lv_btn_create(ui->menu_screen_tabview_1_tab_1);
	ui->menu_screen_settings_save_btn_label = lv_label_create(ui->menu_screen_settings_save_btn);
	lv_label_set_text(ui->menu_screen_settings_save_btn_label, "Save");
	lv_label_set_long_mode(ui->menu_screen_settings_save_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->menu_screen_settings_save_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->menu_screen_settings_save_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->menu_screen_settings_save_btn, 490, 244);
	lv_obj_set_size(ui->menu_screen_settings_save_btn, 114, 37);

	//Write style for menu_screen_settings_save_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_screen_settings_save_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_settings_save_btn, lv_color_hex(0x636363), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->menu_screen_settings_save_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_screen_settings_save_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_settings_save_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_settings_save_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_settings_save_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_settings_save_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes clock
	ui->menu_screen_tabview_1_tab_2 = lv_tabview_add_tab(ui->menu_screen_tabview_1,"clock");
	lv_obj_t * menu_screen_tabview_1_tab_2_label = lv_label_create(ui->menu_screen_tabview_1_tab_2);
	lv_label_set_text(menu_screen_tabview_1_tab_2_label, "");

	//Write codes menu_screen_roller_1
	ui->menu_screen_roller_1 = lv_roller_create(ui->menu_screen_tabview_1_tab_2);
	lv_roller_set_options(ui->menu_screen_roller_1, "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23", LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->menu_screen_roller_1, 4);
	lv_obj_set_pos(ui->menu_screen_roller_1, 169, 56);
	lv_obj_set_width(ui->menu_screen_roller_1, 100);

	//Write style for menu_screen_roller_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->menu_screen_roller_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->menu_screen_roller_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_roller_1, lv_color_hex(0xa9a9a9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_roller_1, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_roller_1, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_roller_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->menu_screen_roller_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->menu_screen_roller_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->menu_screen_roller_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->menu_screen_roller_1, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_roller_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for menu_screen_roller_1, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_screen_roller_1, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_roller_1, lv_color_hex(0x636363), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_roller_1, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_roller_1, &lv_font_montserratMedium_24, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_roller_1, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes menu_screen_roller_2
	ui->menu_screen_roller_2 = lv_roller_create(ui->menu_screen_tabview_1_tab_2);
	lv_roller_set_options(ui->menu_screen_roller_2, "00\n01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59", LV_ROLLER_MODE_NORMAL);
	lv_roller_set_visible_row_count(ui->menu_screen_roller_2, 4);
	lv_obj_set_pos(ui->menu_screen_roller_2, 342, 56);
	lv_obj_set_width(ui->menu_screen_roller_2, 100);

	//Write style for menu_screen_roller_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->menu_screen_roller_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->menu_screen_roller_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_roller_2, lv_color_hex(0xa9a9a9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_roller_2, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_roller_2, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_roller_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->menu_screen_roller_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->menu_screen_roller_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->menu_screen_roller_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->menu_screen_roller_2, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_roller_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for menu_screen_roller_2, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_radius(ui->menu_screen_roller_2, 5, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_opa(ui->menu_screen_roller_2, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->menu_screen_roller_2, lv_color_hex(0xA9A9A9), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_color(ui->menu_screen_roller_2, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->menu_screen_roller_2, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_align(ui->menu_screen_roller_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->menu_screen_roller_2, 2, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_opa(ui->menu_screen_roller_2, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_color(ui->menu_screen_roller_2, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_side(ui->menu_screen_roller_2, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->menu_screen_roller_2, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write style for menu_screen_roller_2, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_screen_roller_2, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_roller_2, lv_color_hex(0x636363), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_roller_2, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_roller_2, &lv_font_montserratMedium_24, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_roller_2, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED|LV_STATE_DEFAULT);

	//Write codes menu_screen_label_1
	ui->menu_screen_label_1 = lv_label_create(ui->menu_screen_tabview_1_tab_2);
	lv_label_set_text(ui->menu_screen_label_1, "HH");
	lv_label_set_long_mode(ui->menu_screen_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->menu_screen_label_1, 168, 20);
	lv_obj_set_size(ui->menu_screen_label_1, 100, 32);

	//Write style for menu_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->menu_screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_screen_label_2
	ui->menu_screen_label_2 = lv_label_create(ui->menu_screen_tabview_1_tab_2);
	lv_label_set_text(ui->menu_screen_label_2, "MM");
	lv_label_set_long_mode(ui->menu_screen_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->menu_screen_label_2, 340, 16);
	lv_obj_set_size(ui->menu_screen_label_2, 100, 32);

	//Write style for menu_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_label_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->menu_screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_screen_label_3
	ui->menu_screen_label_3 = lv_label_create(ui->menu_screen_tabview_1_tab_2);
	lv_label_set_text(ui->menu_screen_label_3, ":");
	lv_label_set_long_mode(ui->menu_screen_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->menu_screen_label_3, 257, 102);
	lv_obj_set_size(ui->menu_screen_label_3, 100, 32);

	//Write style for menu_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_label_3, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->menu_screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_screen_clock_save_btn
	ui->menu_screen_clock_save_btn = lv_btn_create(ui->menu_screen_tabview_1_tab_2);
	ui->menu_screen_clock_save_btn_label = lv_label_create(ui->menu_screen_clock_save_btn);
	lv_label_set_text(ui->menu_screen_clock_save_btn_label, "Save");
	lv_label_set_long_mode(ui->menu_screen_clock_save_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->menu_screen_clock_save_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->menu_screen_clock_save_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->menu_screen_clock_save_btn, 481, 237);
	lv_obj_set_size(ui->menu_screen_clock_save_btn, 114, 37);

	//Write style for menu_screen_clock_save_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_screen_clock_save_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_screen_clock_save_btn, lv_color_hex(0x636363), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->menu_screen_clock_save_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_screen_clock_save_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_clock_save_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_clock_save_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_clock_save_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_clock_save_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes info
	ui->menu_screen_tabview_1_tab_3 = lv_tabview_add_tab(ui->menu_screen_tabview_1,"info");
	lv_obj_t * menu_screen_tabview_1_tab_3_label = lv_label_create(ui->menu_screen_tabview_1_tab_3);
	lv_label_set_text(menu_screen_tabview_1_tab_3_label, "");

	//Write codes menu_screen_img_1
	ui->menu_screen_img_1 = lv_img_create(ui->menu_screen_tabview_1_tab_3);
	lv_obj_add_flag(ui->menu_screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->menu_screen_img_1, &_gtmqr_alpha_200x200);
	lv_img_set_pivot(ui->menu_screen_img_1, 50,50);
	lv_img_set_angle(ui->menu_screen_img_1, 0);
	lv_obj_set_pos(ui->menu_screen_img_1, 211, 39);
	lv_obj_set_size(ui->menu_screen_img_1, 200, 200);

	//Write style for menu_screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->menu_screen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_screen_label_4
	ui->menu_screen_label_4 = lv_label_create(ui->menu_screen_tabview_1_tab_3);
	lv_label_set_text(ui->menu_screen_label_4, "V1.0.1");
	lv_label_set_long_mode(ui->menu_screen_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->menu_screen_label_4, 260, 254);
	lv_obj_set_size(ui->menu_screen_label_4, 100, 32);

	//Write style for menu_screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->menu_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_label_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->menu_screen_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->menu_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->menu_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->menu_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->menu_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->menu_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->menu_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_screen_img_5
	ui->menu_screen_img_5 = lv_img_create(ui->menu_screen);
	lv_obj_add_flag(ui->menu_screen_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->menu_screen_img_5, &_empty_alpha_800x80);
	lv_img_set_pivot(ui->menu_screen_img_5, 50,50);
	lv_img_set_angle(ui->menu_screen_img_5, 0);
	lv_obj_set_pos(ui->menu_screen_img_5, 0, 395);
	lv_obj_set_size(ui->menu_screen_img_5, 800, 80);

	//Write style for menu_screen_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->menu_screen_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_screen_img_settings
	ui->menu_screen_img_settings = lv_img_create(ui->menu_screen);
	lv_obj_add_flag(ui->menu_screen_img_settings, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->menu_screen_img_settings, &_settings_alpha_40x40);
	lv_img_set_pivot(ui->menu_screen_img_settings, 50,50);
	lv_img_set_angle(ui->menu_screen_img_settings, 0);
	lv_obj_set_pos(ui->menu_screen_img_settings, 168, 17);
	lv_obj_set_size(ui->menu_screen_img_settings, 40, 40);

	//Write style for menu_screen_img_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->menu_screen_img_settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_screen_img_clock
	ui->menu_screen_img_clock = lv_img_create(ui->menu_screen);
	lv_obj_add_flag(ui->menu_screen_img_clock, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->menu_screen_img_clock, &_clock_alpha_40x40);
	lv_img_set_pivot(ui->menu_screen_img_clock, 50,50);
	lv_img_set_angle(ui->menu_screen_img_clock, 0);
	lv_obj_set_pos(ui->menu_screen_img_clock, 380, 17);
	lv_obj_set_size(ui->menu_screen_img_clock, 40, 40);

	//Write style for menu_screen_img_clock, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->menu_screen_img_clock, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_screen_img_info
	ui->menu_screen_img_info = lv_img_create(ui->menu_screen);
	lv_obj_add_flag(ui->menu_screen_img_info, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->menu_screen_img_info, &_info_alpha_40x40);
	lv_img_set_pivot(ui->menu_screen_img_info, 50,50);
	lv_img_set_angle(ui->menu_screen_img_info, 0);
	lv_obj_set_pos(ui->menu_screen_img_info, 603, 17);
	lv_obj_set_size(ui->menu_screen_img_info, 40, 40);

	//Write style for menu_screen_img_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->menu_screen_img_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_screen_imgbtn_1
	ui->menu_screen_imgbtn_1 = lv_imgbtn_create(ui->menu_screen);
	lv_obj_add_flag(ui->menu_screen_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->menu_screen_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_Menu_alpha_57x57, NULL);
	ui->menu_screen_imgbtn_1_label = lv_label_create(ui->menu_screen_imgbtn_1);
	lv_label_set_text(ui->menu_screen_imgbtn_1_label, "");
	lv_label_set_long_mode(ui->menu_screen_imgbtn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->menu_screen_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->menu_screen_imgbtn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->menu_screen_imgbtn_1, 20, 406);
	lv_obj_set_size(ui->menu_screen_imgbtn_1, 57, 57);

	//Write style for menu_screen_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->menu_screen_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for menu_screen_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->menu_screen_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->menu_screen_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->menu_screen_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->menu_screen_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for menu_screen_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->menu_screen_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->menu_screen_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->menu_screen_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->menu_screen_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for menu_screen_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->menu_screen_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes menu_screen_clock_lbl
	ui->menu_screen_clock_lbl = lv_label_create(ui->menu_screen);
	lv_label_set_text(ui->menu_screen_clock_lbl, "00:00");
	lv_label_set_long_mode(ui->menu_screen_clock_lbl, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->menu_screen_clock_lbl, 649, 420);
	lv_obj_set_size(ui->menu_screen_clock_lbl, 140, 36);

	//Write style for menu_screen_clock_lbl, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->menu_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_screen_clock_lbl, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_screen_clock_lbl, &lv_font_montserratMedium_34, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->menu_screen_clock_lbl, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->menu_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_screen_clock_lbl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->menu_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->menu_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->menu_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->menu_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->menu_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_screen_clock_lbl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->menu_screen);

	
	//Init events for screen.
	events_init_menu_screen(ui);
}
