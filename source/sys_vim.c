/** @file sys_vim.c 
*   @brief VIM Driver Implementation File
*   @date 11-Dec-2018
*   @version 04.07.01
*
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



#include "sys_vim.h"
#include "system.h"
#include "esm.h"

void _Enable_Irq(void) {
__asm(" MRS R1, CPSR");
__asm(" BIC R1, R1, #0x80");
__asm(" MSR CPSR, R1");
}

void _HW_Vec_Init(void) {
__asm(" MRC p15 ,#0 ,R1 ,c1 ,c0 ,#0");
__asm(" ORR R1 ,R1 ,#0x1000000");
__asm(" MCR p15 ,#0 ,R1 ,c1 ,c0 ,#0");
}

// Реализация обработчика по-умолчанию.
#pragma CODE_STATE(__Default_Handler, 32)
#pragma INTERRUPT(__Default_Handler, IRQ)
static void __Default_Handler(void)
{
    while (1);
}

// Обработчик по-умолчанию.
void Default_Handler(void) __attribute__((weak,alias("__Default_Handler")));

//// Прерывания ядра
//void _c_int00(void) HANDLER_ATTR;       //0
//void undefEntry(void) HANDLER_ATTR;     //1
//void svcEntry(void) HANDLER_ATTR;       //2
//void prefetchEntry(void) HANDLER_ATTR;  //3
//void _dabort(void) HANDLER_ATTR;        //4
//                                        //5
//void IRQEntry(void) HANDLER_ATTR;       //6
//void FIQEntry(void) HANDLER_ATTR;       //7

// Внешние прерывания
void Phantom_interrupt(void) HANDLER_ATTR;
void ESM_High_level_interrupt(void) HANDLER_ATTR; //0
void RTI_compare_interrupt_0(void) HANDLER_ATTR; //  2
void RTI_compare_interrupt_1(void) HANDLER_ATTR; //  3
void RTI_compare_interrupt_2(void) HANDLER_ATTR; //  4
void RTI_compare_interrupt_3(void) HANDLER_ATTR; //  5
void RTI_overflow_interrupt_0(void) HANDLER_ATTR; //  6
void RTI_overflow_interrupt_1(void) HANDLER_ATTR; //  7
void RTI_timebase_interrupt(void) HANDLER_ATTR; //  8
void GIO_interrupt_A(void) HANDLER_ATTR; //  9
void N2HET1_level_0_interrupt(void) HANDLER_ATTR; //  10
void HTU1_level_0_interrupt(void) HANDLER_ATTR; //  11
void MIBSPI1_level_0_interrupt(void) HANDLER_ATTR; //  12
void LIN_level_0_interrupt(void) HANDLER_ATTR; //  13
void MIBADC1_event_group_interrupt(void) HANDLER_ATTR; //  14
void MIBADC1_sw_group_1_interrupt(void) HANDLER_ATTR; //  15
void DCAN1_level_0_interrupt(void) HANDLER_ATTR; //  16
void SPI2_level_0_interrupt(void) HANDLER_ATTR; //  17
void CRC_Interrupt(void) HANDLER_ATTR; //  19
void ESM_Low_level_interrupt(void) HANDLER_ATTR; //  20
void Software_interrupt(void) HANDLER_ATTR; //  21
void PMU_Interrupt(void) HANDLER_ATTR; //  22
void GIO_interrupt_B(void) HANDLER_ATTR; //  23
void N2HET1_level_1_interrupt(void) HANDLER_ATTR; //  24
void HTU1_level_1_interrupt(void) HANDLER_ATTR; //  25
void MIBSPI1_level_1_interrupt(void) HANDLER_ATTR; //  26
void LIN_level_1_interrupt(void) HANDLER_ATTR; //  27
void MIBADC1_sw_group_2_interrupt(void) HANDLER_ATTR; //  28
void DCAN1_level_1_interrupt(void) HANDLER_ATTR; //  29
void SPI2_level_1_interrupt(void) HANDLER_ATTR; //  30
void MIBADC1_magnitude_compare_interrupt(void) HANDLER_ATTR; //  31
void FTCA_interrupt(void) HANDLER_ATTR; //  33
void LFSA_interrupt(void) HANDLER_ATTR; //  34
void DCAN2_level_0_interrupt(void) HANDLER_ATTR; //  35
void MIBSPI3_level_0_interrupt(void) HANDLER_ATTR; //  37
void MIBSPI3_level_1_interrupt(void) HANDLER_ATTR; //  38
void HBCA_interrupt(void) HANDLER_ATTR; //  39
void BTCA_interrupt(void) HANDLER_ATTR; //  40
void AEMIFINT3(void) HANDLER_ATTR; //  41
void DCAN2_level_1_interrupt(void) HANDLER_ATTR; //  42
void DCAN1_IF3_interrupt(void) HANDLER_ATTR; //  44
void DCAN3_level_0_interrupt(void) HANDLER_ATTR; //  45
void DCAN2_IF3_interrupt(void) HANDLER_ATTR; //  46
void FPU_interrupt(void) HANDLER_ATTR; //  47
void SPI4_level_0_interrupt(void) HANDLER_ATTR; //  49
void MibADC2_event_group_interrupt(void) HANDLER_ATTR; //  50
void MibADC2_sw_group1_interrupt(void) HANDLER_ATTR; //  51
void MIBSPI5_level_0_interrupt(void) HANDLER_ATTR; //  53
void SPI4_level_1_interrupt(void) HANDLER_ATTR; //  54
void DCAN3_level_1_interrupt(void) HANDLER_ATTR; //  55
void MIBSPI5_level_1_interrupt(void) HANDLER_ATTR; //  56
void MibADC2_sw_group2_interrupt(void) HANDLER_ATTR; //  57
void MibADC2_magnitude_compare_interrupt(void) HANDLER_ATTR; //  59
void DCAN3_IF3_interrupt(void) HANDLER_ATTR; //  60
void FSM_DONE_interrupt(void) HANDLER_ATTR; //  61
void N2HET2_level_0_interrupt(void) HANDLER_ATTR; //  63
void SCI_level_0_interrupt(void) HANDLER_ATTR; //  64
void HTU2_level_0_interrupt(void) HANDLER_ATTR; //  65
void I2C_level_0_interrupt(void) HANDLER_ATTR; //  66
void N2HET2_level_1_interrupt(void) HANDLER_ATTR; //  73
void SCI_level_1_interrupt(void) HANDLER_ATTR; //  74
void HTU2_level_1_interrupt(void) HANDLER_ATTR; //  75
void HWA_1_INT_REQ_H(void) HANDLER_ATTR; //  80
void HWA_2_INT_REQ_H(void) HANDLER_ATTR; //  81
void DCC1_done_interrupt(void) HANDLER_ATTR; //  82
void DCC2_done_interrupt(void) HANDLER_ATTR; //  83
void PBIST_Done_Interrupt(void) HANDLER_ATTR; //  85
void HWA1_INT_REQ_L(void) HANDLER_ATTR; //  88
void HWA2_INT_REQ_L(void) HANDLER_ATTR; //  89
void ePWM1_Interrupt(void) HANDLER_ATTR; //  90
void ePWM1_Trip_Zone_Interrupt(void) HANDLER_ATTR; //  91
void ePWM2_Interrupt(void) HANDLER_ATTR; //  92
void ePWM2_Trip_Zone_Interrupt(void) HANDLER_ATTR; //  93
void ePWM3_Interrupt(void) HANDLER_ATTR; //  94
void ePWM3_Trip_Zone_Interrupt(void) HANDLER_ATTR; //  95
void ePWM4_Interrupt(void) HANDLER_ATTR; //  96
void ePWM4_Trip_Zone_Interrupt(void) HANDLER_ATTR; //  97
void ePWM5_Interrupt(void) HANDLER_ATTR; //  98
void ePWM5_Trip_Zone_Interrupt(void) HANDLER_ATTR; //  99
void ePWM6_Interrupt(void) HANDLER_ATTR; //  100
void ePWM6_Trip_Zone_Interrupt(void) HANDLER_ATTR; //  101
void ePWM7_Interrupt(void) HANDLER_ATTR; //  102
void ePWM7_Trip_Zone_Interrupt(void) HANDLER_ATTR; //  103
void eCAP1_Interrupt(void) HANDLER_ATTR; //  104
void eCAP2_Interrupt(void) HANDLER_ATTR; //  105
void eCAP3_Interrupt(void) HANDLER_ATTR; //  106
void eCAP4_Interrupt(void) HANDLER_ATTR; //  107
void eCAP5_Interrupt(void) HANDLER_ATTR; //  108
void eCAP6_Interrupt(void) HANDLER_ATTR; //  109
void eQEP1_Interrupt(void) HANDLER_ATTR; //  110
void eQEP2_Interrupt(void) HANDLER_ATTR; //  111


static const t_isrFuncPTR s_vim_init[VIM_CHANNELS] =
{
        &Default_Handler, //-1
        &ESM_High_level_interrupt, //  0
        &Default_Handler, //  1
        &RTI_compare_interrupt_0, //  2
        &RTI_compare_interrupt_1, //  3
        &RTI_compare_interrupt_2, //  4
        &RTI_compare_interrupt_3, //  5
        &RTI_overflow_interrupt_0, //  6
        &RTI_overflow_interrupt_1, //  7
        &RTI_timebase_interrupt, //  8
        &GIO_interrupt_A, //  9
        &N2HET1_level_0_interrupt, //  10
        &HTU1_level_0_interrupt, //  11
        &MIBSPI1_level_0_interrupt, //  12
        &LIN_level_0_interrupt, //  13
        &MIBADC1_event_group_interrupt, //  14
        &MIBADC1_sw_group_1_interrupt, //  15
        &DCAN1_level_0_interrupt, //  16
        &SPI2_level_0_interrupt, //  17
        &Default_Handler, //  18
        &CRC_Interrupt, //  19
        &ESM_Low_level_interrupt, //  20
        &Software_interrupt, //  21
        &PMU_Interrupt, //  22
        &GIO_interrupt_B, //  23
        &N2HET1_level_1_interrupt, //  24
        &HTU1_level_1_interrupt, //  25
        &MIBSPI1_level_1_interrupt, //  26
        &LIN_level_1_interrupt, //  27
        &MIBADC1_sw_group_2_interrupt, //  28
        &DCAN1_level_1_interrupt, //  29
        &SPI2_level_1_interrupt, //  30
        &MIBADC1_magnitude_compare_interrupt, //  31
        &Default_Handler, //  32
        &FTCA_interrupt, //  33
        &LFSA_interrupt, //  34
        &DCAN2_level_0_interrupt, //  35
        &Default_Handler, //  36
        &MIBSPI3_level_0_interrupt, //  37
        &MIBSPI3_level_1_interrupt, //  38
        &HBCA_interrupt, //  39
        &BTCA_interrupt, //  40
        &AEMIFINT3, //  41
        &DCAN2_level_1_interrupt, //  42
        &Default_Handler, //  43
        &DCAN1_IF3_interrupt, //  44
        &DCAN3_level_0_interrupt, //  45
        &DCAN2_IF3_interrupt, //  46
        &FPU_interrupt, //  47
        &Default_Handler, //  48
        &SPI4_level_0_interrupt, //  49
        &MibADC2_event_group_interrupt, //  50
        &MibADC2_sw_group1_interrupt, //  51
        &Default_Handler, //  52
        &MIBSPI5_level_0_interrupt, //  53
        &SPI4_level_1_interrupt, //  54
        &DCAN3_level_1_interrupt, //  55
        &MIBSPI5_level_1_interrupt, //  56
        &MibADC2_sw_group2_interrupt, //  57
        &Default_Handler, //  58
        &MibADC2_magnitude_compare_interrupt, //  59
        &DCAN3_IF3_interrupt, //  60
        &FSM_DONE_interrupt, //  61
        &Default_Handler, //  62
        &N2HET2_level_0_interrupt, //  63
        &SCI_level_0_interrupt, //  64
        &HTU2_level_0_interrupt, //  65
        &I2C_level_0_interrupt, //  66
        &Default_Handler, //  67
        &Default_Handler, //  68
        &Default_Handler, //  69
        &Default_Handler, //  70
        &Default_Handler, //  71
        &Default_Handler, //  72
        &N2HET2_level_1_interrupt, //  73
        &SCI_level_1_interrupt, //  74
        &HTU2_level_1_interrupt, //  75
        &Default_Handler, //  76
        &Default_Handler, //  77
        &Default_Handler, //  78
        &Default_Handler, //  79
        &HWA_1_INT_REQ_H, //  80
        &HWA_2_INT_REQ_H, //  81
        &DCC1_done_interrupt, //  82
        &DCC2_done_interrupt, //  83
        &Default_Handler, //  84
        &PBIST_Done_Interrupt, //  85
        &Default_Handler, //  86
        &Default_Handler, //  87
        &HWA1_INT_REQ_L, //  88
        &HWA2_INT_REQ_L, //  89
        &ePWM1_Interrupt, //  90
        &ePWM1_Trip_Zone_Interrupt, //  91
        &ePWM2_Interrupt, //  92
        &ePWM2_Trip_Zone_Interrupt, //  93
        &ePWM3_Interrupt, //  94
        &ePWM3_Trip_Zone_Interrupt, //  95
        &ePWM4_Interrupt, //  96
        &ePWM4_Trip_Zone_Interrupt, //  97
        &ePWM5_Interrupt, //  98
        &ePWM5_Trip_Zone_Interrupt, //  99
        &ePWM6_Interrupt, //  100
        &ePWM6_Trip_Zone_Interrupt, //  101
        &ePWM7_Interrupt, //  102
        &ePWM7_Trip_Zone_Interrupt, //  103
        &eCAP1_Interrupt, //  104
        &eCAP2_Interrupt, //  105
        &eCAP3_Interrupt, //  106
        &eCAP4_Interrupt, //  107
        &eCAP5_Interrupt, //  108
        &eCAP6_Interrupt, //  109
        &eQEP1_Interrupt, //  110
        &eQEP2_Interrupt, //  111
        &Default_Handler, //  112
        &Default_Handler, //  113
        &Default_Handler, //  114
        &Default_Handler, //  115
        &Default_Handler, //  116
        &Default_Handler, //  117
        &Default_Handler, //  118
        &Default_Handler, //  119
        &Default_Handler, //  120
        &Default_Handler, //  121
        &Default_Handler, //  122
        &Default_Handler, //  123
        &Default_Handler, //  124
        &Default_Handler, //  125
        &Default_Handler //  126
};

void vimParityErrorHandler(void);

/** @fn void vimInit(void)
*   @brief Initializes VIM module
*
*   This function initializes VIM RAM and registers
*/
/* SourceId : VIM_SourceId_001 */
/* DesignId : VIM_DesignId_001 */
/* Requirements : HL_SR100 */
void vimInit(void)
{
	/* VIM RAM Parity Enable */
	VIM_PARCTL = 0xAU;

	/* Initialize VIM table */
    {
        uint32 i;

        for (i = 0U; i < VIM_CHANNELS; i++)
        {
            vimRAM->ISR[i] = s_vim_init[i];
        }
    }

    /* Set Fall-Back Address Parity Error Register */
	/*SAFETYMCUSW 439 S MR:11.3 <APPROVED> " Need to store the address of a function in a 32 bit register - Advisory as per MISRA" */
    VIM_FBPARERR = (uint32)&vimParityErrorHandler;

    /* set IRQ/FIQ priorities */
    vimREG->FIRQPR0 = (uint32)((uint32)SYS_FIQ << 0U)
                    | (uint32)((uint32)SYS_FIQ << 1U)
                    | (uint32)((uint32)SYS_IRQ << 2U)
                    | (uint32)((uint32)SYS_IRQ << 3U)
                    | (uint32)((uint32)SYS_IRQ << 4U)
                    | (uint32)((uint32)SYS_IRQ << 5U)
                    | (uint32)((uint32)SYS_IRQ << 6U)
                    | (uint32)((uint32)SYS_IRQ << 7U)
                    | (uint32)((uint32)SYS_IRQ << 8U)
                    | (uint32)((uint32)SYS_IRQ << 9U)
                    | (uint32)((uint32)SYS_IRQ << 10U)
                    | (uint32)((uint32)SYS_IRQ << 11U)
                    | (uint32)((uint32)SYS_IRQ << 12U)
                    | (uint32)((uint32)SYS_IRQ << 13U)
                    | (uint32)((uint32)SYS_IRQ << 14U)
                    | (uint32)((uint32)SYS_IRQ << 15U)
                    | (uint32)((uint32)SYS_IRQ << 16U)
                    | (uint32)((uint32)SYS_IRQ << 17U)
                    | (uint32)((uint32)SYS_IRQ << 18U)
                    | (uint32)((uint32)SYS_IRQ << 19U)
                    | (uint32)((uint32)SYS_IRQ << 20U)
                    | (uint32)((uint32)SYS_IRQ << 21U)
                    | (uint32)((uint32)SYS_IRQ << 22U)
                    | (uint32)((uint32)SYS_IRQ << 23U)
                    | (uint32)((uint32)SYS_IRQ << 24U)
                    | (uint32)((uint32)SYS_IRQ << 25U)
                    | (uint32)((uint32)SYS_IRQ << 26U)
                    | (uint32)((uint32)SYS_IRQ << 27U)
                    | (uint32)((uint32)SYS_IRQ << 28U)
                    | (uint32)((uint32)SYS_IRQ << 29U)
                    | (uint32)((uint32)SYS_IRQ << 30U)
                    | (uint32)((uint32)SYS_IRQ << 31U);

    vimREG->FIRQPR1 = (uint32)((uint32)SYS_IRQ << 0U)
                    | (uint32)((uint32)SYS_IRQ << 1U)
                    | (uint32)((uint32)SYS_IRQ << 2U)
                    | (uint32)((uint32)SYS_IRQ << 3U)
                    | (uint32)((uint32)SYS_IRQ << 4U)
                    | (uint32)((uint32)SYS_IRQ << 5U)
                    | (uint32)((uint32)SYS_IRQ << 6U)
                    | (uint32)((uint32)SYS_IRQ << 7U)
                    | (uint32)((uint32)SYS_IRQ << 8U)
                    | (uint32)((uint32)SYS_IRQ << 9U)
                    | (uint32)((uint32)SYS_IRQ << 10U)
                    | (uint32)((uint32)SYS_IRQ << 11U)
                    | (uint32)((uint32)SYS_IRQ << 12U)
                    | (uint32)((uint32)SYS_IRQ << 13U)
                    | (uint32)((uint32)SYS_IRQ << 14U)
                    | (uint32)((uint32)SYS_IRQ << 15U)
                    | (uint32)((uint32)SYS_IRQ << 16U)
                    | (uint32)((uint32)SYS_IRQ << 17U)
                    | (uint32)((uint32)SYS_IRQ << 18U)
                    | (uint32)((uint32)SYS_IRQ << 19U)
                    | (uint32)((uint32)SYS_IRQ << 20U)
                    | (uint32)((uint32)SYS_IRQ << 21U)
                    | (uint32)((uint32)SYS_IRQ << 22U)
                    | (uint32)((uint32)SYS_IRQ << 23U)
                    | (uint32)((uint32)SYS_IRQ << 24U)
                    | (uint32)((uint32)SYS_IRQ << 25U)
                    | (uint32)((uint32)SYS_IRQ << 26U)
                    | (uint32)((uint32)SYS_IRQ << 27U)
                    | (uint32)((uint32)SYS_IRQ << 28U)
                    | (uint32)((uint32)SYS_IRQ << 29U)
                    | (uint32)((uint32)SYS_IRQ << 30U)
                    | (uint32)((uint32)SYS_IRQ << 31U);


    vimREG->FIRQPR2 = (uint32)((uint32)SYS_IRQ << 0U)
                    | (uint32)((uint32)SYS_IRQ << 1U)
                    | (uint32)((uint32)SYS_IRQ << 2U)
                    | (uint32)((uint32)SYS_IRQ << 3U)
                    | (uint32)((uint32)SYS_IRQ << 4U)
                    | (uint32)((uint32)SYS_IRQ << 5U)
                    | (uint32)((uint32)SYS_IRQ << 6U)
                    | (uint32)((uint32)SYS_IRQ << 7U)
                    | (uint32)((uint32)SYS_IRQ << 8U)
                    | (uint32)((uint32)SYS_IRQ << 9U)
                    | (uint32)((uint32)SYS_IRQ << 10U)
                    | (uint32)((uint32)SYS_IRQ << 11U)
                    | (uint32)((uint32)SYS_IRQ << 12U)
                    | (uint32)((uint32)SYS_IRQ << 13U)
                    | (uint32)((uint32)SYS_IRQ << 14U)
                    | (uint32)((uint32)SYS_IRQ << 15U)
                    | (uint32)((uint32)SYS_IRQ << 16U)
                    | (uint32)((uint32)SYS_IRQ << 17U)
                    | (uint32)((uint32)SYS_IRQ << 18U)
                    | (uint32)((uint32)SYS_IRQ << 19U)
                    | (uint32)((uint32)SYS_IRQ << 20U)
                    | (uint32)((uint32)SYS_IRQ << 21U)
                    | (uint32)((uint32)SYS_IRQ << 22U)
                    | (uint32)((uint32)SYS_IRQ << 23U)
                    | (uint32)((uint32)SYS_IRQ << 24U)
                    | (uint32)((uint32)SYS_IRQ << 25U)
                    | (uint32)((uint32)SYS_IRQ << 26U)
                    | (uint32)((uint32)SYS_IRQ << 27U)
                    | (uint32)((uint32)SYS_IRQ << 28U)
                    | (uint32)((uint32)SYS_IRQ << 29U)
                    | (uint32)((uint32)SYS_IRQ << 30U)
                    | (uint32)((uint32)SYS_IRQ << 31U);

    vimREG->FIRQPR3 = (uint32)((uint32)SYS_IRQ << 0U)
                    | (uint32)((uint32)SYS_IRQ << 1U)
                    | (uint32)((uint32)SYS_IRQ << 2U)
                    | (uint32)((uint32)SYS_IRQ << 3U)
                    | (uint32)((uint32)SYS_IRQ << 4U)
                    | (uint32)((uint32)SYS_IRQ << 5U)
                    | (uint32)((uint32)SYS_IRQ << 6U)
                    | (uint32)((uint32)SYS_IRQ << 7U)
                    | (uint32)((uint32)SYS_IRQ << 8U)
                    | (uint32)((uint32)SYS_IRQ << 9U)
                    | (uint32)((uint32)SYS_IRQ << 10U)
                    | (uint32)((uint32)SYS_IRQ << 11U)
                    | (uint32)((uint32)SYS_IRQ << 12U)
                    | (uint32)((uint32)SYS_IRQ << 13U)
                    | (uint32)((uint32)SYS_IRQ << 14U)
                    | (uint32)((uint32)SYS_IRQ << 15U)
                    | (uint32)((uint32)SYS_IRQ << 16U)
                    | (uint32)((uint32)SYS_IRQ << 17U)
                    | (uint32)((uint32)SYS_IRQ << 18U)
                    | (uint32)((uint32)SYS_IRQ << 19U)
                    | (uint32)((uint32)SYS_IRQ << 20U)
                    | (uint32)((uint32)SYS_IRQ << 21U)
                    | (uint32)((uint32)SYS_IRQ << 22U)
                    | (uint32)((uint32)SYS_IRQ << 23U)
                    | (uint32)((uint32)SYS_IRQ << 24U)
                    | (uint32)((uint32)SYS_IRQ << 25U)
                    | (uint32)((uint32)SYS_IRQ << 26U)
                    | (uint32)((uint32)SYS_IRQ << 27U)
                    | (uint32)((uint32)SYS_IRQ << 28U)
                    | (uint32)((uint32)SYS_IRQ << 29U)
                    | (uint32)((uint32)SYS_IRQ << 30U)
                    | (uint32)((uint32)SYS_IRQ << 31U);


    /* enable interrupts */
    vimREG->REQMASKSET0 = (uint32)((uint32)1U << 0U) /*0*/
                        | (uint32)((uint32)1U << 1U) /*1*/
                        | (uint32)((uint32)0U << 2U) /*2*/
                        | (uint32)((uint32)0U << 3U) /*3*/
                        | (uint32)((uint32)0U << 4U) /*4*/
                        | (uint32)((uint32)0U << 5U) /*5*/
                        | (uint32)((uint32)0U << 6U) /*6*/
                        | (uint32)((uint32)0U << 7U) /*7*/
                        | (uint32)((uint32)0U << 8U) /*8*/
                        | (uint32)((uint32)0U << 9U) /*9*/
                        | (uint32)((uint32)0U << 10U) /*10*/
                        | (uint32)((uint32)0U << 11U) /*11*/
                        | (uint32)((uint32)0U << 12U) /*12*/
                        | (uint32)((uint32)0U << 13U) /*13*/
                        | (uint32)((uint32)0U << 14U) /*14*/
                        | (uint32)((uint32)0U << 15U) /*15*/
                        | (uint32)((uint32)0U << 16U) /*16*/
                        | (uint32)((uint32)0U << 17U) /*17*/
                        | (uint32)((uint32)0U << 18U) /*18*/
                        | (uint32)((uint32)0U << 19U) /*19*/
                        | (uint32)((uint32)0U << 20U) /*20*/
                        | (uint32)((uint32)0U << 21U) /*21*/
                        | (uint32)((uint32)0U << 22U) /*22*/
                        | (uint32)((uint32)0U << 23U) /*GIO_interrupt_B 23*/
                        | (uint32)((uint32)1U << 24U) /*N2HET1_level_1_interrupt 24*/
                        | (uint32)((uint32)0U << 25U) /*25*/
                        | (uint32)((uint32)0U << 26U) /*26*/
                        | (uint32)((uint32)0U << 27U) /*27*/
                        | (uint32)((uint32)0U << 28U) /*28*/
                        | (uint32)((uint32)0U << 29U) /*29*/
                        | (uint32)((uint32)0U << 30U) /*30*/
                        | (uint32)((uint32)0U << 31U); /*31*/

    vimREG->REQMASKSET1 = (uint32)((uint32)0U << 0U) /*32*/
                        | (uint32)((uint32)0U << 1U) /*33*/
                        | (uint32)((uint32)0U << 2U) /*34*/
                        | (uint32)((uint32)0U << 3U) /*35*/
                        | (uint32)((uint32)0U << 4U) /*36*/
                        | (uint32)((uint32)0U << 5U) /*37*/
                        | (uint32)((uint32)0U << 6U) /*38*/
                        | (uint32)((uint32)0U << 7U) /*39*/
                        | (uint32)((uint32)0U << 8U) /*40*/
                        | (uint32)((uint32)0U << 9U) /*41*/
                        | (uint32)((uint32)0U << 10U) /*42*/
                        | (uint32)((uint32)0U << 11U) /*43*/
                        | (uint32)((uint32)0U << 12U) /*44*/
                        | (uint32)((uint32)0U << 13U) /*45*/
                        | (uint32)((uint32)0U << 14U) /*46*/
                        | (uint32)((uint32)0U << 15U) /*47*/
                        | (uint32)((uint32)0U << 16U) /*48*/
                        | (uint32)((uint32)0U << 17U) /*49*/
                        | (uint32)((uint32)0U << 18U) /*50*/
                        | (uint32)((uint32)0U << 19U) /*51*/
                        | (uint32)((uint32)0U << 20U) /*52*/
                        | (uint32)((uint32)0U << 21U) /*53*/
                        | (uint32)((uint32)0U << 22U) /*54*/
                        | (uint32)((uint32)0U << 23U) /*55*/
                        | (uint32)((uint32)0U << 24U) /*56*/
                        | (uint32)((uint32)0U << 25U) /*57*/
                        | (uint32)((uint32)0U << 26U) /*58*/
                        | (uint32)((uint32)0U << 27U) /*59*/
                        | (uint32)((uint32)0U << 28U) /*60*/
                        | (uint32)((uint32)0U << 29U) /*61*/
                        | (uint32)((uint32)0U << 30U) /*62*/
                        | (uint32)((uint32)0U << 31U); /*63*/

    vimREG->REQMASKSET2 = (uint32)((uint32)0U << 0U) /*64*/
                        | (uint32)((uint32)0U << 1U) /*65*/
                        | (uint32)((uint32)0U << 2U) /*66*/
                        | (uint32)((uint32)0U << 3U) /*67*/
                        | (uint32)((uint32)0U << 4U) /*68*/
                        | (uint32)((uint32)0U << 5U) /*69*/
                        | (uint32)((uint32)0U << 6U) /*70*/
                        | (uint32)((uint32)0U << 7U) /*71*/
                        | (uint32)((uint32)0U << 8U) /*72*/
                        | (uint32)((uint32)0U << 9U) /*73*/
                        | (uint32)((uint32)0U << 10U) /*74*/
                        | (uint32)((uint32)0U << 11U) /*75*/
                        | (uint32)((uint32)0U << 12U) /*76*/
                        | (uint32)((uint32)0U << 13U) /*77*/
                        | (uint32)((uint32)0U << 14U) /*78*/
                        | (uint32)((uint32)0U << 15U) /*79*/
                        | (uint32)((uint32)0U << 16U) /*80*/
                        | (uint32)((uint32)0U << 17U) /*81*/
                        | (uint32)((uint32)0U << 18U) /*82*/
                        | (uint32)((uint32)0U << 19U) /*83*/
                        | (uint32)((uint32)0U << 20U) /*84*/
                        | (uint32)((uint32)0U << 21U) /*85*/
                        | (uint32)((uint32)0U << 22U) /*86*/
                        | (uint32)((uint32)0U << 23U) /*87*/
                        | (uint32)((uint32)1U << 24U) /*HWA1_INT_REQ_L 88*/
                        | (uint32)((uint32)0U << 25U) /*89*/
                        | (uint32)((uint32)0U << 26U) /*90*/
                        | (uint32)((uint32)0U << 27U) /*91*/
                        | (uint32)((uint32)0U << 28U) /*92*/
                        | (uint32)((uint32)0U << 29U) /*93*/
                        | (uint32)((uint32)0U << 30U) /*94*/
                        | (uint32)((uint32)0U << 31U); /*95*/

    vimREG->REQMASKSET3 = (uint32)((uint32)0U << 0U) /*96*/
                        | (uint32)((uint32)0U << 1U) /*97*/
                        | (uint32)((uint32)0U << 2U) /*98*/
                        | (uint32)((uint32)0U << 3U) /*99*/
                        | (uint32)((uint32)0U << 4U) /*100*/
                        | (uint32)((uint32)0U << 5U) /*101*/
                        | (uint32)((uint32)0U << 6U) /*102*/
                        | (uint32)((uint32)0U << 7U) /*103*/
                        | (uint32)((uint32)0U << 8U) /*104*/
                        | (uint32)((uint32)0U << 9U) /*105*/
                        | (uint32)((uint32)0U << 10U) /*106*/
                        | (uint32)((uint32)0U << 11U) /*107*/
                        | (uint32)((uint32)0U << 12U) /*108*/
                        | (uint32)((uint32)0U << 13U) /*109*/
                        | (uint32)((uint32)0U << 14U) /*110*/
                        | (uint32)((uint32)0U << 15U) /*111*/
                        | (uint32)((uint32)0U << 16U) /*112*/
                        | (uint32)((uint32)0U << 17U) /*113*/
                        | (uint32)((uint32)0U << 18U) /*114*/
                        | (uint32)((uint32)0U << 19U) /*115*/
                        | (uint32)((uint32)0U << 20U) /*116*/
                        | (uint32)((uint32)0U << 21U) /*117*/
                        | (uint32)((uint32)0U << 22U) /*118*/
                        | (uint32)((uint32)0U << 23U) /*119*/
                        | (uint32)((uint32)0U << 24U) /*120*/
                        | (uint32)((uint32)0U << 25U) /*121*/
                        | (uint32)((uint32)0U << 26U) /*122*/
                        | (uint32)((uint32)0U << 27U) /*123*/
                        | (uint32)((uint32)0U << 28U) /*124*/
                        | (uint32)((uint32)0U << 29U) /*125*/
                        | (uint32)((uint32)0U << 30U) /*126*/
                        | (uint32)((uint32)0U << 31U); /*127*/

    /* Set Capture event sources */
	vimREG->CAPEVT = ((uint32)((uint32)0U << 0U)
	                 |(uint32)((uint32)0U << 16U));
}

