#include <REG52.H>
#include "delay.h"

sbit bell = P2^0;

int main()
{
    unsigned char i;

    bell = 0;
    while(1)
    {
        /*
            P0 = 0xff;
            delay_x_ms(1000);
            P0 = 0;
            delay_x_ms(1000);
            */
#if 0
            P1 = 0xff;
            delay_x_ms(1000);
            P1 = 0;
            delay_x_ms(1000);
#endif
#if 1

            bell = ~bell;
            delay_x_ms(1000);
            bell = ~bell;
            delay_x_ms(1000);
#endif
#if 0
            P3 = 0xff;
            delay_x_ms(1000);
            P3 = 0;
            delay_x_ms(1000);
#endif
    }
}