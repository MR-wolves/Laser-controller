#include "bsp_lcd.h"

u32 Tick_Lcd_Point = 0;
u8 Lcd_Dis[22];

void Lcd_Init(void){
	LCD_Init();
	LCD_Clear(White);
	LCD_SetBackColor(Black);
	LCD_SetTextColor(White);
}

void Lcd_Proc(void){
	if((uwTick - Tick_Lcd_Point) < 100)
		return;
	Tick_Lcd_Point = uwTick;
	
	sprintf((char*)Lcd_Dis,"        TEST        ");
	LCD_DisplayStringLine(Line0,Lcd_Dis);
}