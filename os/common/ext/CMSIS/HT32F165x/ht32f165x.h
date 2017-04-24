/*
 * Copyright (C) 2014-2016 Fabio Utzig, http://fabioutzig.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _HT32F165x_H_
#define _HT32F165x_H_

#define HT32

/*
 * ==============================================================
 * ---------- Interrupt Number Definition -----------------------
 * ==============================================================
 */
typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ****************/
    InitialSP_IRQn                = -16,
    InitialPC_IRQn                = -15,
    NonMaskableInt_IRQn           = -14,
    HardFault_IRQn                = -13,
    MemoryManagement_IRQn         = -12,
    BusFault_IRQn                 = -11,
    UsageFault_IRQn               = -10,

    SVCall_IRQn                   = -5,
    DebugMonitor_IRQn             = -4,

    PendSV_IRQn                   = -2,
    SysTick_IRQn                  = -1,

/******  HT32F165x Specific Interrupt Numbers ***********************/
    CKRDY_IRQn                    = 0,
    LVD_IRQn                      = 1,
    BOD_IRQn                      = 2,
    WDT_IRQn                      = 3,
    RTC_IRQn                      = 4,
    FMC_IRQn                      = 5,
    EVWUP_IRQn                    = 6,
    LPWUP_IRQn                    = 7,
    EXTI0_IRQn                    = 8,
    EXTI1_IRQn                    = 9,
    EXTI2_IRQn                    = 10,
    EXTI3_IRQn                    = 11,
    EXTI4_IRQn                    = 12,
    EXTI5_IRQn                    = 13,
    EXTI6_IRQn                    = 14,
    EXTI7_IRQn                    = 15,
    EXTI8_IRQn                    = 16,
    EXTI9_IRQn                    = 17,
    EXTI10_IRQn                   = 18,
    EXTI11_IRQn                   = 19,
    EXTI12_IRQn                   = 20,
    EXTI13_IRQn                   = 21,
    EXTI14_IRQn                   = 22,
    EXTI15_IRQn                   = 23,
    COMP_IRQn                     = 24,
    ADC_IRQn                      = 25,

    MCTM0_BRK_IRQn                = 27,
    MCTM0_UP_IRQn                 = 28,
    MCTM0_TR_UP2_IRQn             = 29,
    MCTM0_CC_IRQn                 = 30,
    MCTM1_BRK_IRQn                = 31,
    MCTM1_UP_IRQn                 = 32,
    MCTM1_TR_UP2_IRQn             = 33,
    MCTM1_CC_IRQn                 = 34,
    GPTM0_IRQn                    = 35,
    GPTM1_IRQn                    = 36,

    BFTM0_IRQn                    = 41,
    BFTM1_IRQn                    = 42,
    I2C0_IRQn                     = 43,
    I2C1_IRQn                     = 44,
    SPI0_IRQn                     = 45,
    SPI1_IRQn                     = 46,
    USART0_IRQn                   = 47,
    USART1_IRQn                   = 48,
    UART0_IRQn                    = 49,
    UART1_IRQn                    = 50,
    SCI_IRQn                      = 51,
    I2C_IRQn                      = 52,
    USB_IRQn                      = 53,

    PDMA_CH0_IRQn                 = 55,
    PDMA_CH1_IRQn                 = 56,
    PDMA_CH2_IRQn                 = 57,
    PDMA_CH3_IRQn                 = 58,
    PDMA_CH4_IRQn                 = 59,
    PDMA_CH5_IRQn                 = 60,
    PDMA_CH6_IRQn                 = 61,
    PDMA_CH7_IRQn                 = 62,

    EBI_IRQn                      = 68,
} IRQn_Type;

/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/**
 * @brief HT32F165x Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
#define __FPU_PRESENT           0
#define __MPU_PRESENT           0
#define __NVIC_PRIO_BITS        4
#define __Vendor_SysTickConfig  0
#define __CM3_REV               0x0201

#include "core_cm3.h"           /* Cortex-M3 processor and core peripherals */

#endif
