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

#include "hal.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)

/**
 * @brief   PAL setup.
 * @details Digital I/O ports static configuration as defined in @p board.h.
 *          This variable is used by the HAL when initializing the PAL driver.
 */

const PALConfig pal_default_config =
{
  .ioport1_pmd = 0xFFffFdff,
  .ioport2_pmd = 0xFFffFFff,
  .ioport3_pmd = 0xFFffFFff,
  .ioport4_pmd = 0xFFffFFff,
  .ioport5_pmd = 0xFFffFFff,
};
#endif

/**
 * @brief   Early initialization code.
 * @details This initialization is performed just after reset before BSS and
 *          DATA segments initialization.
 */
void __early_init(void)
{
}

/**
 * @brief   Late initialization code.
 * @note    This initialization is performed after BSS and DATA segments
 *          initialization and before invoking the main() function.
 */
void boardInit(void)
{
}
