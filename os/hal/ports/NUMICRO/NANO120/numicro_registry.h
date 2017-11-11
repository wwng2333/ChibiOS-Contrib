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
 * @file    NANO120/numicro_registry.h
 * @brief   NANO120 capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef NUMICRO_REGISTRY_H_
#define NUMICRO_REGISTRY_H_

#if !defined(NANO120) || defined(__DOXYGEN__)
#define NANO120
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/*
 * @name    NANO120 capabilities
 * @{
 */
/*===========================================================================*/
/* NANO120                                                                    */
/*===========================================================================*/
#if defined(NANO120Sxxxx) || defined(NANO120Lxxxx) || defined(NANO120Kxxxx) || \
    defined(__DOXYGEN__)

/* GPIO attributes */
#define NUMICRO_HAS_GPIOD           TRUE
#define NUMICRO_HAS_GPIOE           TRUE
#define NUMICRO_HAS_GPIOF           TRUE

/* EXT attributes.*/
#define NUMICRO_PORTAB_IRQ_VECTOR    Vector50
#define NUMICRO_PORTCDF_IRQ_VECTOR   Vector54

/* Serial attributes.*/
#define NUMICRO_HAS_SERIAL0         TRUE
#define NUMICRO_SERIAL0_IRQ_VECTOR  Vector70

#define NUMICRO_HAS_SERIAL1         TRUE
#define NUMICRO_SERIAL1_IRQ_VECTOR  Vector74

#define NUMICRO_HAS_COMMON_SERIAL02_IRQ FALSE

/* USB attributes.*/
#define NUMICRO_HAS_USB             TRUE
#define NUMICRO_USB_IRQ_VECTOR      Vector9C

/**
 * @brief   Maximum endpoint address.
 */
#define USB_MAX_ENDPOINTS                   8

#endif /* NANO120 */

/** @} */

#endif /* NUMICRO_REGISTRY_H_ */

/** @} */
