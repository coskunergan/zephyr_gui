
#ifndef PAN_PROCCES_H_
#define PAN_PROCCES_H_

#include "gui_guider.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************/
typedef struct
{
    uint16_t state_active   : 1,
             pan_state      : 1,
             vertical_horizontal: 1,
             circle_rectangle: 1,
             pan_size       :  2,
             pan_heat       :  1,
             reserve        :  9;
} pan_state_t;

typedef struct
{
    uint16_t x;
    uint16_t y;
    pan_state_t pan_state;
} tft_pan_registers_t;

typedef struct
{
    uint16_t set_value;
    void *img_pan;
    void *img_ring_l;
    void *img_ring_h;
    void *obj_cont;
    void *timer_label;
    lv_anim_t a_x;
    lv_anim_t a_y;
    tft_pan_registers_t pan;
} system_pan_registers_t;

typedef struct
{
    uint8_t select_pan;
    uint8_t slider_value;
    system_pan_registers_t pan1;
    system_pan_registers_t pan2;
    system_pan_registers_t pan3;
    system_pan_registers_t pan4;
    system_pan_registers_t pan5;
    uint16_t level_backup[5];
    bool pause;
    bool lock;
} system_obj_t;

typedef struct
{
    uint16_t onoff_state            : 1,
             logo_off_state         : 1,
             reserved               : 10,
             warning_info           : 1,
             surge_error            : 1,
             low_volt_freq_error    : 1,
             high_volt_freq_error   : 1;
} master_param_bits_t;

typedef struct
{
    uint16_t power_limit     : 4,
             buzzer_bit_pause: 1,
             buzzer_bit_lock : 1,
             buzzer_bit_pan  : 1,
             buzzer_bit_mute : 1,
             clock_updated   : 1,
             buzzer_bit_alarm: 1,
             demo_mode_on    : 1,
             chef_mode_on    : 1,
             reserve         : 4;
} slave_param_bits_t;

typedef struct
{
    uint16_t reserved[7];
    uint8_t minute;
    uint8_t hour;
    uint16_t grid_x;
    uint16_t grid_y;
    master_param_bits_t master_param_bits;
    tft_pan_registers_t pan1_regs;
    tft_pan_registers_t pan2_regs;
    tft_pan_registers_t pan3_regs;
    tft_pan_registers_t pan4_regs;
    tft_pan_registers_t pan5_regs;
    tft_pan_registers_t pan6_regs;
    tft_pan_registers_t pan7_regs;
    tft_pan_registers_t pan8_regs;
} tft_write_registers_t;

typedef struct
{
    uint16_t reserved[8];
    uint8_t minute_set;
    uint8_t hour_set;
    slave_param_bits_t slave_param_bits;
    uint16_t panx_value[5];
} tft_read_registers_t;

typedef struct
{
    uint8_t data_stream_fail   : 1,
            reserve            : 7;
} modbus_status_t;

typedef struct
{
    tft_write_registers_t write_regs;
    tft_read_registers_t read_regs;
    modbus_status_t modbus_status;
    size_t read_fail_count;
    size_t write_fail_count;
} tft_registers_t;

/*******************************************************************************/

void logo_screen_init(void);
void main_screen_init(void);
void menu_screen_init(void);
void set_slider(uint8_t val);
void set_select(uint8_t sel);
void refresh_display(void);
void click_pause(void);
void click_main_timer(void);
void long_press_lock(void);
void pressed_lock(void);
void released_lock(void);
void buzzer_beep(void);
void pressed_clock_save(void);
void pressed_setting_save(void);
void click_timer_ok_btn(void);
void click_timer_close_btn(void);
void click_warm_btn(void);
void set_keypad(uint8_t key);
void pressed_service_btn(void);
void wifi_active(void);
void wifi_deactive(void);

#ifdef __cplusplus
}
#endif

#endif /* PAN_PROCCES */
