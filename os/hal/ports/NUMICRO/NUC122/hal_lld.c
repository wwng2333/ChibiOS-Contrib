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
 * @file    NUMICRO/NUC122/hal_lld.c
 * @brief   NUC122 HAL Driver subsystem low level driver source.
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
  UNLOCKREG();

  /* enable internal osc and low frequency osc*/
  CLK->PWRCON = CLK_PWRCON_PD_WU_DLY_Msk | CLK_PWRCON_OSC22M_EN_Msk;

  while ((CLK->CLKSTATUS & CLK_CLKSTATUS_OSC22M_STB_Msk) == 0)
    ;

  /* configure the PLL */
  /* page 108/109 of NUC122 Technical Reference Manual */
  /* PLL =~ 239.98464Mhz */
  CLK->PLLCON = (215 << CLK_PLLCON_FB_DV_Pos) | (8 <<CLK_PLLCON_IN_DV_Pos) | (1<<CLK_PLLCON_OUT_DV_Pos) | CLK_PLLCON_PLL_SRC_Msk;

  /* HCLK =~ 59.99616 MHz, USB_CLK =~ 47.996928 MHz */
  CLK->CLKDIV = (3 << CLK_CLKDIV_HCLK_N_Pos) | (4 << CLK_CLKDIV_USB_N_Pos);

  /* enable pll */
  CLK->PLLCON &= ~(CLK_PLLCON_OE_Msk | CLK_PLLCON_PD_Msk);

  while ((CLK->CLKSTATUS & CLK_CLKSTATUS_PLL_STB_Msk) == 0)
    ;

  /* Switch to PLL as clock source*/
  CLK->CLKSEL0 = (2 << CLK_CLKSEL0_HCLK_S_Pos) | (7 << CLK_CLKSEL0_STCLK_S_Pos);
}

/**
 * @}
 */
