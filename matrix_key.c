/*
	���󰴼����ƶ�̬�������ʾֵ
*/

#include<reg52.h>

typedef unsigned int u16;
typedef unsigned char u8;

sbit LSA = P2 ^ 2;
sbit LSB = P2 ^ 3;
sbit LSC = P2 ^ 4;

// ���� 0~9 �� dp ��10λ˳�����У�dp����ĩ��
u8 code segments[11] = {
	// 0b(dp)gfedcba
	0x3F, // 0 -> 0b00111111 -> 0b0011 = 0x3 0b1111 = 0xf
	0x06, // 1 -> 0b00000110 -> 0b0000 = 0x0 0b0110 = 0x6
	0x5B, // 2 -> 0b01011011 -> 0b0101 = 0x5 0b1011 = 0xb
	0x4F, // 3 -> 0b01001111 -> 0b0100 = 0x4 0b1111 = 0xf
	0x66, // 4 -> 0b01100110 -> 0b0110 = 0x6 0b0110 = 0x6
	0x6D, // 5 -> 0b01101101 -> 0b0110 = 0x6 0b1101 = 0xd
	0x7D, // 6 -> 0b01111101 -> 0b0111 = 0x7 0b1101 = 0xd
	0x07, // 7 -> 0b00000111 -> 0b0000 = 0x0 0b0111 = 0x7
	0x7F, // 8 -> 0b01111111 -> 0b0111 = 0x7 0b1111 = 0xf
	0x6F, // 9 -> 0b01101111 -> 0b0110 = 0x6 0b1111 = 0xf
	0x80  // . -> 0b10000000 -> 0b1000 = 0x8 0b0000 = 0x0
};


void delay_matrix_key(u16 t)
{
	while(t--);
}


/* ��ʾ��̬����ܣ���ѡλ�����ݿ�������Ͼ��󰴼����Ƴ���Ч��

    params:
        u16* Is ��Ҫ������ʾ��λ���п��ܶ�λ������������
        u8*  Ns ��Ӧÿһλ��Ҫ��ʾ������ 
*/
void display_digital_tube(u16* Is, u8* Ns, u16 len)
{
      u16 i;
      for(i=0; i<len;i++)
      {
          switch(Is[i])
          {
              //       0b0cba
              // ��1λ 0b0111 = 7
              case(0): LSA = 1; LSB = 1; LSC = 1; break;
              // ��2λ 0b0110 = 6
              case(1): LSA = 0; LSB = 1; LSC = 1; break;
              // ��3λ 0b0101 = 5
              case(2): LSA = 1; LSB = 0; LSC = 1; break;
              // ��4λ 0b0100 = 4
              case(3): LSA = 0; LSB = 0; LSC = 1; break;
              // ��5λ 0b0011 = 3
              case(4): LSA = 1; LSB = 1; LSC = 0; break;
              // ��6λ 0b0010 = 2
              case(5): LSA = 0; LSB = 1; LSC = 0; break;
              // ��7λ 0b0001 = 1
              case(6): LSA = 1; LSB = 0; LSC = 0; break;
              // ��8λ 0b0000 = 0
              case(7): LSA = 0; LSB = 0; LSC = 0; break;
          }
          P0 = segments[Ns[i]];
          delay_matrix_key(100);
          // ����
          P0=0x00;
      }
}


void matrix_action()
{
    // ��Ҫ��ʾ��λ
    u16 code locs[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    // ��Ӧλ��Ҫ��ʾ������
    u8 code disps[8] = {2, 0, 1, 8, 0, 8, 2, 2};
    // ��ֹ�����������ʾ�������ٵĿ�����ʾλ��
    u16 len = (sizeof(disps) / sizeof(u8)) > (sizeof(locs) / sizeof(u16)) ? (sizeof(locs) / sizeof(u16)) : (sizeof(disps) / sizeof(u8));
    
    while(1){
        display_digital_tube(locs, disps, len);
    }
}