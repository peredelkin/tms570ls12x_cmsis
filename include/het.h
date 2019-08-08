/**
 * het.h
 * tms570ls12x
 * BE32
 *
 */



#ifndef __HET_H__
#define __HET_H__

#include "sys_common.h"
#include "reg_gio.h"
#include "static_assert.h"

//Дефайны N2HET

//Дефайны HETGCR
#define HETGCR_HET_PIN_ENA      ((uint32_t)(1 << 24)) //Enables the pin output buffer structure when DIR = output, PINDIS.x is set and nDIS = 1.
#define HETGCR_MP(N)            ((uint32_t)(((N) << 21) & (0x3 << 21))) //
#define HETGCR_PPF              ((uint32_t)(1<<18)) //When TO is 1,the program fields are readable but not writable for all masters, which could access the N2HET RAM.
#define HETGCR_IS               ((uint32_t)(1<<17)) //N2HET ignores suspend mode and continues operation.
#define HETGCR_CMS              ((uint32_t)(1<<16)) //N2HET is configured as a master.
#define HETGCR_TO               ((uint32_t)(1<<0))  //N2HET is ON. The timer program execution starts synchronously to the Loop clock.

//Дефайны HETPFR
//Loop-Resolution Pre-scale Factor Code.
#define HETPFR_LRPFC(N)         ((uint32_t)(((N) << 8) & (0xF << 8)))  //[1-7] -> [2,4,8,16,32,64,128]
//High-Resolution Pre-scale Factor Code.
#define HETPFR_HRPFC(N)         ((uint32_t)((N) & 0x3F)) //[0-63] -> [1-64]

//Дефайны HETOFF
#define HETOFF_OVF_PRG          ((uint32_t) 33) //Program Overflow
#define HETOFF_UNF_APCNT        ((uint32_t) 34) //APCNT Underflow
#define HETOFF_OVF_APCNT        ((uint32_t) 35) //APCNT Overflow

//Дефайны HETEXC1
#define HETEXC1_APCNT_OVRFL_ENA ((uint32_t)(1 << 24)) //Enables the APCNT overflow exception.
#define HETEXC1_APCNT_UNRFL_ENA ((uint32_t)(1 << 16)) //Enables the APCNT underflow exception.
#define HETEXC1_PRGM_OVRFL_ENA  ((uint32_t)(1 << 8))  //Enables the program overflow exception.
#define HETEXC1_APCNT_OVRFL_PRY ((uint32_t)(1 << 2))  //Exception priority level 1
#define HETEXC1_APCNT_UNRFL_PRY ((uint32_t)(1 << 1))  //Exception priority level 1.
#define HETEXC1_PRGM_OVRFL_PRY  ((uint32_t) 1)     //Exception priority level 1.

//Дефайны HETEXC2
#define HETEXC2_DEBUG_STATUS_FLAG   ((uint32_t)(1 << 8))  //Debug Status Flag
#define HETEXC2_APCNT_OVRFL_FLAG    ((uint32_t)(1 << 2))  //APCNT Overflow Flag
#define HETEXC2_APCNT_UNDFL_FLAG    ((uint32_t)(1 << 1))  //APCNT Underflow Flag
#define HETEXC2_PRGM_OVERFL_FLAG    ((uint32_t) 1)     //Program Overflow Flag

//Дефайны HETREQENS/HETREQENC
#define HETREQEN_REQ(N)         ((uint32_t)((1 << (N)) & 0xFF)) //Request Line N(0 to 7) Enable/Disable Bit

//Дефайны HETREQDS
#define HETREQDS_TDBS(N)        ((uint32_t)(((1 << (N)) << 16) & 0xF00))  //N2HET request line n is assigned to both DMA and HTU.
#define HETREQDS_TDS(N)         ((uint32_t)((1 << (N)) & 0xF))  //N2HET request line n is assigned to DMA (TDBS bit n is zero).

//Дефайны HETPCR
#define HETPCR_TEST             ((uint32_t)(1<<8))  //Parity bits are memory mapped.
#define HETPCR_PARITY_ENA       ((uint32_t)(0x5))   //Parity check is disabled.

