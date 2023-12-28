/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "fsl_lpflexcomm.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.lpflexcomm"
#endif

/*!
 * @brief Used for conversion between `void*` and `uint32_t`.
 */
typedef union pvoid_to_u32
{
    void *pvoid;
    uint32_t u32;
} pvoid_to_u32_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*! @brief Set the LP_FLEXCOMM mode . */
static status_t LP_FLEXCOMM_SetPeriph(LP_FLEXCOMM_Type *base, LP_FLEXCOMM_PERIPH_T periph, int lock);

/*! @brief check whether lpflexcomm supports peripheral type */
static bool LP_FLEXCOMM_PeripheralIsPresent(LP_FLEXCOMM_Type *base, LP_FLEXCOMM_PERIPH_T periph);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! @brief Array to map LP_FLEXCOMM instance number to base address. */
static const uint32_t s_lpflexcommBaseAddrs[] = LP_FLEXCOMM_BASE_ADDRS;

/*! @brief Pointers to real IRQ handlers installed by drivers for each instance. */
static lpflexcomm_irq_handler_t s_lpflexcommIrqHandler[ARRAY_SIZE(s_lpflexcommBaseAddrs)];

/*! @brief Pointers to handles for each instance to provide context to interrupt routines */
static void *s_lpflexcommHandle[ARRAY_SIZE(s_lpflexcommBaseAddrs)];

/*! @brief Array to map LP_FLEXCOMM instance number to IRQ number. */
IRQn_Type const kFlexcommIrqs[] = LP_FLEXCOMM_IRQS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief IDs of clock for each LP_FLEXCOMM module */
static const clock_ip_name_t s_lpflexcommClocks[] = FLEXCOMM_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_FEATURE_LP_FLEXCOMM_HAS_NO_RESET) && FSL_FEATURE_LP_FLEXCOMM_HAS_NO_RESET)
/*! @brief Pointers to LP_FLEXCOMM resets for each instance. */
// static const reset_ip_name_t s_lpflexcommResets[] = LP_FLEXCOMM_RSTS; //TODO to be provided
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/* check whether lpflexcomm supports peripheral type */
static bool LP_FLEXCOMM_PeripheralIsPresent(LP_FLEXCOMM_Type *base, LP_FLEXCOMM_PERIPH_T periph)
{
    if (periph == LP_FLEXCOMM_PERIPH_NONE)
    {
        return true;
    }
    else if (periph <= LP_FLEXCOMM_PERIPH_LPI2C)
    {
        return (base->PSELID & (1UL << ((uint32_t)periph + 3U))) > 0UL ? true : false;
    }
    else
    {
        return false;
    }
}

/* Get the index corresponding to the LP_FLEXCOMM */
/*! brief Returns instance number for LP_FLEXCOMM module with given base address. */
uint32_t LP_FLEXCOMM_GetInstance(void *base)
{
    uint32_t i;
    pvoid_to_u32_t BaseAddr;
    BaseAddr.pvoid = base;

    for (i = 0U; i < (uint32_t)ARRAY_SIZE(s_lpflexcommBaseAddrs); i++)
    {
        if (BaseAddr.u32 == s_lpflexcommBaseAddrs[i])
        {
            break;
        }
    }

    assert(i < (uint32_t)ARRAY_SIZE(s_lpflexcommBaseAddrs));
    return i;
}

/* Changes LP_FLEXCOMM mode */
static status_t LP_FLEXCOMM_SetPeriph(LP_FLEXCOMM_Type *base, LP_FLEXCOMM_PERIPH_T periph, int lock)
{
    assert(periph <= LP_FLEXCOMM_PERIPH_LPI2C);

    /* Check whether peripheral type is present */
    if (!LP_FLEXCOMM_PeripheralIsPresent(base, periph))
    {
        return kStatus_OutOfRange;
    }

    /* Flexcomm is locked to different peripheral type than expected  */
    if (((base->PSELID & LP_FLEXCOMM_PSELID_LOCK_MASK) != 0U) &&
        ((base->PSELID & LP_FLEXCOMM_PSELID_PERSEL_MASK) != (uint32_t)periph))
    {
        return kStatus_Fail;
    }

    /* Check if we are asked to lock */
    if (lock != 0)
    {
        base->PSELID = (uint32_t)periph | LP_FLEXCOMM_PSELID_LOCK_MASK;
    }
    else
    {
        base->PSELID = (uint32_t)periph;
    }

    return kStatus_Success;
}

