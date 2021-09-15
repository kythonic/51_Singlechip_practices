/*
	独立按键控制LED灯亮灭
*/

#include<reg52.h>


sbit key1 = P3 ^ 1;
sbit led1 = P2 ^ 0;


typedef unsigned int u18;


void delay_kl(u18 t)
{
	while(t--);
}


void turn_on_off()
{

	if(key1 == 0)
	{
		 // 消抖 10ms
		 delay_kl(1000);

		 if(key1 == 0)
		 {
		 	led1 = 0;
		 }
		 else
		 {
		 	led1 = 1;
		 }
		 // while(!key1);
	}
}


void turn_on_and_off_led()
{
	led1 = 1;
	while(1)
	{
		turn_on_off();
	}
}