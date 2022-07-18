#include "gpio.h"
void led_init()
{
    pinMode(LED_BUILTIN,OUTPUT);
    digitalWrite(LED_BUILTIN,HIGH);
}
void lcd_gpio_init()
{
    pinMode(LCD_RES,OUTPUT);
    digitalWrite(LCD_RES,HIGH);
    pinMode(LCD_DC,OUTPUT);
    digitalWrite(LCD_DC,HIGH);
    pinMode(LCD_BLK,OUTPUT);
    digitalWrite(LCD_BLK,HIGH);
}
