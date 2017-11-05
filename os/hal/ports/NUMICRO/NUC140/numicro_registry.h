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
 * @file    NUC140/numicro_registry.h
 * @brief   NUC140 capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef NUMICRO_REGISTRY_H_
#define NUMICRO_REGISTRY_H_

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    NUC140 capabilities
 * @{
 */

#if !defined(NUC140) || defined(__DOXYGEN__)
#define NUC140
#endif
/*===========================================================================*/
/* NUC140                                                                    */
/*===========================================================================*/
#if defined(NUC140Lxxxx) || defined(NUC140Rxxxx) || defined(NUC140Vxxxx) || \
    defined(__DOXYGEN__)

/* GPIO attributes */
#if defined(NUC140Lxxxx) || defined(NUC140Rxxxx)
#define NUMICRO_HAS_GPIOD           TRUE
#define NUMICRO_HAS_GPIOE           FALSE
#define NUMICRO_HAS_GPIOF           FALSE
#elif defined(NUC140Vxxxx)
#define NUMICRO_HAS_GPIOD           TRUE
#define NUMICRO_HAS_GPIOE           TRUE
#define NUMICRO_HAS_GPIOF           FALSE
#endif

/* EXT attributes.*/
#define NUMICRO_PORTAB_IRQ_VECTOR    Vector50
#define NUMICRO_PORTCDE_IRQ_VECTOR   Vector54

/* Serial attributes.*/
#define NUMICRO_HAS_SERIAL0         TRUE
#define NUMICRO_SERIAL0_IRQ_VECTOR  Vector70

#define NUMICRO_HAS_COMMON_SERIAL02_IRQ TRUE

#define NUMICRO_HAS_SERIAL1         TRUE
#define NUMICRO_SERIAL1_IRQ_VECTOR  Vector74

#if defined(NUC140Rxxxx) || defined(NUC140Vxxxx)
/* not yet implemented - has much less features than Serial0/1 */
#define NUMICRO_HAS_SERIAL2         TRUE
/* shares the interrupt with Serial0 */
#endif

/* USB attributes.*/
#define NUMICRO_HAS_USB             TRUE
#define NUMICRO_USB_IRQ_VECTOR      Vector9C

/**
 * @brief   Maximum endpoint address.
 */
#define USB_MAX_ENDPOINTS                   6

#endif /* NUC140 */

/** @} */

#endif /* NUMICRO_REGISTRY_H_ */

/** @} */
