#include "het.h"

void hwag_init(hetBASE_t* nhet,uint8_t pin,bool arst,bool ted,bool cri,bool fil,uint8_t stwd,uint8_t thnb,uint16_t fil1,uint16_t fil2) {
    nhet->HWAGCR0 = 1; //HWAG Enable;

    nhet->HWAPINSEL = 2; //HWAG Pin Select

    nhet->HWAGCR2 = 0;
    if(arst)nhet->HWAGCR2 |= (1<<24);
    if(ted) nhet->HWAGCR2 |= (1<<17);
    if(cri) nhet->HWAGCR2 |= (1<<16);
    if(fil) nhet->HWAGCR2 |= (1<<8);

    nhet->HWASTWD = (0xF & stwd);

    nhet->HWATHNB = (0xFF & thnb);

    nhet->HWAFIL = (0x3FF & fil1);

    nhet->HWAFIL2 = (0xFFF & fil2);
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








