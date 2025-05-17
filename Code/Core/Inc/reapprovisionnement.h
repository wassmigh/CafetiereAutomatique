#ifndef LOGIQUE_REAPPROVISIONNEMENT_H
#define LOGIQUE_REAPPROVISIONNEMENT_H
#include <stdint.h>
#include "stm32f4xx_hal.h"
void verifier_niveaux_et_declencher_reappro(void);
extern uint8_t boutons_actifs;
#endif