/** @fn void vimChannelMap(uint32 request, uint32 channel, t_isrFuncPTR handler)
*   @brief Map selected interrupt request to the selected channel
*
*    @param[in] request: Interrupt request number 2..127
*    @param[in] channel: VIM Channel number 2..127
*    @param[in] handler: Address of the interrupt handler
*
*   This function will map selected interrupt request to the selected channel.
*
*/
/* SourceId : VIM_SourceId_002 */
/* DesignId : VIM_DesignId_002 */
/* Requirements : HL_SR101 */
void vimChannelMap(uint32 request, uint32 channel, t_isrFuncPTR handler)
{
    uint32 i,j;
    i = channel >> 2U;              /* Find the register to configure */
    j = channel - (i << 2U);        /* Find the offset of the type    */
    j = 3U - j;                     /* reverse the byte order         */
    j = j << 3U;                    /* find the bit location          */

    /*Mapping the required interrupt request to the required channel*/
    vimREG->CHANCTRL[i] &= ~(uint32)((uint32)0xFFU << j);
    vimREG->CHANCTRL[i] |= (request << j);

    /*Updating VIMRAM*/
    vimRAM->ISR[channel + 1U] = handler;
}

/** @fn void vimEnableInterrupt(uint32 channel, boolean inttype)
*   @brief Enable interrupt for the the selected channel
*
*    @param[in] channel: VIM Channel number 2..127
*    @param[in] inttype: Interrupt type
*                        - SYS_IRQ: Selected channel will be enabled as IRQ
*                        - SYS_FIQ: Selected channel will be enabled as FIQ
*
*   This function will enable interrupt for the selected channel.
*
*/
/* SourceId : VIM_SourceId_003 */
/* DesignId : VIM_DesignId_003 */
/* Requirements : HL_SR102 */
void vimEnableInterrupt(uint32 channel, systemInterrupt_t inttype)
{
	if (channel >= 96U)
    {
        if(inttype == SYS_IRQ)
        {
            vimREG->FIRQPR3 &= ~(uint32)((uint32)1U << (channel-96U));
        }
        else
        {
            vimREG->FIRQPR3 |= ((uint32)1U << (channel-96U));
        }
        vimREG->REQMASKSET3 = (uint32)1U << (channel-96U);
    }
    else if (channel >= 64U)
    {
        if(inttype == SYS_IRQ)
        {
            vimREG->FIRQPR2 &= ~(uint32)((uint32)1U << (channel-64U));
        }
        else
        {
            vimREG->FIRQPR2 |= ((uint32)1U << (channel-64U));
        }
        vimREG->REQMASKSET2 = (uint32)1U << (channel-64U);
    }
    else if (channel >= 32U)
    {
        if(inttype == SYS_IRQ)
        {
            vimREG->FIRQPR1 &= ~(uint32)((uint32)1U << (channel-32U));
        }
        else
        {
            vimREG->FIRQPR1 |= ((uint32)1U << (channel-32U));
        }
        vimREG->REQMASKSET1 = (uint32)1U << (channel-32U);
    }
    else if (channel >= 2U)
    {
        if(inttype == SYS_IRQ)
        {
            vimREG->FIRQPR0 &= ~(uint32)((uint32)1U << channel);
        }
        else
        {
            vimREG->FIRQPR0 |= ((uint32)1U << channel);
        }
        vimREG->REQMASKSET0 = (uint32)1U << channel;
    }
    else
    {
		/* Empty */
    }
}

