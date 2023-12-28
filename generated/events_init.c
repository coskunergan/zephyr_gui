/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"


static void main_screen_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		
		break;
	}
	default:
		break;
	}
}
static void main_screen_img_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSING:
	{
		        lv_indev_t *indev = lv_indev_get_act();
	        lv_point_t p;
	        lv_indev_get_point(indev, &p);
	        lv_obj_set_pos(guider_ui.main_screen_img_1, p.x - 100, p.y - 100);
		break;
	}
	default:
		break;
	}
}
static void main_screen_img_2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSING:
	{
		        lv_indev_t *indev = lv_indev_get_act();
	        lv_point_t p;
	        lv_indev_get_point(indev, &p);
	        lv_obj_set_pos(guider_ui.main_screen_img_2, p.x - 100, p.y - 100);
		break;
	}
	default:
		break;
	}
}
void events_init_main_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->main_screen, main_screen_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_img_1, main_screen_img_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->main_screen_img_2, main_screen_img_2_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{

}
