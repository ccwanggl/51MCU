#ifndef __AT24C02_H_
#define __AT24C02_H_

void at24c02_write_byte(unsigned char addr, unsigned char Data);
unsigned char at24c02_read_byte(unsigned char addr);

#endif