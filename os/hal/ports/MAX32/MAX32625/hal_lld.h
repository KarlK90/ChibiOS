/*
    ChibiOS - Copyright (C) 2006..2020 Rocco Marco Guglielmi

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    MAX32625/hal_lld.h
 * @brief   MAX32625 HAL subsystem low level driver header.
 * @pre     This module requires the following macros to be defined in the
 *          @p board.h file:
 *          - MAX32_LFXTAL.
 *          .
 *          One of the following macros must also be defined:
 *          - MAX32625.
 *          .
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HAL_LLD_H
#define HAL_LLD_H

#include "max32_registry.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Platform identification macros
 * @{
 */
#if defined(MAX32625) || defined(__DOXYGEN__)
#define PLATFORM_NAME           "MAX32625 Ultra-Low-Power Arm Cortex-M4"

#else
#error "MAX32 device unsupported or not specified"
#endif
/** @} */

/**
 * @name    Absolute Maximum Ratings
 * @{
 */
/**
 * @name    Internal clock sources
 * @{
 */
#define MAX32_SRO               96000000    /**< System Relaxation Oscillator. */
#define MAX32_RTC               32768       /**< Real Time Clock.  */
/** @} */

/**
 * @name    CLKMAN_SYS_CLK_CTRL_0_CM4 bit definition
 * @{
 */
#define MAX32_CM4_DIV1          (1 << 0)    /**< Clock divided by 1.        */
#define MAX32_CM4_DIV2          (2 << 0)    /**< Clock divided by 2.        */
#define MAX32_CM4_DIV4          (3 << 0)    /**< Clock divided by 4.        */
#define MAX32_CM4_DIV8          (4 << 0)    /**< Clock divided by 8.        */
#define MAX32_CM4_DIV16         (5 << 0)    /**< Clock divided by 16.       */
#define MAX32_CM4_DIV32         (6 << 0)    /**< Clock divided by 32.       */
#define MAX32_CM4_DIV64         (7 << 0)    /**< Clock divided by 64.       */
#define MAX32_CM4_DIV128        (8 << 0)    /**< Clock divided by 128.      */
#define MAX32_CM4_DIV256        (9 << 0)    /**< Clock divided by 256.      */
/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   Disables the CA initialization in the HAL.
 */
#if !defined(MAX32_NO_INIT) || defined(__DOXYGEN__)
#define MAX32_NO_INIT                       FALSE
#endif

/**
 * @brief   Main Core clock divider.
 */
#if !defined(MAX32_CM4_DIV1) || defined(__DOXYGEN__)
#define MAX32_CM4_DIV                       MAX32_CM4_DIV1
#endif
/** @} */
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
#if !defined(MAX32625_MCUCONF)
#error "Using a wrong mcuconf.h file, MAX32625_MCUCONF not defined"
#endif

/**
 * @brief   Main core frequency.
 */
#if (MAX32_CM4_DIV == MAX32_CM4_DIV1) || defined(__DOXYGEN__)
#define MAX32_SYSCLK                (MAX32_SRO / 1)
#elif MAX32_CM4_DIV == MAX32_CM4_DIV2
#define MAX32_SYSCLK                (MAX32_SRO / 2)
#elif MAX32_CM4_DIV == MAX32_CM4_DIV4
#define MAX32_SYSCLK                (MAX32_SRO / 4)
#elif MAX32_CM4_DIV == MAX32_CM4_DIV8
#define MAX32_SYSCLK                (MAX32_SRO / 8)
#elif MAX32_CM4_DIV == MAX32_CM4_DIV16
#define MAX32_SYSCLK                (MAX32_SRO / 16)
#elif MAX32_CM4_DIV == MAX32_CM4_DIV32
#define MAX32_SYSCLK                (MAX32_SRO / 32)
#elif MAX32_CM4_DIV == MAX32_CM4_DIV64
#define MAX32_SYSCLK                (MAX32_SRO / 64)
#elif MAX32_CM4_DIV == MAX32_CM4_DIV128
#define MAX32_SYSCLK                (MAX32_SRO / 128)
#elif MAX32_CM4_DIV == MAX32_CM4_DIV256
#define MAX32_SYSCLK                (MAX32_SRO / 256)
#else
#error "invalid MAX32_CM4_DIV value specified"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Various helpers.*/
#include "nvic.h"
#include "cache.h"
#include "max32_isr.h"

#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void max32_clock_init(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_LLD_H */

/** @} */
