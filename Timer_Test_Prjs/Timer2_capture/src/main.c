#include <REG52.H>


//-----------------------------------------------


sbit bell = P2^0;                     //Clock Output pin
unsigned int cnt;

void timer_init()
{
    EXEN2 = 1;    
    TF2 = 0;
    EXF2 = 0;

    RCAP2L = TL2 = 0x18;        //initial timer2 low byte
    RCAP2H = TH2 = 0xFC;        //initial timer2 high byte
    TR2 = 1;                        //timer2 start running

}
/* main program */
void main()
{
    timer_init();
    ET2 = 1;
    EA = 1;                         //open global interrupt switch

    while (1);                      //loop
}

void timer2_interupt_routine() interrupt 5
{
    cnt++;

    if(TF2 ==1 )
    {
        TF2 = 0 ;
        if(cnt ==  1000)
        {
            cnt =  0;
            P0 = ~P0;
        }
    }

    if(EXF2 == 1)
    {
        EXF2 = 0;
        bell = ~bell;
    }
}

