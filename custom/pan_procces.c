
#include <pan_procces.h>
#include "gui_guider.h"

/*******************************************************************************/
/*******************************************************************************/

void pan_move(uint16_t x, uint16_t y)
{
  	  	lv_anim_t main_screen_img_1_anim_move_x;
	  	lv_anim_init(&main_screen_img_1_anim_move_x);
	  	lv_anim_set_var(&main_screen_img_1_anim_move_x, guider_ui.main_screen_pan_1);
	  	lv_anim_set_time(&main_screen_img_1_anim_move_x, 2000);
	  	lv_anim_set_delay(&main_screen_img_1_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&main_screen_img_1_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&main_screen_img_1_anim_move_x, lv_obj_get_x(guider_ui.main_screen_pan_1), x);
	  	lv_anim_set_path_cb(&main_screen_img_1_anim_move_x, &lv_anim_path_ease_in_out);
	  	lv_anim_set_repeat_count(&main_screen_img_1_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&main_screen_img_1_anim_move_x, 0);
	  	lv_anim_set_playback_time(&main_screen_img_1_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&main_screen_img_1_anim_move_x, 0);
		lv_anim_start(&main_screen_img_1_anim_move_x);
		//Write animation: main_screen_img_1 move_y
	  	lv_anim_t main_screen_img_1_anim_move_y;
	  	lv_anim_init(&main_screen_img_1_anim_move_y);
	  	lv_anim_set_var(&main_screen_img_1_anim_move_y, guider_ui.main_screen_pan_1);
	  	lv_anim_set_time(&main_screen_img_1_anim_move_y, 2000);
	  	lv_anim_set_delay(&main_screen_img_1_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&main_screen_img_1_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&main_screen_img_1_anim_move_y, lv_obj_get_y(guider_ui.main_screen_pan_1), y);
	  	lv_anim_set_path_cb(&main_screen_img_1_anim_move_y, &lv_anim_path_ease_in_out);
	  	lv_anim_set_repeat_count(&main_screen_img_1_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&main_screen_img_1_anim_move_y, 0);
	  	lv_anim_set_playback_time(&main_screen_img_1_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&main_screen_img_1_anim_move_y, 0);
		lv_anim_start(&main_screen_img_1_anim_move_y);
}

void level_set(void *ui, uint8_t level)
{
  switch(level)
  {
	case 0: lv_img_set_src(ui, &_img_pan_0_alpha_200x194);
	lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_0_alpha_800x80, LV_PART_MAIN|LV_STATE_DEFAULT);		
	break;
	case 1: lv_img_set_src(ui, &_img_pan_1_alpha_200x194); 
	lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_1_alpha_800x80, LV_PART_MAIN|LV_STATE_DEFAULT);		
	break;
	case 2: lv_img_set_src(ui, &_img_pan_2_alpha_200x194); 
	lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_2_alpha_800x80, LV_PART_MAIN|LV_STATE_DEFAULT);		
	break;
	case 3: lv_img_set_src(ui, &_img_pan_3_alpha_200x194); 
	lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_3_alpha_800x80, LV_PART_MAIN|LV_STATE_DEFAULT);		
	break;
	case 4: lv_img_set_src(ui, &_img_pan_4_alpha_200x194); 
	lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_4_alpha_800x80, LV_PART_MAIN|LV_STATE_DEFAULT);		
	break;
	case 5: lv_img_set_src(ui, &_img_pan_5_alpha_200x194); 
	lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_5_alpha_800x80, LV_PART_MAIN|LV_STATE_DEFAULT);		
	break;
	case 6: lv_img_set_src(ui, &_img_pan_6_alpha_200x194); 
	lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_6_alpha_800x80, LV_PART_MAIN|LV_STATE_DEFAULT);		
	break;
	case 7: lv_img_set_src(ui, &_img_pan_7_alpha_200x194); 
	lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_7_alpha_800x80, LV_PART_MAIN|LV_STATE_DEFAULT);		
	break;	
	case 8: lv_img_set_src(ui, &_img_pan_8_alpha_200x194); 
	lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_8_alpha_800x80, LV_PART_MAIN|LV_STATE_DEFAULT);		
	break;
	case 9: lv_img_set_src(ui, &_img_pan_9_alpha_200x194); 
	lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_9_alpha_800x80, LV_PART_MAIN|LV_STATE_DEFAULT);		
	break;
	case 10: lv_img_set_src(ui, &_img_pan_P_alpha_200x194); 
	lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_P_alpha_800x80, LV_PART_MAIN|LV_STATE_DEFAULT);		
	break;	
  default:break;
	}
}

void pan_level(uint8_t sel, uint8_t level)
{
  switch(sel)
    {
      case 1:
	  level_set(guider_ui.main_screen_pan_1, level);
	  break;
      case 2:	  
	  level_set(guider_ui.main_screen_pan_2, level);
	  break;
      case 3:
	  level_set(guider_ui.main_screen_pan_3, level);
	  break;
      case 4:	  
	  level_set(guider_ui.main_screen_pan_4, level);
	  break;
	  case 5:
	  level_set(guider_ui.main_screen_pan_5, level);
	  break;
      default:	  
	  break;
	  }
}

/*******************************************************************************/
