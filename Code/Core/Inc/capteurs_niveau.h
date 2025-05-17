#ifndef CAPTEUR_NIVEAU_H
#define CAPTEUR_NIVEAU_H

#include <stdint.h>

void CAPTEUR_Init(void);
uint16_t Lire_Niveau_Cafe(void);
uint16_t Lire_Niveau_Lait(void);
uint16_t Lire_Seuil_Cafe(void);
uint16_t Lire_Seuil_Lait(void);

#endif