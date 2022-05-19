#include <REG52.H>
#include "delay.h"


int main()
{
    while(1)
    {
        P0 = 0x0;
        delay_x_ms(1000);
        P0 = 0xff;
        delay_x_ms(1000);
    }
}