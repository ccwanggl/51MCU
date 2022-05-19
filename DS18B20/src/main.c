#include "ds18b20.h"
#include <REG52.H>

int main()
{
   while(1)
   {
       ds_convert_tempeture();
       P0 = ds_read_tempeture_tlsb();
   }
}