/** @fn void vimDisableInterrupt(uint32 channel)
*   @brief Disable interrupt for the the selected channel
*
*    @param[in] channel: VIM Channel number 2..127
*
*   This function will disable interrupt for the selected channel.
*
*/
/* SourceId : VIM_SourceId_004 */
/* DesignId : VIM_DesignId_004 */
/* Requirements : HL_SR103 */
void vimDisableInterrupt(uint32 channel)
{
    if (channel >= 96U)
    {
        vimREG->REQMASKCLR3 = (uint32)1U << (channel-96U);
    }
    else if (channel >= 64U)
    {
        vimREG->REQMASKCLR2 = (uint32)1U << (channel-64U);
    }
    else if (channel >=32U)
    {
        vimREG->REQMASKCLR1 = (uint32)1U << (channel-32U);
    }
    else if (channel >= 2U)
    {
        vimREG->REQMASKCLR0 = (uint32)1U << channel;
    }
    else
    {
		/* Empty */
    }
}

/* USER CODE BEGIN (1) */
/* USER CODE END */

/** @fn void vimGetConfigValue(vim_config_reg_t *config_reg, config_value_type_t type)
*   @brief Get the initial or current values of the configuration registers
*
*    @param[in] *config_reg: pointer to the struct to which the initial or current value of the configuration registers need to be stored
*    @param[in] type:     whether initial or current value of the configuration registers need to be stored
*                        - InitialValue: initial value of the configuration registers will be stored in the struct pointed by config_reg
*                        - CurrentValue: initial value of the configuration registers will be stored in the struct pointed by config_reg
*
*   This function will copy the initial or current value (depending on the parameter 'type') of the configuration 
*   registers to the struct pointed by config_reg
*
*/
/* SourceId : VIM_SourceId_005 */
/* DesignId : VIM_DesignId_005 */
/* Requirements : HL_SR104 */
void vimGetConfigValue(vim_config_reg_t *config_reg, config_value_type_t type)
{  
    if (type == InitialValue)
    {
        config_reg->CONFIG_FIRQPR0 = VIM_FIRQPR0_CONFIGVALUE;
        config_reg->CONFIG_FIRQPR1 = VIM_FIRQPR1_CONFIGVALUE;
        config_reg->CONFIG_FIRQPR2 = VIM_FIRQPR2_CONFIGVALUE;
        config_reg->CONFIG_FIRQPR3 = VIM_FIRQPR3_CONFIGVALUE;
        config_reg->CONFIG_REQMASKSET0 = VIM_REQMASKSET0_CONFIGVALUE;
        config_reg->CONFIG_REQMASKSET1 = VIM_REQMASKSET1_CONFIGVALUE;
        config_reg->CONFIG_REQMASKSET2 = VIM_REQMASKSET2_CONFIGVALUE;
        config_reg->CONFIG_REQMASKSET3 = VIM_REQMASKSET3_CONFIGVALUE;
        config_reg->CONFIG_WAKEMASKSET0 = VIM_WAKEMASKSET0_CONFIGVALUE;
        config_reg->CONFIG_WAKEMASKSET1 = VIM_WAKEMASKSET1_CONFIGVALUE;
        config_reg->CONFIG_WAKEMASKSET2 = VIM_WAKEMASKSET2_CONFIGVALUE;
        config_reg->CONFIG_WAKEMASKSET3 = VIM_WAKEMASKSET3_CONFIGVALUE;
        config_reg->CONFIG_CAPEVT = VIM_CAPEVT_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[0U] = VIM_CHANCTRL0_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[1U] = VIM_CHANCTRL1_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[2U] = VIM_CHANCTRL2_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[3U] = VIM_CHANCTRL3_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[4U] = VIM_CHANCTRL4_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[5U] = VIM_CHANCTRL5_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[6U] = VIM_CHANCTRL6_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[7U] = VIM_CHANCTRL7_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[8U] = VIM_CHANCTRL8_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[9U] = VIM_CHANCTRL9_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[10U] = VIM_CHANCTRL10_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[11U] = VIM_CHANCTRL11_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[12U] = VIM_CHANCTRL12_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[13U] = VIM_CHANCTRL13_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[14U] = VIM_CHANCTRL14_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[15U] = VIM_CHANCTRL15_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[16U] = VIM_CHANCTRL16_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[17U] = VIM_CHANCTRL17_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[18U] = VIM_CHANCTRL18_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[19U] = VIM_CHANCTRL19_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[20U] = VIM_CHANCTRL20_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[21U] = VIM_CHANCTRL21_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[22U] = VIM_CHANCTRL22_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[23U] = VIM_CHANCTRL23_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[24U] = VIM_CHANCTRL24_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[25U] = VIM_CHANCTRL25_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[26U] = VIM_CHANCTRL26_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[27U] = VIM_CHANCTRL27_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[28U] = VIM_CHANCTRL28_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[29U] = VIM_CHANCTRL29_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[30U] = VIM_CHANCTRL30_CONFIGVALUE;
		config_reg->CONFIG_CHANCTRL[31U] = VIM_CHANCTRL31_CONFIGVALUE;
    }
    else
    {
	/*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "LDRA Tool issue" */
        config_reg->CONFIG_FIRQPR0 = vimREG->FIRQPR0;
        config_reg->CONFIG_FIRQPR1 = vimREG->FIRQPR1;
        config_reg->CONFIG_FIRQPR2 = vimREG->FIRQPR2;
        config_reg->CONFIG_FIRQPR3 = vimREG->FIRQPR3;
        config_reg->CONFIG_REQMASKSET0 = vimREG->REQMASKSET0;
        config_reg->CONFIG_REQMASKSET1 = vimREG->REQMASKSET1;
        config_reg->CONFIG_REQMASKSET2 = vimREG->REQMASKSET2;
        config_reg->CONFIG_REQMASKSET3 = vimREG->REQMASKSET3;
        config_reg->CONFIG_WAKEMASKSET0 = vimREG->WAKEMASKSET0;
        config_reg->CONFIG_WAKEMASKSET1 = vimREG->WAKEMASKSET1;
        config_reg->CONFIG_WAKEMASKSET2 = vimREG->WAKEMASKSET2;
        config_reg->CONFIG_WAKEMASKSET3 = vimREG->WAKEMASKSET3;
        config_reg->CONFIG_CAPEVT = vimREG->CAPEVT;
		config_reg->CONFIG_CHANCTRL[0U] = vimREG->CHANCTRL[0U];
		config_reg->CONFIG_CHANCTRL[1U] = vimREG->CHANCTRL[1U];
		config_reg->CONFIG_CHANCTRL[2U] = vimREG->CHANCTRL[2U];
		config_reg->CONFIG_CHANCTRL[3U] = vimREG->CHANCTRL[3U];
		config_reg->CONFIG_CHANCTRL[4U] = vimREG->CHANCTRL[4U];
		config_reg->CONFIG_CHANCTRL[5U] = vimREG->CHANCTRL[5U];
		config_reg->CONFIG_CHANCTRL[6U] = vimREG->CHANCTRL[6U];
		config_reg->CONFIG_CHANCTRL[7U] = vimREG->CHANCTRL[7U];
		config_reg->CONFIG_CHANCTRL[8U] = vimREG->CHANCTRL[8U];
		config_reg->CONFIG_CHANCTRL[9U] = vimREG->CHANCTRL[9U];
		config_reg->CONFIG_CHANCTRL[10U] = vimREG->CHANCTRL[10U];
		config_reg->CONFIG_CHANCTRL[11U] = vimREG->CHANCTRL[11U];
		config_reg->CONFIG_CHANCTRL[12U] = vimREG->CHANCTRL[12U];
		config_reg->CONFIG_CHANCTRL[13U] = vimREG->CHANCTRL[13U];
		config_reg->CONFIG_CHANCTRL[14U] = vimREG->CHANCTRL[14U];
		config_reg->CONFIG_CHANCTRL[15U] = vimREG->CHANCTRL[15U];
		config_reg->CONFIG_CHANCTRL[16U] = vimREG->CHANCTRL[16U];
		config_reg->CONFIG_CHANCTRL[17U] = vimREG->CHANCTRL[17U];
		config_reg->CONFIG_CHANCTRL[18U] = vimREG->CHANCTRL[18U];
		config_reg->CONFIG_CHANCTRL[19U] = vimREG->CHANCTRL[19U];
		config_reg->CONFIG_CHANCTRL[20U] = vimREG->CHANCTRL[20U];
		config_reg->CONFIG_CHANCTRL[21U] = vimREG->CHANCTRL[21U];
		config_reg->CONFIG_CHANCTRL[22U] = vimREG->CHANCTRL[22U];
		config_reg->CONFIG_CHANCTRL[23U] = vimREG->CHANCTRL[23U];
		config_reg->CONFIG_CHANCTRL[24U] = vimREG->CHANCTRL[24U];
		config_reg->CONFIG_CHANCTRL[25U] = vimREG->CHANCTRL[25U];
		config_reg->CONFIG_CHANCTRL[26U] = vimREG->CHANCTRL[26U];
		config_reg->CONFIG_CHANCTRL[27U] = vimREG->CHANCTRL[27U];
		config_reg->CONFIG_CHANCTRL[28U] = vimREG->CHANCTRL[28U];
		config_reg->CONFIG_CHANCTRL[29U] = vimREG->CHANCTRL[29U];
		config_reg->CONFIG_CHANCTRL[30U] = vimREG->CHANCTRL[30U];
		config_reg->CONFIG_CHANCTRL[31U] = vimREG->CHANCTRL[31U];
    }
}


