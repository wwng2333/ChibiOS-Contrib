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
 * @file    NUC123/numicro_registry.h
 * @brief   NUC123 capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef NUMICRO_REGISTRY_H_
#define NUMICRO_REGISTRY_H_

#if !defined(NUC123) || defined(__DOXYGEN__)
#define NUC123
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/*
 * @name    NUC123 capabilities
 * @{
 */
/*===========================================================================*/
/* NUC123                                                                    */
/*===========================================================================*/
#if defined(NUC123ZxxANx) || defined(NUC123LxxANx) || defined(NUC123SxxANx) || \
    defined(NUC123ZxxAEx) || defined(NUC123LxxAEx) || defined(NUC123SxxAEx) || \
    defined(__DOXYGEN__)

/* GPIO attributes */
#define NUMICRO_HAS_GPIOD           TRUE
#define NUMICRO_HAS_GPIOE           FALSE
#define NUMICRO_HAS_GPIOF           TRUE

/* EXT attributes.*/
#define NUMICRO_PORTAB_IRQ_VECTOR    Vector50
#define NUMICRO_PORTCDF_IRQ_VECTOR   Vector54

/* Serial attributes.*/
#define NUMICRO_HAS_SERIAL0         TRUE
#define NUMICRO_SERIAL0_IRQ_VECTOR  Vector70


#if defined(NUC123LxxANx) || defined(NUC123SxxANx) || \
    defined(NUC123LxxAEx) || defined(NUC123SxxAEx)
#define NUMICRO_HAS_SERIAL1         TRUE
#define NUMICRO_SERIAL1_IRQ_VECTOR  Vector74
#endif

/* USB attributes.*/
#define NUMICRO_HAS_USB             TRUE
#define NUMICRO_USB_IRQ_VECTOR      Vector9C

/**
 * @brief   Maximum endpoint address.
 */
#define USB_MAX_ENDPOINTS                   8

#endif /* NUC123 */

/** @} */

#endif /* NUMICRO_REGISTRY_H_ */

/** @} */
