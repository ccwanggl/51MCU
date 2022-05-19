#include <REG52.H>
#include "delay.h"
#include "mkeyboard.h"

int main()
{
    while(1)
    {
        P0 = keyboard();
    }
}