#include <REG52.H>


void timer_init()
{
    TMOD &= 0x0f;
    TMOD |= 0x00;

    TL1 = 0x30;
    TH1 = 0xe3;

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
    TL1 = 0x30;
    TH1 = 0xe3;

    cnt++;
    if(cnt == 1000)
    {
        cnt = 0;
        P0 = ~P0;
    }

}