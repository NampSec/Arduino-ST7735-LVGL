#ifndef __GPIO_H
#define __GPIO_H
//分别对应A10-A13四个GPIO
#define LCD_RES 4
#define LCD_DC 0
#define LCD_BLK 15
#include <Arduino.h>
void lcd_gpio_init();
void led_init();
#endif
