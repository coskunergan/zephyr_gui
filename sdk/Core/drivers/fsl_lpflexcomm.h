/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_LP_FLEXCOMM_H_
#define _FSL_LP_FLEXCOMM_H_

#include "fsl_common.h"

/*!
 * @addtogroup lpflexcomm_driver
 * @{
 */

/*! @name Driver version */
/*@{*/
/*! @brief FlexCOMM driver version. */
#define FSL_LP_FLEXCOMM_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*! @brief LP_FLEXCOMM peripheral modes. */
typedef enum
{
    LP_FLEXCOMM_PERIPH_NONE,   /*!< No peripheral */
    LP_FLEXCOMM_PERIPH_LPUART, /*!< LPUART peripheral */
    LP_FLEXCOMM_PERIPH_LPSPI,  /*!< LPSPI Peripheral */
    LP_FLEXCOMM_PERIPH_LPI2C,  /*!< LPI2C Peripheral */
} LP_FLEXCOMM_PERIPH_T;

/*! @brief Typedef for interrupt handler. */
typedef void (*lpflexcomm_irq_handler_t)(void *base, void *handle);

/*! @brief Array with IRQ number for each LP_FLEXCOMM module. */
extern IRQn_Type const kFlexcommIrqs[];

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*! @brief Returns instance number for LP_FLEXCOMM module with given base address. */
uint32_t LP_FLEXCOMM_GetInstance(void *base);

/*! @brief Initializes LP_FLEXCOMM and selects peripheral mode according to the second parameter. */
status_t LP_FLEXCOMM_Init(void *base, LP_FLEXCOMM_PERIPH_T periph);

/*! @brief Deinitializes LP_FLEXCOMM. */
void LP_FLEXCOMM_Deinit(void *base);

/*! @brief Sets IRQ handler for given LP_FLEXCOMM module. It is used by drivers register IRQ handler according to
 * LP_FLEXCOMM mode */
void LP_FLEXCOMM_SetIRQHandler(void *base, lpflexcomm_irq_handler_t handler, void *lpflexcommHandle);

#if defined(__cplusplus)
}
#endif

/*@}*/

#endif /* _FSL_LP_FLEXCOMM_H_*/
