#include "stm32f10x.h"                  // Device header
#include "Delay.h"
void Key_Init(void)
{
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}

uint8_t Key_GetNum(void)
{
	uint8_t Key_Num = 0;//局部变量Keynum
 if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0)
	{
			Delay_ms(20);//按钮按下会抖动一段时间，故需要等待一下
		while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0);//检测有没有松开
			Delay_ms(20);//松开后仍旧会抖动一段时间，再等待一下
		Key_Num =1;
	}
	 if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0)
	{
			Delay_ms(20);//按钮按下会抖动一段时间，故需要等待一下
		while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0);//检测有没有松开
			Delay_ms(20);//松开后仍旧会抖动一段时间，再等待一下
		Key_Num =2;
	}
	return Key_Num;
}