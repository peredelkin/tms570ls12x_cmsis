#include "het.h"

void hwag_init(hetBASE_t* nhet,uint8_t pin,bool arst,bool ted,bool cri,bool fil,uint8_t stwd,uint8_t thnb,uint16_t fil1,uint16_t fil2) {
    nhet->HWAGCR0 = HWAGCR0_RESET; //HWAG Enable;

    nhet->HWAPINSEL = HWAPINSEL_PINSEL(pin); //HWAG Pin Select

    nhet->HWAGCR2 = 0;
    if(arst)nhet->HWAGCR2 |= HWAGCR2_ARST;
    if(ted) nhet->HWAGCR2 |= HWAGCR2_TED;
    if(cri) nhet->HWAGCR2 |= HWAGCR2_CRI;
    if(fil) nhet->HWAGCR2 |= HWAGCR2_FIL;

    nhet->HWASTWD = HWASTWD_STWD(stwd);

    nhet->HWATHNB = HWATHNB_THNB(thnb);

    nhet->HWAFIL = HWAFIL_FIL1(fil1);

    nhet->HWAFIL2 = HWAFIL2_FIL2(fil2);
}

void hwag_start(hetBASE_t* het) {
    het->HWAGCR2 |= HWAGCR2_STRT;
}

void hwag_stop(hetBASE_t* het) {
    het->HWAGCR2 &= ~HWAGCR2_STRT;
}

void hwag_interrupt(hetBASE_t* het,uint32_t hwena,bool ena) {
    if(ena) het->HWAENASET = hwena;
    else het->HWAENACLR = hwena;
}

void hwag_interrupt_lvl(hetBASE_t* het,uint32_t hwena,bool lvl) {
    if(lvl) het->HWALVLSET = hwena;
    else het->HWALVLCLR = hwena;
}

bool hwag_interrupt_flag_read(hetBASE_t* het,uint32_t hwena) {
    if((het->HWAFLG) & hwena) return true;
    else return false;
}

void hwag_interrupt_flag_clear(hetBASE_t* het,uint32_t hwena) {
    het->HWAFLG = hwena;
}








