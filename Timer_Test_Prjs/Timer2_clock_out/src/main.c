/*------------------------------------------------------------------*/
/* --- STC MCU Limited ---------------------------------------------*/
/* --- STC89-90xx Series Programmable Clock Output Demo ------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ---------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966----------------------*/
/* --- Web: www.STCMCU.com -----------------------------------------*/
/* --- Web: www.GXWMCU.com -----------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/

#include "reg51.h"

typedef unsigned char BYTE;
typedef unsigned int WORD;

//-----------------------------------------------

/* define constants */
#define FOSC 11059200L

#define F38_4KHz    (65536-18432000/4/38400)

/* define SFR */

sfr T2CON = 0xc8;                   //timer2 control register
sbit TF2  = T2CON^7;
sbit TR2  = T2CON^2;

sfr T2MOD = 0xc9;                   //timer2 mode register
sfr RCAP2L = 0xca;
sfr RCAP2H = 0xcb;
sfr TL2 = 0xcc;
sfr TH2 = 0xcd;

sbit T2 = P1^0;                     //Clock Output pin

//-----------------------------------------------

/* main program */
void main()
{
    T2MOD = 0x02;                   //enable timer2 output clock
    RCAP2L = TL2 = F38_4KHz;        //initial timer2 low byte
    RCAP2H = TH2 = F38_4KHz >> 8;   //initial timer2 high byte
    TR2 = 1;                        //timer2 start running
    EA = 1;                         //open global interrupt switch

    while (1);                      //loop
}

