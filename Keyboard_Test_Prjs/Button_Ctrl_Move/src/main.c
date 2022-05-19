#include <REG52.H>
#include "Indep_keyboard.h"
#include "delay.h"

int main()
{
    unsigned char cnt = 0 ;
    P0 = ~(0x01);

    while(1)
    {
        if(SS1 == 0)
        {
            delay_x_ms(20);
            while(SS1 == 0);
            delay_x_ms(20);

            cnt++;
            if(cnt == 8)
            {
                cnt  = 0;
            }

            P0 = ~(0x01 << cnt);
        }
        if(SS2 == 0)
        {
            delay_x_ms(20);
            while(SS2 == 0);
            delay_x_ms(20);

            if(cnt == 0)
            {
                cnt  = 7;
            }
            else
            {
                cnt--;
            }

            P0 = ~(0x01 << cnt);
        }
    }
}