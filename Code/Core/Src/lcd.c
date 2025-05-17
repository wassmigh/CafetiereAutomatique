#include "lcd.h"
#include "stm32f4xx_hal.h"

// Définitions des broches
#define LCD_RS_Pin GPIO_PIN_1
#define LCD_RW_Pin GPIO_PIN_0
#define LCD_E_Pin  GPIO_PIN_10
#define LCD_D4_Pin GPIO_PIN_12
#define LCD_D5_Pin GPIO_PIN_13
#define LCD_D6_Pin GPIO_PIN_14
#define LCD_D7_Pin GPIO_PIN_15
#define LCD_GPIO GPIOB

// Fonctions internes
void LCD_Enable(void);
void LCD_Send_4Bits(uint8_t data);

void LCD_Init(void) {
    HAL_Delay(50);
    LCD_Send_4Bits(0x03); HAL_Delay(5);
    LCD_Send_4Bits(0x03); HAL_Delay(5);
    LCD_Send_4Bits(0x03); HAL_Delay(5);
    LCD_Send_4Bits(0x02); HAL_Delay(1); // Mode 4-bit

    LCD_Send_Cmd(0x28); // 2 lignes, 5x8 font
    LCD_Send_Cmd(0x0C); // Affichage ON, curseur OFF
    LCD_Send_Cmd(0x06); // Incrément auto
    LCD_Clear();
}

void LCD_Clear(void) {
    LCD_Send_Cmd(0x01);
    HAL_Delay(2);
}

void LCD_Send_Cmd(uint8_t cmd) {
    HAL_GPIO_WritePin(LCD_GPIO, LCD_RS_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_GPIO, LCD_RW_Pin, GPIO_PIN_RESET);
    LCD_Send_4Bits(cmd >> 4);
    LCD_Send_4Bits(cmd & 0x0F);
}

void LCD_Send_Data(uint8_t data) {
    HAL_GPIO_WritePin(LCD_GPIO, LCD_RS_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LCD_GPIO, LCD_RW_Pin, GPIO_PIN_RESET);
    LCD_Send_4Bits(data >> 4);
    LCD_Send_4Bits(data & 0x0F);
}

void LCD_Send_4Bits(uint8_t data) {
    HAL_GPIO_WritePin(LCD_GPIO, LCD_D4_Pin, (data & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_GPIO, LCD_D5_Pin, (data & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_GPIO, LCD_D6_Pin, (data & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_GPIO, LCD_D7_Pin, (data & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    LCD_Enable();
}

void LCD_Enable(void) {
    HAL_GPIO_WritePin(LCD_GPIO, LCD_E_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(LCD_GPIO, LCD_E_Pin, GPIO_PIN_RESET);
    HAL_Delay(1);
}

void LCD_Send_String(char *str) {
    while(*str) {
        LCD_Send_Data((uint8_t)(*str));
        str++;
    }
}	