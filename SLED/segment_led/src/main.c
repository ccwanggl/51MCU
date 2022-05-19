#include <REG52.H>
#include "sled_code.inc"
#include "delay.h"

int main()
{
   unsigned char i = 0; 

   P3 = 0x0;  
   while(1)
   {
        for(i = 0; i < 17; ++i)
        {
            P0 = common_cathode_led[i];
            delay_x_ms(1000);
        }
   }
}