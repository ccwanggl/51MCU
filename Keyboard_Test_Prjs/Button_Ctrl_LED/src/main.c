#include <REG52.H>

sbit SS1 = P1 ^ 0;
sbit LED1 = P0 ^ 0;

int main()
{
    while(1)
    {
        if(SS1 == 0)
        {
            LED1 = 0;
        }
        else
        {
            LED1 = 1;
        }
    }
}