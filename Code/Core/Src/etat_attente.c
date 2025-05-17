#include <stdbool.h>
#include "etat_attente.h"
#include "lcd.h"
#include "stm32f4xx_hal.h"
#include "main.h"

void LED_Init(void)
{
    // Configurée via CubeMX ou HAL_GPIO_Init
}

void EtatAttenteLoop(void)
{
    static uint32_t lastToggle = 0;
    static bool ledState = false;

    if (HAL_GetTick() - lastToggle > 500)
    {
        ledState = !ledState;
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, ledState ? GPIO_PIN_SET : GPIO_PIN_RESET); // LED verte
        lastToggle = HAL_GetTick();
    }

    LCD_Send_Cmd(0x80); 
    LCD_Send_String("Choisir Cafe :  ");
		LCD_Send_Cmd(0xC0);
		LCD_Send_String("Expresso/CafeLait");

    
		
    
}	
