#include "bsp_key.h"

u32 Set_Key_Point = 0;
u8 Key_Up = 0;
u8 Key_Down = 0;
u8 Key_Old = 0;
u8 Key_Val = 0;

u8 Key_Scan(void){
	u8 KeyVal = 0;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0) == GPIO_PIN_RESET)
		KeyVal = 1;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1) == GPIO_PIN_RESET)
		KeyVal = 2;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2) == GPIO_PIN_RESET)
		KeyVal = 3;
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_RESET)
		KeyVal = 4;
	
	return KeyVal;
}

void Key_Porc(void){
	if((uwTick - Set_Key_Point) < 100)
		return;
	Set_Key_Point = uwTick;
	
	Key_Val = Key_Scan();
	Key_Down = Key_Val &(Key_Val ^ Key_Old);
	Key_Up = ~Key_Val &(Key_Val ^ Key_Old);
	Key_Old = Key_Val;
	
	if(Key_Down == 3)
		Led_Dis(0x55);
	if(Key_Up == 3)
		Led_Dis(0x00);
}

