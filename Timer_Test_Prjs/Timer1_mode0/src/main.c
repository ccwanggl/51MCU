#include <REG52.H>

sbit LED1 = P0^0;


void timer1_init()
{
    TMOD = TMOD & 0x0f;
    TL1 = 0xC0;
    TH1 = 0xE0;
    TR1 = 1;
    TF1 = 0;
}

unsigned int cnt;

int main()
{
    timer1_init();
    ET1 = 1;
    EA = 1;

    while(1);
}

void timer1_callback() interrupt 3 
{
    TL1 = 0xC0;
    TH1 = 0xE0;

    cnt++;
    if(cnt == 1000)
    {
        LED1 = !LED1;
        cnt = 0;
    }
}