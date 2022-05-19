#include <REG52.H>

sbit LED1 = P0^0;


void timer0_init()
{
    TMOD = TMOD & 0xf0;
    TL0 = 0xC0;
    TH0 = 0xE0;
    TR0 = 1;
    TF0 = 0;
}

unsigned int cnt;

int main()
{
    timer0_init();
    ET0 = 1;
    EA = 1;

    while(1);
}

void timer0_callback() interrupt 1 
{
    TL0 = 0xC0;
    TH0 = 0xE0;
    cnt++;
    if(cnt == 1000)
    {
        LED1 = !LED1;
        cnt = 0;
    }
}