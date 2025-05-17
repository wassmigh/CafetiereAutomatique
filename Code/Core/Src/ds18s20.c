#include "ds18s20.h"
#include "delay.h"  // Nécessaire pour avoir des fonctions delay_us et delay_ms

#define DS18S20_PORT GPIOA
#define DS18S20_PIN  GPIO_PIN_5

static void DS18S20_Pin_Output(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DS18S20_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(DS18S20_PORT, &GPIO_InitStruct);
}

static void DS18S20_Pin_Input(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = DS18S20_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DS18S20_PORT, &GPIO_InitStruct);
}

static uint8_t DS18S20_Reset(void) {
    uint8_t response = 0;
    DS18S20_Pin_Output();
    HAL_GPIO_WritePin(DS18S20_PORT, DS18S20_PIN, GPIO_PIN_RESET);
    delay_us(480);
    DS18S20_Pin_Input();
    delay_us(80);
    response = HAL_GPIO_ReadPin(DS18S20_PORT, DS18S20_PIN);
    delay_us(400);
    return response == 0 ? 1 : 0;
}

static void DS18S20_WriteBit(uint8_t bit) {
    DS18S20_Pin_Output();
    HAL_GPIO_WritePin(DS18S20_PORT, DS18S20_PIN, GPIO_PIN_RESET);
    delay_us(bit ? 1 : 60);
    HAL_GPIO_WritePin(DS18S20_PORT, DS18S20_PIN, GPIO_PIN_SET);
    delay_us(bit ? 60 : 1);
}

static uint8_t DS18S20_ReadBit(void) {
    uint8_t bit = 0;
    DS18S20_Pin_Output();
    HAL_GPIO_WritePin(DS18S20_PORT, DS18S20_PIN, GPIO_PIN_RESET);
    delay_us(1);
    DS18S20_Pin_Input();
    delay_us(14);
    bit = HAL_GPIO_ReadPin(DS18S20_PORT, DS18S20_PIN);
    delay_us(45);
    return bit;
}

static void DS18S20_WriteByte(uint8_t byte) {
    for (int i = 0; i < 8; i++) {
        DS18S20_WriteBit(byte & 0x01);
        byte >>= 1;
    }
}

static uint8_t DS18S20_ReadByte(void) {
    uint8_t byte = 0;
    for (int i = 0; i < 8; i++) {
        byte |= (DS18S20_ReadBit() << i);
    }
    return byte;
}

void DS18S20_Init(void) {
    // Initialisation déjà faite dans MX_GPIO_Init()
}

float DS18S20_ReadTemperature(void) {
    uint8_t temp_lsb, temp_msb;
    int16_t temp_raw;
    float temp_c;

    if (DS18S20_Reset()) {
        DS18S20_WriteByte(0xCC); // Skip ROM
        DS18S20_WriteByte(0x44); // Convert T
        HAL_Delay(750); // Conversion

        DS18S20_Reset();
        DS18S20_WriteByte(0xCC); // Skip ROM
        DS18S20_WriteByte(0xBE); // Read Scratchpad

        temp_lsb = DS18S20_ReadByte();
        temp_msb = DS18S20_ReadByte();
        temp_raw = (temp_msb << 8) | temp_lsb;
        temp_c = (float)temp_raw / 2.0;  // Résolution DS18S20 : 0.5°C

        return temp_c;
    }
    return -1000.0; // Erreur
}
