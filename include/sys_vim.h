/** @file sys_vim.h
*   @brief Vectored Interrupt Module Header File
*   @date 11-Dec-2018
*   @version 04.07.01
*   
*   This file contains:
*   - VIM Type Definitions
*   - VIM General Definitions
*   .
*   which are relevant for Vectored Interrupt Controller.
*/

/* 
* Copyright (C) 2009-2018 Texas Instruments Incorporated - www.ti.com  
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


#ifndef __SYS_VIM_H__
#define __SYS_VIM_H__

#include "reg_vim.h"

/* USER CODE BEGIN (0) */
/* USER CODE END */

/* VIM General Configuration */

#define VIM_CHANNELS 128U

/* VIM Type Definitions */

/** @typedef t_isrFuncPTR
*   @brief ISR Function Pointer Type Definition
*
*   This type is used to access the ISR handler.
*/
typedef void (*t_isrFuncPTR)(void);

/* Vim Ram Definition */
/** @struct vimRam
*   @brief Vim Ram Definition
*
*   This type is used to access the Vim Ram.
*/
/** @typedef vimRAM_t
*   @brief Vim Ram Type Definition
*
*   This type is used to access the Vim Ram.
*/
typedef volatile struct vimRam
{
    t_isrFuncPTR ISR[VIM_CHANNELS];
} vimRAM_t;

#define vimRAM ((vimRAM_t *)0xFFF82000U)

// Атрибуты обработчиков прерываний.
#ifndef HANDLER_ATTR
#define HANDLER_ATTR __attribute__((weak, alias("Default_Handler")))
#endif

// Атрибуты extern обработчиков прерываний.
#ifndef EXTERN_HANDLER_ATTR
#define EXTERN_HANDLER_ATTR __attribute__((weak, interrupt("IRQ"), target("arm")))
#endif

// Обработчик по умолчанию
extern void Default_Handler(void);

//// Прерывания ядра
//extern void _c_int00(void) EXTERN_HANDLER_ATTR;         //0
//extern void undefEntry(void) EXTERN_HANDLER_ATTR;       //1
//extern void svcEntry(void) EXTERN_HANDLER_ATTR;         //2
//extern void prefetchEntry(void) EXTERN_HANDLER_ATTR;    //3
//extern void _dabort(void) EXTERN_HANDLER_ATTR;          //4
//                                                        //5
//extern void IRQEntry(void) EXTERN_HANDLER_ATTR;         //6
//extern void FIQEntry(void) EXTERN_HANDLER_ATTR;         //7


