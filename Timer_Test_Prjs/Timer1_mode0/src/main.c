#include <REG52.H>


void timer_init()
{
    TMOD &= 0x0f;
    TMOD |= 0x10;

    TH1
    TL1

    TF2
    TR1
}


int main()
{
    timer_init();
}

void timer_response interrupt 3
{

}