#include <reg52.h>
#include "at24c02.h"
#include "delay.h"

int main()
{
    unsigned char i;

    at24c02_write_byte(0,0x01);
    delay_x_ms(5);
    at24c02_write_byte(1,0x02);
    delay_x_ms(5);
    at24c02_write_byte(2,0x04);
    delay_x_ms(5);
    at24c02_write_byte(3,0x08);
    delay_x_ms(5);
    at24c02_write_byte(4,0x10);
    delay_x_ms(5);
    at24c02_write_byte(5,0x20);
    delay_x_ms(5);
    at24c02_write_byte(6,0x40);
    delay_x_ms(5);
    at24c02_write_byte(7,0x80);
    delay_x_ms(5);


    while(1)
    {
        for(i = 0; i < 8; i++)
        {
            P0 = at24c02_read_byte(i);
            delay_x_ms(100);
        }
    }
}