// Внешние прерывания
extern void ESM_High_level_interrupt(void) EXTERN_HANDLER_ATTR; //0
extern void RTI_compare_interrupt_0(void) EXTERN_HANDLER_ATTR; //  2
extern void RTI_compare_interrupt_1(void) EXTERN_HANDLER_ATTR; //  3
extern void RTI_compare_interrupt_2(void) EXTERN_HANDLER_ATTR; //  4
extern void RTI_compare_interrupt_3(void) EXTERN_HANDLER_ATTR; //  5
extern void RTI_overflow_interrupt_0(void) EXTERN_HANDLER_ATTR; //  6
extern void RTI_overflow_interrupt_1(void) EXTERN_HANDLER_ATTR; //  7
extern void RTI_timebase_interrupt(void) EXTERN_HANDLER_ATTR; //  8
extern void GIO_interrupt_A(void) EXTERN_HANDLER_ATTR; //  9
extern void N2HET1_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  10
extern void HTU1_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  11
extern void MIBSPI1_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  12
extern void LIN_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  13
extern void MIBADC1_event_group_interrupt(void) EXTERN_HANDLER_ATTR; //  14
extern void MIBADC1_sw_group_1_interrupt(void) EXTERN_HANDLER_ATTR; //  15
extern void DCAN1_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  16
extern void SPI2_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  17
extern void CRC_Interrupt(void) EXTERN_HANDLER_ATTR; //  19
extern void ESM_Low_level_interrupt(void) EXTERN_HANDLER_ATTR; //  20
extern void Software_interrupt(void) EXTERN_HANDLER_ATTR; //  21
extern void PMU_Interrupt(void) EXTERN_HANDLER_ATTR; //  22
extern void GIO_interrupt_B(void) EXTERN_HANDLER_ATTR; //  23
extern void N2HET1_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  24
extern void HTU1_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  25
extern void MIBSPI1_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  26
extern void LIN_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  27
extern void MIBADC1_sw_group_2_interrupt(void) EXTERN_HANDLER_ATTR; //  28
extern void DCAN1_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  29
extern void SPI2_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  30
extern void MIBADC1_magnitude_compare_interrupt(void) EXTERN_HANDLER_ATTR; //  31
extern void FTCA_interrupt(void) EXTERN_HANDLER_ATTR; //  33
extern void LFSA_interrupt(void) EXTERN_HANDLER_ATTR; //  34
extern void DCAN2_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  35
extern void MIBSPI3_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  37
extern void MIBSPI3_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  38
extern void HBCA_interrupt(void) EXTERN_HANDLER_ATTR; //  39
extern void BTCA_interrupt(void) EXTERN_HANDLER_ATTR; //  40
extern void AEMIFINT3(void) EXTERN_HANDLER_ATTR; //  41
extern void DCAN2_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  42
extern void DCAN1_IF3_interrupt(void) EXTERN_HANDLER_ATTR; //  44
extern void DCAN3_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  45
extern void DCAN2_IF3_interrupt(void) EXTERN_HANDLER_ATTR; //  46
extern void FPU_interrupt(void) EXTERN_HANDLER_ATTR; //  47
extern void SPI4_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  49
extern void MibADC2_event_group_interrupt(void) EXTERN_HANDLER_ATTR; //  50
extern void MibADC2_sw_group1_interrupt(void) EXTERN_HANDLER_ATTR; //  51
extern void MIBSPI5_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  53
extern void SPI4_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  54
extern void DCAN3_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  55
extern void MIBSPI5_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  56
extern void MibADC2_sw_group2_interrupt(void) EXTERN_HANDLER_ATTR; //  57
extern void MibADC2_magnitude_compare_interrupt(void) EXTERN_HANDLER_ATTR; //  59
extern void DCAN3_IF3_interrupt(void) EXTERN_HANDLER_ATTR; //  60
extern void FSM_DONE_interrupt(void) EXTERN_HANDLER_ATTR; //  61
extern void N2HET2_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  63
extern void SCI_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  64
extern void HTU2_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  65
extern void I2C_level_0_interrupt(void) EXTERN_HANDLER_ATTR; //  66
extern void N2HET2_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  73
extern void SCI_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  74
extern void HTU2_level_1_interrupt(void) EXTERN_HANDLER_ATTR; //  75
extern void HWA_1_INT_REQ_H(void) EXTERN_HANDLER_ATTR; //  80
extern void HWA_2_INT_REQ_H(void) EXTERN_HANDLER_ATTR; //  81
extern void DCC1_done_interrupt(void) EXTERN_HANDLER_ATTR; //  82
extern void DCC2_done_interrupt(void) EXTERN_HANDLER_ATTR; //  83
extern void PBIST_Done_Interrupt(void) EXTERN_HANDLER_ATTR; //  85
extern void HWA1_INT_REQ_L(void) EXTERN_HANDLER_ATTR; //  88
extern void HWA2_INT_REQ_L(void) EXTERN_HANDLER_ATTR; //  89
extern void ePWM1_Interrupt(void) EXTERN_HANDLER_ATTR; //  90
extern void ePWM1_Trip_Zone_Interrupt(void) EXTERN_HANDLER_ATTR; //  91
extern void ePWM2_Interrupt(void) EXTERN_HANDLER_ATTR; //  92
extern void ePWM2_Trip_Zone_Interrupt(void) EXTERN_HANDLER_ATTR; //  93
extern void ePWM3_Interrupt(void) EXTERN_HANDLER_ATTR; //  94
extern void ePWM3_Trip_Zone_Interrupt(void) EXTERN_HANDLER_ATTR; //  95
extern void ePWM4_Interrupt(void) EXTERN_HANDLER_ATTR; //  96
extern void ePWM4_Trip_Zone_Interrupt(void) EXTERN_HANDLER_ATTR; //  97
extern void ePWM5_Interrupt(void) EXTERN_HANDLER_ATTR; //  98
extern void ePWM5_Trip_Zone_Interrupt(void) EXTERN_HANDLER_ATTR; //  99
extern void ePWM6_Interrupt(void) EXTERN_HANDLER_ATTR; //  100
extern void ePWM6_Trip_Zone_Interrupt(void) EXTERN_HANDLER_ATTR; //  101
extern void ePWM7_Interrupt(void) EXTERN_HANDLER_ATTR; //  102
extern void ePWM7_Trip_Zone_Interrupt(void) EXTERN_HANDLER_ATTR; //  103
extern void eCAP1_Interrupt(void) EXTERN_HANDLER_ATTR; //  104
extern void eCAP2_Interrupt(void) EXTERN_HANDLER_ATTR; //  105
extern void eCAP3_Interrupt(void) EXTERN_HANDLER_ATTR; //  106
extern void eCAP4_Interrupt(void) EXTERN_HANDLER_ATTR; //  107
extern void eCAP5_Interrupt(void) EXTERN_HANDLER_ATTR; //  108
extern void eCAP6_Interrupt(void) EXTERN_HANDLER_ATTR; //  109
extern void eQEP1_Interrupt(void) EXTERN_HANDLER_ATTR; //  110
extern void eQEP2_Interrupt(void) EXTERN_HANDLER_ATTR; //  111

