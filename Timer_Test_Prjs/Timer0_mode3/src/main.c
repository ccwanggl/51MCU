#include <REG52.H>

sbit bell = P2^0;

void timer_init()
{
    TMOD &= 0xf0;
    TMOD |= 0x03;


    TL0 = 0x38;
    TH0 = 0x38;

    TF0 = 0;
    TR0 = 1;

    TF1 = 0;
    TR1 = 1;
}

unsigned int cnt1;
unsigned int cnt2;

int main()
{
    bell = 0;

    timer_init();
    ET0 = 1;
    ET1 = 1;

    EA = 1;

    while(1);
}

void timer0_response() interrupt 1
{
    TL0 = 0x38;

    cnt1++;
    if(cnt1 == 1000)
    {
        cnt1 = 0;
        P0 = ~P0;
    }
}

void timer1_response() interrupt 3
{
    TH0 = 0x38;

    cnt2++;
    if(cnt2 == 5000)
    {
        cnt2 = 0;
        bell = ~bell;
    }
}