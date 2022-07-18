#include "spi_lcd.h"

void spi_init()
{
  extern SPIClass * vspi;
  vspi->begin();
  pinMode(vspi->pinSS(),OUTPUT);
}
void spi_send8(uint8_t data)
{
  extern SPIClass * vspi;
  vspi->beginTransaction(SPISettings(SPICLK, MSBFIRST, SPI_MODE0));
  digitalWrite(vspi->pinSS(), LOW); //pull SS slow to prep other end for transfer
  vspi->write(data);
  digitalWrite(vspi->pinSS(), HIGH); //pull ss high to signify end of data transfer
  vspi->endTransaction();

}
void spi_send16(uint16_t data)
{
  extern SPIClass * vspi;
  vspi->beginTransaction(SPISettings(SPICLK, MSBFIRST, SPI_MODE0));
  digitalWrite(vspi->pinSS(), LOW); //pull SS slow to prep other end for transfer
  vspi->write16(data);
  digitalWrite(vspi->pinSS(), HIGH); //pull ss high to signify end of data transfer
  vspi->endTransaction();
}


/*
从数据手册里面可以看出来，spi在发送完读命令最后一个位之后，在SCK的下降沿屏幕开始在SDA上发送数据。
通过SS上拉可以暂时中断立马的读数据
目前最好的办法时通过软件模拟一个SPI，发送并接受
*/
//根据数据手册一共只有三种读数据模式，8bit/24bit/32bit
uint32_t spi_read(uint8_t query_instc,uint16_t size)
{

  assert((size == 8) || (size == 24) || (size == 32));
  uint32_t out = 0;
  pinMode(MOSI,OUTPUT);
  pinMode(SCL,OUTPUT);
  digitalWrite(SCL,LOW);//时钟信号
  digitalWrite(SS,LOW); //片选信号
  digitalWrite(LCD_DC,LOW); //DC/CX型号，低电平为命令或者寄存器
  for(uint16_t i = 0; i < 7 ; i++)
  {
    if((query_instc&&0x80) == 1)
    {
      digitalWrite(MOSI,HIGH);
    }else
    {
      digitalWrite(MOSI,LOW);
    }
    query_instc = query_instc << 1;
    digitalWrite(SCL,HIGH);
    delay(1);
    digitalWrite(SCL,LOW);
    delay(1);
  }
  if((query_instc&&0x80) == 1)
  {
    digitalWrite(MOSI,HIGH);
  }else
  {
    digitalWrite(MOSI,LOW);
  }
  digitalWrite(SCL,HIGH);
  pinMode(MOSI,INPUT);
  delay(1);
  digitalWrite(SCL,LOW);
  delay(1);
  for(uint16_t i = 0; i < size ; i++)
  {
    if (digitalRead(MOSI) == HIGH)
    {
      out |= 1<<(size - i -1);
    } 
    digitalWrite(SCL,HIGH);
    delay(1);
    digitalWrite(SCL,LOW);
    delay(1);
  }

  digitalWrite(LCD_DC,HIGH);
  digitalWrite(SS,HIGH);
  pinMode(MOSI,OUTPUT);
  //恢复为输出模式
  return out;


}