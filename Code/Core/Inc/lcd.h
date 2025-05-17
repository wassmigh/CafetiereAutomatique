#ifndef LCD_H
#define LCD_H
#include <stdint.h>  

void LCD_Init(void);
void LCD_Send_Cmd(uint8_t cmd);
void LCD_Send_Data(uint8_t data);
void LCD_Send_String(char *str);
void LCD_Clear(void);

#endif