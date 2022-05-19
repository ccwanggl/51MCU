#include <REG52.H>
#include "delay.h"
#include "sled_code.inc"

void sel_sled(unsigned char seg, unsigned char led)
{
    P3 = ~(0x01 << (seg -1));
    P0 = common_cathode_led[led];
}


int main()
{
    while(1)
    {
        sel_sled(1,1);
        delay_x_ms(5);
        sel_sled(2,2);
        delay_x_ms(5);
        sel_sled(3,3);
        delay_x_ms(5);
    }
}