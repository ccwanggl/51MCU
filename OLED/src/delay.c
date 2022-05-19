#include "delay.h"

void delay_x_ms(unsigned int time)		//@12.000MHz
{
	unsigned char i, j;

    while(time--)
    {
        i = 12;
        j = 169;
        do
        {
            while (--j);
        } while (--i);
    }
}