/** @enum systemInterrupt
*   @brief Alias names for clock sources
*
*   This enumeration is used to provide alias names for the clock sources:
*     - IRQ
*     - FIQ
*/
typedef enum systemInterrupt
{
    SYS_IRQ = 0U, /**< Alias for IRQ interrupt */
    SYS_FIQ = 1U  /**< Alias for FIQ interrupt */
}systemInterrupt_t;

/* Interrupt Handlers */

extern void esmHighInterrupt(void);
extern void phantomInterrupt(void);



#define VIM_PARFLG		(*(volatile uint32 *)0xFFFFFDECU)
#define VIM_PARCTL		(*(volatile uint32 *)0xFFFFFDF0U)
#define VIM_ADDERR		(*(volatile uint32 *)0xFFFFFDF4U)
#define VIM_FBPARERR	(*(volatile uint32 *)0xFFFFFDF8U)

#define VIMRAMPARLOC	(*(volatile uint32 *)0xFFF82400U)
#define VIMRAMLOC		(*(volatile uint32 *)0xFFF82000U)

/* Configuration registers */
typedef struct vim_config_reg
{
    uint32 CONFIG_FIRQPR0;
    uint32 CONFIG_FIRQPR1;
    uint32 CONFIG_FIRQPR2;
    uint32 CONFIG_FIRQPR3;
    uint32 CONFIG_REQMASKSET0;
    uint32 CONFIG_REQMASKSET1;
    uint32 CONFIG_REQMASKSET2;
    uint32 CONFIG_REQMASKSET3;
    uint32 CONFIG_WAKEMASKSET0;
    uint32 CONFIG_WAKEMASKSET1;
    uint32 CONFIG_WAKEMASKSET2;
    uint32 CONFIG_WAKEMASKSET3;
    uint32 CONFIG_CAPEVT;
    uint32 CONFIG_CHANCTRL[32U];
} vim_config_reg_t;

