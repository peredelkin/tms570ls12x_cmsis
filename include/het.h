/**
 * het.h
 * tms570ls12x
 * BE32
 *
 */



#ifndef __HET_H__
#define __HET_H__

#define HETOFF_OVF_PRG 33

#define HWAOFF_PHANTOM 0
#define HWAOFF_OVF_PERIOD 1
#define HWAOFF_SINGULARITY_NOT_FOUND 2
#define HWAOFF_TOOTH 3
#define HWAOFF_OVF_ACNT 4
#define HWAOFF_SING_DRNG_NORM_TOOTH 5
#define HWAOFF_BAD_ACT_EDGE_TOOTH 6
#define HWAOFF_GAP_FLAG 7
#define HWAOFF_OVF_AINC 8

#include "static_assert.h"
#include "sys_common.h"
#include "reg_gio.h"
#include "std_nhet.h"


typedef volatile struct hetBase
{
    /*00*/ uint32_t HETGCR;        /** Global Configuration Register */
    /*04*/ uint32_t HETPFR;        /** Prescale Factor Register */
    /*08*/ uint32_t HETADDR;       /** NHET Current Address Register */
    /*0C*/ uint32_t HETOFF1;       /** Offset Index Priority Level 1 Register */
    /*10*/ uint32_t HETOFF2;       /** Offset Index Priority Level 2 Register */
    /*14*/ uint32_t HETINTENAS;    /** Interrupt Enable Set Register */
    /*18*/ uint32_t HETINTENAC;    /** Interrupt Enable Clear Register */
    /*1C*/ uint32_t HETEXC1;       /** Exception Control Register 1 */
    /*20*/ uint32_t HETEXC2;       /** Exception Control Register 2 */
    /*24*/ uint32_t HETPRY;        /** Interrupt Priority Register */
    /*28*/ uint32_t HETFLG;        /** Interrupt Flag Register */
    /*2C*/ uint32_t HETAND;        /** AND Share Control Register */
    /*30*/ uint32_t : 32U;
    /*34*/ uint32_t HETHRSH;       /** HR Share Control Register */
    /*38*/ uint32_t HETXOR;        /** HR XOR-Share Control Register */
    /*3C*/ uint32_t HETREQENS;     /** Request Enable Set Register */
    /*40*/ uint32_t HETREQENC;     /** Request Enable Clear Register */
    /*44*/ uint32_t HETREQDS;      /** Request Destination Select Register */
    /*48*/ uint32_t : 32U;
    /*4C*/ uint32_t HETDIR;        /** NHET Direction Register */
    /*50*/ uint32_t HETDIN;        /** NHET Data Input Register */
    /*54*/ uint32_t HETDOUT;       /** NHET Data Output Register */
    /*58*/ uint32_t HETDSET;       /** NHET Data Set Register */
    /*5C*/ uint32_t HETDCLR;       /** NHET Data Clear Register */
    /*60*/ uint32_t HETPDR;        /** NHET Open Drain Register */
    /*64*/ uint32_t HETPULDIS;     /** NHET Pull Disable Register */
    /*68*/ uint32_t HETPSL;        /** NHET Pull Select Register */
    /*6C*/ uint32_t : 32U;
    /*70*/ uint32_t : 32U;
    /*74*/ uint32_t HETPCR;        /** Parity Control Register */
    /*78*/ uint32_t HETPAR;        /** Parity Address Register */
    /*7C*/ uint32_t HETPPR;        /** Parity Pin Register */
    /*80*/ uint32_t HETSFPRLD;     /** Suppression Filter Preload Register */
    /*84*/ uint32_t HETSFENA;      /** Suppression Filter Enable Register */
    /*88*/ uint32_t : 32U;
    /*8C*/ uint32_t HETLBPSEL;     /** Loop Back Pair Select Register */
    /*90*/ uint32_t HETLBPDIR;     /** Loop Back Pair Direction Register */
    /*94*/ uint32_t HETPINDIS;     /** NHET Pin Disable Register */
    /*98*/ uint32_t : 32U;
    /*9C*/ uint32_t HWAPINSEL;     /** HWAG Pin Select Register */
    /*A0*/ uint32_t HWAGCR0;       /** HWAG Global Control Register 0 */
    /*A4*/ uint32_t HWAGCR1;       /** HWAG Global Control Register 1 */
    /*A8*/ uint32_t HWAGCR2;       /** HWAG Global Control Register 2 */
    /*AC*/ uint32_t HWAENASET;     /** HWAG Interrupt Enable Set Register */
    /*B0*/ uint32_t HWAENACLR;     /** HWAG Interrupt Enable Clear Register */
    /*B4*/ uint32_t HWALVLSET;     /** HWAG Interrupt Level Set Register */
    /*B8*/ uint32_t HWALVLCLR;     /** HWAG Interrupt Level Clear Register */
    /*BC*/ uint32_t HWAFLG;        /** HWAG Interrupt Flag Register */
    /*C0*/ uint32_t HWAOFF0;       /** HWAG Interrupt Offset Register 1 */
    /*C4*/ uint32_t HWAOFF1;       /** HWAG Interrupt Offset Register 2 */
    /*C8*/ uint32_t HWAACNT;       /** HWAG Angle Value Register */
    /*CC*/ uint32_t HWAPCNT1;      /** HWAG Previous Tooth Period Value Register */
    /*D0*/ uint32_t HWAPCNT;       /** HWAG Current Tooth Period Value Register */
    /*D4*/ uint32_t HWASTWD;       /** HWAG Step Width Register */
    /*D8*/ uint32_t HWATHNB;       /** HWAG Teeth Number Register */
    /*DC*/ uint32_t HWATHVL;       /** HWAG Current Teeth Number Register */
    /*E0*/ uint32_t HWAFIL;        /** HWAG Filter Register */
    /*E4*/ uint32_t : 32U;
    /*E8*/ uint32_t HWAFIL2;       /** HWAG Filter Register 2 */
    /*EC*/ uint32_t : 32U;
    /*F0*/ uint32_t HWAANGI;       /** HWAG Angle Increment Register */

} hetBASE_t;

