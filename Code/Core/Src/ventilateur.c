#include "lcd.h"
#include "main.h"
#include "ventilateur.h"

void ventilateur_ON(void)
{

    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET); 
   }
    

void ventilateur_OFF(void)
{

    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET); 
   }

