#include <REG52.H>
#include "I2C.h"
#include "at24c02.h"

#define AT24C02_ADDRESS 0xA0

void at24c02_write_byte(unsigned char addr, unsigned char Data)
{
    iic_start();
    iic_send_byte(AT24C02_ADDRESS);
    iic_recive_ack();
    iic_send_byte(addr);
    iic_recive_ack();
    iic_send_byte(Data);
    iic_recive_ack();
    iic_stop();
}

unsigned char at24c02_read_byte(unsigned char addr)
{
    unsigned char Data;
    iic_start();
    iic_send_byte(AT24C02_ADDRESS);
    iic_recive_ack();
    iic_send_byte(addr);
    iic_recive_ack();

    iic_start();
    iic_send_byte(AT24C02_ADDRESS | 0x01);
    iic_recive_ack();
    Data = iic_recive_byte();
    iic_send_ack(1);
    iic_stop();

    return Data;
}