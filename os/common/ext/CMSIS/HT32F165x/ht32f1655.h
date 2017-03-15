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

#ifndef _HT32F1655_H_
#define _HT32F1655_H_

#include "ht32f165x.h"
#include "ht32f1655_reg.h"

#define FLASH_SIZE      0x20000 // 128k
#define SRAM_SIZE       0x8000  // 32k

/****************************************************************/
/*                  Peripheral memory map                       */
/****************************************************************/
#define USART0_BASE             ((uint32_t)0x40000000)
#define UART0_BASE              ((uint32_t)0x40001000)
#define SPI0_BASE               ((uint32_t)0x40004000)
#define ADC_BASE                ((uint32_t)0x40010000)
#define CMP_BASE                ((uint32_t)0x40018000)
#define OPA_BASE                ((uint32_t)0x40018000)
#define AFIO_BASE               ((uint32_t)0x40022000)
#define EXTI_BASE               ((uint32_t)0x40024000)
#define I2S_BASE                ((uint32_t)0x40026000)
#define MCTM0_BASE              ((uint32_t)0x4002C000)
#define MCTM1_BASE              ((uint32_t)0x4002D000)

#define USART1_BASE             ((uint32_t)0x40040000)
#define UART1_BASE              ((uint32_t)0x40041000)
#define SCI_BASE                ((uint32_t)0x40043000)
#define SPI1_BASE               ((uint32_t)0x40044000)
#define I2C0_BASE               ((uint32_t)0x40048000)
#define I2C1_BASE               ((uint32_t)0x40049000)
#define WDT_BASE                ((uint32_t)0x40068000)
#define RTC_BASE                ((uint32_t)0x4006A000)
#define PWRCU_BASE              ((uint32_t)0x4006A000)
#define GPTM0_BASE              ((uint32_t)0x4006E000)
#define GPTM1_BASE              ((uint32_t)0x4006F000)
#define BFTM0_BASE              ((uint32_t)0x40076000)
#define BFTM1_BASE              ((uint32_t)0x40077000)

#define FMC_BASE                ((uint32_t)0x40080000)
#define CKCU_BASE               ((uint32_t)0x40088000)
#define RSTCU_BASE              ((uint32_t)0x40088000)
#define CRC_BASE                ((uint32_t)0x4008A000)
#define PDMA_BASE               ((uint32_t)0x40090000)
#define EBI_BASE                ((uint32_t)0x40098000)
#define USB_BASE                ((uint32_t)0x400A8000)
#define USB_SRAM_BASE           ((uint32_t)0x400AA000)
#define GPIO_A_BASE             ((uint32_t)0x400B0000)
#define GPIO_B_BASE             ((uint32_t)0x400B2000)
#define GPIO_C_BASE             ((uint32_t)0x400B4000)
#define GPIO_D_BASE             ((uint32_t)0x400B6000)
#define GPIO_E_BASE             ((uint32_t)0x400B8000)

/****************************************************************/
/*                 Peripheral declaration                       */
/****************************************************************/
//#define USART0                  ((USART_map *)  USART0_BASE)
//#define UART0                   ((UART_map *)   UART0_BASE)
#define SPI0                    ((SPI0_map *)   SPI0_BASE)
//#define ADC                     ((ADC_map *)    ADC_BASE)
//#define CMP                     ((CMP_map *)    CMP_BASE)
//#define OPA                     ((OPA_map *)    OPA_BASE)
#define AFIO                    ((AFIO_map *)   AFIO_BASE)
//#define EXTI                    ((EXTI_map *)   EXTI_BASE)
//#define I2S                     ((I2S_map *)    I2S_BASE)
//#define MCTM0                   ((MCTM_map *)   MCTM0_BASE)
//#define MCTM1                   ((MCTM_map *)   MCTM1_BASE)

//#define USART1                  ((USART_map *)  USART1_BASE)
//#define UART1                   ((UART_map *)   UART1_BASE)
//#define SCI                     ((SCI_map *)    SCI_BASE)
#define SPI1                    ((SPI_map *)    SPI1_BASE)
//#define I2C0                    ((I2C_map *)    I2C0_BASE)
//#define I2C1                    ((I2C_map *)    I2C1_BASE)
#define WDT                     ((WDT_map *)    WDT_BASE)
//#define RTC                     ((RTC_map *)    RTC_BASE)
#define PWRCU                   ((PWRCU_map *)  PWRCU_BASE)
#define GPTM0                   ((GPTM_map *)   GPTM0_BASE)
#define GPTM1                   ((GPTM_map *)   GPTM1_BASE)
//#define BFTM0                   ((BFTM_map *)   BFTM0_BASE)
//#define BFTM1                   ((BFTM_map *)   BFTM1_BASE)

#define FMC                     ((FMC_map *)    FMC_BASE)
#define CKCU                    ((CKCU_map *)   CKCU_BASE)
#define RSTCU                   ((RSTCU_map *)  RSTCU_BASE)
//#define CRC                     ((CRC_map *)    CRC_BASE)
//#define PDMA                    ((PDMA_map *)   PDMA_BASE)
//#define EBI                     ((EBI_map *)    EBI_BASE)
#define USB                     ((USB_map *)    USB_BASE)
#define GPIO_A                  ((GPIO_map *)   GPIO_A_BASE)
#define GPIO_B                  ((GPIO_map *)   GPIO_B_BASE)
#define GPIO_C                  ((GPIO_map *)   GPIO_C_BASE)
#define GPIO_D                  ((GPIO_map *)   GPIO_D_BASE)
#define GPIO_E                  ((GPIO_map *)   GPIO_E_BASE)

#endif