/* Configuration registers initial value */
#define VIM_FIRQPR0_CONFIGVALUE	( (uint32)((uint32)SYS_FIQ << 0U)\
                                | (uint32)((uint32)SYS_FIQ << 1U)\
                                | (uint32)((uint32)SYS_IRQ << 2U)\
                                | (uint32)((uint32)SYS_IRQ << 3U)\
                                | (uint32)((uint32)SYS_IRQ << 4U)\
                                | (uint32)((uint32)SYS_IRQ << 5U)\
                                | (uint32)((uint32)SYS_IRQ << 6U)\
                                | (uint32)((uint32)SYS_IRQ << 7U)\
                                | (uint32)((uint32)SYS_IRQ << 8U)\
                                | (uint32)((uint32)SYS_IRQ << 9U)\
                                | (uint32)((uint32)SYS_IRQ << 10U)\
                                | (uint32)((uint32)SYS_IRQ << 11U)\
                                | (uint32)((uint32)SYS_IRQ << 12U)\
                                | (uint32)((uint32)SYS_IRQ << 13U)\
                                | (uint32)((uint32)SYS_IRQ << 14U)\
                                | (uint32)((uint32)SYS_IRQ << 15U)\
                                | (uint32)((uint32)SYS_IRQ << 16U)\
                                | (uint32)((uint32)SYS_IRQ << 17U)\
                                | (uint32)((uint32)SYS_IRQ << 18U)\
                                | (uint32)((uint32)SYS_IRQ << 19U)\
                                | (uint32)((uint32)SYS_IRQ << 20U)\
                                | (uint32)((uint32)SYS_IRQ << 21U)\
                                | (uint32)((uint32)SYS_IRQ << 22U)\
                                | (uint32)((uint32)SYS_IRQ << 23U)\
                                | (uint32)((uint32)SYS_IRQ << 24U)\
                                | (uint32)((uint32)SYS_IRQ << 25U)\
                                | (uint32)((uint32)SYS_IRQ << 26U)\
                                | (uint32)((uint32)SYS_IRQ << 27U)\
                                | (uint32)((uint32)SYS_IRQ << 28U)\
                                | (uint32)((uint32)SYS_IRQ << 29U)\
                                | (uint32)((uint32)SYS_IRQ << 30U)\
                                | (uint32)((uint32)SYS_IRQ << 31U))
					
#define VIM_FIRQPR1_CONFIGVALUE	( (uint32)((uint32)SYS_IRQ << 0U)\
                                | (uint32)((uint32)SYS_IRQ << 1U)\
                                | (uint32)((uint32)SYS_IRQ << 2U)\
                                | (uint32)((uint32)SYS_IRQ << 3U)\
                                | (uint32)((uint32)SYS_IRQ << 4U)\
                                | (uint32)((uint32)SYS_IRQ << 5U)\
                                | (uint32)((uint32)SYS_IRQ << 6U)\
                                | (uint32)((uint32)SYS_IRQ << 7U)\
                                | (uint32)((uint32)SYS_IRQ << 8U)\
                                | (uint32)((uint32)SYS_IRQ << 9U)\
                                | (uint32)((uint32)SYS_IRQ << 10U)\
                                | (uint32)((uint32)SYS_IRQ << 11U)\
                                | (uint32)((uint32)SYS_IRQ << 12U)\
                                | (uint32)((uint32)SYS_IRQ << 13U)\
                                | (uint32)((uint32)SYS_IRQ << 14U)\
                                | (uint32)((uint32)SYS_IRQ << 15U)\
                                | (uint32)((uint32)SYS_IRQ << 16U)\
                                | (uint32)((uint32)SYS_IRQ << 17U)\
                                | (uint32)((uint32)SYS_IRQ << 18U)\
                                | (uint32)((uint32)SYS_IRQ << 19U)\
                                | (uint32)((uint32)SYS_IRQ << 20U)\
                                | (uint32)((uint32)SYS_IRQ << 21U)\
                                | (uint32)((uint32)SYS_IRQ << 22U)\
                                | (uint32)((uint32)SYS_IRQ << 23U)\
                                | (uint32)((uint32)SYS_IRQ << 24U)\
                                | (uint32)((uint32)SYS_IRQ << 25U)\
                                | (uint32)((uint32)SYS_IRQ << 26U)\
                                | (uint32)((uint32)SYS_IRQ << 27U)\
                                | (uint32)((uint32)SYS_IRQ << 28U)\
                                | (uint32)((uint32)SYS_IRQ << 29U)\
                                | (uint32)((uint32)SYS_IRQ << 30U)\
                                | (uint32)((uint32)SYS_IRQ << 31U))
					