#pragma CODE_STATE(vimParityErrorHandler, 32)
#pragma INTERRUPT(vimParityErrorHandler, IRQ)
#pragma WEAK(vimParityErrorHandler)

/* SourceId : VIM_SourceId_006 */
/* DesignId : VIM_DesignId_006 */
/* Requirements : HL_SR105 */
void vimParityErrorHandler(void)
{
    uint32 vec;
    
    /* Identify the corrupted address */
    uint32 error_addr = VIM_ADDERR;

    /* Identify the channel number */
    uint32 error_channel = ((error_addr & 0x1FFU) >> 2U);

    /* Correct the corrupted location */
    vimRAM->ISR[error_channel] = s_vim_init[error_channel];

    /* Clear Parity Error Flag */
    VIM_PARFLG = 1U;

    /* Disable and enable the highest priority pending channel */
    if (vimREG->FIQINDEX != 0U)
    {
        vec = vimREG->FIQINDEX - 1U;
    }
    else 
    {
	   /*SAFETYMCUSW 134 S MR:12.2 <APPROVED> "Read 32 bit volatile register" */
        vec = vimREG->IRQINDEX - 1U;
    }
    if(vec == 0U)
    {
        vimREG->INTREQ0 = 1U;
	    vec = esmREG->IOFFHR - 1U;
		
        if (vec < 32U)
        {
            esmREG->SR1[0U] = (uint32)1U << vec;
            esmGroup1Notification(vec);
        }
        else if (vec < 64U)
        {
            esmREG->SR1[1U] = (uint32)1U << (vec-32U);
            esmGroup2Notification(vec-32U);
        }
        else if (vec < 96U)
        {
            esmREG->SR4[0U] = (uint32)1U << (vec-64U);
            esmGroup1Notification(vec-32U);
        }
        else
        {
            esmREG->SR4[1U] = (uint32)1U << (vec-96U);
            esmGroup2Notification(vec-64U);
        }
    }
    else if (vec < 32U)
    {
        vimREG->REQMASKCLR0 = (uint32)1U << vec;
        vimREG->REQMASKSET0 = (uint32)1U << vec;
    }
    else if (vec < 64U)
    {
        vimREG->REQMASKCLR1 = (uint32)1U << (vec-32U);
        vimREG->REQMASKSET1 = (uint32)1U << (vec-32U);
    }
    else if(vec < 96U)
    {
        vimREG->REQMASKCLR2 = (uint32)1U << (vec-64U);
        vimREG->REQMASKSET2 = (uint32)1U << (vec-64U);
    }
	else
	{
	    vimREG->REQMASKCLR3 = (uint32)1U << (vec-96U);
        vimREG->REQMASKSET3 = (uint32)1U << (vec-96U);
	}
}
