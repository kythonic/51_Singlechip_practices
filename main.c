/*
	入口
*/

#include "digital_tube.h"
#include "led.h"
#include "key_led.h"
#include "matrix_key.h"


int main()
{
	// 动态数码管
	// digital_tube_display();
	// reset_digital_tube();

	// LED流水灯
	// light_led();
	// light_led_with_cro();
	// reset_led();

	// 独立按键控制LED亮灭
	// turn_on_and_off_led();

	// 矩阵按键
	matrix_action();

	return 0;
}