#define VIM_FIRQPR2_CONFIGVALUE	( (uint32)((uint32)SYS_IRQ << 0U)\
                                | (uint32)((uint32)SYS_IRQ << 1U)\
                                | (uint32)((uint32)SYS_IRQ << 2U)\
                                | (uint32)((uint32)SYS_IRQ << 3U)\
                                | (uint32)((uint32)SYS_IRQ << 4U)\
                                | (uint32)((uint32)SYS_IRQ << 5U)\
                                | (uint32)((uint32)SYS_IRQ << 6U)\
                                | (uint32)((uint32)SYS_IRQ << 7U)\
                                | (uint32)((uint32)SYS_IRQ << 8U)\
                                | (uint32)((uint32)SYS_IRQ << 9U)\
                                | (uint32)((uint32)SYS_IRQ << 10U)\
                                | (uint32)((uint32)SYS_IRQ << 11U)\
                                | (uint32)((uint32)SYS_IRQ << 12U)\
                                | (uint32)((uint32)SYS_IRQ << 13U)\
                                | (uint32)((uint32)SYS_IRQ << 14U)\
                                | (uint32)((uint32)SYS_IRQ << 15U)\
                                | (uint32)((uint32)SYS_IRQ << 16U)\
                                | (uint32)((uint32)SYS_IRQ << 17U)\
                                | (uint32)((uint32)SYS_IRQ << 18U)\
                                | (uint32)((uint32)SYS_IRQ << 19U)\
                                | (uint32)((uint32)SYS_IRQ << 20U)\
                                | (uint32)((uint32)SYS_IRQ << 21U)\
                                | (uint32)((uint32)SYS_IRQ << 22U)\
                                | (uint32)((uint32)SYS_IRQ << 23U)\
                                | (uint32)((uint32)SYS_IRQ << 24U)\
                                | (uint32)((uint32)SYS_IRQ << 25U)\
					            | (uint32)((uint32)SYS_IRQ << 26U)\
                                | (uint32)((uint32)SYS_IRQ << 27U)\
                                | (uint32)((uint32)SYS_IRQ << 28U)\
                                | (uint32)((uint32)SYS_IRQ << 29U)\
                                | (uint32)((uint32)SYS_IRQ << 30U)\
                                | (uint32)((uint32)SYS_IRQ << 31U))
					
#define VIM_FIRQPR3_CONFIGVALUE	( (uint32)((uint32)SYS_IRQ << 0U)\
                                | (uint32)((uint32)SYS_IRQ << 1U)\
                                | (uint32)((uint32)SYS_IRQ << 2U)\
                                | (uint32)((uint32)SYS_IRQ << 3U)\
                                | (uint32)((uint32)SYS_IRQ << 4U)\
                                | (uint32)((uint32)SYS_IRQ << 5U)\
                                | (uint32)((uint32)SYS_IRQ << 6U)\
                                | (uint32)((uint32)SYS_IRQ << 7U)\
                                | (uint32)((uint32)SYS_IRQ << 8U)\
                                | (uint32)((uint32)SYS_IRQ << 9U)\
                                | (uint32)((uint32)SYS_IRQ << 10U)\
                                | (uint32)((uint32)SYS_IRQ << 11U)\
                                | (uint32)((uint32)SYS_IRQ << 12U)\
                                | (uint32)((uint32)SYS_IRQ << 13U)\
                                | (uint32)((uint32)SYS_IRQ << 14U)\
                                | (uint32)((uint32)SYS_IRQ << 15U)\
                                | (uint32)((uint32)SYS_IRQ << 16U)\
                                | (uint32)((uint32)SYS_IRQ << 17U)\
                                | (uint32)((uint32)SYS_IRQ << 18U)\
                                | (uint32)((uint32)SYS_IRQ << 19U)\
                                | (uint32)((uint32)SYS_IRQ << 20U)\
                                | (uint32)((uint32)SYS_IRQ << 21U)\
                                | (uint32)((uint32)SYS_IRQ << 22U)\
                                | (uint32)((uint32)SYS_IRQ << 23U)\
                                | (uint32)((uint32)SYS_IRQ << 24U)\
                                | (uint32)((uint32)SYS_IRQ << 25U)\
					            | (uint32)((uint32)SYS_IRQ << 26U)\
                                | (uint32)((uint32)SYS_IRQ << 27U)\
                                | (uint32)((uint32)SYS_IRQ << 28U)\
                                | (uint32)((uint32)SYS_IRQ << 29U)\
                                | (uint32)((uint32)SYS_IRQ << 30U)\
                                | (uint32)((uint32)SYS_IRQ << 31U))
					
