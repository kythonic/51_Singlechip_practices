/*
    动态数码管显示Demo
*/

#include <reg52.h>

typedef unsigned int u16;
typedef unsigned char u8;

sbit LSA = P2 ^ 2;
sbit LSB = P2 ^ 3;
sbit LSC = P2 ^ 4;


/* 段码:
	
	每个数字都是由a b c d e f g dp 八段构成，dp是小数点decimal point，通过二进制表示的高低电平来显示：
	
	aaaaa
	f   b
	f   b
	ggggg
	e   c
	e   c
	ddddd .(dp)

	这八段位号由高位向低位排列为： dp - g - f - e - d - c - b - a
	比如需要显示数字7，则需要 dp, d, e, f, g消隐，a, b, c显示，
	则对应电平二进制为（0代表低电平，1高电平）: 0b00000111
	转换为十六进制则为: 0x07
	即数字7的段码为 0x07
*/

// 0-F段码
u8 smgduan[17] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
u8 d[17] = {0x5b,0x3f,0x06,0x7f,0x3f,0x7f,0x5b,0x5b};

// display: 1314-520
u8 segment_nums[8] = {
    0x6, 0x4f, 0x6, 0x66, 0x40, 0x6d, 0x5b, 0x3f 
};


// 延时
void delay_temp(u16 t)
{
	while(t--);
}


void tube_display()
{
    u16 i;
	for(i=0;i<8;i++)
	{
		switch(i)
		{
			case(0):
			    LSA = 1;
				LSB = 1;
				LSC = 1;
				break;
			case(1):
				LSA = 0;
				LSB = 1;
				LSC = 1;
				break;
			case(2):
			    LSA = 1;
				LSB = 0;
				LSC = 1;
				break;
			case(3):
				LSA = 0;
				LSB = 0;
				LSC = 1;
				break;
			case(4):
				LSA = 1;
				LSB = 1;
				LSC = 0;
				break;
			case(5):
				LSA = 0;
				LSB = 1;
				LSC = 0;
				break;
			case(6):
				LSA = 1;
				LSB = 0;
				LSC = 0;
				break;
			case(7):
				LSA = 0;
				LSB = 0;
				LSC = 0;
				break;
			default: break;
		}
		P0 = segment_nums[i];
		delay_temp(100);
		P0 = 0x00;
	}
}


void digital_tube_display()
{
	while(1)
	{
		tube_display();
	}
}


void reset_digital_tube()
{
	P0 = 0x00;
}