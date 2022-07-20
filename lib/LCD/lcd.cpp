#include "lcd.h"

void lcd_init()
{
    led_init();
    Serial.println("LED init Success");//初始化LED
    lcd_gpio_init();
    Serial.println("GPIO init Success");//初始化LCD控制GPIO
    spi_init();
    Serial.println("SPI init Success");//初始化SPI
    lcd_res_clear();//复位屏幕
    delay(100);
    lcd_res_set();
    delay(100);
    lcd_blk_set();//开启背光

    lcd_write_reg(0x11); //Sleep out 
	delay(120);              //Delay 120ms 
	//------------------------------------ST7735S Frame Rate-----------------------------------------// 
	lcd_write_reg(0xB1); 
	lcd_write_data8(0x05); 
	lcd_write_data8(0x3C); 
	lcd_write_data8(0x3C); 
	lcd_write_reg(0xB2); 
	lcd_write_data8(0x05);
	lcd_write_data8(0x3C); 
	lcd_write_data8(0x3C); 
	lcd_write_reg(0xB3); 
	lcd_write_data8(0x05); 
	lcd_write_data8(0x3C); 
	lcd_write_data8(0x3C); 
	lcd_write_data8(0x05); 
	lcd_write_data8(0x3C); 
	lcd_write_data8(0x3C); 
	//------------------------------------End ST7735S Frame Rate---------------------------------// 
	lcd_write_reg(0xB4); //Dot inversion 
	lcd_write_data8(0x03); 
	//------------------------------------ST7735S Power Sequence---------------------------------// 
	lcd_write_reg(0xC0); 
	lcd_write_data8(0x28); 
	lcd_write_data8(0x08); 
	lcd_write_data8(0x04); 
	lcd_write_reg(0xC1); 
	lcd_write_data8(0XC0); 
	lcd_write_reg(0xC2); 
	lcd_write_data8(0x0D); 
	lcd_write_data8(0x00); 
	lcd_write_reg(0xC3); 
	lcd_write_data8(0x8D); 
	lcd_write_data8(0x2A); 
	lcd_write_reg(0xC4); 
	lcd_write_data8(0x8D); 
	lcd_write_data8(0xEE); 
	//---------------------------------End ST7735S Power Sequence-------------------------------------// 
	lcd_write_reg(0xC5); //VCOM 
	lcd_write_data8(0x1A); 
	lcd_write_reg(0x36); //MX, MY, RGB mode 
	#if(USE_HORIZONTAL==0)
	lcd_write_data8(0x00);
	#elif(USE_HORIZONTAL==1)
	lcd_write_data8(0xC0);
	#elif(USE_HORIZONTAL==2)
	lcd_write_data8(0x70);
	#else
	lcd_write_data8(0xA0); 
	#endif
	//------------------------------------ST7735S Gamma Sequence---------------------------------// 
	lcd_write_reg(0xE0); 
	lcd_write_data8(0x04); 
	lcd_write_data8(0x22); 
	lcd_write_data8(0x07); 
	lcd_write_data8(0x0A); 
	lcd_write_data8(0x2E); 
	lcd_write_data8(0x30); 
	lcd_write_data8(0x25); 
	lcd_write_data8(0x2A); 
	lcd_write_data8(0x28); 
	lcd_write_data8(0x26); 
	lcd_write_data8(0x2E); 
	lcd_write_data8(0x3A); 
	lcd_write_data8(0x00); 
	lcd_write_data8(0x01); 
	lcd_write_data8(0x03); 
	lcd_write_data8(0x13); 
	lcd_write_reg(0xE1); 
	lcd_write_data8(0x04); 
	lcd_write_data8(0x16); 
	lcd_write_data8(0x06); 
	lcd_write_data8(0x0D); 
	lcd_write_data8(0x2D); 
	lcd_write_data8(0x26); 
	lcd_write_data8(0x23); 
	lcd_write_data8(0x27); 
	lcd_write_data8(0x27); 
	lcd_write_data8(0x25); 
	lcd_write_data8(0x2D); 
	lcd_write_data8(0x3B); 
	lcd_write_data8(0x00); 
	lcd_write_data8(0x01); 
	lcd_write_data8(0x04); 
	lcd_write_data8(0x13); 
	//------------------------------------End ST7735S Gamma Sequence-----------------------------// 
	lcd_write_reg(0x3A); //65k mode 
	lcd_write_data8(0x05); 
	lcd_write_reg(0x29); //Display on 


}

