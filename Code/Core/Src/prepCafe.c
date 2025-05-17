#include "prepCafe.h"
#include "reapprovisionnement.h"
#include "reapprovisionnement.h"
void prepCafeLoop(void)
{
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4) == GPIO_PIN_SET)
    {
        MaintenanceLoop();  
    }
    else
    {
				verifier_niveaux_et_declencher_reappro();
				if (boutons_actifs == 1){
					EtatAttenteLoop();
					if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == GPIO_PIN_SET || HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1) == GPIO_PIN_SET)
					{
							if (ChoixCafeLoop())
							{          
									BrassageLoop();
							}
					}
				}
    }
}