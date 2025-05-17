#include "reapprovisionnement.h"
#include "capteurs_niveau.h"
#include "lcd.h"
#include "buzzer.h"
#include "led.h"

uint8_t boutons_actifs = 1;

void verifier_niveaux_et_declencher_reappro(void) {
    uint16_t niveau_cafe = Lire_Niveau_Cafe();
    uint16_t niveau_lait = Lire_Niveau_Lait();
    uint16_t seuil_cafe = Lire_Seuil_Cafe();
    uint16_t seuil_lait = Lire_Seuil_Lait();

    if (niveau_cafe < seuil_cafe || niveau_lait < seuil_lait) {
        LCD_Clear();
        LCD_Send_String("Reapprovisionnement");
        LED_Reappro_ON();
        Buzzer_ON();
        boutons_actifs = 0;
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET); 
    } else {
        //LCD_Clear();
        //LCD_Send_String("Pret");
        LED_Reappro_OFF();
        Buzzer_OFF();
        boutons_actifs = 1;
    }
}