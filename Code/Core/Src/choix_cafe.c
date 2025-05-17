#include "choix_cafe.h"
#include "lcd.h"
#include "main.h"

bool ChoixCafeLoop(void)
{
		extern TIM_HandleTypeDef htim2;
    extern volatile uint8_t timer_expired ; 
		timer_expired = 0;
		HAL_TIM_Base_Start_IT(&htim2); 
    int choix = -1;
    bool validation_effectuee = false;

    while (!timer_expired)
    {
        if (choix == -1 && HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == GPIO_PIN_SET)
        {
            choix = 1;
            LCD_Clear();
            LCD_Send_String("Expresso choisi");
            HAL_Delay(300); 
        }

        else if (choix == -1 && HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1) == GPIO_PIN_SET)
        {
            choix = 2;
            LCD_Clear();
            LCD_Send_String("Cafe au lait");
            HAL_Delay(300); 
        }

        if (choix > 0 && HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2) == GPIO_PIN_SET)
        {
            HAL_TIM_Base_Stop_IT(&htim2);  // Stop timer
            validation_effectuee = true;

            LCD_Clear();
            if (choix == 1)
                LCD_Send_String("Expresso lance");
            else
                LCD_Send_String("CafeLait lance");

            HAL_Delay(1000);
            return true;
        }
    }

    HAL_TIM_Base_Stop_IT(&htim2);  // Stop timer

    if (!validation_effectuee)
    {
        LCD_Clear();
        LCD_Send_Cmd(0x80);
        LCD_Send_String("Commande");
        LCD_Send_Cmd(0xC0);
        LCD_Send_String("annulee");
        HAL_Delay(2000);
        return false;
    }

    return true; // Ce cas ne devrait jamais arriver
}
