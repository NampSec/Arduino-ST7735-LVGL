#ifndef __SPILCD_H
#define __SPILCD_H
#include <Arduino.h>
#include <SPI.h>
#include "../GPIO/gpio.h"
#define SPICLK (1000000)
void spi_init();
void spi_send8(uint8_t data);
void spi_send16(uint16_t data);
uint32_t spi_read(uint8_t query_instc,uint16_t size);
#endif
