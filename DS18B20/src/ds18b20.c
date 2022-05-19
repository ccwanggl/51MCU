#include <REG52.H>
#include "ds18b20.h"
#include "one_wire.h"


void ds_convert_tempeture()
{
    one_wire_init();
    one_wire_send_byte(0xcc);
    one_wire_send_byte(0x44);
}


float ds_read_tempeture()
{
    unsigned char tlsb;
    unsigned char tmsb;

    one_wire_init();
    one_wire_send_byte(0xcc);
    one_wire_send_byte(0xbe);

    tlsb = one_wire_receive_byte();
    tmsb = one_wire_receive_byte();

    return ((tmsb << 8) | tlsb) /4.0;
}

unsigned char ds_read_tempeture_tlsb()
{
    unsigned char tlsb;
    unsigned char tmsb;

    one_wire_init();
    one_wire_send_byte(0xcc);
    one_wire_send_byte(0xbe);

    tlsb = one_wire_receive_byte();
    tmsb = one_wire_receive_byte();

    return tlsb;
}

unsigned char ds_read_tempeture_tmsb()
{
    unsigned char tlsb;
    unsigned char tmsb;

    one_wire_init();
    one_wire_send_byte(0xcc);
    one_wire_send_byte(0xbe);

    tlsb = one_wire_receive_byte();
    tmsb = one_wire_receive_byte();

    return tmsb;
}