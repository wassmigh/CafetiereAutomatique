#ifndef BOUTONS_H
#define BOUTONS_H

#include <stdint.h>

void Boutons_Init(void);
uint8_t Bouton_Espresso_Presse(void);
uint8_t Bouton_CafeLait_Presse(void);

//extern uint8_t boutons_actifs;

#endif