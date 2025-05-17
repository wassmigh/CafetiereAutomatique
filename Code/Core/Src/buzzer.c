#include "buzzer.h"
#include "stm32f4xx_hal.h"

void Buzzer_Init(void) {
    // Optionnel : si GPIOA5 déjà configuré
}

void Buzzer_ON(void) {
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
}

void Buzzer_OFF(void) {
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
}