void lcd_res_clear()
{
    digitalWrite(LCD_RES,LOW);
}

void lcd_res_set()
{
    digitalWrite(LCD_RES,HIGH);
}
void lcd_blk_set()
{
    digitalWrite(LCD_BLK,HIGH);
}
void lcd_write_data8(uint8_t data)
{
	spi_send8(data);
}
void lcd_write_data16(uint16_t data)
{
	spi_send16(data);
}
void lcd_write_reg(uint8_t data)
{
	digitalWrite(LCD_DC,LOW);
	spi_send8(data);
	digitalWrite(LCD_DC,HIGH);
}
void lcd_addr_set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	#if(USE_HORIZONTAL==0)
	{
		
		lcd_write_reg(0x2a);//行地址
		lcd_write_data16(x1);
		lcd_write_data16(x2);
		lcd_write_reg(0x2b);//列地址
		lcd_write_data16(y1);
		lcd_write_data16(y2);
		lcd_write_reg(0x2c);//存储地址
	}
	#elif(USE_HORIZONTAL==1)
	{
		lcd_write_reg(0x2a);//行地址
		lcd_write_data16(x1);
		lcd_write_data16(x2);
		lcd_write_reg(0x2b);//列地址
		lcd_write_data16(y1);
		lcd_write_data16(y2);
		lcd_write_reg(0x2c);//存储地址
	}
	#elif(USE_HORIZONTAL==2)
	{
		lcd_write_reg(0x2a);//行地址
		lcd_write_data16(x1);
		lcd_write_data16(x2);
		lcd_write_reg(0x2b);//列地址
		lcd_write_data16(y1);
		lcd_write_data16(y2);
		lcd_write_reg(0x2c);//存储地址
	}
	#else
	{
		lcd_write_reg(0x2a);//行地址
		lcd_write_data16(x1);
		lcd_write_data16(x2);
		lcd_write_reg(0x2b);//列地址
		lcd_write_data16(y1);
		lcd_write_data16(y2);
		lcd_write_reg(0x2c);//存储地址
	}
	#endif

}

void lcd_draw_rectangle(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color)
{
	uint16_t i,j; 
	lcd_addr_set(x1,y1,x2-1,y2-1);
	for(i=y1;i<y2;i++)
	{                               
		for(j=x1;j<x2;j++)
		{
		lcd_write_data16(color);
		}
	}                   
}
//打印出16x8的一句话
void font_16_print(uint8_t (*ptr)[16],int size,uint8_t x,uint8_t y)
{
	uint8_t temp = 0;
    int row = size / 16;
	assert((x + row * 8 < WIDTH) && (y + 16  < HEIGHT));

    lcd_addr_set(x,y, x + row * 8 - 1,y + 16 - 1);
    for(int i = 0; i < size;i++)
    {

        temp = ptr[i % row][i / row];
        for(int j = 0;j < 8;j++)
        {
            if (temp & 0x01)
                lcd_write_data16(BLACK);//字体颜色
            else
                lcd_write_data16(WHITE);//调试的时候一定不要用空格这些看不见的符号，背景颜色
            temp >>= 1;
        }
    }

}
//打印出16x16一个字
void font_16_print_char(uint8_t x,uint8_t y,uint8_t * data)
{
	uint8_t temp = 0;
	assert((x + 16 <= WIDTH) && (y + 16  <= HEIGHT));
	lcd_addr_set(x,y, x +  16 - 1,y + 16 - 1);
    for(int i = 0; i < 32;i++)
    {

        temp = *data++;
        for(int j = 0;j < 8;j++)
        {
            if (temp & 0x01)
                lcd_write_data16(BLACK);//字体颜色
            else
                lcd_write_data16(WHITE);//调试的时候一定不要用空格这些看不见的符号，背景颜色
            temp >>= 1;
        }
    }

}