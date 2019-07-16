/*
 * dma.h
 * tms570ls12x/11x
 * BE32
 *
 *  Created on: 6 июл. 2019 г.
 *      Author: Stoyanov Ruslan
 */

#ifndef INCLUDE_DMA_H_
#define INCLUDE_DMA_H_

#include "sys_common.h"
#include <assert.h>

#define DMA_BASE_CR 0xFFFFF000U //base address for the Control Registers

#define DMA_BASE_PCP 0xFFF80000U //base address for the Primary Control Packet

#define DMA_BASE_WCP (DMA_BASE_PCP + 0x800U) //base address for the Working Control Packet

// DMA Control Registers
typedef struct DMA_CR
{
    uint32_t GCTRL;     //  0x000 Global Control Register.

    uint16_t :16U;      //  0x004
    uint16_t PEND;      //  0x006 Channel pending register.

    uint32_t :32U;      //    008

    uint16_t :16U;      //  0x00C
    uint16_t STCH;      //  0x00E Status of DMA channels.

    uint32_t :32U;      //    010

    uint16_t :16U;      //  0x014
    uint16_t HWCHENA;   //  0x016 Hardware channel enable bit.

    uint32_t :32U;      //    018

    uint16_t :16U;      //  0x01C
    uint16_t HWCHDIS;   //  0x01E Hardware channel disable bit.

    uint32_t :32U;      //    020

    uint16_t :16U;      //  0x024
    uint16_t SWCHENA;   //  0x026 SW channel enable bit.

    uint32_t :32U;      //    028

    uint16_t :16U;      //  0x02C
    uint16_t SWCHDIS;   //  0x02E SW channel disable bit.

    uint32_t :32U;      //    030

    uint16_t :16U;      //  0x034
    uint16_t CPS;       //  0x036 Channel priority set bit.

    uint32_t :32U;      //    038

    uint16_t :16U;      //  0x03C
    uint16_t CPR;       //  0x03E Channel priority reset bit.

    uint32_t :32U;      //    040

    uint16_t :16U;      //  0x044
    uint16_t GCHIE;     //  0x046 Global channel interrupt enable bit.

    uint32_t :32U;      //    048

    uint16_t :16U;      //  0x04C
    uint16_t GCHID;     //  0x04E Global channel interrupt disable bit.

    uint32_t :32U;      //    050

    uint8_t CHASI[16];  //  0x054 Channel request assignment.

//    uint32_t DREQASI0;  //    054
//    uint32_t DREQASI1;  //    058
//    uint32_t DREQASI2;  //    05C
//    uint32_t DREQASI3;  //    060

    uint32_t :32U;      //    064
    uint32_t :32U;      //    068
    uint32_t :32U;      //    06C
    uint32_t :32U;      //    070
    uint32_t :32U;      //    074
    uint32_t :32U;      //    078
    uint32_t :32U;      //    07C
    uint32_t :32U;      //    080
    uint32_t :32U;      //    084
    uint32_t :32U;      //    088
    uint32_t :32U;      //    08C
    uint32_t :32U;      //    090

    uint8_t CH0PA :4U;  //  0x094 These bit fields determine to which port channel 0 is assigned.
    uint8_t CH1PA :4U;  //  0x094 These bit fields determine to which port channel 1 is assigned.
    uint8_t CH2PA :4U;  //  0x095 These bit fields determine to which port channel 2 is assigned.
    uint8_t CH3PA :4U;  //  0x095 These bit fields determine to which port channel 3 is assigned.
    uint8_t CH4PA :4U;  //  0x096 These bit fields determine to which port channel 4 is assigned.
    uint8_t CH5PA :4U;  //  0x096 These bit fields determine to which port channel 5 is assigned.
    uint8_t CH6PA :4U;  //  0x097 These bit fields determine to which port channel 6 is assigned.
    uint8_t CH7PA :4U;  //  0x097 These bit fields determine to which port channel 7 is assigned.
    uint8_t CH8PA :4U;  //  0x098 These bit fields determine to which port channel 8 is assigned.
    uint8_t CH9PA :4U;  //  0x098 These bit fields determine to which port channel 9 is assigned.
    uint8_t CH10PA :4U; //  0x099 These bit fields determine to which port channel 10 is assigned.
    uint8_t CH11PA :4U; //  0x099 These bit fields determine to which port channel 11 is assigned.
    uint8_t CH12PA :4U; //  0x09A These bit fields determine to which port channel 12 is assigned.
    uint8_t CH13PA :4U; //  0x09A These bit fields determine to which port channel 13 is assigned.
    uint8_t CH14PA :4U; //  0x09B These bit fields determine to which port channel 14 is assigned.
    uint8_t CH15PA :4U; //  0x09B These bit fields determine to which port channel 15 is assigned.

//    uint32_t PAR0;      //    094
//    uint32_t PAR1;      //    098

    uint32_t :32U;      //    09C
    uint32_t :32U;      //    0A0
    uint32_t :32U;      //    0A4
    uint32_t :32U;      //    0A8
    uint32_t :32U;      //    0AC
    uint32_t :32U;      //    0B0

    uint16_t :16U;      //  0x0B4
    uint16_t FTCAB;     //  0x0B6 Frame transfer complete (FTC) interrupt to Group A or Group B.

    uint32_t :32U;      //    0B8

    uint16_t :16U;      //  0x0BC
    uint16_t LFSAB;     //  0x0BE Last frame started (LFS) interrupt to Group A or Group B.

    uint32_t :32U;      //    0C0

    uint16_t :16U;      //  0x0C4
    uint16_t HBCAB;     //  0x0C6 Half block complete (HBC) interrupt to Group A or Group B.

    uint32_t :32U;      //    0C8

    uint16_t :16U;      //  0x0CC
    uint16_t BTCAB;     //  0x0CE Block transfer complete (BTC) interrupt to Group A or Group B.

    uint32_t :32U;      //    0D0
    uint32_t :32U;      //    0D4
    uint32_t :32U;      //    0D8

    uint16_t :16U;      //  0x0DC
    uint16_t FTCINTENA; //  0x0DE Frame transfer complete (FTC) interrupt enable.

    uint32_t :32U;      //    0E0

    uint16_t :16U;      //  0x0E4
    uint16_t FTCINTDIS; //  0x0E6 Frame transfer complete (FTC) interrupt disable.

    uint32_t :32U;      //    0E8

    uint16_t :16U;      //  0x0EC
    uint16_t LFSINTENA; //  0x0EE Last frame started (LFS) interrupt enable.

    uint32_t :32U;      //    0F0

    uint16_t :16U;      //  0x0F4
    uint16_t LFSINTDIS;//   0x0F6 Last frame started (LFS) interrupt disable.

    uint32_t :32U;      //    0F8

    uint16_t :16U;      //  0x0FC
    uint16_t HBCINTENA; //  0x0FE Half block complete (HBC) interrupt enable.

    uint32_t :32U;      //    100

    uint16_t :16U;      //  0x104
    uint16_t HBCINTDIS; //  0x106 Half block complete (HBC) interrupt disable.

    uint32_t :32U;      //    108

    uint16_t :16U;      //  0x10C
    uint16_t BTCINTENA; //  0x10E Block transfer complete (BTC) interrupt enable.

    uint32_t :32U;      //    110

    uint16_t :16U;      //  0x114
    uint16_t BTCINTDIS; //  0x116 Block transfer complete (BTC) interrupt disable.

    uint32_t :32U;      //    118

    uint16_t :16U;      //  0x11C
    uint16_t GINT;      //  0x11E Global interrupt flags.

    uint32_t :32U;      //    120

    uint16_t :16U;      //  0x124
    uint16_t FTCI;      //  0x126 Frame transfer complete (FTC) flags.

    uint32_t :32U;      //    128

    uint16_t :16U;      //  0x12C
    uint16_t LFSI;      //  0x12E Last frame started (LFS) flags.

    uint32_t :32U;      //    130

    uint16_t :16U;      //  0x134
    uint16_t HBCI;      //  0x136 Half block transfer (HBC) complete flags.

    uint32_t :32U;      //    138

    uint16_t :16U;      //  0x13C
    uint16_t BTCI;      //  0x13E Block transfer complete (BTC) flags.

    uint32_t :32U;      //    140

    uint32_t BERFLAG;   //  0x144 The BERFLAG will never be set in this device.

    uint32_t :32U;      //    148

    uint16_t :16U;      //  0x14C
    uint8_t :8U;        //  0x14E
    uint8_t FTCA;       //  0x14F Channel causing FTC interrupt Group A.

    uint16_t :16U;      //  0x150
    uint8_t :8U;        //  0x152
    uint8_t LFSA;       //  0x153 Channel causing LFS interrupt Group A.

    uint16_t :16U;      //  0x154
    uint8_t :8U;        //  0x156
    uint8_t HBCA;       //  0x157 Channel causing HBC interrupt Group A.

    uint16_t :16U;      //  0x158
    uint8_t :8U;        //  0x15A
    uint8_t BTCA;       //  0x15B Channel causing BTC interrupt Group A.

    uint32_t :32U;      //    15C

    uint16_t :16U;      //  0x160
    uint8_t :8U;        //  0x162
    uint8_t FTCB;       //  0x163 Channel causing FTC interrupt Group B.

    uint16_t :16U;      //  0x164
    uint8_t :8U;        //  0x166
    uint8_t LFSB;       //  0x167 Channel causing LFS interrupt Group B.

    uint16_t :16U;      //  0x168
    uint16_t :8U;       //  0x16A
    uint8_t HBCB;       //  0x16B Channel causing HBC interrupt Group B.

    uint16_t :16U;      //  0x16C
    uint8_t :8U;        //  0x16E
    uint8_t BTCB;       //  0x16F Channel causing BTC interrupt Group B.

    uint32_t :32U;      //    170
    uint32_t :32U;      //    174

    uint32_t PTCRL;     //  0x178 Port Control Register.
    uint32_t RTCTRL;    //  0x17C RAM Test Control.
    uint32_t DCTRL;     //  0x180 Debug Control.
    uint32_t WPR;       //  0x184 Watch Point Register.
    uint32_t WMR;       //  0x188 Watch Mask Register.

    uint32_t :32U;      //    18C
    uint32_t :32U;      //    190
    uint32_t :32U;      //    194

    uint32_t PBACSADDR; //  0x198 Port B Active Channel Source Address Register.
    uint32_t PBACDADDR; //  0x19C Port B Active Channel Destination Address Register.

    uint16_t PBFTCOUNT; //  0x1A0 Port B active channel frame count.
    uint16_t PBETCOUNT; //  0x1A2 Port B active channel element count.

    uint32_t :32U;      //    1A4

    uint32_t DMAPCR;    //  0x1A8 Parity Control Register.
    uint32_t DMAPAR;    //  0x1AC DMA Parity Error Address Register.
    uint32_t DMAMPCTRL; //  0x1B0 DMA Memory Protection Control Register
    uint32_t DMAMPST;   //  0x1B4 DMA Memory Protection Status Register.
    uint32_t DMAMPR0S;  //  0x1B8 DMA Memory Protection Region 0 Start Address Register.
    uint32_t DMAMPR0E;  //  0x1BC DMA Memory Protection Region 0 End Address Register.
    uint32_t DMAMPR1S;  //  0x1C0 DMA Memory Protection Region 1 Start Address Register.
    uint32_t DMAMPR1E;  //  0x1C4 DMA Memory Protection Region 1 End Address Register.
    uint32_t DMAMPR2S;  //  0x1C8 DMA Memory Protection Region 2 Start Address Register.
    uint32_t DMAMPR2E;  //  0x1CC DMA Memory Protection Region 2 End Address Register.
    uint32_t DMAMPR3S;  //  0x1D0 DMA Memory Protection Region 3 Start Address Register.
    uint32_t DMAMPR3E;  //  0x1D4 DMA Memory Protection Region 3 End Address Register.
} DMA_CR_t;


