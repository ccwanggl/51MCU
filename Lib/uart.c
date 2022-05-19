#include "uart.h"
#include <REG52.h>

void uart_init()
{
    SCON = 0x40;

    PCON |= 0x80;
    TMOD &= 0x0f;
    TMOD |= 0x20;
    TL1 = 0xf3;
    TH1 = 0xf3;
    ET1 = 0;
    TR1 = 1;

    EA = 1;
    ES = 1;
}

void uart_send_byte(unsigned char byte)
{
    SBUF = byte;
    while(TI == 0);
    TI = 0;

}

void uart_routine() interrupt 4
{
    if(RI == 1)
    {
        //
        RI = 0;
    }
}