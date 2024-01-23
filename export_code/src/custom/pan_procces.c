
#include <pan_procces.h>
#include "gui_guider.h"

#define SELECT_TIMEOUT 5000
#define REFRESH_TIME   300
#define MINI_PAN_SCALE 180
#define MID_PAN_SCALE  256

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
    memset(&tft_regs, 0, sizeof(tft_regs));
    tft_regs.write_regs.pan1_regs.x = 1;
    tft_regs.write_regs.pan1_regs.y = 1;
    tft_regs.write_regs.pan2_regs.x = 1;
    tft_regs.write_regs.pan2_regs.y = 1;
    tft_regs.write_regs.pan3_regs.x = 1;
    tft_regs.write_regs.pan3_regs.y = 1;
    tft_regs.write_regs.pan4_regs.x = 1;
    tft_regs.write_regs.pan4_regs.y = 1;
    tft_regs.write_regs.pan5_regs.x = 1;
    tft_regs.write_regs.pan5_regs.y = 1;
    timeout_timer = lv_timer_create(timeout_timer_cb, SELECT_TIMEOUT,  NULL);
    refresh_timer = lv_timer_create(refresh_timer_cb, REFRESH_TIME,  NULL);
    lv_anim_init(&system_obj.pan1.a_x);
    lv_anim_init(&system_obj.pan1.a_y);
    lv_anim_init(&system_obj.pan2.a_x);
    lv_anim_init(&system_obj.pan2.a_y);
    lv_anim_init(&system_obj.pan3.a_x);
    lv_anim_init(&system_obj.pan3.a_y);
    lv_anim_init(&system_obj.pan4.a_x);
    lv_anim_init(&system_obj.pan4.a_y);
    lv_anim_init(&system_obj.pan5.a_x);
    lv_anim_init(&system_obj.pan5.a_y);
    system_obj.pan1.img_pan = guider_ui.main_screen_pan_1;
    system_obj.pan1.img_ring = guider_ui.main_screen_select_ring_h1;
    system_obj.pan1.obj_cont = guider_ui.main_screen_cont_1;
    system_obj.pan2.img_pan = guider_ui.main_screen_pan_2;
    system_obj.pan2.img_ring = guider_ui.main_screen_select_ring_h2;
    system_obj.pan2.obj_cont = guider_ui.main_screen_cont_2;
    // system_obj.pan3.img_pan = guider_ui.main_screen_pan_3;
    // system_obj.pan3.img_ring = guider_ui.main_screen_select_ring_h3;
    // system_obj.pan3.obj_cont = guider_ui.main_screen_cont_3;
    // system_obj.pan4.img_pan = guider_ui.main_screen_pan_4;
    // system_obj.pan4.img_ring = guider_ui.main_screen_select_ring_h4;
    // system_obj.pan4.obj_cont = guider_ui.main_screen_cont_4;
    // system_obj.pan5.img_pan = guider_ui.main_screen_pan_5;
    // system_obj.pan5.img_ring = guider_ui.main_screen_select_ring_h5;
    // system_obj.pan5.obj_cont = guider_ui.main_screen_cont_5;
    refresh_display();
}
/*******************************************************************************/
void select_timer_start(void)
{
    lv_timer_reset(timeout_timer);
}
/*******************************************************************************/
void pan_slide(lv_anim_t *a_x, lv_anim_t *a_y, void *ui, uint16_t x, uint16_t y)
{    
    lv_anim_del(a_x, NULL);
    lv_anim_set_var(a_x, ui);
    lv_anim_set_time(a_x, 15000 * ((float)(abs((int)lv_obj_get_x(ui) - (int)x)) / 800) + 1000);
    lv_anim_set_delay(a_x, 0);
    lv_anim_set_exec_cb(a_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
    lv_anim_set_values(a_x, lv_obj_get_x(ui), x);
    lv_anim_set_path_cb(a_x, &lv_anim_path_ease_in_out);
    lv_anim_set_repeat_count(a_x, 0);
    lv_anim_set_repeat_delay(a_x, 0);
    lv_anim_set_playback_time(a_x, 0);
    lv_anim_set_playback_delay(a_x, 0);
    lv_anim_start(a_x);
    //Write animation: move_y
    lv_anim_del(a_y, NULL);
    lv_anim_set_var(a_y, ui);
    lv_anim_set_time(a_y, 3000);
    lv_anim_set_delay(a_y, 0);
    lv_anim_set_exec_cb(a_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_set_values(a_y, lv_obj_get_y(ui), y);
    lv_anim_set_path_cb(a_y, &lv_anim_path_ease_in_out);
    lv_anim_set_repeat_count(a_y, 0);
    lv_anim_set_repeat_delay(a_y, 0);
    lv_anim_set_playback_time(a_y, 0);
    lv_anim_set_playback_delay(a_y, 0);
    lv_anim_start(a_y);
}
/*******************************************************************************/
void pan_move(uint8_t sel, uint16_t x, uint16_t y)
{
    switch(sel)
    {
        case 1:
            lv_obj_set_pos(guider_ui.main_screen_cont_1, x, y);
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
    lv_img_set_pivot(ui, 50, 50);
}
/*******************************************************************************/
void pan_refresh(tft_pan_registers_t *pan_regs, system_pan_registers_t *sys_pan_regs)
{
    if(sys_pan_regs->pan.pan_state.state_active != pan_regs->pan_state.state_active)
    {
        sys_pan_regs->pan.pan_state.state_active = pan_regs->pan_state.state_active;
        if(pan_regs->pan_state.state_active)
        {
            lv_img_set_zoom(sys_pan_regs->img_pan, (pan_regs->pan_state.pan_size) ? MID_PAN_SCALE : MINI_PAN_SCALE);
            lv_img_set_zoom(sys_pan_regs->img_ring, (pan_regs->pan_state.pan_size) ? MID_PAN_SCALE : MINI_PAN_SCALE);
            lv_obj_set_pos(sys_pan_regs->obj_cont, (pan_regs->x - 1) * 150 + ((pan_regs->pan_state.pan_size) ? 0 : 17), (pan_regs->pan_state.pan_size) ? (198 - (pan_regs->y - 1) * 33) : (246 - (pan_regs->x - 1) * 41));
            lv_obj_clear_flag(sys_pan_regs->obj_cont, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {
            lv_obj_add_flag(sys_pan_regs->obj_cont, LV_OBJ_FLAG_HIDDEN);
        }
    }
    else if((sys_pan_regs->pan.x != pan_regs->x) || (sys_pan_regs->pan.y != pan_regs->y))
    {
        sys_pan_regs->pan.x = pan_regs->x;
        sys_pan_regs->pan.y = pan_regs->y;
        pan_slide(&sys_pan_regs->a_x, &sys_pan_regs->a_y, sys_pan_regs->obj_cont, (pan_regs->x - 1) * 150 + ((pan_regs->pan_state.pan_size) ? 0 : 17), (pan_regs->pan_state.pan_size) ? (198 - (pan_regs->y - 1) * 33) : (246 - (pan_regs->y - 1) * 41));
    }
}
/*******************************************************************************/
void refresh_display(void)
{
    /////// TEST ///////
    //tft_regs.write_regs.pan1_state.state_active = true;
    ////////////////////

    pan_refresh(&tft_regs.write_regs.pan1_regs, &system_obj.pan1);
    pan_refresh(&tft_regs.write_regs.pan2_regs, &system_obj.pan2);
    // pan_refresh(&tft_regs.write_regs.pan3_regs, &system_obj.pan3);
    // pan_refresh(&tft_regs.write_regs.pan4_regs, &system_obj.pan4);
    // pan_refresh(&tft_regs.write_regs.pan5_regs, &system_obj.pan5);

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
    if(sel)
    {
        tft_regs.read_regs.slave_param_bits.buzzer_bit_pan = !tft_regs.read_regs.slave_param_bits.buzzer_bit_pan;
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
