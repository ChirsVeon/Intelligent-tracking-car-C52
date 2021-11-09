//小车动力驱动
#include <reg52.h>
#include <driver.h>


int value = 1;

void driver()
{
	int sum;
	//按键功能
/*
	while (1)
	{
		if (KEY1 == 0)//KEY1按下小车前进
		{
			KEY[1] = 0;
			KEY[2] = 1;
		}
		if (KEY[1] == 0)
		{
			ai();
		}
		if (KEY2 == 0)//KEY2按下小车后退
		{
			KEY[2] = 0;
			KEY[1] = 1;
			back();
		}
		else
		{
			KEY[2] = 1;
		}
		if (KEY3 == 0)//KEY3按下小车左转
		{
			KEY[3] = 0;
			left();
		}
		else
		{
			KEY[3] = 1;
		}
		if (KEY4 == 0)//KEY4按下小车右转
		{
			KEY[4] = 0;
			right();
		}
		else
		{
			KEY[4] = 1;
		}
		sum = KEY[1] + KEY[2] + KEY[3] + KEY[4];//两个KEY同时按下小车报警
		if (sum <= 2)
		{
			BEEP = 0;
		}
		else
		{
			BEEP = 1;
		}
	}
	*/
	ai();
}

//延时
void delay_ms(int n)
{
	int i;
	while (n--)
	{
		for (i = 0; i < 113; i++);
	}
}

//前进
void forward()
{
	Right_A = 1;
	Right_B = 0;

	Left_B = 0;
	Left_A = 1;
	delay_ms(17);
	Left_A = 0;
	delay_ms(3);
}

//后退
void back()
{
	Left_A = 0;
	Left_B = 1;

	Right_A = 0;
	Right_B = 1;
}

//左转
void left()
{
	Left_A = 0;
	Left_B = 1;

	Right_A = 1;
	Right_B = 0;
}

//右转
void right()
{
	Left_A = 1;
	Left_B = 0;

	Right_A = 0;
	Right_B = 1;
}

//停止
void stop()
{
	Left_A = 1;
	Left_B = 1;

	Right_A = 1;
	Right_B = 1;
}

//结束
void end(void)
{
	stop();
	//	BEEP = 0;
	//	delay_ms(100);
	//	BEEP = 1;
	P1 = 0x00;
	delay_ms(200);
	P1 = 0xFF;
	delay_ms(200);
	P1 = 0x00;
	delay_ms(200);
	P1 = 0xFF;
	delay_ms(200);
	P1 = 0x00;
	delay_ms(200);
	P1 = 0xFF;
	value = 0;
}

//循迹
void ai(void)
{
	if (RedIN_Left == 1)
	{
		left();
	}
	if (RedIN_Right == 1)
	{
		right();
	}
	if (RedIN_Left == 1 && RedIN_Right == 1)
	{
		end();
	}
	if (RedIN_Left == 0 && RedIN_Right == 0)
	{
		while(RedIN_Left == 0 && RedIN_Right == 0)
		{
			forward();
			Right_B = 1;
			delay_ms(18);
		}
	}
}