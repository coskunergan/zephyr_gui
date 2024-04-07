
#include <pan_procces.h>
#include "gui_guider.h"
#ifndef LV_USE_GUIDER_SIMULATOR
#include <zephyr/device.h>
#include <zephyr/drivers/eeprom.h>
#endif

#define SELECT_TIMEOUT 5000
#define REFRESH_TIME   300
#define MINI_PAN_SCALE 180
#define MID_PAN_SCALE  256

lv_timer_t *timeout_timer;
lv_timer_t *refresh_timer;
lv_timer_t *second_timer;
system_obj_t system_obj;
tft_registers_t tft_regs;
lv_anim_t anim_pause;
lv_anim_t anim_lock;
uint8_t long_press_countdown;
bool timer_set_menu = false;
uint8_t  timer_select = 0;
uint32_t minute_minder_timer = 0;
uint32_t minute_zone_timer[5] = {0, 0, 0, 0, 0};
uint8_t zone_keep_warm[5] = {0, 0, 0, 0, 0};
uint32_t timer_menu_timeout = 0;
uint32_t alarm_count = 0;
uint8_t button_ignore_count = 0;
bool wifi_state = false;
#define NUMBER_OF_ALARM_COUNT 30
#define TIMER_MENU_TIMEOUT_SECOMD 30
#define BUTTON_IGNORE_VAL 2

#define EEPROM_SLAVE_PARAM_ID 1

#ifndef LV_USE_GUIDER_SIMULATOR
const struct device *eeprom = DEVICE_DT_GET(DT_ALIAS(eeprom_1));
#endif

void stop_minute_minder();

