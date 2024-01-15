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
uint8_t select = 0;
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
			pan_level(select, 0);
			break;
		}
		case 1:
		{
			pan_level(select, 1);
			break;
		}
		case 2:
		{
			pan_level(select, 2);
			break;
		}
		case 3:
		{
			pan_level(select, 3);
			break;
		}
		case 4:
		{
			pan_level(select, 4);
			break;
		}
		case 5:
		{
			pan_level(select, 5);
			break;
		}
		case 6:
		{
			pan_level(select, 6);
			break;
		}
		case 7:
		{
			pan_level(select, 7);
			break;
		}
		case 8:
		{
			pan_level(select, 8);
			break;
		}
		case 9:
		{
			pan_level(select, 9);
			break;
		}
		case 10:
		{
			pan_level(select, 10);
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
static void main_screen_pan_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSING:
	{
		lv_obj_clear_flag(guider_ui.main_screen_cont_1, LV_OBJ_FLAG_SCROLL_ELASTIC);
	lv_obj_add_flag(guider_ui.main_screen_select_ring_h2, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(guider_ui.main_screen_select_ring_h1, LV_OBJ_FLAG_HIDDEN);
	select = 1;
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
	case LV_EVENT_PRESSING:
	{
		        lv_indev_t *indev = lv_indev_get_act();
	        lv_point_t p;
	        lv_indev_get_point(indev, &p);
	        lv_obj_set_pos(guider_ui.main_screen_cont_1, p.x - 100, p.y - 100);                
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
	case LV_EVENT_PRESSING:
	{
		lv_obj_clear_flag(guider_ui.main_screen_cont_2, LV_OBJ_FLAG_SCROLL_ELASTIC);
	lv_obj_add_flag(guider_ui.main_screen_select_ring_h1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(guider_ui.main_screen_select_ring_h2, LV_OBJ_FLAG_HIDDEN);
	select = 2;
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
	case LV_EVENT_PRESSING:
	{
		        lv_indev_t *indev = lv_indev_get_act();
	        lv_point_t p;
	        lv_indev_get_point(indev, &p);
	        lv_obj_set_pos(guider_ui.main_screen_cont_2, p.x - 100, p.y - 100);                
		break;
	}
	default:
		break;
	}
}
void events_init_main_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->main_screen_slider, main_screen_slider_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_pan_1, main_screen_pan_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_select_ring_h1, main_screen_select_ring_h1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_pan_2, main_screen_pan_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_select_ring_h2, main_screen_select_ring_h2_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{

}
