#ifndef _driver_H
#define _driver_H


#include <reg52.h>

//����LED��
sbit LED1 = P1 ^ 0;
sbit LED2 = P1 ^ 1;
sbit LED3 = P1 ^ 2;
sbit LED4 = P1 ^ 3;

//����KEY����
sbit KEY1 = P3 ^ 3;
sbit KEY2 = P3 ^ 4;
sbit KEY3 = P3 ^ 6;
sbit KEY4 = P3 ^ 7;

//���������
sbit BEEP = P0 ^ 7;

//�������缫
sbit Left_A = P0 ^ 0;
sbit Left_B = P0 ^ 1;
sbit Right_A = P0 ^ 2;
sbit Right_B = P0 ^ 3;

//������⴫��
sbit RedIN_Left = P2 ^ 0;
sbit RedIN_Right = P2 ^ 1;

void driver();
void delay_ms(int n);
void forward();
void back();
void left();
void right();
void stop();
void light();
void end();
void ai();

extern int value;
static int KEY[5];

#endif/*_driver_H*/