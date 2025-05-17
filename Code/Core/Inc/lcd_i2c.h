#ifndef LCD_I2C_H
#define LCD_I2C_H

#include "stm32f4xx_hal.h"       
#include "stm32f4xx_hal_i2c.h" 
void LCD_Init(I2C_HandleTypeDef *hi2c);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_Print(char *str);

#endif
