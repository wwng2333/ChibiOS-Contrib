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
 * @file    NUMICRO/LLD/hal_lld.c
 * @brief   NUC1xx HAL Driver subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

#if !defined(PWRCON_VAL_OSC_XTL)

#if defined(NUMICRO_CLK_PLL_48MHz_XTL12M)
/* configure clock with external 12M crystal for 48MHz*/
#define PWRCON_VAL_OSC_XTL \
  (CLK_PWRCON_OSC22M_EN_Msk | CLK_PWRCON_XTL12M_EN_Msk)
#define PLLCON_FB_DV 30
#define PLLCON_IN_DV 0
#define PLLCON_OUT_DV 3
#define PLLCON_VAL (PLLCON_FB_DV << CLK_PLLCON_FB_DV_Pos) | \
  (PLLCON_IN_DV << CLK_PLLCON_IN_DV_Pos) | \
  (PLLCON_OUT_DV << CLK_PLLCON_OUT_DV_Pos)
#else
/* configure clock with internal 22.184MHz oscillator for ~48.06MHz */
#define PWRCON_VAL_OSC_XTL CLK_PWRCON_OSC22M_EN_Msk
#define PLLCON_FB_DV 111
#define PLLCON_IN_DV 11
#define PLLCON_OUT_DV 3
#define PLLCON_VAL (PLLCON_FB_DV << CLK_PLLCON_FB_DV_Pos) | \
  (PLLCON_IN_DV << CLK_PLLCON_IN_DV_Pos) | \
  (PLLCON_OUT_DV << CLK_PLLCON_OUT_DV_Pos) | \
  CLK_PLLCON_PLL_SRC_Msk
#endif

#endif

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void)
{
}

void numicro_clock_init(void)
{
#if !defined(NUMICRO_NO_CLK_INIT)
  SYS_UnlockReg(); // for NUC121

  CLK->PWRCON |= CLK_PWRCTL_HIRCEN_Msk; //Enable HIRC clock (Internal RC 48 MHz)
  while (!(CLK->CLKSTATUS & CLK_STATUS_HIRCSTB_Msk)); //Wait for HIRC clock ready

  LOCKREG();
#endif
}

/**
 * @}
 */
