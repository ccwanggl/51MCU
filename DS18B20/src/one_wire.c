#include <REG52.h>

sbit one_wire_dq = P2^1;

unsigned char one_wire_init()
{
    unsigned char i;
    unsigned char ack;
    one_wire_dq =  1;
    one_wire_dq =  0;
    i = 247;while(--i);
    one_wire_dq =  1;
    i = 32;while(--i);
    ack = one_wire_dq;
    i = 247;while(--i);

    return ack;
}

void one_wire_write_bit(unsigned char b)
{
    unsigned char i;

    one_wire_dq = 0;
    i = 4; while(--i);
    one_wire_dq = b;
    i = 24; while(--i);
    one_wire_dq = 1;
}

unsigned char one_wire_receive_bit()
{
    unsigned char i;
    unsigned char b;

    one_wire_dq = 0;
    i = 2; while(--i);
    one_wire_dq = 1;
    i = 2; while(--i);
    b = one_wire_dq;
    i = 24; while(--i);

    return b;
}

void one_wire_send_byte(unsigned char byte)
{
    unsigned char i;

    for(i = 0; i < 8; ++i)
    {
        one_wire_write_bit(byte & (0x01 << i));
    }
}

unsigned char one_wire_receive_byte()
{
    unsigned char i;
    unsigned char byte = 0x00;

    for(i = 0; i < 8; ++i)
    {
        if(one_wire_receive_bit())
        {
            byte |= (0x01 << i);
        }
    }

    return byte;
}