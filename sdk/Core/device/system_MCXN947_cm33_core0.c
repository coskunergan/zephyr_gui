/*
** ###################################################################
**     Processors:          MCXN947VDF_cm33_core0
**                          MCXN947VNL_cm33_core0
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**                          MCUXpresso Compiler
**
**     Reference manual:    N9xx DraftA Rev0 2021 Aug
**     Version:             rev. 1.0, 2021-08-03
**     Build:               b220701
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2022 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-08-03)
**         Initial version based on SPEC1.6
**
** ###################################################################
*/

/*!
 * @file MCXN947_cm33_core0
 * @version 1.0
 * @date 2021-08-03
 * @brief Device specific configuration file for MCXN947_cm33_core0
 *        (implementation file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#include <stdint.h>
#include "fsl_device_registers.h"

/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;

/* ----------------------------------------------------------------------------
   -- SystemInit()
   ---------------------------------------------------------------------------- */

__attribute__((weak)) void SystemInit(void)
{
#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
    SCB->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2)); /* set CP10, CP11 Full Access in Secure mode */
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    SCB_NS->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2)); /* set CP10, CP11 Full Access in Non-secure mode */
#endif                                                    /* (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */
#endif                                                    /* ((__FPU_PRESENT == 1) && (__FPU_USED == 1)) */

    SCB->NSACR |= ((3UL << 0) | (3UL << 10)); /* enable CP0, CP1, CP10, CP11 Non-secure Access */

#if defined(__MCUXPRESSO)
    extern void (*const g_pfnVectors[])(void);
    SCB->VTOR = (uint32_t)&g_pfnVectors;
#else
    extern void *__Vectors;
    SCB->VTOR = (uint32_t)&__Vectors;
#endif

    SystemInitHook();
}

/* ----------------------------------------------------------------------------
   -- SystemCoreClockUpdate()
   ---------------------------------------------------------------------------- */

void SystemCoreClockUpdate(void)
{
}

/* ----------------------------------------------------------------------------
   -- SystemInitHook()
   ---------------------------------------------------------------------------- */

__attribute__((weak)) void SystemInitHook(void)
{
    /* Void implementation of the weak function. */
}
