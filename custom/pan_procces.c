
#include <pan_procces.h>
#include "gui_guider.h"

/*******************************************************************************/
/*******************************************************************************/

void pan_move(uint16_t x, uint16_t y)
{
  	  	lv_anim_t main_screen_img_1_anim_move_x;
	  	lv_anim_init(&main_screen_img_1_anim_move_x);
	  	lv_anim_set_var(&main_screen_img_1_anim_move_x, guider_ui.main_screen_img_1);
	  	lv_anim_set_time(&main_screen_img_1_anim_move_x, 2000);
	  	lv_anim_set_delay(&main_screen_img_1_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&main_screen_img_1_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&main_screen_img_1_anim_move_x, lv_obj_get_x(guider_ui.main_screen_img_1), x);
	  	lv_anim_set_path_cb(&main_screen_img_1_anim_move_x, &lv_anim_path_ease_in_out);
	  	lv_anim_set_repeat_count(&main_screen_img_1_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&main_screen_img_1_anim_move_x, 0);
	  	lv_anim_set_playback_time(&main_screen_img_1_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&main_screen_img_1_anim_move_x, 0);
		lv_anim_start(&main_screen_img_1_anim_move_x);
		//Write animation: main_screen_img_1 move_y
	  	lv_anim_t main_screen_img_1_anim_move_y;
	  	lv_anim_init(&main_screen_img_1_anim_move_y);
	  	lv_anim_set_var(&main_screen_img_1_anim_move_y, guider_ui.main_screen_img_1);
	  	lv_anim_set_time(&main_screen_img_1_anim_move_y, 2000);
	  	lv_anim_set_delay(&main_screen_img_1_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&main_screen_img_1_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&main_screen_img_1_anim_move_y, lv_obj_get_y(guider_ui.main_screen_img_1), y);
	  	lv_anim_set_path_cb(&main_screen_img_1_anim_move_y, &lv_anim_path_ease_in_out);
	  	lv_anim_set_repeat_count(&main_screen_img_1_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&main_screen_img_1_anim_move_y, 0);
	  	lv_anim_set_playback_time(&main_screen_img_1_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&main_screen_img_1_anim_move_y, 0);
		lv_anim_start(&main_screen_img_1_anim_move_y);
}

/*******************************************************************************/
