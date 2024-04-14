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


extern lv_ui guider_ui;
static void logo_screen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		logo_screen_init();
		break;
	}
	case LV_EVENT_VALUE_CHANGED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.main_screen_del == true) {
	          setup_scr_main_screen(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.main_screen, LV_SCR_LOAD_ANIM_NONE, 50, 50, true);
	        guider_ui.logo_screen_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_logo_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->logo_screen, logo_screen_event_handler, LV_EVENT_ALL, NULL);
}
static void main_screen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		main_screen_init();
		break;
	}
	default:
		break;
	}
}
static void main_screen_pan_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(1);
		break;
	}
	default:
		break;
	}
}
static void main_screen_select_ring_h1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(1);
		break;
	}
	default:
		break;
	}
}
static void main_screen_select_ring_l1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(1);
		break;
	}
	default:
		break;
	}
}
static void main_screen_pan_2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(2);
		break;
	}
	default:
		break;
	}
}
static void main_screen_select_ring_h2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(2);
		break;
	}
	default:
		break;
	}
}
static void main_screen_select_ring_l2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(2);
		break;
	}
	default:
		break;
	}
}
static void main_screen_pan_3_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(3);
		break;
	}
	default:
		break;
	}
}
static void main_screen_select_ring_h3_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(3);
		break;
	}
	default:
		break;
	}
}
static void main_screen_select_ring_l3_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(3);
		break;
	}
	default:
		break;
	}
}
static void main_screen_pan_4_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(4);
		break;
	}
	default:
		break;
	}
}
static void main_screen_select_ring_h4_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(4);
		break;
	}
	default:
		break;
	}
}
static void main_screen_select_ring_l4_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(4);
		break;
	}
	default:
		break;
	}
}
static void main_screen_pan_5_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(5);
		break;
	}
	default:
		break;
	}
}
static void main_screen_select_ring_h5_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(5);
		break;
	}
	default:
		break;
	}
}
static void main_screen_select_ring_l5_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		set_select(5);
		break;
	}
	default:
		break;
	}
}
static void main_screen_zone_timer_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		click_main_timer();
		break;
	}
	default:
		break;
	}
}
static void main_screen_zone_warm_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		click_warm_btn();
		break;
	}
	default:
		break;
	}
}
static void main_screen_timer_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		click_main_timer();
		break;
	}
	default:
		break;
	}
}
static void main_screen_pause_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		click_pause();
		break;
	}
	default:
		break;
	}
}
static void main_screen_menu_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.menu_screen_del == true) {
	          setup_scr_menu_screen(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.menu_screen, LV_SCR_LOAD_ANIM_NONE, 50, 50, false);
	        guider_ui.main_screen_del = false;
	    }
		break;
	}
	default:
		break;
	}
}
static void main_screen_lock_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_LONG_PRESSED:
	{
		long_press_lock();
		break;
	}
	case LV_EVENT_PRESSED:
	{
		pressed_lock();
		break;
	}
	case LV_EVENT_RELEASED:
	{
		released_lock();
		break;
	}
	default:
		break;
	}
}
static void main_screen_slider_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSING:
	{
		lv_obj_t * obj = lv_event_get_target(e);
		uint32_t id = lv_btnmatrix_get_selected_btn(obj);
		switch(id) {
		case 0:
		{
			set_slider(0);
			break;
		}
		case 1:
		{
			set_slider(2);
			break;
		}
		case 2:
		{
			set_slider(4);
			break;
		}
		case 3:
		{
			set_slider(6);
			break;
		}
		case 4:
		{
			set_slider(8);
			break;
		}
		case 5:
		{
			set_slider(10);
			break;
		}
		case 6:
		{
			set_slider(12);
			break;
		}
		case 7:
		{
			set_slider(14);
			break;
		}
		case 8:
		{
			set_slider(16);
			break;
		}
		case 9:
		{
			set_slider(18);
			break;
		}
		case 10:
		{
			set_slider(20);
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
static void main_screen_set_timer_win_item0_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		click_timer_ok_btn();
		break;
	}
	default:
		break;
	}
}
static void main_screen_set_timer_win_item1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		click_timer_close_btn();
		break;
	}
	default:
		break;
	}
}
static void main_screen_oops_win_item0_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_add_flag(guider_ui.main_screen_oops_cont, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
void events_init_main_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->main_screen, main_screen_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_pan_1, main_screen_pan_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_select_ring_h1, main_screen_select_ring_h1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_select_ring_l1, main_screen_select_ring_l1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_pan_2, main_screen_pan_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_select_ring_h2, main_screen_select_ring_h2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_select_ring_l2, main_screen_select_ring_l2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_pan_3, main_screen_pan_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_select_ring_h3, main_screen_select_ring_h3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_select_ring_l3, main_screen_select_ring_l3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_pan_4, main_screen_pan_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_select_ring_h4, main_screen_select_ring_h4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_select_ring_l4, main_screen_select_ring_l4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_pan_5, main_screen_pan_5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_select_ring_h5, main_screen_select_ring_h5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_select_ring_l5, main_screen_select_ring_l5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_zone_timer_btn, main_screen_zone_timer_btn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_zone_warm_btn, main_screen_zone_warm_btn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_timer_btn, main_screen_timer_btn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_pause_btn, main_screen_pause_btn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_menu_btn, main_screen_menu_btn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_lock_btn, main_screen_lock_btn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_slider, main_screen_slider_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_set_timer_win_item0, main_screen_set_timer_win_item0_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_set_timer_win_item1, main_screen_set_timer_win_item1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_oops_win_item0, main_screen_oops_win_item0_event_handler, LV_EVENT_ALL, NULL);
}
static void menu_screen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		menu_screen_init();
		break;
	}
	default:
		break;
	}
}
static void menu_screen_settings_save_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		pressed_setting_save();
		break;
	}
	default:
		break;
	}
}
static void menu_screen_img_6_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		pressed_setting_save();
		break;
	}
	default:
		break;
	}
}
static void menu_screen_service_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		pressed_service_btn();
		break;
	}
	default:
		break;
	}
}
static void menu_screen_img_8_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		pressed_service_btn();
		break;
	}
	default:
		break;
	}
}
static void menu_screen_keypad_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * obj = lv_event_get_target(e);
		uint32_t id = lv_btnmatrix_get_selected_btn(obj);
		switch(id) {
		case 0:
		{
			set_keypad(1);
			break;
		}
		case 1:
		{
			set_keypad(2);
			break;
		}
		case 2:
		{
			set_keypad(3);
			break;
		}
		case 3:
		{
			set_keypad(4);
			break;
		}
		case 4:
		{
			set_keypad(5);
			break;
		}
		case 5:
		{
			set_keypad(6);
			break;
		}
		case 6:
		{
			set_keypad(7);
			break;
		}
		case 7:
		{
			set_keypad(8);
			break;
		}
		case 8:
		{
			set_keypad(9);
			break;
		}
		case 9:
		{
			set_keypad(10);
			break;
		}
		case 10:
		{
			set_keypad(0);
			break;
		}
		case 11:
		{
			set_keypad(11);
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
static void menu_screen_clock_save_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		pressed_clock_save();
		break;
	}
	default:
		break;
	}
}
static void menu_screen_img_7_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		pressed_clock_save();
		break;
	}
	default:
		break;
	}
}
static void menu_screen_img_settings_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		lv_tabview_set_act(guider_ui.menu_screen_tabview_1,0,LV_ANIM_ON);
		break;
	}
	default:
		break;
	}
}
static void menu_screen_img_clock_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		lv_tabview_set_act(guider_ui.menu_screen_tabview_1, 1, LV_ANIM_ON);
		break;
	}
	default:
		break;
	}
}
static void menu_screen_img_info_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		lv_tabview_set_act(guider_ui.menu_screen_tabview_1, 2, LV_ANIM_ON);
		break;
	}
	default:
		break;
	}
}
static void menu_screen_imgbtn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.main_screen_del == true) {
	          setup_scr_main_screen(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.main_screen, LV_SCR_LOAD_ANIM_NONE, 50, 50, true);
	        guider_ui.menu_screen_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_menu_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->menu_screen, menu_screen_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->menu_screen_settings_save_btn, menu_screen_settings_save_btn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->menu_screen_img_6, menu_screen_img_6_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->menu_screen_service_btn, menu_screen_service_btn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->menu_screen_img_8, menu_screen_img_8_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->menu_screen_keypad_btn, menu_screen_keypad_btn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->menu_screen_clock_save_btn, menu_screen_clock_save_btn_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->menu_screen_img_7, menu_screen_img_7_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->menu_screen_img_settings, menu_screen_img_settings_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->menu_screen_img_clock, menu_screen_img_clock_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->menu_screen_img_info, menu_screen_img_info_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->menu_screen_imgbtn_1, menu_screen_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{

}
