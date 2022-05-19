/*------------------------------------------------------------------*/
/* --- STC MCU Limited ---------------------------------------------*/
/* --- STC89-90xx Series 16-bit Timer Demo -------------------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ---------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966----------------------*/
/* --- Web: www.STCMCU.com -----------------------------------------*/
/* --- Web: www.GXWMCU.com -----------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/

#include <REG52.H>

//-----------------------------------------------

/* define constants */
//#define FOSC 11059200L
#define FOSC 12000000L

#define T1MS (65536-FOSC/12/1000)   //1ms timer calculation method in 12T mode

/* define variables */
unsigned int count;                         //1000 times counter

//-----------------------------------------------

/* Timer2 interrupt routine */
void timer2_interrupt_routine() interrupt 5
{
    TF2 = 0;
    if (count-- == 0)               //1ms * 1000 -> 1s
    {
        count = 1000;               //reset counter
        P0 = ~ P0;      //work LED flash
    }
}

void timer2_init()
{

    RCAP2L = TL2 = T1MS;            //initial timer2 low byte
    RCAP2H = TH2 = T1MS >> 8;       //initial timer2 high byte

    TR2 = 1;                        //timer2 start running
}
//-----------------------------------------------

/* main program */
void main()
{
    timer2_init();
    ET2 = 1;                        //enable timer2 interrupt
    EA = 1;                         //open global interrupt switch
    count = 0;                      //initial counter

    while (1);                      //loop
}

