
#ifndef PAN_PROCCES_H_
#define PAN_PROCCES_H_

#include "gui_guider.h"

/*******************************************************************************/
typedef struct
{
    uint8_t select_pan;
    uint8_t slider_value;
    uint8_t flag_1: 1,
            flag_2: 1,
            flag_3: 1,
            reserve: 6;
} system_obj_t;

typedef struct
{
    uint16_t onoff_state            : 1,
             reserve                : 12,
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
    uint16_t state_active   : 1,
             pan_state      : 1,
             vertical_horizontal: 1,
             circle_rectangle: 1,
             pan_size       :  2,
             reserve        : 10;
} pan_state_t;

typedef struct
{
    uint16_t reserved[8];
    uint16_t grid_x;
    uint16_t grid_y;
    master_param_bits_t master_param_bits;
    uint16_t pan1_x;
    uint16_t pan1_y;
    pan_state_t pan1_state;
    uint16_t pan2_x;
    uint16_t pan2_y;
    pan_state_t pan2_state;
    uint16_t pan3_x;
    uint16_t pan3_y;
    pan_state_t pan3_state;
    uint16_t pan4_x;
    uint16_t pan4_y;
    pan_state_t pan4_state;
    uint16_t pan5_x;
    uint16_t pan5_y;
    pan_state_t pan5_state;
    uint16_t pan6_x;
    uint16_t pan6_y;
    pan_state_t pan6_state;
    uint16_t pan7_x;
    uint16_t pan7_y;
    pan_state_t pan7_state;
    uint16_t pan8_x;
    uint16_t pan8_y;
    pan_state_t pan8_state;
} tft_write_registers_t;

typedef struct
{
    uint16_t reserved[9];
    slave_param_bits_t slave_param_bits;
    uint16_t pan1_value;
    uint16_t pan2_value;
    uint16_t pan3_value;
    uint16_t pan4_value;
    uint16_t pan5_value;
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
}tft_registers_t;

/*******************************************************************************/

void system_init(void);
void set_slider(uint8_t val);
void set_select(uint8_t sel);
void refresh_display(void);
void pan_move(uint16_t x, uint16_t y);
void pan_level(uint8_t sel, uint8_t level);

#endif /* PAN_PROCCES */
