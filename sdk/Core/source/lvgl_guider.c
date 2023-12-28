/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "FreeRTOS.h"
#include "task.h"

#include "pin_mux.h"
#include "lvgl_support.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_lpuart.h"
#include "fsl_debug_console.h"
#include "flexio_8080_drv.h"
#include "lcd_hx8357_drv.h"
#include "fsl_inputmux.h"
#include "string.h"
#include "fsl_lpi2c.h"
#include "lvgl.h"
#include "fsl_ft5406.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define LCD_SSD1963 //ST7796S
   
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static volatile bool s_lvgl_initialized = false;
lv_ui guider_ui;

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
#if LV_USE_LOG
static void print_cb(const char *buf)
{
    PRINTF("\r%s\n", buf);
}
#endif

static void AppTask(void *param)
{
#if LV_USE_LOG
    lv_log_register_print_cb(print_cb);
#endif

    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    s_lvgl_initialized = true;

    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);

    for (;;)
    {
        lv_task_handler();
        vTaskDelay(5);
    }
}


/*!
 * @brief Main function
 */
int main(void)
{
     BaseType_t stat;

    /* Init debug lpuart. */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM6);
    CLOCK_EnableClock(kCLOCK_LPFlexComm6);
    CLOCK_EnableClock(kCLOCK_LPUart6);
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom6Clk, 0u, true);
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom6Clk, 1u, false);
        
    /* Init I2C2 for Touch, LCD, PMIC*/
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM2);
    CLOCK_EnableClock(kCLOCK_LPFlexComm2);
    CLOCK_EnableClock(kCLOCK_LPI2c2);
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom2Clk, 0u , true);
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom2Clk, 1u , false);  
    
    SYSCON->LPCAC_CTRL &= ~1;   // rocky: enable LPCAC ICache
    SYSCON->NVM_CTRL &= SYSCON->NVM_CTRL & ~(1<<2|1<<4); // enable flash Data cache       
    
    BOARD_InitPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole(); 

    /* Init FlexIO for this demo. */
    Demo_FLEXIO_8080_Init();    
    
#ifdef LCD_SSD1963  
    LCD_SSD1963_Init();  
#else    
    LCD_ST7796S_Init();
#endif    
 
    stat = xTaskCreate(AppTask, "lvgl", configMINIMAL_STACK_SIZE + 800, NULL, tskIDLE_PRIORITY + 2, NULL);

    if (pdPASS != stat)
    {
        PRINTF("Failed to create lvgl task");
        while (1)
            ;
    }

    vTaskStartScheduler();

    for (;;)
    {
    } /* should never get here */    
}


/*!
 * @brief Malloc failed hook.
 */
void vApplicationMallocFailedHook(void)
{
    for (;;)
        ;
}

/*!
 * @brief FreeRTOS tick hook.
 */
void vApplicationTickHook(void)
{
    if (s_lvgl_initialized)
    {
        lv_tick_inc(1);
    }
}

/*!
 * @brief Stack overflow hook.
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    (void)pcTaskName;
    (void)xTask;

    for (;;)
        ;
}
