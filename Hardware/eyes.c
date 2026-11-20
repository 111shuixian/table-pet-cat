#include "stm32f10x.h"                  // Device header

extern void OLED_Full1(uint8_t Line, uint8_t Column);
extern void OLED_Fulldown(uint8_t Line, uint8_t Column);
extern void OLED_Fullup(uint8_t Line, uint8_t Column);
extern void OLED_Fullleft(uint8_t Line, uint8_t Column);
extern void OLED_Fullright(uint8_t Line, uint8_t Column);
extern void OLED_Clear(void);
extern void Delay_ms(uint32_t ms);
                                    
void Eyesleft()//4*16
{
	OLED_Fulldown(1,3);
	OLED_Fulldown(1,4);
	OLED_Fullleft(2,2);
	OLED_Fullright(2,5);
	OLED_Fullleft(3,2);
	OLED_Fulldown(3,4);
	OLED_Fullright(3,5);
	OLED_Fullup(4,3);
	OLED_Fullup(4,4);
}

void Eyesleft2()//左眼状态2
{
	OLED_Fullup(3,2);
	OLED_Fullup(3,3);
	OLED_Fullup(3,4);
	OLED_Fullup(3 ,5);
}
	
	
void Eyesright()//4*16
{
	OLED_Fulldown(1,11);
	OLED_Fulldown(1,12);
	OLED_Fullleft(2,10);
	OLED_Fullright(2,13);
	OLED_Fullleft(3,10);
	OLED_Fulldown(3,12);
	OLED_Fullright(3,13);
	OLED_Fullup(4,11);
	OLED_Fullup(4,12);
}

void Eyesright2()//右眼状态2
{
	OLED_Fullup(3,10);
	OLED_Fullup(3,11);
	OLED_Fullup(3,12);
	OLED_Fullup(3,13);
}

void Eyesblink()//眨眼
{
	Eyesleft();
	Eyesright();
	Delay_ms(1000);
	OLED_Clear();
	Eyesright2();
	Eyesleft2();
	Delay_ms(10);
	OLED_Clear();
}
