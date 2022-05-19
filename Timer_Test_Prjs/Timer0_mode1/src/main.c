#include <REG52.H>


void timer_init()
{
    TMOD &= 0xf0;
    TMOD |= 0x01;


    TL0 = 0x18;
    TH0 = 0xFC;

    TF0 = 0;
    TR0 = 1;
}

unsigned int cnt;

int main()
{
    timer_init();
    ET0 = 1;
    EA = 1;

    while(1);
}

void timer0_response() interrupt 1
{
    TL0 = 0x18;
    TH0 = 0xFC;

    cnt++;
    if(cnt == 1000)
    {
        cnt = 0;
        P0 = ~P0;
    }
}