//Checking size of DMA_CR_t
STATIC_ASSERT(sizeof(DMA_CR_t) == 0x1D8,);

//DMA Primary Control Packet
typedef volatile struct DMA_PCP {
    uint32_t ISADDR;    //0x00 Initial Source Address Register
    uint32_t IDADDR;    //0x04 Initial Destination Address Register
    uint16_t IFTCOUNT;  //0x08 Initial frame transfer count.
    uint16_t IETCOUNT;  //0x0A Initial element transfer count.

    uint32_t : 32U;     //0x0C

    uint32_t CHCTRL;    //0x10 Channel Control Register
    uint16_t EIDXD;     //0x14 Destination address element index.
    uint16_t EIDXS;     //0x16 Source address element index.
    uint16_t FIDXD;     //0x18 Destination address frame index.
    uint16_t FIDXS;     //0x1A Source address frame index.

    uint32_t : 32U;     //0x1C
}DMA_PCP_t[16];

//Checking size of DMA_PCP_t
STATIC_ASSERT(sizeof(DMA_PCP_t) == 0x200,);

//DMA Working Control Packet
typedef volatile struct DMA_WCP {
    uint32_t CSADDR;    //0x00 Current Source Address Register
    uint32_t CDADDR;    //0x04 Current Destination Address Register

    uint16_t CFTCOUNT;  //0x08 Current frame transfer count.
    uint16_t CETCOUNT;  //0x0A Current element transfer count.

    uint32_t : 32U;     //0x0C
}DMA_WCP_t[16];

//Checking size of DMA_WCP_t
STATIC_ASSERT(sizeof(DMA_WCP_t) == 0x100,);

#define dma_CR ((DMA_CR_t *)DMA_BASE_CR)
#define dma_PCP ((DMA_PCP_t *)DMA_BASE_PCP)
#define dma_WCP ((DMA_WCP_t *)DMA_BASE_WCP)

#endif /* INCLUDE_DMA_H_ */
