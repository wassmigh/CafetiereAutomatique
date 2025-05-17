#include "brassage.h"
#include "lcd.h"
#include "main.h"

void Motor_Init(void)
{
    // Initialisation GPIO moteur CC via CubeMX
}

void BrassageLoop(void)
{
    LCD_Clear();
    LCD_Send_Cmd(0x80);
    LCD_Send_String("Brassage...");
		HAL_Delay(800);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET); 
    HAL_Delay(800);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET); 
		HAL_Delay(7000);
    LCD_Clear();
    LCD_Send_Cmd(0x80);
    LCD_Send_String("Cafe pret !");
    HAL_Delay(3000);
		
}
