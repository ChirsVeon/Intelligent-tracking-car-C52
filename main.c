//主程序
#include <reg52.h>
#include <driver.h>


void light();

int main()
{
	light();
	while (1)
	{
		driver();//启动驱动程序
	}
}

//流水灯
void light()
{
	int LED[] = { 0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,0x00,0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF };
	int x;
	P1 = 0xFF;
	for (x = 0; x < 16; x++)
	{
		P1 = LED[x];
		delay_ms(50);
	}
}