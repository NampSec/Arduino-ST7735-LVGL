#ifndef __LCD_H
#define __LCD_H
#include "../GPIO/gpio.h"
#include "../SPI/spi_lcd.h"
#include <Arduino.h>
#define USE_HORIZONTAL 0
//0和1为竖屏，2和3为横屏
#define WIDTH 128
#define HEIGHT 160
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40
#define BRRED 			     0XFC07
#define GRAY  			     0X8430
#define DARKBLUE      	 0X01CF
#define LIGHTBLUE      	 0X7D7C
#define GRAYBLUE       	 0X5458
#define LIGHTGREEN     	 0X841F
#define LGRAY 			     0XC618
#define LGRAYBLUE        0XA651
#define LBBLUE           0X2B12
void lcd_init();
void lcd_res_clear();
void lcd_res_set();
void lcd_blk_set();
void lcd_write_reg(uint8_t data);
void lcd_write_data8(uint8_t data);
void lcd_write_data16(uint16_t data);
void lcd_addr_set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void lcd_draw_rectangle(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color);
void font_16_print(uint8_t (*ptr)[16],int size,uint8_t x,uint8_t y);
void font_16_print_char(uint8_t x,uint8_t y,uint8_t * data);
#endif