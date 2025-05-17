#include "maintenance.h"
#include "lcd.h"
#include "main.h"

bool IsMaintenanceMode(void)
{
    return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4) == GPIO_PIN_SET; 
}

void MaintenanceLoop(void)
{
    LCD_Clear();
    LCD_Send_Cmd(0x80); 
    LCD_Send_String("Sous Maintenance");

    while (IsMaintenanceMode())
    {
        HAL_Delay(200);
    }

    LCD_Clear();
}
