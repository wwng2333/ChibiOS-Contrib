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
 * @file    HT32F1655/ht32_registry.h
 * @brief   HT32F1655 capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HT32_REGISTRY_H
#define HT32_REGISTRY_H

/**
 * @brief   Sub-family identifier.
 */
#if !defined(HT32F1655) || defined(__DOXYGEN__)
#define HT32F165x
#endif

/*===========================================================================*/
/* Common features.                                                          */
/*===========================================================================*/

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    HT32F1655 capabilities
 * @{
 */
/*===========================================================================*/
/* HT32F1655                                                                 */
/*===========================================================================*/
#if defined(HT32F1655) || defined(__DOXYGEN__)

/* USB attributes.*/
#define HT32_HAS_USB                        TRUE
#define HT32_USB_IRQ_VECTOR                 Vector114

#endif /* defined(HT32F1655) */

/** @} */

#endif /* HT32_REGISTRY_H */

/** @} */
