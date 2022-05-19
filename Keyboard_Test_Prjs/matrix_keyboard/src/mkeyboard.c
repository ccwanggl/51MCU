#include <REG52.h>

#include "delay.h"
#include "mkeyboard.h"


unsigned char keyboard()
{
    int key_number = 0;

    P1 = 0xff;
    P1 = P1 & 0xfe;        
    // P10 = 0;

    if( P17 == 0 ) 
    //if( (P1 & 0x80 )== 0 ) 
    { 
        delay_x_ms(5);
        if( P17 == 0 ) 
        /
        {
            key_number = 1; 
            return ~key_number; 
        }
    }

    if( (P1 & 0x40 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x40 )== 0 ) 
        {
            key_number = 4; 
            return ~key_number; 
        }
    }

    if( (P1 & 0x20 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x20 )== 0 ) 
        {
            key_number = 7; 
            return ~key_number; 
        }
    }

    if( (P1 & 0x10 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x10 )== 0 ) 
        {
            key_number = 0; 
            return ~key_number; 
        }
    }


    P1 = 0xff;
    P1 = P1 & 0xfd;

    if( (P1 & 0x80 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x80 )== 0 ) 
        {
            key_number = 2; 
            return ~key_number; 
        }
    }
    if( (P1 & 0x40 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x40 )== 0 ) 
        {
            key_number = 5; 
            return ~key_number; 
        }
    }
    if( (P1 & 0x20 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x20 )== 0 ) 
        {
            key_number = 8; 
            return ~key_number; 
        }
    }
    if( (P1 & 0x10 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x10 )== 0 ) 
        {
            key_number = 0; 
            return ~key_number; 
        }
    }

    P1 = 0xff;
    P1 = P1 & 0xfb;

    if( (P1 & 0x80 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x80 )== 0 ) 
        {
            key_number = 3; 
            return ~key_number; 
        }
    }
    if( (P1 & 0x40 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x40 )== 0 ) 
        {
            key_number = 6; 
            return ~key_number; 
        }
    }
    if( (P1 & 0x20 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x20 )== 0 ) 
        {
            key_number = 9; 
            return ~key_number; 
        }
    }
    if( (P1 & 0x10 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x10 )== 0 ) 
        {
            key_number = 0; 
            return ~key_number; 
        }
    }
    

    P1 = 0xff;
    P1 = P1 & 0xf7;

    // 
    if( (P1 & 0x80 )== 0 ) 
    { 
        delay_x_ms(5); 
        if((P1 & 0x80) == 0) 
        {
            key_number = 0; 
            return ~key_number; 
        }
    }

    if( (P1 & 0x40 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x40 )== 0 ) 
        {
            key_number = 0; 
            return ~key_number; 
        }
    }


    if( (P1 & 0x20 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x20 )== 0 ) 
        {
            key_number = 0; 
            return ~key_number; 
        }
    }


    if( (P1 & 0x10 )== 0 ) 
    { 
        delay_x_ms(5);
        if( (P1 & 0x10 )== 0 ) 
        {
            key_number = 0; 
            return ~key_number; 
        }
    }
    return 0xff;
}