//Дефайны HETSFPRLD
#define HETSFPRLD_CCDIV(N)      ((uint32_t)(((N) << 16) & (0x3 << 16))) //[0-3] -> [1-4] Ratio between the counter clock and VCLK2.
#define HETSFPRLD_CPRLD(N)      ((uint32_t)((N) & 0x3FF)) //Counter Preload Value

//Дефайны HWAG

//Дефайны HWAPINSEL
#define HWAPINSEL_PINSEL(N)     ((uint32_t)((N) & 0x1F)) //HWAG Pin Select.

//Дефайны HWAGCR0
#define HWAGCR0_RESET           ((uint32_t) 1)  //HWAG module is not in reset.

//Дефайны HWAGCR2
#define HWAGCR2_ARST            ((uint32_t)(1<<24)) //Reset ACNT once it reaches the angle zero point.
#define HWAGCR2_TED             ((uint32_t)(1<<17)) //Rising edge.
#define HWAGCR2_CRI             ((uint32_t)(1<<16)) //Criteria is enabled.
#define HWAGCR2_FIL             ((uint32_t)(1<<8))  //Filter is enabled.
#define HWAGCR2_STRT            ((uint32_t) 1)     //Start counting.

//Дефайны HWAENASET/HWAENACLR and HWALVLSET/HWALVLCLR, and HWAFLG
#define HWAENA_OVF_PERIOD               ((uint32_t) 1)          //Overflow period interrupt.
#define HWAENA_SINGULARITY_NOT_FOUND    ((uint32_t) (1 << 1))   //Singularity not found interrupt.
#define HWAENA_TOOTH                    ((uint32_t) (1 << 2))   //Tooth interrupt.
#define HWAENA_OVF_ACNT                 ((uint32_t) (1 << 3))   //ACNT overflow interrupt.
#define HWAENA_SING_DRNG_NORM_TOOTH     ((uint32_t) (1 << 4))   //PCNT(n) > 2 x PCNT (n-1) during normal tooth interrupt.
#define HWAENA_BAD_ACT_EDGE_TOOTH       ((uint32_t) (1 << 5))   //Bad active edge tooth interrupt.
#define HWAENA_GAP_FLAG                 ((uint32_t) (1 << 6))   //Gap flag interrupt.
#define HWAENA_OVF_AINC                 ((uint32_t) (1 << 7))   //Angle increment overflow interrupt.

//Дефайны HWAOFF0/HWAOFF1
#define HWAOFF_PHANTOM                  ((uint32_t) 0)  //Phantom interrupt
#define HWAOFF_OVF_PERIOD               ((uint32_t) 1)  //Overflow period
#define HWAOFF_SINGULARITY_NOT_FOUND    ((uint32_t) 2)  //Singularity not found
#define HWAOFF_TOOTH                    ((uint32_t) 3)  //Tooth interrupt
#define HWAOFF_OVF_ACNT                 ((uint32_t) 4)  //ACNT overflow
#define HWAOFF_SING_DRNG_NORM_TOOTH     ((uint32_t) 5)  //PCNT(n) > 2 × PCNT (n-1) during normal tooth
#define HWAOFF_BAD_ACT_EDGE_TOOTH       ((uint32_t) 6)  //Bad active edge tooth
#define HWAOFF_GAP_FLAG                 ((uint32_t) 7)  //Gap flag
#define HWAOFF_OVF_AINC                 ((uint32_t) 8)  //Angle increment overflow

//Дефайны HWASTWD
#define HWASTWD_STWD(N)                 ((uint32_t) ((N) & 0xF))    //Step Width
#define HWAG_STEP_WIDTH(STWD)           ((uint32_t) (4 << (STWD)))  //HWAG Step Width (Only for calculating)

//Дефайны HWATHNB
#define HWATHNB_THNB(N)                 ((uint32_t) ((N) & 0xFF))   //Teeth Number. Sets the teeth number with the maximum value of the toothed wheel.

//Дефайны HWAFIL
#define HWAFIL_FIL1(N)                  ((uint32_t) ((N) & 0x3FF))  //Filter Value. Contains the value to be compared to the tick counter.

//Дефайн HWAFIL2
#define HWAFIL2_FIL2(N)                 ((uint32_t) ((N) & 0xFFF))  //Filter Value 2. Contains the value to be compared to the tick counter during the singularity tooth.


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
