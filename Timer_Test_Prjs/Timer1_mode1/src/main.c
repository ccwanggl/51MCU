#include <REG52.H>


void timer_init()
{
    TMOD &= 0x0f;
    TMOD |= 0x10;

    TL1 = 0x18;
    TH1 = 0xfc;

    TF1 = 0;
    TR1 = 1;
}

unsigned int cnt;
int main()
{
    timer_init();
    ET1 = 1;
    EA = 1;


    while(1);
}

void timer_response() interrupt 3
{
    TL1 = 0x18;
    TH1 = 0xfc;

    cnt++;
    if(cnt == 500)
    {
        cnt = 0;
        P0 = ~P0;
    }

}