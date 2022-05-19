#include <REG52.H>

void timer_init()
{
    TMOD &= 0xf0;
    TMOD |= 0x02;


    TL0 = 0x38;
    TH0 = 0x38;

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
    cnt++;
    if(cnt == 1000)
    {
        cnt = 0;
        P0 = ~P0;
    }
}