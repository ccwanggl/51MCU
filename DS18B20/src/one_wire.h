#ifndef __ONE_WIRE_H
#define __ONE_WIRE_H


unsigned char one_wire_init();

void one_wire_write_bit(unsigned char b);
void one_wire_send_byte(unsigned char byte);

unsigned char one_wire_receive_bit();
unsigned char one_wire_receive_byte();


#endif