#define VIM_REQMASKSET0_CONFIGVALUE	( (uint32)((uint32)1U << 0U)\
                                    | (uint32)((uint32)1U << 1U)\
                                    | (uint32)((uint32)0U << 2U)\
                                    | (uint32)((uint32)0U << 3U)\
                                    | (uint32)((uint32)0U << 4U)\
                                    | (uint32)((uint32)0U << 5U)\
                                    | (uint32)((uint32)0U << 6U)\
                                    | (uint32)((uint32)0U << 7U)\
                                    | (uint32)((uint32)0U << 8U)\
                                    | (uint32)((uint32)0U << 9U)\
                                    | (uint32)((uint32)0U << 10U)\
                                    | (uint32)((uint32)0U << 11U)\
                                    | (uint32)((uint32)0U << 12U)\
                                    | (uint32)((uint32)0U << 13U)\
                                    | (uint32)((uint32)0U << 14U)\
                                    | (uint32)((uint32)0U << 15U)\
                                    | (uint32)((uint32)0U << 16U)\
                                    | (uint32)((uint32)0U << 17U)\
                                    | (uint32)((uint32)0U << 18U)\
                                    | (uint32)((uint32)0U << 19U)\
                                    | (uint32)((uint32)0U << 20U)\
                                    | (uint32)((uint32)0U << 21U)\
                                    | (uint32)((uint32)0U << 22U)\
                                    | (uint32)((uint32)0U << 23U)\
                                    | (uint32)((uint32)0U << 24U)\
                                    | (uint32)((uint32)0U << 25U)\
                                    | (uint32)((uint32)0U << 26U)\
                                    | (uint32)((uint32)0U << 27U)\
                                    | (uint32)((uint32)0U << 28U)\
                                    | (uint32)((uint32)0U << 29U)\
                                    | (uint32)((uint32)0U << 30U)\
                                    | (uint32)((uint32)0U << 31U))
						
#define VIM_REQMASKSET1_CONFIGVALUE	( (uint32)((uint32)0U << 0U)\
                                    | (uint32)((uint32)0U << 1U)\
                                    | (uint32)((uint32)0U << 2U)\
                                    | (uint32)((uint32)0U << 3U)\
                                    | (uint32)((uint32)0U << 4U)\
                                    | (uint32)((uint32)0U << 5U)\
                                    | (uint32)((uint32)0U << 6U)\
                                    | (uint32)((uint32)0U << 7U)\
                                    | (uint32)((uint32)0U << 8U)\
                                    | (uint32)((uint32)0U << 9U)\
                                    | (uint32)((uint32)0U << 10U)\
                                    | (uint32)((uint32)0U << 11U)\
                                    | (uint32)((uint32)0U << 12U)\
                                    | (uint32)((uint32)0U << 13U)\
                                    | (uint32)((uint32)0U << 14U)\
                                    | (uint32)((uint32)0U << 15U)\
                                    | (uint32)((uint32)0U << 16U)\
                                    | (uint32)((uint32)0U << 17U)\
                                    | (uint32)((uint32)0U << 18U)\
                                    | (uint32)((uint32)0U << 19U)\
                                    | (uint32)((uint32)0U << 20U)\
                                    | (uint32)((uint32)0U << 21U)\
                                    | (uint32)((uint32)0U << 22U)\
                                    | (uint32)((uint32)0U << 23U)\
                                    | (uint32)((uint32)0U << 24U)\
                                    | (uint32)((uint32)0U << 25U)\
                                    | (uint32)((uint32)0U << 26U)\
                                    | (uint32)((uint32)0U << 27U)\
                                    | (uint32)((uint32)0U << 28U)\
                                    | (uint32)((uint32)0U << 29U)\
                                    | (uint32)((uint32)0U << 30U)\
                                    | (uint32)((uint32)0U << 31U))
						
