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

#ifndef PWRCTL_VAL_OSC_XTL

#ifdef NUMICRO_CLK_PLL_48MHz_XTL12M
/* configure clock with external 12M crystal for 48MHz*/
#define PWRCTL_VAL_OSC_XTL (CLK_PWRCTL_HIRC_EN_Msk | CLK_PWRCTL_HXT_EN_Msk)
#define PLLCTL_FB_DV 32
#define PLLCTL_IN_DV 3
#define PLLCTL_OUT_DV 0
#define PLLCTL_VAL (PLLCTL_FB_DV << CLK_PLLCTL_FB_DV_Pos) | \
  (PLLCTL_IN_DV << CLK_PLLCTL_IN_DV_Pos) | \
  (PLLCTL_OUT_DV << CLK_PLLCTL_OUT_DV_Pos)
#else
/* configure clock with internal 22.184MHz oscillator for ~48.06MHz */
#define PWRCTL_VAL_OSC_XTL CLK_PWRCTL_HIRC_EN_Msk
#define PLLCTL_FB_DV 32
#define PLLCTL_IN_DV 3
#define PLLCTL_OUT_DV 0
#define PLLCTL_VAL (PLLCTL_FB_DV << CLK_PLLCTL_FB_DV_Pos) | \
  (PLLCTL_IN_DV << CLK_PLLCTL_IN_DV_Pos) | \
  (PLLCTL_OUT_DV << CLK_PLLCTL_OUT_DV_Pos) | \
  CLK_PLLCTL_PLL_SRC_Msk
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
#ifndef NUMICRO_NO_CLK_INIT
  UNLOCKREG();

  /* enable clock sources */
  CLK->PWRCTL = CLK_PWRCTL_WK_DLY_Msk | PWRCTL_VAL_OSC_XTL;

  /* wait until clocks are stable */
  if ((PWRCTL_VAL_OSC_XTL & CLK_PWRCTL_LIRC_EN_Msk) != 0)
    while ((CLK->CLKSTATUS & CLK_CLKSTATUS_LIRC_STB_Msk) == 0)
      ;
  if ((PWRCTL_VAL_OSC_XTL & CLK_PWRCTL_HIRC_EN_Msk) != 0)
    while ((CLK->CLKSTATUS & CLK_CLKSTATUS_HIRC_STB_Msk) == 0)
      ;
  if ((PWRCTL_VAL_OSC_XTL & CLK_PWRCTL_LXT_EN_Msk) != 0)
    while ((CLK->CLKSTATUS & CLK_CLKSTATUS_LXT_STB_Msk) == 0)
      ;
  if ((PWRCTL_VAL_OSC_XTL & CLK_PWRCTL_HXT_EN_Msk) != 0)
    while ((CLK->CLKSTATUS & CLK_CLKSTATUS_HXT_STB_Msk) == 0)
      ;

  /* configure the PLL */
  CLK->PLLCTL = PLLCTL_VAL;

  while ((CLK->CLKSTATUS & CLK_CLKSTATUS_PLL_STB_Msk) == 0)
    ;

  /* Switch to internal HIRC as HCLK and Systick clock */
  CLK->CLKSEL0 = (7 << CLK_CLKSEL0_HCLK_S_Pos);

  LOCKREG();
#endif
}

/**
 * @}
 */
