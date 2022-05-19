#ifndef __IIC_H_
#define __IIC_H_


void iic_start();
void iic_stop() ;
void iic_send_byte(unsigned char byte);
unsigned char iic_recive_byte();
void iic_send_ack(unsigned char ack);
unsigned char iic_recive_ack();

#endif