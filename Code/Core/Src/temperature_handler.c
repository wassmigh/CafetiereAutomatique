#include "temperature_handler.h"
#include "ds18s20.h"
#include "ventilateur.h"
#include <stdint.h>

#define TEMP_THRESHOLD 27.0f


void TemperatureHandler_Update(void) {
    float temp = DS18S20_ReadTemperature();
		
    
    if (temp > TEMP_THRESHOLD ) {


        // Déclenchement venti 
      ventilateur_ON();
			
    
		} else if (temp <= TEMP_THRESHOLD ) {

       // Arret venti
			ventilateur_OFF();
			
			
    }
}

