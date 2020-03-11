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
 * @file    NUC121/numicro_registry.h
 * @brief   NUC121 capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef NUMICRO_REGISTRY_H_
#define NUMICRO_REGISTRY_H_

#if !defined(NUC121) || defined(__DOXYGEN__)
#define NUC121
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    NUC121 capabilities
 * @{
 */
/*===========================================================================*/
/* NUC121                                                                    */
/*===========================================================================*/
#if defined(NUC121Zxxxx) || defined(NUC121Lxxxx) || defined(NUC121Sxxxx) || defined(__DOXYGEN__)

/* GPIO attributes */
#define NUMICRO_HAS_GPIOD           TRUE
#define NUMICRO_HAS_GPIOE           TRUE
#define NUMICRO_HAS_GPIOF           TRUE

/* EXT attributes.*/
#define NUMICRO_PORTAB_IRQ_VECTOR    Vector50
#define NUMICRO_PORTCD_IRQ_VECTOR    Vector54

/* Serial attributes.*/
#define NUMICRO_HAS_SERIAL0         TRUE
#define NUMICRO_SERIAL0_IRQ_VECTOR  Vector70

#define NUMICRO_HAS_COMMON_SERIAL02_IRQ FALSE

#if defined(NUC121Lxxxx) || defined(NUC121Sxxxx)
#define NUMICRO_HAS_SERIAL1         TRUE
#define NUMICRO_SERIAL1_IRQ_VECTOR  Vector74
#endif

/* USB attributes.*/
#define NUMICRO_HAS_USB             TRUE
#define NUMICRO_USB_IRQ_VECTOR      Vector9C

/**
 * @brief   Maximum endpoint address.
 */
#define USB_MAX_ENDPOINTS                   6

#endif /* NUC121 */

/** @} */

#endif /* NUMICRO_REGISTRY_H_ */

/** @} */
