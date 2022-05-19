#include "I2C.h"
#include <reg52.h>

sbit iic_scl  = P2^6;
sbit iic_sda  = P2^7;


void iic_start()
{
    iic_sda = 1;
    iic_scl = 1;
    iic_sda = 0;
    iic_scl = 0;
}

void iic_stop() 
{
    iic_sda = 0;
    iic_scl = 1;
    iic_sda = 1;
}

void iic_send_byte(unsigned char byte)
{
    unsigned char i;
    for(i = 0; i < 8; i++)
    {
        iic_sda = byte & (0x80 >> i);
        iic_scl = 1;
        iic_scl = 0;
    }
}

unsigned char iic_recive_byte()
{
    unsigned char i, byte= 0;
    iic_sda = 1;
    for(i = 0; i < 8; ++i)
    {
        iic_scl = 1;
        if(iic_sda)
        {
            byte |= (0x80 >> i);
        }
        iic_scl = 0;
    }

    return byte;
}

void iic_send_ack(unsigned char ack)
{
    iic_sda = ack;
    iic_scl = 1;
    iic_scl = 0;
}

unsigned char iic_recive_ack()
{
    unsigned char ack;

    iic_sda = 1;
    iic_scl = 1;
    ack = iic_sda;
    iic_scl = 0;

    return ack;
}