#include "led.h"
#include "stm32f4xx_hal.h"

void LED_Reappro_Init(void) {
    // Optionnel : si configuration GPIOA4 déjà faite
}

void LED_Reappro_ON(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}

void LED_Reappro_OFF(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
}
