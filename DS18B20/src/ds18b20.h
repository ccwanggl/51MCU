#ifndef __DS18B20_H_
#define __DS18B20_H_

void ds_convert_tempeture();
float ds_read_tempeture();
unsigned char ds_read_tempeture_tmsb();
unsigned char ds_read_tempeture_tlsb();

#endif