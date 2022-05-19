#include <REG52.h>

void Delay100us()		//@12.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 39;
	do
	{
		while (--j);
	} while (--i);
}

int main()
{
	int i = 0;
	
	while(1)
	{
		P0 = 0x55;

		for(i =0; i < 1000; ++i)
		{
			Delay100us();
		}
		
		P0 = 0xFF;
		for(i =0; i < 1000; ++i)
		{
			Delay100us();
		}
	}
	
	return 0;
}