#define VIM_REQMASKSET2_CONFIGVALUE	( (uint32)((uint32)0U << 0U)\
                                    | (uint32)((uint32)0U << 1U)\
                                    | (uint32)((uint32)0U << 2U)\
                                    | (uint32)((uint32)0U << 3U)\
                                    | (uint32)((uint32)0U << 4U)\
                                    | (uint32)((uint32)0U << 5U)\
                                    | (uint32)((uint32)0U << 6U)\
                                    | (uint32)((uint32)0U << 7U)\
                                    | (uint32)((uint32)0U << 8U)\
                                    | (uint32)((uint32)0U << 9U)\
                                    | (uint32)((uint32)0U << 10U)\
                                    | (uint32)((uint32)0U << 11U)\
                                    | (uint32)((uint32)0U << 12U)\
                                    | (uint32)((uint32)0U << 13U)\
                                    | (uint32)((uint32)0U << 14U)\
                                    | (uint32)((uint32)0U << 15U)\
                                    | (uint32)((uint32)0U << 16U)\
                                    | (uint32)((uint32)0U << 17U)\
                                    | (uint32)((uint32)0U << 18U)\
                                    | (uint32)((uint32)0U << 19U)\
                                    | (uint32)((uint32)0U << 20U)\
                                    | (uint32)((uint32)0U << 21U)\
                                    | (uint32)((uint32)0U << 22U)\
                                    | (uint32)((uint32)0U << 23U)\
                                    | (uint32)((uint32)0U << 24U)\
                                    | (uint32)((uint32)0U << 25U)\
					                | (uint32)((uint32)0U << 26U)\
                                    | (uint32)((uint32)0U << 27U)\
                                    | (uint32)((uint32)0U << 28U)\
                                    | (uint32)((uint32)0U << 29U)\
                                    | (uint32)((uint32)0U << 30U)\
                                    | (uint32)((uint32)0U << 31U))
						
#define VIM_REQMASKSET3_CONFIGVALUE	( (uint32)((uint32)0U << 0U)\
                                    | (uint32)((uint32)0U << 1U)\
                                    | (uint32)((uint32)0U << 2U)\
                                    | (uint32)((uint32)0U << 3U)\
                                    | (uint32)((uint32)0U << 4U)\
                                    | (uint32)((uint32)0U << 5U)\
                                    | (uint32)((uint32)0U << 6U)\
                                    | (uint32)((uint32)0U << 7U)\
                                    | (uint32)((uint32)0U << 8U)\
                                    | (uint32)((uint32)0U << 9U)\
                                    | (uint32)((uint32)0U << 10U)\
                                    | (uint32)((uint32)0U << 11U)\
                                    | (uint32)((uint32)0U << 12U)\
                                    | (uint32)((uint32)0U << 13U)\
                                    | (uint32)((uint32)0U << 14U)\
                                    | (uint32)((uint32)0U << 15U)\
                                    | (uint32)((uint32)0U << 16U)\
                                    | (uint32)((uint32)0U << 17U)\
                                    | (uint32)((uint32)0U << 18U)\
                                    | (uint32)((uint32)0U << 19U)\
                                    | (uint32)((uint32)0U << 20U)\
                                    | (uint32)((uint32)0U << 21U)\
                                    | (uint32)((uint32)0U << 22U)\
                                    | (uint32)((uint32)0U << 23U)\
                                    | (uint32)((uint32)0U << 24U)\
                                    | (uint32)((uint32)0U << 25U)\
						            | (uint32)((uint32)0U << 26U)\
                                    | (uint32)((uint32)0U << 27U)\
                                    | (uint32)((uint32)0U << 28U)\
                                    | (uint32)((uint32)0U << 29U)\
                                    | (uint32)((uint32)0U << 30U)\
                                    | (uint32)((uint32)0U << 31U))
						