//Checking size of hetBASE_t
STATIC_ASSERT(sizeof(hetBASE_t) == 0xF4,);

typedef volatile struct hetInstructionBase
{
    uint32 Program;
    uint32 Control;
    uint32 Data;
    uint32 rsvd1;
} hetINSTRUCTION_t;


typedef volatile struct het1RamBase
{
    hetINSTRUCTION_t Instruction[160U];
} hetRAMBASE_t;

//Checking size of hetRAMBASE_t
STATIC_ASSERT(sizeof(hetRAMBASE_t) == 0xA00,);


#define hetREG1 ((hetBASE_t *)0xFFF7B800U)
#define hetPORT1 ((gioPORT_t *)0xFFF7B84CU)
#define hetRAM1 ((hetRAMBASE_t *)0xFF460000U)

#define NHET1RAMPARLOC  (*(volatile uint32 *)0xFF462000U)
#define NHET1RAMLOC     (*(volatile uint32 *)0xFF460000U)


#define hetREG2 ((hetBASE_t *)0xFFF7B900U)
#define hetPORT2 ((gioPORT_t *)0xFFF7B94CU)
#define hetRAM2 ((hetRAMBASE_t *)0xFF440000U)

#define NHET2RAMPARLOC  (*(volatile uint32 *)0xFF442000U)
#define NHET2RAMLOC     (*(volatile uint32 *)0xFF440000U)

extern void hwag_init(hetBASE_t* het,uint8_t pin,bool arst,bool ted,bool cri,bool fil,uint8_t stwd,uint8_t thnb,uint16_t fil1,uint16_t fil2);
extern void hwag_interrupt(hetBASE_t* het,uint32_t hwena,bool ena);
extern void hwag_interrupt_flag_clear(hetBASE_t* het,uint32_t hwena);
extern void hwag_start(hetBASE_t* het);
extern void hwag_stop(hetBASE_t* het);

#endif
