#include "lcd_i2c.h"
#include "string.h"

#define LCD_ADDR (0x27 << 1)
#define LCD_BACKLIGHT 0x08
#define LCD_ENABLE 0x04

static I2C_HandleTypeDef *lcd_i2c;

static void LCD_SendCommand(uint8_t cmd);
static void LCD_SendData(uint8_t data);
static void LCD_SendNibble(uint8_t nibble, uint8_t mode);

void LCD_Init(I2C_HandleTypeDef *hi2c)
{
    lcd_i2c = hi2c;
    HAL_Delay(50);

    LCD_SendNibble(0x30, 0);
    HAL_Delay(5);
    LCD_SendNibble(0x30, 0);
    HAL_Delay(1);
    LCD_SendNibble(0x30, 0);
    HAL_Delay(10);
    LCD_SendNibble(0x20, 0); // mode 4 bits

    LCD_SendCommand(0x28);
    LCD_SendCommand(0x0C);
    LCD_SendCommand(0x06);
    LCD_Clear();
}

void LCD_Clear(void)
{
    LCD_SendCommand(0x01);
    HAL_Delay(2);
}

void LCD_SetCursor(uint8_t row, uint8_t col)
{
    uint8_t pos[] = {0x00, 0x40};
    LCD_SendCommand(0x80 + pos[row] + col);
}

void LCD_Print(char *str)
{
    while (*str)
        LCD_SendData((uint8_t)*str++);
}

static void LCD_SendCommand(uint8_t cmd)
{
    LCD_SendNibble(cmd & 0xF0, 0);
    LCD_SendNibble((cmd << 4) & 0xF0, 0);
}

static void LCD_SendData(uint8_t data)
{
    LCD_SendNibble(data & 0xF0, 1);
    LCD_SendNibble((data << 4) & 0xF0, 1);
}

static void LCD_SendNibble(uint8_t nibble, uint8_t mode)
{
    uint8_t data = nibble | LCD_BACKLIGHT | (mode ? 0x01 : 0x00);
    uint8_t data_e = data | LCD_ENABLE;

    uint8_t buf[4] = {data, data_e, data, 0};
    HAL_I2C_Master_Transmit(lcd_i2c, LCD_ADDR, buf, 4, HAL_MAX_DELAY);
}
