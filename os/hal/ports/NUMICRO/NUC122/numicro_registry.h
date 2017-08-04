/*
    ChibiOS - Copyright (C) 2017 Frank Zschockelt

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
 * @file    NUC122/numicro_registry.h
 * @brief   NUC122 capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef NUMICRO_REGISTRY_H_
#define NUMICRO_REGISTRY_H_

#if !defined(NUC122) || defined(__DOXYGEN__)
#define NUC122
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    NUC122 capabilities
 * @{
 */
/*===========================================================================*/
/* NUC122SC1AN/NUC122SD2AN                                                   */
/*===========================================================================*/
#if defined(NUC122SC1) || defined(NUC122SD2) || defined(__DOXYGEN__)

/* ADC attributes.*/
#define NUMICRO_HAS_ADC0            FALSE

/* EXT attributes.*/
#define NUMICRO_PORTAB_IRQ_VECTOR    Vector50
#define NUMICRO_PORTCD_IRQ_VECTOR    Vector54

/* I2C attributes.*/
#define NUMICRO_HAS_I2C0            TRUE
#define NUMICRO_I2C0_IRQ_VECTOR     Vector8C

/* Serial attributes.*/
#define NUMICRO_HAS_SERIAL0         TRUE
#define NUMICRO_SERIAL0_IRQ_VECTOR  Vector70
#define NUMICRO_HAS_SERIAL1         TRUE
#define NUMICRO_SERIAL1_IRQ_VECTOR  Vector74

/* SPI attributes.*/
#define NUMICRO_HAS_SPI0            TRUE
#define NUMICRO_SPI0_IRQ_VECTOR     Vector78
#define NUMICRO_HAS_SPI1            TRUE
#define NUMICRO_SPI1_IRQ_VECTOR     Vector7C

/* USB attributes.*/
#define NUMICRO_HAS_USB             TRUE
#define NUMICRO_USB_IRQ_VECTOR      Vector9C

#endif /* NUC122SC1 */

/** @} */

#endif /* NUMICRO_REGISTRY_H_ */

/** @} */
