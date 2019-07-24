/*
 * vim.h
 * tms570ls12x/11x
 * BE32
 *
 *  Created on: 22 июл. 2019 г.
 *      Author: Stoyanov Ruslan
 */

#ifndef INCLUDE_VIM_H_
#define INCLUDE_VIM_H_

//#include "sys_common.h"
//#include <assert.h>
//
//#define VIM_BASE_CR 0xFFFFFE00U //base address of the control registers
//
//typedef volatile struct VIM_CR {
//   uint32_t IRQINDEX;       //  0x00
//   uint32_t FIQINDEX;       //  0x04
//   uint32_t : 32U;          //  0x08
//   uint32_t : 32U;          //  0x0C
//   uint32_t FIRQPR[4];      //  0x10
//   uint32_t INTREQ[4];      //  0x20
//   uint32_t REQENASET[4];   //  0x30
//   uint32_t REQENACLR[4];   //  0x40
//   uint32_t WAKEENASET[4];  //  0x50
//   uint32_t WAKEENACLR[4];  //  0x60
//   uint32_t IRQVECREG;      //  0x70
//   uint32_t FIQVECREG;      //  0x74
//   uint32_t CAPEVT;         //  0x78
//   uint32_t : 32U;          //  0x7C
//   uint8_t CHANCTRL[128];   //  0x80
//}VIM_CR_t;
//
////Checking size of VIM_CR_t
//STATIC_ASSERT(sizeof(VIM_CR_t) == 0x100,);
//
//#define vim_CR ((VIM_CR_t *)VIM_BASE_CR)

#endif /* INCLUDE_VIM_H_ */