/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
void second_timer_cb(lv_timer_t *timeout_timer)
{
#if LV_USE_GUIDER_SIMULATOR
    static bool first = false;
    tft_regs.write_regs.pan1_regs.pan_state.state_active = true;
    tft_regs.write_regs.pan1_regs.pan_state.pan_state = true;
    tft_regs.write_regs.pan2_regs.pan_state.state_active = true;
    tft_regs.write_regs.pan2_regs.pan_state.pan_state = true;  
    tft_regs.write_regs.pan2_regs.x = 3;  
    if(!first)
    {
        first = true;
        lv_obj_t *act_scr = lv_scr_act();
        lv_event_send(act_scr, LV_EVENT_VALUE_CHANGED, NULL);
    }
#endif
    if(guider_ui.menu_screen_del == false)
    {
        lv_label_set_text_fmt(guider_ui.menu_screen_clock_lbl, "%02d:%02d", tft_regs.write_regs.hour, tft_regs.write_regs.minute);
    }
    else if(guider_ui.main_screen_del == false)
    {
        lv_obj_clear_flag(guider_ui.main_screen_clock_lbl, LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text_fmt(guider_ui.main_screen_clock_lbl, "%02d:%02d", tft_regs.write_regs.hour, tft_regs.write_regs.minute);
    }
    else
    {
        lv_obj_clear_flag(guider_ui.logo_screen_clock_lbl, LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text_fmt(guider_ui.logo_screen_clock_lbl, "%02d:%02d", tft_regs.write_regs.hour, tft_regs.write_regs.minute);
        if(tft_regs.write_regs.pan1_regs.pan_state.pan_heat ||
                tft_regs.write_regs.pan2_regs.pan_state.pan_heat ||
                tft_regs.write_regs.pan3_regs.pan_state.pan_heat ||
                tft_regs.write_regs.pan4_regs.pan_state.pan_heat ||
                tft_regs.write_regs.pan5_regs.pan_state.pan_heat)
        {
            lv_obj_clear_flag(guider_ui.logo_screen_heat_lbl, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(guider_ui.logo_screen_img_heat, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {
            lv_obj_add_flag(guider_ui.logo_screen_heat_lbl, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.logo_screen_img_heat, LV_OBJ_FLAG_HIDDEN);
        }
    }
    if(tft_regs.write_regs.hour == tft_regs.read_regs.hour_set && tft_regs.write_regs.minute == tft_regs.read_regs.minute_set)
    {
        tft_regs.read_regs.slave_param_bits.clock_updated = false;
    }
    if(system_obj.pause == false)
    {
        for(size_t i = 0; i < 5; i++)
        {
            if(minute_zone_timer[i])
            {
                if(--minute_zone_timer[i] == 0)
                {
                    zone_keep_warm[i] = 0;
                    tft_regs.read_regs.panx_value[i] = 0;
                    set_select(i + 1);
                    alarm_count = NUMBER_OF_ALARM_COUNT;
                }
                else if(minute_zone_timer[i] == 10)
                {
                    tft_regs.read_regs.slave_param_bits.buzzer_bit_alarm = !tft_regs.read_regs.slave_param_bits.buzzer_bit_alarm;
                }
            }
        }
        if(minute_minder_timer)
        {
            if(--minute_minder_timer == 0)
            {
                lv_obj_add_flag(guider_ui.main_screen_timer_spinner, LV_OBJ_FLAG_HIDDEN);
                alarm_count = NUMBER_OF_ALARM_COUNT;
            }
        }
    }
    if(alarm_count)
    {
        --alarm_count;
        tft_regs.read_regs.slave_param_bits.buzzer_bit_pan = !tft_regs.read_regs.slave_param_bits.buzzer_bit_pan;
        tft_regs.read_regs.slave_param_bits.buzzer_bit_alarm = !tft_regs.read_regs.slave_param_bits.buzzer_bit_alarm;
    }
    if(timer_menu_timeout)
    {
        if(--timer_menu_timeout == 0 && timer_set_menu)
        {
            timer_set_menu = false;
            lv_obj_add_flag(guider_ui.main_screen_set_timer_cont, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(guider_ui.main_screen_pause_btn, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(guider_ui.main_screen_menu_btn, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(guider_ui.main_screen_lock_btn, LV_OBJ_FLAG_HIDDEN);
        }
    }
}
/*******************************************************************************/
void timeout_timer_cb(lv_timer_t *timer)
{
    set_select(0);
}
/*******************************************************************************/
void refresh_timer_cb(lv_timer_t *timer)
{
    if(button_ignore_count)
    {
        --button_ignore_count;
    }
    refresh_display();
    if(long_press_countdown)
    {
        --long_press_countdown;
        lv_label_set_text_fmt(guider_ui.main_screen_count_down_label, "%d", long_press_countdown);
    }
}
/*******************************************************************************/
void logo_screen_init(void)
{
    guider_ui.logo_screen_del = false;
    memset(&system_obj, 0, sizeof(system_obj));
    memset(&tft_regs, 0, sizeof(tft_regs));
#ifndef LV_USE_GUIDER_SIMULATOR
    eeprom_read(eeprom, EEPROM_SLAVE_PARAM_ID, &tft_regs.read_regs.slave_param_bits, sizeof(tft_regs.read_regs.slave_param_bits));
    if(*(uint16_t *)&tft_regs.read_regs.slave_param_bits == 0xFFFF)
    {
        *(uint16_t *)&tft_regs.read_regs.slave_param_bits = 0;
    }
#endif
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
    second_timer = lv_timer_create(second_timer_cb, 1000,  NULL);
}
/*******************************************************************************/
void main_screen_init(void)
{
    guider_ui.menu_screen_del = true;
    guider_ui.logo_screen_del = true;
    if(guider_ui.main_screen_del == true)
    {
        guider_ui.main_screen_del = false;
        tft_regs.write_regs.master_param_bits.logo_off_state = true;
        lv_obj_clear_flag(guider_ui.main_screen, LV_OBJ_FLAG_SCROLL_ELASTIC);
        lv_obj_clear_flag(guider_ui.main_screen_cont_1, LV_OBJ_FLAG_SCROLL_ELASTIC);
        lv_obj_clear_flag(guider_ui.main_screen_cont_2, LV_OBJ_FLAG_SCROLL_ELASTIC);
        lv_obj_clear_flag(guider_ui.main_screen_cont_3, LV_OBJ_FLAG_SCROLL_ELASTIC);
        lv_obj_clear_flag(guider_ui.main_screen_cont_4, LV_OBJ_FLAG_SCROLL_ELASTIC);
        lv_obj_clear_flag(guider_ui.main_screen_cont_5, LV_OBJ_FLAG_SCROLL_ELASTIC);
        lv_obj_clear_flag(guider_ui.main_screen_cont_1, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.main_screen_cont_2, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.main_screen_cont_3, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.main_screen_cont_4, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.main_screen_cont_5, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.main_screen_set_timer_cont, LV_OBJ_FLAG_SCROLLABLE);
        timeout_timer = lv_timer_create(timeout_timer_cb, SELECT_TIMEOUT,  NULL);
        refresh_timer = lv_timer_create(refresh_timer_cb, REFRESH_TIME,  NULL);
        system_obj.pan1.img_pan = guider_ui.main_screen_pan_1;
        system_obj.pan1.img_ring_l = guider_ui.main_screen_select_ring_l1;
        system_obj.pan1.img_ring_h = guider_ui.main_screen_select_ring_h1;
        system_obj.pan1.obj_cont = guider_ui.main_screen_cont_1;
        system_obj.pan1.timer_label = guider_ui.main_screen_timer_label_1;
        system_obj.pan2.img_pan = guider_ui.main_screen_pan_2;
        system_obj.pan2.img_ring_l = guider_ui.main_screen_select_ring_l2;
        system_obj.pan2.img_ring_h = guider_ui.main_screen_select_ring_h2;
        system_obj.pan2.obj_cont = guider_ui.main_screen_cont_2;
        system_obj.pan2.timer_label = guider_ui.main_screen_timer_label_2;
        system_obj.pan3.img_pan = guider_ui.main_screen_pan_3;
        system_obj.pan3.img_ring_l = guider_ui.main_screen_select_ring_l3;
        system_obj.pan3.img_ring_h = guider_ui.main_screen_select_ring_h3;
        system_obj.pan3.obj_cont = guider_ui.main_screen_cont_3;
        system_obj.pan3.timer_label = guider_ui.main_screen_timer_label_3;
        system_obj.pan4.img_pan = guider_ui.main_screen_pan_4;
        system_obj.pan4.img_ring_l = guider_ui.main_screen_select_ring_l4;
        system_obj.pan4.img_ring_h = guider_ui.main_screen_select_ring_h4;
        system_obj.pan4.obj_cont = guider_ui.main_screen_cont_4;
        system_obj.pan4.timer_label = guider_ui.main_screen_timer_label_4;
        system_obj.pan5.img_pan = guider_ui.main_screen_pan_5;
        system_obj.pan5.img_ring_l = guider_ui.main_screen_select_ring_l5;
        system_obj.pan5.img_ring_h = guider_ui.main_screen_select_ring_h5;
        system_obj.pan5.obj_cont = guider_ui.main_screen_cont_5;
        system_obj.pan5.timer_label = guider_ui.main_screen_timer_label_5;
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
        lv_anim_init(&anim_pause);
    }
    refresh_display();
    buzzer_beep();
    lv_label_set_text_fmt(guider_ui.main_screen_clock_lbl, "%02d:%02d", tft_regs.write_regs.hour, tft_regs.write_regs.minute);
}
/*******************************************************************************/
void menu_screen_init(void)
{
    guider_ui.menu_screen_del = false;
    lv_obj_clear_flag(guider_ui.menu_screen_tabview_1, LV_OBJ_FLAG_SCROLLABLE);
    buzzer_beep();
    if(tft_regs.read_regs.slave_param_bits.buzzer_bit_mute)
    {
        lv_obj_add_state(guider_ui.menu_screen_sound_switch, LV_STATE_CHECKED);
    }
    else
    {
        lv_obj_clear_state(guider_ui.menu_screen_sound_switch, LV_STATE_CHECKED);
    }
    if(tft_regs.read_regs.slave_param_bits.demo_mode_on)
    {
        lv_obj_clear_flag(guider_ui.menu_screen_demo_lbl, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(guider_ui.menu_screen_demo_lbl, LV_OBJ_FLAG_HIDDEN);
    }
    lv_roller_set_selected(guider_ui.menu_screen_power_roller, tft_regs.read_regs.slave_param_bits.power_limit, LV_ANIM_ON);
    lv_roller_set_selected(guider_ui.menu_screen_roller_1, tft_regs.write_regs.hour, LV_ANIM_ON);
    lv_roller_set_selected(guider_ui.menu_screen_roller_2, tft_regs.write_regs.minute, LV_ANIM_ON);
    lv_label_set_text_fmt(guider_ui.menu_screen_clock_lbl, "%02d:%02d", tft_regs.write_regs.hour, tft_regs.write_regs.minute);

}
/*******************************************************************************/
void select_timer_start(void)
{
    lv_timer_reset(timeout_timer);
}
/*******************************************************************************/
void pan_slide(lv_anim_t *a_x, lv_anim_t *a_y, void *ui, int32_t x, int32_t y)
{
    lv_anim_del(a_x, NULL);
    lv_anim_set_var(a_x, ui);
    lv_anim_set_time(a_x, 2500/*15000 * ((float)(abs((int)lv_obj_get_x(ui) - (int)x)) / 800) + 1000*/);
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
    lv_anim_set_time(a_y, 2500);
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
        case 11:
            lv_img_set_src(ui, &_img_warm_1_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_0_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 12:
            lv_img_set_src(ui, &_img_warm_2_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_0_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        case 13:
            lv_img_set_src(ui, &_img_warm_3_alpha_200x194);
            lv_obj_set_style_bg_img_src(guider_ui.main_screen_slider, &_slider_0_alpha_800x80, LV_PART_MAIN | LV_STATE_DEFAULT);
            break;
        default:
            break;
    }
    lv_img_set_pivot(ui, 100, 5);
}
/*******************************************************************************/
void no_level_set(void *ui, uint8_t level)
{
    switch(level)
    {
        case 0:
            lv_img_set_src(ui, &_NoHob_0_alpha_200x194);
            break;
        case 1:
            lv_img_set_src(ui, &_NoHob_1_alpha_200x194);
            break;
        case 2:
            lv_img_set_src(ui, &_NoHob_2_alpha_200x194);
            break;
        case 3:
            lv_img_set_src(ui, &_NoHob_3_alpha_200x194);
            break;
        case 4:
            lv_img_set_src(ui, &_NoHob_4_alpha_200x194);
            break;
        case 5:
            lv_img_set_src(ui, &_NoHob_5_alpha_200x194);
            break;
        case 6:
            lv_img_set_src(ui, &_NoHob_6_alpha_200x194);
            break;
        case 7:
            lv_img_set_src(ui, &_NoHob_7_alpha_200x194);
            break;
        case 8:
            lv_img_set_src(ui, &_NoHob_8_alpha_200x194);
            break;
        case 9:
            lv_img_set_src(ui, &_NoHob_9_alpha_200x194);
            break;
        case 10:
            lv_img_set_src(ui, &_NoHob_P_alpha_200x194);
            break;
        case 11:
            lv_img_set_src(ui, &_img_no_warm_1_alpha_200x194);
            break;
        case 12:
            lv_img_set_src(ui, &_img_no_warm_2_alpha_200x194);
            break;
        case 13:
            lv_img_set_src(ui, &_img_no_warm_3_alpha_200x194);
            break;
        default:
            break;
    }
    lv_img_set_pivot(ui, 100, 5);
}
/*******************************************************************************/
void pan_refresh(tft_pan_registers_t *pan_regs, system_pan_registers_t *sys_pan_regs, size_t index)
{
    lv_obj_add_flag(sys_pan_regs->img_ring_l, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(sys_pan_regs->img_ring_h, LV_OBJ_FLAG_HIDDEN);
    if(system_obj.select_pan == 0)
    {
        lv_obj_add_flag(guider_ui.main_screen_zone_timer_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.main_screen_zone_warm_btn, LV_OBJ_FLAG_HIDDEN);
    }
    if(system_obj.select_pan == index + 1)
    {
        if(pan_regs->y < 4)
        {
            lv_obj_clear_flag(sys_pan_regs->img_ring_l, LV_OBJ_FLAG_HIDDEN);
            if(pan_regs->pan_state.pan_size)
            {
                lv_obj_set_pos(guider_ui.main_screen_zone_timer_btn, 146 + lv_obj_get_x(sys_pan_regs->obj_cont), 8 + lv_obj_get_y(sys_pan_regs->obj_cont));
                lv_obj_set_pos(guider_ui.main_screen_zone_warm_btn, 3 + lv_obj_get_x(sys_pan_regs->obj_cont), 8 + lv_obj_get_y(sys_pan_regs->obj_cont));
            }
            else
            {
                lv_obj_set_pos(guider_ui.main_screen_zone_timer_btn, 131 + lv_obj_get_x(sys_pan_regs->obj_cont), lv_obj_get_y(sys_pan_regs->obj_cont));
                lv_obj_set_pos(guider_ui.main_screen_zone_warm_btn, 25 + lv_obj_get_x(sys_pan_regs->obj_cont), lv_obj_get_y(sys_pan_regs->obj_cont));
            }
        }
        else
        {
            lv_obj_clear_flag(sys_pan_regs->img_ring_h, LV_OBJ_FLAG_HIDDEN);
            if(pan_regs->pan_state.pan_size)
            {
                lv_obj_set_pos(guider_ui.main_screen_zone_timer_btn, 146 + lv_obj_get_x(sys_pan_regs->obj_cont), 139 + lv_obj_get_y(sys_pan_regs->obj_cont));
                lv_obj_set_pos(guider_ui.main_screen_zone_warm_btn, 3 + lv_obj_get_x(sys_pan_regs->obj_cont), 139 + lv_obj_get_y(sys_pan_regs->obj_cont));
            }
            else
            {
                lv_obj_set_pos(guider_ui.main_screen_zone_timer_btn, 131 + lv_obj_get_x(sys_pan_regs->obj_cont), 105 + lv_obj_get_y(sys_pan_regs->obj_cont));
                lv_obj_set_pos(guider_ui.main_screen_zone_warm_btn, 25 + lv_obj_get_x(sys_pan_regs->obj_cont), 105 + lv_obj_get_y(sys_pan_regs->obj_cont));
            }
        }
        lv_obj_clear_flag(guider_ui.main_screen_zone_timer_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.main_screen_zone_warm_btn, LV_OBJ_FLAG_HIDDEN);
    }
    if(sys_pan_regs->pan.pan_state.state_active != pan_regs->pan_state.state_active)
    {
        sys_pan_regs->pan.pan_state.state_active = pan_regs->pan_state.state_active;
        if(pan_regs->pan_state.state_active)
        {
            lv_img_set_zoom(sys_pan_regs->img_pan, (pan_regs->pan_state.pan_size) ? MID_PAN_SCALE : MINI_PAN_SCALE);
            lv_img_set_zoom(sys_pan_regs->img_ring_h, (pan_regs->pan_state.pan_size) ? MID_PAN_SCALE : MINI_PAN_SCALE);
            lv_img_set_zoom(sys_pan_regs->img_ring_l, (pan_regs->pan_state.pan_size) ? MID_PAN_SCALE : MINI_PAN_SCALE);
            lv_obj_set_pos(sys_pan_regs->obj_cont, (pan_regs->x - 1) * 150, (pan_regs->pan_state.pan_size) ? ((270 - (pan_regs->y - 1) * 45) - 40) : ((258 - (pan_regs->y - 1) * 43) - 3));
            lv_obj_clear_flag(sys_pan_regs->obj_cont, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {
            minute_zone_timer[index] = 0;
            zone_keep_warm[index] = 0;
            tft_regs.read_regs.panx_value[index] = 0;
            level_set(sys_pan_regs->img_pan, 0);
            lv_obj_add_flag(sys_pan_regs->obj_cont, LV_OBJ_FLAG_HIDDEN);
        }
    }
    else if(pan_regs->pan_state.state_active)
    {
        if(sys_pan_regs->set_value != tft_regs.read_regs.panx_value[index])
        {
            sys_pan_regs->set_value = tft_regs.read_regs.panx_value[index];
            if(pan_regs->pan_state.pan_state)
            {
                level_set(sys_pan_regs->img_pan, tft_regs.read_regs.panx_value[index] / 2);
            }
            else
            {
                if(index == (system_obj.select_pan - 1))
                {
                    system_obj.select_pan = 0;
                }
                no_level_set(sys_pan_regs->img_pan, tft_regs.read_regs.panx_value[index] / 2);
            }
        }
        if((sys_pan_regs->pan.x != pan_regs->x) || (sys_pan_regs->pan.y != pan_regs->y))
        {
            sys_pan_regs->pan.x = pan_regs->x;
            sys_pan_regs->pan.y = pan_regs->y;
            pan_slide(&sys_pan_regs->a_x, &sys_pan_regs->a_y, sys_pan_regs->obj_cont, (pan_regs->x - 1) * 150, (pan_regs->pan_state.pan_size) ? ((270 - (pan_regs->y - 1) * 45) - 40) : ((258 - (pan_regs->y - 1) * 43) - 3));
        }
    }
    if(minute_zone_timer[index] && system_obj.pause == false)
    {
        if(pan_regs->pan_state.pan_size)
        {
            lv_obj_set_pos(sys_pan_regs->timer_label, 51, 136);
        }
        else
        {
            lv_obj_set_pos(sys_pan_regs->timer_label, 51, 93);
        }
        lv_obj_clear_flag(sys_pan_regs->timer_label, LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text_fmt(sys_pan_regs->timer_label, "%02d:%02d", minute_zone_timer[index] / 60, minute_zone_timer[index] % 60);
    }
    else
    {
        lv_obj_add_flag(sys_pan_regs->timer_label, LV_OBJ_FLAG_HIDDEN);
    }
}
/*******************************************************************************/
void refresh_display(void)
{
    /////// TEST ///////
    //tft_regs.write_regs.pan1_regs.pan_state.state_active = true;
    //tft_regs.write_regs.pan2_regs.pan_state.state_active = true;
    //tft_regs.write_regs.pan2_regs.pan_state.pan_size = 1;
    ////////////////////
    pan_refresh(&tft_regs.write_regs.pan1_regs, &system_obj.pan1, 0);
    pan_refresh(&tft_regs.write_regs.pan2_regs, &system_obj.pan2, 1);
    pan_refresh(&tft_regs.write_regs.pan3_regs, &system_obj.pan3, 2);
    pan_refresh(&tft_regs.write_regs.pan4_regs, &system_obj.pan4, 3);
    pan_refresh(&tft_regs.write_regs.pan5_regs, &system_obj.pan5, 4);
}
/*******************************************************************************/
void set_slider(uint8_t val)
{
    zone_keep_warm[system_obj.select_pan - 1] = 0;
    select_timer_start();
    if(system_obj.slider_value != val && system_obj.pause == false)
    {
        system_obj.slider_value = val;
        if(system_obj.select_pan)
        {
            tft_regs.read_regs.panx_value[system_obj.select_pan - 1] = val;
        }
        refresh_display();
    }
}
/*******************************************************************************/
void set_select(uint8_t sel)
{
    select_timer_start();
    switch(sel)
    {
        case 1:
            sel = (tft_regs.write_regs.pan1_regs.pan_state.pan_state) ? sel : 0;
            system_obj.pan1.set_value = 0xFF;
            break;
        case 2:
            sel = (tft_regs.write_regs.pan2_regs.pan_state.pan_state) ? sel : 0;
            system_obj.pan2.set_value = 0xFF;
            break;
        case 3:
            sel = (tft_regs.write_regs.pan3_regs.pan_state.pan_state) ? sel : 0;
            system_obj.pan3.set_value = 0xFF;
            break;
        case 4:
            sel = (tft_regs.write_regs.pan4_regs.pan_state.pan_state) ? sel : 0;
            system_obj.pan4.set_value = 0xFF;
            break;
        case 5:
            sel = (tft_regs.write_regs.pan5_regs.pan_state.pan_state) ? sel : 0;
            system_obj.pan5.set_value = 0xFF;
            break;
        default:
            break;
    }
    if(sel)
    {
        buzzer_beep();
    }
    if(system_obj.select_pan != sel && system_obj.pause == false && system_obj.lock == false && timer_set_menu == false)
    {
        system_obj.select_pan = sel;
    }
    else
    {
        system_obj.select_pan = 0;
    }
    refresh_display();
    if(system_obj.select_pan)
    {
        lv_obj_clear_flag(guider_ui.main_screen_slider, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.main_screen_menu_cont, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(guider_ui.main_screen_slider, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.main_screen_menu_cont, LV_OBJ_FLAG_HIDDEN);
    }
}
/*******************************************************************************/
void released_lock(void)
{
    long_press_countdown = 0;
    lv_obj_add_flag(guider_ui.main_screen_count_down_label, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.main_screen_spinner_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_img_opa(guider_ui.main_screen_pan_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(guider_ui.main_screen_pan_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(guider_ui.main_screen_pan_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(guider_ui.main_screen_pan_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(guider_ui.main_screen_pan_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
}
/*******************************************************************************/
void pressed_lock(void)
{
    if(wifi_state)
    {
        return;
    }
    lv_obj_add_flag(guider_ui.main_screen_set_timer_cont, LV_OBJ_FLAG_HIDDEN);
    timer_set_menu = false;
    long_press_countdown = 5;
    lv_label_set_text_fmt(guider_ui.main_screen_count_down_label, "%d", long_press_countdown);
    lv_obj_clear_flag(guider_ui.main_screen_count_down_label, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(guider_ui.main_screen_spinner_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_style_img_opa(guider_ui.main_screen_pan_1, 72, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(guider_ui.main_screen_pan_2, 72, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(guider_ui.main_screen_pan_3, 72, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(guider_ui.main_screen_pan_4, 72, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(guider_ui.main_screen_pan_5, 72, LV_PART_MAIN | LV_STATE_DEFAULT);
    buzzer_beep();
}
/*******************************************************************************/
void pause_anim_ready_cb(lv_anim_t *a)
{
    if(system_obj.pause == false)
    {
        lv_obj_clear_flag(guider_ui.main_screen_timer_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.main_screen_lock_btn, LV_OBJ_FLAG_HIDDEN);
        if(minute_minder_timer)
        {
            lv_obj_clear_flag(guider_ui.main_screen_timer_spinner, LV_OBJ_FLAG_HIDDEN);
        }
    }
}
/*******************************************************************************/
void pause_slide(bool active)
{
    lv_anim_del(&anim_pause, NULL);
    lv_anim_set_var(&anim_pause, guider_ui.main_screen_pause_btn);
    lv_anim_set_time(&anim_pause, 500);
    lv_anim_set_delay(&anim_pause, 0);
    lv_anim_set_exec_cb(&anim_pause, (lv_anim_exec_xcb_t)lv_obj_set_x);
    lv_anim_set_values(&anim_pause, lv_obj_get_x(guider_ui.main_screen_pause_btn), (active) ? 372 : 462);
    lv_anim_set_path_cb(&anim_pause, &lv_anim_path_ease_in_out);
    lv_anim_set_repeat_count(&anim_pause, 0);
    lv_anim_set_repeat_delay(&anim_pause, 0);
    lv_anim_set_playback_time(&anim_pause, 0);
    lv_anim_set_playback_delay(&anim_pause, 0);
    lv_anim_set_ready_cb(&anim_pause, &pause_anim_ready_cb);
    lv_anim_start(&anim_pause);
}
/*******************************************************************************/
void lock_anim_ready_cb(lv_anim_t *a)
{
    if(system_obj.lock == false)
    {
        lv_obj_clear_flag(guider_ui.main_screen_timer_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.main_screen_pause_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.main_screen_menu_btn, LV_OBJ_FLAG_HIDDEN);
        if(minute_minder_timer)
        {
            lv_obj_clear_flag(guider_ui.main_screen_timer_spinner, LV_OBJ_FLAG_HIDDEN);
        }
    }
}
/*******************************************************************************/
void lock_slide(bool active)
{
    lv_anim_del(&anim_lock, NULL);
    lv_anim_set_var(&anim_lock, guider_ui.main_screen_lock_btn);
    lv_anim_set_time(&anim_lock, 500);
    lv_anim_set_delay(&anim_lock, 0);
    lv_anim_set_exec_cb(&anim_lock, (lv_anim_exec_xcb_t)lv_obj_set_x);
    lv_anim_set_values(&anim_lock, lv_obj_get_x(guider_ui.main_screen_lock_btn), (active) ? 372 : 280);
    lv_anim_set_path_cb(&anim_lock, &lv_anim_path_ease_in_out);
    lv_anim_set_repeat_count(&anim_lock, 0);
    lv_anim_set_repeat_delay(&anim_lock, 0);
    lv_anim_set_playback_time(&anim_lock, 0);
    lv_anim_set_playback_delay(&anim_lock, 0);
    lv_anim_set_ready_cb(&anim_lock, &lock_anim_ready_cb);
    lv_anim_start(&anim_lock);
}
/*******************************************************************************/
void click_pause(void)
{
    if(button_ignore_count)
    {
        return;
    }
    button_ignore_count = BUTTON_IGNORE_VAL;
    lv_obj_add_flag(guider_ui.main_screen_set_timer_cont, LV_OBJ_FLAG_HIDDEN);
    timer_set_menu = false;
    system_obj.pause = !system_obj.pause;
    if(system_obj.pause)
    {
        system_obj.select_pan = 0;
        memcpy(system_obj.level_backup, tft_regs.read_regs.panx_value, sizeof(tft_regs.read_regs.panx_value));
        memset(tft_regs.read_regs.panx_value, 0, sizeof(tft_regs.read_regs.panx_value));
        tft_regs.read_regs.slave_param_bits.buzzer_bit_pause = true;
        lv_imgbtn_set_src(guider_ui.main_screen_pause_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_Play_alpha_57x57, NULL);
        lv_imgbtn_set_src(guider_ui.main_screen_pause_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_Pause_alpha_57x57, NULL);
        lv_obj_set_style_img_opa(guider_ui.main_screen_pan_1, 72, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_img_opa(guider_ui.main_screen_pan_2, 72, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_img_opa(guider_ui.main_screen_pan_3, 72, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_img_opa(guider_ui.main_screen_pan_4, 72, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_img_opa(guider_ui.main_screen_pan_5, 72, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_flag(guider_ui.main_screen_timer_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.main_screen_lock_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.main_screen_timer_spinner, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        memcpy(tft_regs.read_regs.panx_value, system_obj.level_backup, sizeof(tft_regs.read_regs.panx_value));
        tft_regs.read_regs.slave_param_bits.buzzer_bit_pause = false;
        lv_imgbtn_set_src(guider_ui.main_screen_pause_btn, LV_IMGBTN_STATE_RELEASED, NULL, &_Pause_alpha_57x57, NULL);
        lv_imgbtn_set_src(guider_ui.main_screen_pause_btn, LV_IMGBTN_STATE_PRESSED, NULL, &_Play_alpha_57x57, NULL);
        lv_obj_set_style_img_opa(guider_ui.main_screen_pan_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_img_opa(guider_ui.main_screen_pan_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_img_opa(guider_ui.main_screen_pan_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_img_opa(guider_ui.main_screen_pan_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_img_opa(guider_ui.main_screen_pan_5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    pause_slide(system_obj.pause);
}
/*******************************************************************************/
void long_press_lock(void)
{
    if(wifi_state)
    {
        return;
    }
    system_obj.lock = !system_obj.lock;
    if(system_obj.lock)
    {
        tft_regs.read_regs.slave_param_bits.buzzer_bit_lock = true;
        lv_obj_add_flag(guider_ui.main_screen_timer_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.main_screen_pause_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.main_screen_menu_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.main_screen_timer_spinner, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        tft_regs.read_regs.slave_param_bits.buzzer_bit_lock = false;
    }
    lv_obj_add_flag(guider_ui.main_screen_count_down_label, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.main_screen_spinner_1, LV_OBJ_FLAG_HIDDEN);
    lock_slide(system_obj.lock);
}
/*******************************************************************************/
void start_minute_minder(uint32_t sec)
{
    minute_minder_timer = sec;
    timer_menu_timeout = 0;
    lv_obj_add_flag(guider_ui.main_screen_set_timer_cont, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(guider_ui.main_screen_timer_spinner, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(guider_ui.main_screen_pause_btn, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(guider_ui.main_screen_menu_btn, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(guider_ui.main_screen_lock_btn, LV_OBJ_FLAG_HIDDEN);
}
/*******************************************************************************/
void stop_minute_minder()
{
    alarm_count = 0;
    minute_minder_timer = 0;
    timer_menu_timeout = 0;
    lv_obj_add_flag(guider_ui.main_screen_set_timer_cont, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(guider_ui.main_screen_timer_spinner, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(guider_ui.main_screen_pause_btn, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(guider_ui.main_screen_menu_btn, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(guider_ui.main_screen_lock_btn, LV_OBJ_FLAG_HIDDEN);
}
/*******************************************************************************/
void click_main_timer(void)
{
    if(button_ignore_count)
    {
        return;
    }
    button_ignore_count = BUTTON_IGNORE_VAL;
    buzzer_beep();
    timer_select = system_obj.select_pan;
    if(timer_select != 0)
    {
        timer_set_menu = true;
        timer_menu_timeout = TIMER_MENU_TIMEOUT_SECOMD;
        lv_roller_set_selected(guider_ui.main_screen_timer_10min_roller, minute_zone_timer[timer_select - 1] / 600, LV_ANIM_ON);
        if(minute_zone_timer[timer_select - 1])
        {
            lv_roller_set_selected(guider_ui.main_screen_timer_min_roller, minute_zone_timer[timer_select - 1] / 60 + 1, LV_ANIM_ON);
        }
        else
        {
            lv_roller_set_selected(guider_ui.main_screen_timer_min_roller, 0, LV_ANIM_ON);
        }
        lv_obj_clear_flag(guider_ui.main_screen_set_timer_cont, LV_OBJ_FLAG_HIDDEN);
        set_select(0);
    }
    else
    {
        timer_set_menu = !timer_set_menu;
        if(timer_set_menu)
        {
            timer_menu_timeout = TIMER_MENU_TIMEOUT_SECOMD;
            lv_roller_set_selected(guider_ui.main_screen_timer_10min_roller, minute_minder_timer / 600, LV_ANIM_ON);
            if(minute_minder_timer)
            {
                lv_roller_set_selected(guider_ui.main_screen_timer_min_roller, minute_minder_timer / 60 + 1, LV_ANIM_ON);
            }
            else
            {
                lv_roller_set_selected(guider_ui.main_screen_timer_min_roller, 0, LV_ANIM_ON);
            }
            lv_obj_clear_flag(guider_ui.main_screen_set_timer_cont, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.main_screen_pause_btn, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.main_screen_menu_btn, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.main_screen_lock_btn, LV_OBJ_FLAG_HIDDEN);
            system_obj.select_pan = 0;
        }
        else
        {
            timer_menu_timeout = 0;
            lv_obj_add_flag(guider_ui.main_screen_set_timer_cont, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(guider_ui.main_screen_pause_btn, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(guider_ui.main_screen_menu_btn, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(guider_ui.main_screen_lock_btn, LV_OBJ_FLAG_HIDDEN);
        }
    }
}
/*******************************************************************************/
void pressed_clock_save(void)
{
    if(button_ignore_count)
    {
        return;
    }
    button_ignore_count = BUTTON_IGNORE_VAL;
    lv_timer_reset(second_timer);
    buzzer_beep();
    tft_regs.read_regs.hour_set = lv_roller_get_selected(guider_ui.menu_screen_roller_1);
    tft_regs.read_regs.minute_set = lv_roller_get_selected(guider_ui.menu_screen_roller_2);
    tft_regs.read_regs.slave_param_bits.clock_updated = true;
}
/*******************************************************************************/
void pressed_setting_save(void)
{
    if(button_ignore_count)
    {
        return;
    }
    button_ignore_count = BUTTON_IGNORE_VAL;
    tft_regs.read_regs.slave_param_bits.buzzer_bit_mute = lv_obj_get_state(guider_ui.menu_screen_sound_switch) & LV_STATE_CHECKED ? true : false;
    tft_regs.read_regs.slave_param_bits.power_limit = lv_roller_get_selected(guider_ui.menu_screen_power_roller);
#ifndef LV_USE_GUIDER_SIMULATOR
    eeprom_write(eeprom, EEPROM_SLAVE_PARAM_ID, &tft_regs.read_regs.slave_param_bits, sizeof(tft_regs.read_regs.slave_param_bits));
#endif
    buzzer_beep();
}
/*******************************************************************************/
void buzzer_beep(void)
{
    if(tft_regs.read_regs.slave_param_bits.buzzer_bit_mute == false)
    {
        tft_regs.read_regs.slave_param_bits.buzzer_bit_pan = !tft_regs.read_regs.slave_param_bits.buzzer_bit_pan;
    }
    alarm_count = 0;
}
/*******************************************************************************/
void click_timer_ok_btn(void)
{
    uint32_t time = lv_roller_get_selected(guider_ui.main_screen_timer_10min_roller) * 10;
    time += lv_roller_get_selected(guider_ui.main_screen_timer_min_roller);
    if(timer_select != 0)
    {
        if(time)
        {
            minute_zone_timer[timer_select - 1] = time * 60;
        }
        else
        {
            minute_zone_timer[timer_select - 1] = 0;
        }
    }
    else
    {
        if(time)
        {
            start_minute_minder(time * 60);
        }
        else
        {
            stop_minute_minder();
        }
    }
    timer_set_menu = false;
    lv_obj_add_flag(guider_ui.main_screen_set_timer_cont, LV_OBJ_FLAG_HIDDEN);
    buzzer_beep();
}
/*******************************************************************************/
void click_timer_close_btn(void)
{
    timer_set_menu = false;
    lv_obj_add_flag(guider_ui.main_screen_set_timer_cont, LV_OBJ_FLAG_HIDDEN);
    if(timer_select != 0)
    {
        minute_zone_timer[timer_select - 1] = 0;
    }
    else
    {
        stop_minute_minder();
    }
    buzzer_beep();
}
/*******************************************************************************/
void click_warm_btn(void)
{
    uint8_t index = system_obj.select_pan - 1;
    if(button_ignore_count)
    {
        return;
    }
    button_ignore_count = BUTTON_IGNORE_VAL;
    ++zone_keep_warm[index];
    zone_keep_warm[index] %= 4;
    if(zone_keep_warm[index])
    {
        tft_regs.read_regs.panx_value[index] = 20 + zone_keep_warm[index] * 2;
    }
    else
    {
        tft_regs.read_regs.panx_value[index] = 0;
    }
    buzzer_beep();
}
/*******************************************************************************/
void set_keypad(uint8_t key) // 8316#
{
    const uint8_t password[4] = {8, 3, 1, 6};
    static uint8_t key_index = 0;
    buzzer_beep();
    if(key == 10) //*
    {
        key_index = 0;
    }
    else if(key == 11) //#
    {
        if(key_index == 4)
        {
            tft_regs.read_regs.slave_param_bits.demo_mode_on = !tft_regs.read_regs.slave_param_bits.demo_mode_on;
#ifndef LV_USE_GUIDER_SIMULATOR
            eeprom_write(eeprom, EEPROM_SLAVE_PARAM_ID, &tft_regs.read_regs.slave_param_bits, sizeof(tft_regs.read_regs.slave_param_bits));
#endif
            if(tft_regs.read_regs.slave_param_bits.demo_mode_on)
            {
                lv_obj_clear_flag(guider_ui.menu_screen_demo_lbl, LV_OBJ_FLAG_HIDDEN);
            }
            else
            {
                lv_obj_add_flag(guider_ui.menu_screen_demo_lbl, LV_OBJ_FLAG_HIDDEN);
            }
        }
        key_index = 0;
    }
    else if(password[key_index] == key)
    {
        key_index++;
    }
    else
    {
        key_index = 0;
    }
}
/*******************************************************************************/
void pressed_service_btn(void)
{
    if(button_ignore_count)
    {
        return;
    }
    button_ignore_count = BUTTON_IGNORE_VAL;
    if(lv_obj_has_flag(guider_ui.menu_screen_keypad_btn, LV_OBJ_FLAG_HIDDEN))
    {
        lv_obj_clear_flag(guider_ui.menu_screen_keypad_btn, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(guider_ui.menu_screen_keypad_btn, LV_OBJ_FLAG_HIDDEN);
    }
    buzzer_beep();
}
/*******************************************************************************/
void wifi_deactive(void)
{
    if(wifi_state == true)
    {
        wifi_state = false;
        system_obj.lock = false;
        tft_regs.read_regs.slave_param_bits.buzzer_bit_lock = !tft_regs.read_regs.slave_param_bits.buzzer_bit_lock;
        lv_obj_add_flag(guider_ui.main_screen_count_down_label, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.main_screen_spinner_1, LV_OBJ_FLAG_HIDDEN);
        lock_slide(system_obj.lock);
    }
}
/*******************************************************************************/
void wifi_active(void)
{
    if(wifi_state == false)
    {
        wifi_state = true;
        system_obj.lock = true;
        tft_regs.read_regs.slave_param_bits.buzzer_bit_lock = !tft_regs.read_regs.slave_param_bits.buzzer_bit_lock;
        lv_obj_add_flag(guider_ui.main_screen_timer_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.main_screen_pause_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.main_screen_menu_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.main_screen_timer_spinner, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.main_screen_count_down_label, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.main_screen_spinner_1, LV_OBJ_FLAG_HIDDEN);
        lock_slide(system_obj.lock);
    }
}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
