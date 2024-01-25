
#ifndef PAN_PROCCES_H_
#define PAN_PROCCES_H_

#include "gui_guider.h"

/*******************************************************************************/
typedef struct
{
    uint16_t state_active   : 1,
             pan_state      : 1,
             vertical_horizontal: 1,
             circle_rectangle: 1,
             pan_size       :  2,
             reserve        : 10;
} pan_state_t;

typedef struct
{
    uint16_t x;
    uint16_t y;
    pan_state_t pan_state;
} tft_pan_registers_t;

typedef struct
{
    void *img_pan;
    void *img_ring_l;
    void *img_ring_h;
    void *obj_cont;
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
             reserved               : 11,
             surge_error            : 1,
             low_volt_freq_error    : 1,
             high_volt_freq_error   : 1;
} master_param_bits_t;

typedef struct
{
    uint16_t power_limit_0   : 1,
             power_limit_1   : 1,
             power_limit_2   : 1,
             power_limit_3   : 1,
             buzzer_bit_pause: 1,
             buzzer_bit_lock : 1,
             buzzer_bit_pan  : 1,
             reserve         : 9;
} slave_param_bits_t;

typedef struct
{
    uint16_t reserved[8];
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
    uint16_t reserved[9];
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

void system_init(void);
void set_slider(uint8_t val);
void set_select(uint8_t sel);
void refresh_display(void);
void pan_level(uint8_t sel, uint8_t level);
void click_pause(void);
void click_main_timer(void);
void long_press_lock(void);
void pressed_lock(void);
void released_lock(void);

#endif /* PAN_PROCCES */
