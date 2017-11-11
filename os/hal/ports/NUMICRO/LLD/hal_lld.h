/*
    Copyright (C) 2017 Frank Zschockelt

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
 * @file    NUMICRO/LLD/hal_lld.h
 * @brief   NUC1xx HAL subsystem low level driver header.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HAL_LLD_H
#define HAL_LLD_H

#include "numicro_registry.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Platform identification
 * @{
 */
#if defined(__DOXYGEN__)
#define PLATFORM_NAME           "NuMicro NUC1xx"
#elif defined(NUC122Zxxxx) || defined(NUC122Lxxxx) || defined(NUC122Sxxxx)
#define PLATFORM_NAME           "NuMicro NUC122"
#elif defined(NUC123ZxxANx) || defined(NUC123LxxANx) || defined(NUC123SxxANx) || \
      defined(NUC123ZxxAEx) || defined(NUC123LxxAEx) || defined(NUC123SxxAEx)
#define PLATFORM_NAME           "NuMicro NUC123"
#elif defined(NUC140Lxxxx) || defined(NUC140Rxxxx) || defined(NUC140Vxxxx)
#define PLATFORM_NAME           "NuMicro NUC140"
#elif defined(NANO120Lxxxx) || defined(NANO120Sxxxx) || defined(NANO120Kxxxx)
#define PLATFORM_NAME           "NuMicro NANO120"
#endif

/**
 * @brief  Internal Clock Sources
 */
#define NUC1xx_HSICLK								22118400		/**< High speed internal clock. */
#define NUC1xx_LSICLK								10000				/**< Low speed internal clock.  */

/**
 * @}
 */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#include "nvic.h"


#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void numicro_clock_init(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_LLD_H */

/**
 * @}
 */