#define VIM_WAKEMASKSET0_CONFIGVALUE	0xFFFFFFFFU
#define VIM_WAKEMASKSET1_CONFIGVALUE	0xFFFFFFFFU
#define VIM_WAKEMASKSET2_CONFIGVALUE	0xFFFFFFFFU
#define VIM_WAKEMASKSET3_CONFIGVALUE	0xFFFFFFFFU
#define VIM_CAPEVT_CONFIGVALUE	    	((uint32)((uint32)0U << 0U)|(uint32)((uint32)0U << 16U))

#define VIM_CHANCTRL0_CONFIGVALUE		0x00010203U
#define VIM_CHANCTRL1_CONFIGVALUE		0x04050607U
#define VIM_CHANCTRL2_CONFIGVALUE		0x08090A0BU
#define VIM_CHANCTRL3_CONFIGVALUE		0x0C0D0E0FU
#define VIM_CHANCTRL4_CONFIGVALUE		0x10111213U
#define VIM_CHANCTRL5_CONFIGVALUE		0x14151617U
#define VIM_CHANCTRL6_CONFIGVALUE		0x18191A1BU
#define VIM_CHANCTRL7_CONFIGVALUE		0x1C1D1E1FU
#define VIM_CHANCTRL8_CONFIGVALUE		0x20212223U
#define VIM_CHANCTRL9_CONFIGVALUE		0x24252627U
#define VIM_CHANCTRL10_CONFIGVALUE		0x28292A2BU
#define VIM_CHANCTRL11_CONFIGVALUE		0x2C2D2E2FU
#define VIM_CHANCTRL12_CONFIGVALUE		0x30313233U
#define VIM_CHANCTRL13_CONFIGVALUE		0x34353637U
#define VIM_CHANCTRL14_CONFIGVALUE		0x38393A3BU
#define VIM_CHANCTRL15_CONFIGVALUE		0x3C3D3E3FU
#define VIM_CHANCTRL16_CONFIGVALUE		0x40414243U
#define VIM_CHANCTRL17_CONFIGVALUE		0x44454647U
#define VIM_CHANCTRL18_CONFIGVALUE		0x48494A4BU
#define VIM_CHANCTRL19_CONFIGVALUE		0x4C4D4E4FU
#define VIM_CHANCTRL20_CONFIGVALUE		0x50515253U
#define VIM_CHANCTRL21_CONFIGVALUE		0x54555657U
#define VIM_CHANCTRL22_CONFIGVALUE		0x58595A5BU
#define VIM_CHANCTRL23_CONFIGVALUE		0x5C5D5E5FU
#define VIM_CHANCTRL24_CONFIGVALUE      0x60616263U
#define VIM_CHANCTRL25_CONFIGVALUE      0x64656667U
#define VIM_CHANCTRL26_CONFIGVALUE      0x68696A6BU
#define VIM_CHANCTRL27_CONFIGVALUE      0x6C6D6E6FU
#define VIM_CHANCTRL28_CONFIGVALUE      0x70717273U
#define VIM_CHANCTRL29_CONFIGVALUE      0x74757677U
#define VIM_CHANCTRL30_CONFIGVALUE      0x78797A7BU
#define VIM_CHANCTRL31_CONFIGVALUE      0x7C7D7E7FU


/**
 * @defgroup VIM VIM
 * @brief Vectored Interrupt Manager
 *
 * The vectored interrupt manager (VIM) provides hardware assistance for prioritizing and controlling the
 * many interrupt sources present on a device. Interrupts are caused by events outside of the normal flow of
 * program execution.
 *
 * Related files:
 * - reg_vim.h
 * - sys_vim.h
 * - sys_vim.c
 *
 * @addtogroup VIM
 * @{
 */
/*VIM Interface functions*/
void vimInit(void);
void vimChannelMap(uint32 request, uint32 channel, t_isrFuncPTR handler);
void vimEnableInterrupt(uint32 channel, systemInterrupt_t inttype);
void vimDisableInterrupt(uint32 channel);
void vimGetConfigValue(vim_config_reg_t *config_reg, config_value_type_t type);

extern void _Enable_Irq(void);
extern void _HW_Vec_Init(void);

/*@}*/
#endif
