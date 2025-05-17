#include "boutons.h"
#include "stm32f4xx_hal.h"

/*uint8_t boutons_actifs = 1;

void Boutons_Init(void) {
    // Optionnel si config GPIOA6/A7 déjà faite
}

uint8_t Bouton_Espresso_Presse(void) {
    if (!boutons_actifs) return 0;
    return (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == GPIO_PIN_SET);
}

uint8_t Bouton_CafeLait_Presse(void) {
    if (!boutons_actifs) return 0;
    return (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1) == GPIO_PIN_SET);
}*/