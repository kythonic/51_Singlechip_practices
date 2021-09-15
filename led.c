/*
    LED流水灯Demo
*/

#include <reg52.h>
#include <intrins.h>

#define led P2



void delay(unsigned int t)
{
	while(t--);
}


// 复位
void reset_led()
{
	P2 = 0xff;
}


int light_led_with_cro()
{
	unsigned int i;

	// LED是低电平点亮
	P2 = 0x5F;
	delay(500000);

	while(1)
	{
		for(i = 0; i < 8; ++i)
		{
			P2 = _cror_(P2, 1);
			delay(50000);
		}
	}

	return 0;
}


int light_led()
{

	unsigned int i;

	// LED是低电平点亮
	P2 = ~(0x01);
	delay(500000);

	while(1)
	{
		for(i = 0; i < 8; ++i)
		{
			P2 = ~(0x01<<i);
			delay(50000);
		}
	}

	return 0;
}