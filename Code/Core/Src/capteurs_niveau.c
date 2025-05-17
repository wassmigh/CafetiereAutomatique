#include "capteurs_niveau.h"
#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1;

static uint16_t lire_ADC(uint32_t canal) {
    ADC_ChannelConfTypeDef sConfig = {0};
    sConfig.Channel = canal;
    sConfig.Rank = 1;
    sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    return HAL_ADC_GetValue(&hadc1);
}

void CAPTEUR_Init(void) {
    // Optionnel selon init ADC déjà faite dans main
}

uint16_t Lire_Niveau_Cafe(void) {
    return lire_ADC(ADC_CHANNEL_0);
}

uint16_t Lire_Niveau_Lait(void) {
    return lire_ADC(ADC_CHANNEL_1);
}

uint16_t Lire_Seuil_Cafe(void) {
    return lire_ADC(ADC_CHANNEL_2);
}

uint16_t Lire_Seuil_Lait(void) {
    return lire_ADC(ADC_CHANNEL_3);
}