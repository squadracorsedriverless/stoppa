#include "ws2812_spi.h"
#include <string.h>

uint8_t ws2812_buffer[WS2812_BUF_LEN] = {0};
uint8_t ws2812_empty[WS2812_BUF_LEN] = {0};

uint32_t ws2812_spi_get_led(uint16_t index)
{
    return ws2812_buffer[(index * 24) + index] << 16 | ws2812_buffer[(index * 24) + index + 1] << 8 | ws2812_buffer[(index * 24) + index + 2];
}
void ws2812_spi_set_led(uint16_t index, uint32_t color)
{
    for (uint8_t i = 0; i < 24; i++)
    {
        ws2812_buffer[(index * 24) + i] = ((color >> (24 - i)) & 0b1) ? 0b11111100 : 0b111000000;
    }
}

void ws2812_spi_send(SPI_HandleTypeDef *hspi)
{
    HAL_SPI_Transmit_DMA(hspi, ws2812_buffer, WS2812_BUF_LEN);
}

void HAL_SPI_TxHalfCpltCallback(SPI_HandleTypeDef *hspi)
{
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
}