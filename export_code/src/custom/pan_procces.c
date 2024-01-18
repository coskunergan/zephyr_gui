
#include <pan_procces.h>
#include "gui_guider.h"

#define SELECT_TIMEOUT 5000
#define REFRESH_TIME  300

lv_timer_t *timeout_timer;
lv_timer_t *refresh_timer;
system_obj_t system_obj;
tft_registers_t tft_regs;

/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
void timeout_timer_cb(lv_timer_t *timer)
{
    set_select(0);
}
/*******************************************************************************/
void refresh_timer_cb(lv_timer_t *timer)
{
    refresh_display();
}
/*******************************************************************************/
void system_init(void)
{
    lv_obj_clear_flag(guider_ui.main_screen, LV_OBJ_FLAG_SCROLL_ELASTIC);
    lv_obj_clear_flag(guider_ui.main_screen_cont_1, LV_OBJ_FLAG_SCROLL_ELASTIC);
    lv_obj_clear_flag(guider_ui.main_screen_cont_2, LV_OBJ_FLAG_SCROLL_ELASTIC);
    //lv_obj_clear_flag(guider_ui.main_screen_cont_3, LV_OBJ_FLAG_SCROLL_ELASTIC);
    //lv_obj_clear_flag(guider_ui.main_screen_cont_4, LV_OBJ_FLAG_SCROLL_ELASTIC);
    //lv_obj_clear_flag(guider_ui.main_screen_cont_5, LV_OBJ_FLAG_SCROLL_ELASTIC);
    lv_obj_add_flag(guider_ui.main_screen_select_ring_h1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.main_screen_select_ring_h2, LV_OBJ_FLAG_HIDDEN);
    //lv_obj_add_flag(guider_ui.main_screen_select_ring_h3, LV_OBJ_FLAG_HIDDEN);
    //lv_obj_add_flag(guider_ui.main_screen_select_ring_h4, LV_OBJ_FLAG_HIDDEN);
    //lv_obj_add_flag(guider_ui.main_screen_select_ring_h5, LV_OBJ_FLAG_HIDDEN);
    memset(&system_obj, 0, sizeof(system_obj));
    timeout_timer = lv_timer_create(timeout_timer_cb, SELECT_TIMEOUT,  NULL);
    refresh_timer = lv_timer_create(refresh_timer_cb, REFRESH_TIME,  NULL);
}
/*******************************************************************************/
void select_timer_start(void)
{
    lv_timer_reset(timeout_timer);
}
/*******************************************************************************/
void pan_slide(void *ui, uint16_t x, uint16_t y)
{
    lv_anim_t anim_move_x;
    lv_anim_init(&anim_move_x);
    lv_anim_set_var(&anim_move_x, ui);
    lv_anim_set_time(&anim_move_x, 3000);
    lv_anim_set_delay(&anim_move_x, 0);
    lv_anim_set_exec_cb(&anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
    lv_anim_set_values(&anim_move_x, lv_obj_get_x(ui), x);
    lv_anim_set_path_cb(&anim_move_x, &lv_anim_path_ease_in_out);
    lv_anim_set_repeat_count(&anim_move_x, 0);
    lv_anim_set_repeat_delay(&anim_move_x, 0);
    lv_anim_set_playback_time(&anim_move_x, 0);
    lv_anim_set_playback_delay(&anim_move_x, 0);
    lv_anim_start(&anim_move_x);
    //Write animation: move_y
    lv_anim_t anim_move_y;
    lv_anim_init(&anim_move_y);
    lv_anim_set_var(&anim_move_y, ui);
    lv_anim_set_time(&anim_move_y, 3000);
    lv_anim_set_delay(&anim_move_y, 0);
    lv_anim_set_exec_cb(&anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_set_values(&anim_move_y, lv_obj_get_y(ui), y);
    lv_anim_set_path_cb(&anim_move_y, &lv_anim_path_ease_in_out);
    lv_anim_set_repeat_count(&anim_move_y, 0);
    lv_anim_set_repeat_delay(&anim_move_y, 0);
    lv_anim_set_playback_time(&anim_move_y, 0);
    lv_anim_set_playback_delay(&anim_move_y, 0);
    lv_anim_start(&anim_move_y);
}
/*******************************************************************************/
void pan_move(uint8_t sel, uint16_t x, uint16_t y)
{
    switch(sel)
    {
        case 1:

            break;
        case 2:
            lv_obj_set_pos(guider_ui.main_screen_cont_2, x, y);
            break;
        case 3:
            //lv_obj_set_pos(guider_ui.main_screen_cont_3, x, y);
            break;
        case 4:
            //lv_obj_set_pos(guider_ui.main_screen_cont_4, x, y);
            break;
        case 5:
            //lv_obj_set_pos(guider_ui.main_screen_cont_5, x, y);
            break;
        default:
            break;
    }
}
/*******************************************************************************/
void level_set(void *ui, uint8_t level)
{
    switch(level)
    {
        case 0:
            lv_img_set_src(ui, &_img_pan_0_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_0_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 1:
            lv_img_set_src(ui, &_img_pan_1_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_1_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 2:
            lv_img_set_src(ui, &_img_pan_2_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_2_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 3:
            lv_img_set_src(ui, &_img_pan_3_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_3_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 4:
            lv_img_set_src(ui, &_img_pan_4_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_4_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 5:
            lv_img_set_src(ui, &_img_pan_5_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_5_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 6:
            lv_img_set_src(ui, &_img_pan_6_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_6_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 7:
            lv_img_set_src(ui, &_img_pan_7_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_7_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 8:
            lv_img_set_src(ui, &_img_pan_8_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_8_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 9:
            lv_img_set_src(ui, &_img_pan_9_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_9_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 10:
            lv_img_set_src(ui, &_img_pan_P_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_P_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        default:
            break;
    }
}
/*******************************************************************************/
void refresh_display(void)
{
    if(system_obj.m_pan1_state != tft_regs.write_regs.pan1_state.state_active)
    {
        system_obj.m_pan1_state = tft_regs.write_regs.pan1_state.state_active;
        if(system_obj.m_pan1_state)
        {
            lv_obj_set_pos(guider_ui.main_screen_cont_1, tft_regs.write_regs.pan1_x, tft_regs.write_regs.pan1_y);
            lv_obj_clear_flag(guider_ui.main_screen_cont_1, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {
            lv_obj_add_flag(guider_ui.main_screen_cont_1, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_pos(guider_ui.main_screen_cont_1, tft_regs.write_regs.pan1_x, tft_regs.write_regs.pan1_y);
        }
    }
    else if((system_obj.m_pan1_x != tft_regs.write_regs.pan1_x) || (system_obj.m_pan1_y != tft_regs.write_regs.pan1_y))
    {        
        system_obj.m_pan1_x = tft_regs.write_regs.pan1_x;
        system_obj.m_pan1_y = tft_regs.write_regs.pan1_y;
        pan_slide(guider_ui.main_screen_cont_1, tft_regs.write_regs.pan1_x, tft_regs.write_regs.pan1_y);
    } 
    if(system_obj.m_pan2_state != tft_regs.write_regs.pan2_state.state_active)
    {
        system_obj.m_pan2_state = tft_regs.write_regs.pan2_state.state_active;
        if(system_obj.m_pan2_state)
        {
            lv_obj_set_pos(guider_ui.main_screen_cont_2, tft_regs.write_regs.pan2_x, tft_regs.write_regs.pan2_y);
            lv_obj_clear_flag(guider_ui.main_screen_cont_2, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {
            lv_obj_add_flag(guider_ui.main_screen_cont_2, LV_OBJ_FLAG_HIDDEN);
        }
    }
    else if((system_obj.m_pan2_x != tft_regs.write_regs.pan2_x) || (system_obj.m_pan2_y != tft_regs.write_regs.pan2_y))
    {        
        system_obj.m_pan2_x = tft_regs.write_regs.pan2_x;
        system_obj.m_pan2_y = tft_regs.write_regs.pan2_y;
        pan_slide(guider_ui.main_screen_cont_2, tft_regs.write_regs.pan2_x, tft_regs.write_regs.pan2_y);
    }    
    // if(system_obj.m_pan3_state != tft_regs.write_regs.pan3_state.state_active)
    // {
    //     system_obj.m_pan3_state = tft_regs.write_regs.pan3_state.state_active;
    //     if(system_obj.m_pan3_state)
    //     {
    //         lv_obj_set_pos(guider_ui.main_screen_cont_3, tft_regs.write_regs.pan3_x, tft_regs.write_regs.pan3_y);
    //         lv_obj_clear_flag(guider_ui.main_screen_cont_3, LV_OBJ_FLAG_HIDDEN);
    //     }
    //     else
    //     {
    //         lv_obj_add_flag(guider_ui.main_screen_cont_3, LV_OBJ_FLAG_HIDDEN);
    //     }
    // }
    // else if((system_obj.m_pan3_x != tft_regs.write_regs.pan3_x) || (system_obj.m_pan3_y != tft_regs.write_regs.pan3_y))
    // {        
    //     system_obj.m_pan3_x = tft_regs.write_regs.pan3_x;
    //     system_obj.m_pan3_y = tft_regs.write_regs.pan3_y;
    //     pan_slide(guider_ui.main_screen_cont_3, tft_regs.write_regs.pan3_x, tft_regs.write_regs.pan3_y);
    // }  
    // if(system_obj.m_pan4_state != tft_regs.write_regs.pan4_state.state_active)
    // {
    //     system_obj.m_pan4_state = tft_regs.write_regs.pan4_state.state_active;
    //     if(system_obj.m_pan4_state)
    //     {
    //         lv_obj_set_pos(guider_ui.main_screen_cont_4, tft_regs.write_regs.pan4_x, tft_regs.write_regs.pan4_y);
    //         lv_obj_clear_flag(guider_ui.main_screen_cont_4, LV_OBJ_FLAG_HIDDEN);
    //     }
    //     else
    //     {
    //         lv_obj_add_flag(guider_ui.main_screen_cont_4, LV_OBJ_FLAG_HIDDEN);
    //     }
    // }
    // else if((system_obj.m_pan4_x != tft_regs.write_regs.pan4_x) || (system_obj.m_pan4_y != tft_regs.write_regs.pan4_y))
    // {        
    //     system_obj.m_pan4_x = tft_regs.write_regs.pan4_x;
    //     system_obj.m_pan4_y = tft_regs.write_regs.pan4_y;
    //     pan_slide(guider_ui.main_screen_cont_4, tft_regs.write_regs.pan4_x, tft_regs.write_regs.pan4_y);
    // }      
    // if(system_obj.m_pan5_state != tft_regs.write_regs.pan5_state.state_active)
    // {
    //     system_obj.m_pan5_state = tft_regs.write_regs.pan5_state.state_active;
    //     if(system_obj.m_pan5_state)
    //     {
    //         lv_obj_set_pos(guider_ui.main_screen_cont_5, tft_regs.write_regs.pan5_x, tft_regs.write_regs.pan5_y);
    //         lv_obj_clear_flag(guider_ui.main_screen_cont_5, LV_OBJ_FLAG_HIDDEN);
    //     }
    //     else
    //     {
    //         lv_obj_add_flag(guider_ui.main_screen_cont_5, LV_OBJ_FLAG_HIDDEN);
    //     }
    // }
    // else if((system_obj.m_pan5_x != tft_regs.write_regs.pan5_x) || (system_obj.m_pan5_y != tft_regs.write_regs.pan5_y))
    // {        
    //     system_obj.m_pan5_x = tft_regs.write_regs.pan5_x;
    //     system_obj.m_pan5_y = tft_regs.write_regs.pan5_y;
    //     pan_slide(guider_ui.main_screen_cont_5, tft_regs.write_regs.pan5_x, tft_regs.write_regs.pan5_y);
    // }      
    lv_obj_add_flag(guider_ui.main_screen_select_ring_h1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.main_screen_select_ring_h2, LV_OBJ_FLAG_HIDDEN);
    //lv_obj_add_flag(guider_ui.main_screen_select_ring_h3, LV_OBJ_FLAG_HIDDEN);
    //lv_obj_add_flag(guider_ui.main_screen_select_ring_h4, LV_OBJ_FLAG_HIDDEN);
    //lv_obj_add_flag(guider_ui.main_screen_select_ring_h5, LV_OBJ_FLAG_HIDDEN);
    switch(system_obj.select_pan)
    {
        case 1:
            lv_obj_clear_flag(guider_ui.main_screen_select_ring_h1, LV_OBJ_FLAG_HIDDEN);
            level_set(guider_ui.main_screen_pan_1, tft_regs.read_regs.pan1_value / 2);
            break;
        case 2:
            lv_obj_clear_flag(guider_ui.main_screen_select_ring_h2, LV_OBJ_FLAG_HIDDEN);
            level_set(guider_ui.main_screen_pan_2, tft_regs.read_regs.pan2_value / 2);
            break;
        case 3:
            //lv_obj_add_flag(guider_ui.main_screen_select_ring_h3, LV_OBJ_FLAG_HIDDEN);
            level_set(guider_ui.main_screen_pan_3, tft_regs.read_regs.pan3_value / 2);
            break;
        case 4:
            //lv_obj_add_flag(guider_ui.main_screen_select_ring_h4, LV_OBJ_FLAG_HIDDEN);
            level_set(guider_ui.main_screen_pan_4, tft_regs.read_regs.pan4_value / 2);
            break;
        case 5:
            //lv_obj_add_flag(guider_ui.main_screen_select_ring_h4, LV_OBJ_FLAG_HIDDEN);
            level_set(guider_ui.main_screen_pan_5, tft_regs.read_regs.pan5_value / 2);
            break;
        default:
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_empty_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
    }
}
/*******************************************************************************/
void set_slider(uint8_t val)
{
    select_timer_start();
    if(system_obj.slider_value != val)
    {
        system_obj.slider_value = val;
        switch(system_obj.select_pan)
        {
            case 1:
                tft_regs.read_regs.pan1_value = val;
                break;
            case 2:
                tft_regs.read_regs.pan2_value = val;
                break;
            case 3:
                tft_regs.read_regs.pan3_value = val;
                break;
            case 4:
                tft_regs.read_regs.pan4_value = val;
                break;
            case 5:
                tft_regs.read_regs.pan5_value = val;
                break;
            default:
                break;
        }
        refresh_display();
    }
}
/*******************************************************************************/
void set_select(uint8_t sel)
{
    select_timer_start();
    if(system_obj.select_pan != sel)
    {
        system_obj.select_pan = sel;
        refresh_display();
    }
}
/*******************************************************************************/
void pan_level(uint8_t sel, uint8_t level)
{
    static uint8_t s_level = 0;
    if(s_level == level)
    {
        return;
    }
    s_level = level;

}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