/*! brief Initializes LP_FLEXCOMM and selects peripheral mode according to the second parameter. */
status_t LP_FLEXCOMM_Init(void *base, LP_FLEXCOMM_PERIPH_T periph)
{
    uint32_t idx = LP_FLEXCOMM_GetInstance(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the peripheral clock */
    CLOCK_EnableClock(s_lpflexcommClocks[idx]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_FEATURE_LP_FLEXCOMM_HAS_NO_RESET) && FSL_FEATURE_LP_FLEXCOMM_HAS_NO_RESET)
    /* Reset the LP_FLEXCOMM module */
//    RESET_PeripheralReset(s_lpflexcommResets[idx]);  //TODO to be provided
#endif

    /* Set the LP_FLEXCOMM to given peripheral */
    return LP_FLEXCOMM_SetPeriph((LP_FLEXCOMM_Type *)base, periph, 0);
}

/*! brief Deinitializes LP_FLEXCOMM. */
void LP_FLEXCOMM_Deinit(void *base)
{
    uint32_t idx = LP_FLEXCOMM_GetInstance(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the peripheral clock */
    CLOCK_DisableClock(s_lpflexcommClocks[idx]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*! brief Sets IRQ handler for given LP_FLEXCOMM module. It is used by drivers register IRQ handler according to
 * LP_FLEXCOMM mode */
void LP_FLEXCOMM_SetIRQHandler(void *base, lpflexcomm_irq_handler_t handler, void *lpflexcommHandle)
{
    uint32_t instance;

    /* Look up instance number */
    instance = LP_FLEXCOMM_GetInstance(base);

    /* Clear handler first to avoid execution of the handler with wrong handle */
    s_lpflexcommIrqHandler[instance] = NULL;
    s_lpflexcommHandle[instance]     = lpflexcommHandle;
    s_lpflexcommIrqHandler[instance] = handler;
}

/* IRQ handler functions overloading weak symbols in the startup */
#if defined(LP_FLEXCOMM0)
void LP_FLEXCOMM0_DriverIRQHandler(void);
void LP_FLEXCOMM0_DriverIRQHandler(void)
{
    uint32_t instance;

    /* Look up instance number */
    instance = LP_FLEXCOMM_GetInstance(LP_FLEXCOMM0);
    assert(s_lpflexcommIrqHandler[instance] != NULL);
    s_lpflexcommIrqHandler[instance]((uint32_t *)s_lpflexcommBaseAddrs[instance], s_lpflexcommHandle[instance]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(LP_FLEXCOMM1)
void LP_FLEXCOMM1_DriverIRQHandler(void);
void LP_FLEXCOMM1_DriverIRQHandler(void)
{
    uint32_t instance;

    /* Look up instance number */
    instance = LP_FLEXCOMM_GetInstance(LP_FLEXCOMM1);
    assert(s_lpflexcommIrqHandler[instance] != NULL);
    s_lpflexcommIrqHandler[instance]((uint32_t *)s_lpflexcommBaseAddrs[instance], s_lpflexcommHandle[instance]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(LP_FLEXCOMM2)
void LP_FLEXCOMM2_DriverIRQHandler(void);
void LP_FLEXCOMM2_DriverIRQHandler(void)
{
    uint32_t instance;

    /* Look up instance number */
    instance = LP_FLEXCOMM_GetInstance(LP_FLEXCOMM2);
    assert(s_lpflexcommIrqHandler[instance] != NULL);
    s_lpflexcommIrqHandler[instance]((uint32_t *)s_lpflexcommBaseAddrs[instance], s_lpflexcommHandle[instance]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(LP_FLEXCOMM3)
void LP_FLEXCOMM3_DriverIRQHandler(void);
void LP_FLEXCOMM3_DriverIRQHandler(void)
{
    uint32_t instance;

    /* Look up instance number */
    instance = LP_FLEXCOMM_GetInstance(LP_FLEXCOMM3);
    assert(s_lpflexcommIrqHandler[instance] != NULL);
    s_lpflexcommIrqHandler[instance]((uint32_t *)s_lpflexcommBaseAddrs[instance], s_lpflexcommHandle[instance]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(LP_FLEXCOMM4)
void LP_FLEXCOMM4_DriverIRQHandler(void);
void LP_FLEXCOMM4_DriverIRQHandler(void)
{
    uint32_t instance;

    /* Look up instance number */
    instance = LP_FLEXCOMM_GetInstance(LP_FLEXCOMM4);
    assert(s_lpflexcommIrqHandler[instance] != NULL);
    s_lpflexcommIrqHandler[instance]((uint32_t *)s_lpflexcommBaseAddrs[instance], s_lpflexcommHandle[instance]);
    SDK_ISR_EXIT_BARRIER;
}

#endif

#if defined(LP_FLEXCOMM5)
void LP_FLEXCOMM5_DriverIRQHandler(void);
void LP_FLEXCOMM5_DriverIRQHandler(void)
{
    uint32_t instance;

    /* Look up instance number */
    instance = LP_FLEXCOMM_GetInstance(LP_FLEXCOMM5);
    assert(s_lpflexcommIrqHandler[instance] != NULL);
    s_lpflexcommIrqHandler[instance]((uint32_t *)s_lpflexcommBaseAddrs[instance], s_lpflexcommHandle[instance]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(LP_FLEXCOMM6)
void LP_FLEXCOMM6_DriverIRQHandler(void);
void LP_FLEXCOMM6_DriverIRQHandler(void)
{
    uint32_t instance;

    /* Look up instance number */
    instance = LP_FLEXCOMM_GetInstance(LP_FLEXCOMM6);
    assert(s_lpflexcommIrqHandler[instance] != NULL);
    s_lpflexcommIrqHandler[instance]((uint32_t *)s_lpflexcommBaseAddrs[instance], s_lpflexcommHandle[instance]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(LP_FLEXCOMM7)
void LP_FLEXCOMM7_DriverIRQHandler(void);
void LP_FLEXCOMM7_DriverIRQHandler(void)
{
    uint32_t instance;

    /* Look up instance number */
    instance = LP_FLEXCOMM_GetInstance(LP_FLEXCOMM7);
    assert(s_lpflexcommIrqHandler[instance] != NULL);
    s_lpflexcommIrqHandler[instance]((uint32_t *)s_lpflexcommBaseAddrs[instance], s_lpflexcommHandle[instance]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(LP_FLEXCOMM8)
void LP_FLEXCOMM8_DriverIRQHandler(void);
void LP_FLEXCOMM8_DriverIRQHandler(void)
{
    uint32_t instance;

    /* Look up instance number */
    instance = LP_FLEXCOMM_GetInstance(LP_FLEXCOMM8);
    assert(s_lpflexcommIrqHandler[instance] != NULL);
    s_lpflexcommIrqHandler[instance]((uint32_t *)s_lpflexcommBaseAddrs[instance], s_lpflexcommHandle[instance]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(LP_FLEXCOMM9)
void LP_FLEXCOMM9_DriverIRQHandler(void);
void LP_FLEXCOMM9_DriverIRQHandler(void)
{
    uint32_t instance;

    /* Look up instance number */
    instance = LP_FLEXCOMM_GetInstance(LP_FLEXCOMM9);
    assert(s_lpflexcommIrqHandler[instance] != NULL);
    s_lpflexcommIrqHandler[instance]((uint32_t *)s_lpflexcommBaseAddrs[instance], s_lpflexcommHandle[instance]);
    SDK_ISR_EXIT_BARRIER;
}
#endif
