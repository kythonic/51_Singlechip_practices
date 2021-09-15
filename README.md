# 51 Single-chip practices

>
> Author: KuangQingxu
>
> Date: 2021-09-15
>
>



### 项目结构

```

├── proj
│   ├── main.c          入口文件，引入头文件，`int main(){}`控制实际执行函数
│   ├── xxx.h           头文件，提供对外函数供`main.c`引入调用
│   ├── led.c           **LED流水灯**练习代码
│   ├── digital_tube.c  **动态数码管显示**练习代码
│   ├── key_led.c       **独立按键控制**练习代码
│   ├── matrix_key.c    **矩阵按键控制**练习代码
│   ├── ...

```