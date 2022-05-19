#include <REG52.H>
#include "delay.h"

int main()
{
    unsigned char i;

    for(i = 0; i < 8; ++i)
    {
        P0 = ~(0x01 << i );
        delay_x_ms(1000);
    }

    while(1)
    {
        for(i = 0; i < 7; ++i)
        {
            P0 = ~(0x40 >> i );
            delay_x_ms(1000);
        }

        for(i = 0; i < 7; ++i)
        {
            P0 = ~(0x02 << i );
            delay_x_ms(1000);
        }
    }
}