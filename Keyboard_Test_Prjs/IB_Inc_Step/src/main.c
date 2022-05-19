#include <REG52.H>
#include "Indep_keyboard.h"
#include "delay.h"

int main()
{
    unsigned char led_num = 0;

    P0 = 0xfe;
    while(1)
    {
        if(SS1 == 0)
        {
            delay_x_ms(20);
            while(SS1 == 0);
            delay_x_ms(20);
            
            led_num++;
            if(led_num == 256)
            {
                led_num = 0;
            }

            P0 = ~ led_num;
        }
    }
}
