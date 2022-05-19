#include <REG52.H>
#include "delay.h"


unsigned char sec;

sbit SS1 = P1^0;
sbit SS2 = P1^1;
sbit SS3 = P1^2;
sbit SS4 = P1^3;


sbit LED1 = P0^0;
sbit LED2 = P0^1;
sbit LED3 = P0^2;
sbit LED4 = P0^3;

int main()
{
    while (1)
    {
        if( SS1 == 0)
        {
            delay_x_ms(1);
            if(SS1 == 0)
            {
                LED1 = 0;   
            }
        }
        if( SS2 == 0)
        {
            delay_x_ms(1);
            if(SS2 == 0)
            {
                LED2 = 0;   
            }
        }
        if( SS3 == 0)
        {
            delay_x_ms(1);
            if(SS3 == 0)
            {
                LED3 = 0;   
            }
        }
        if( SS4 == 0)
        {
            delay_x_ms(1);
            if(SS4 == 0)
            {
                LED4 = 0;   
            }
        }

    }
    
}