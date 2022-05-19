#include "delay.h"

void delay_x_ms(unsigned int duration)		//@12.000MHz
{
	unsigned char i, j;

    while(duration--)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);
    }
}
