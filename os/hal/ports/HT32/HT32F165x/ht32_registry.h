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
 * @file    HT32F165x/ht32_registry.h
 * @brief   HT32F165x capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HT32_REGISTRY_H
#define HT32_REGISTRY_H

/**
 * @brief   Sub-family identifier.
 */
#if defined(HT32F1653) || defined(HT32F1654) || \
    defined(HT32F1655) || defined(HT32F1656) || \
    defined(__DOXYGEN__)
#define HT32F165x
#else
#error unknown/unsupported HT32 microcontroller
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

#if defined(HT32F165x) || defined(__DOXYGEN__)

/**
 * @brief   Maximum system and core clock (f_SYS) frequency.
 */
#define HT32_SYSCLK_MAX         72000000L

/**
 * @brief   Maximum bus clock (f_BUS) frequency.
 */
#define HT32_BUSCLK_MAX         50000000L

/**
 * @brief   Maximum flash clock (f_FLASH) frequency.
 */
#define HT32_FLASHCLK_MAX       25000000L

/**
 * @name    HT32F165x attributes
 * @{
 */

/* GPIO attributes.*/
#if defined(HT32F1655) || defined(HT32F1656)
#define HT32_NUM_GPIO               5
#else
#define HT32_NUM_GPIO               4
#endif
#define HT32_GPIO_INDEX_BITS        13
#define HT32_CCR_PAEN               CKCU_AHBCCR_PAEN

#define HT32_GPIO_CLOCK_ENABLE_REG  (CKCU->AHBCCR)

/* I2C attributes.*/
#define HT32_HAS_I2C0               TRUE
#define HT32_I2C0_IRQ_VECTOR        VectorEC
#define HT32_HAS_I2C1               TRUE
#define HT32_I2C1_IRQ_VECTOR        VectorF0

/* SPI attributes.*/
#define HT32_HAS_SPI0               TRUE
#define HT32_SPI0_IRQ_VECTOR        VectorF4
#define HT32_HAS_SPI1               TRUE
#define HT32_SPI1_IRQ_VECTOR        VectorF8

/* UART attributes.*/
#define HT32_HAS_USART0             TRUE
#define HT32_USART0_IRQ_VECTOR      VectorFC
#define HT32_HAS_USART1             TRUE
#define HT32_USART1_IRQ_VECTOR      Vector100
#define HT32_HAS_UART0              TRUE
#define HT32_UART0_IRQ_VECTOR       Vector104
#define HT32_HAS_UART1              TRUE
#define HT32_UART1_IRQ_VECTOR       Vector108

/* USB attributes.*/
#define HT32_HAS_USB                TRUE
#define HT32_USB_IRQ_VECTOR         Vector114
#define HT32_USB0_IS_USBOTG         FALSE
#define HT32_HAS_USB_CLOCK_RECOVERY FALSE

#define HT32_CCR_USBEN_REG (CKCU->AHBCCR)
#define HT32_CCR_USBEN (CKCU_AHBCCR_USBEN)
 
/** @} */

#endif /* defined(HT32F165x) */

#endif /* HT32_REGISTRY_H */

/** @} */
