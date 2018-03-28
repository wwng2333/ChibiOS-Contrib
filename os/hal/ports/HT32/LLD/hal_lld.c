/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

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
 * @file    hal_lld.c
 * @brief   PLATFORM HAL subsystem low level driver source.
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
void hal_lld_init(void) {
}

void ht32_clock_init(void) {
	/* XXX some assumptions here */
	/* Enable backup domain. Needed for USB. */
	CKCU->LPCR = CKCU_LPCR_BKISO;
	CKCU->APBCCR1 |= CKCU_APBCCR1_BKPREN;
	while (PWRCU->BAKTEST != 0x27)
		;
	CKCU->GCCR |= CKCU_GCCR_HSEEN;
	while ((CKCU->GCSR & CKCU_GCSR_HSERDY) == 0)
		; /* wait for HSE ready */
	CKCU->GCFGR &= ~CKCU_GCFGR_PLLSRC; /* HSE as PLL source */
	CKCU->GCCR |= CKCU_GCCR_PLLEN; /* enable PLL */
	CKCU->PLLCFGR = (CKCU->PLLCFGR & ~CKCU_PLLCFGR_PFBD_MASK) | (HT32_PLL_FBDIV << 23); /* multiply 8MHz by 18 */
	while ((CKCU->GCSR & CKCU_GCSR_PLLRDY) == 0)
		; /* wait for PLL ready */
#if HT32_CK_AHB_FREQUENCY > 48000000 && HT32_CK_AHB_FREQUENCY <= 72000000
	FMC->CFCR = (FMC->CFCR & ~FMC_CFCR_WAIT_MASK) | FMC_CFCR_WAIT_2; /* wait state for up to 72MHz */
#elif HT32_CK_AHB_FREQUENCY > 24000000
	FMC->CFCR = (FMC->CFCR & ~FMC_CFCR_WAIT_MASK) | FMC_CFCR_WAIT_1; /* wait state for up to 48MHz */
#elif HT32_CK_AHB_FREQUENCY > 1000000
	FMC->CFCR = (FMC->CFCR & ~FMC_CFCR_WAIT_MASK) | FMC_CFCR_WAIT_0; /* wait state for up to 24MHz */
#else
#error FMC wait
#endif
	CKCU->AHBCFGR = (CKCU->AHBCFGR & ~CKCU_AHBCFGR_AHBPRE_MASK) | (HT32_AHB_PRESCALER - 1); /* AHB clk = PLL/2 */
	CKCU->GCCR = (CKCU->GCCR & ~CKCU_GCCR_SW_MASK) | CKCU_GCCR_SW_PLL; /* switch to HSE via PLL */
	while ((CKCU->GCCR & CKCU_GCCR_SW_MASK) != CKCU_GCCR_SW_PLL)
		; /* wait for clock switch */
	//CKCU->GCCR &= ~CKCU_GCCR_HSIEN; /* power down HSI (but needed for flash writes) */
	//FMC->CFCR &= ~FMC_CFCR_CE; /* disable branch cache */
#if (HAL_USE_USB == TRUE)
	CKCU->GCFGR = (CKCU->GCFGR & ~CKCU_GCFGR_USBPRE_MASK) | ((HT32_USB_PRESCALER - 1) << 22);
#endif
}

/** @} */
