
#ifndef PAN_PROCCES_H_
#define PAN_PROCCES_H_

#include "gui_guider.h"

/*******************************************************************************/
typedef struct
{
    uint8_t pan_1_value;
    uint8_t pan_2_value;
    uint8_t pan_3_value;
    uint8_t pan_4_value;
    uint8_t pan_5_value;
    uint8_t select_pan;
    uint8_t slider_value;
    uint8_t flag_1: 1,
            flag_2: 1,
            flag_3: 1,
            reserve: 6;
} system_obj_t;
/*******************************************************************************/

void system_init(void);
void set_slider(uint8_t val);
void set_select(uint8_t sel);
void refresh_display(void);
void pan_move(uint16_t x, uint16_t y);
void pan_level(uint8_t sel, uint8_t level);

#endif /* PAN_PROCCES */
