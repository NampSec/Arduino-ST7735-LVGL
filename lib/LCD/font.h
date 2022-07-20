#ifndef __CUSTOM_FONT_H
#define __CUSTOM_FONT_H
#include <Arduino.h>
uint8_t strdev[][16] = {
{0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x18,0x0C,0x06,0x1C,0x30,0x20,0x00,0x00,0x00},/*"<",0*/
{0x00,0x00,0x00,0x00,0x3E,0x72,0xC2,0xC2,0xC2,0xC2,0xE2,0x72,0x3E,0x00,0x00,0x00},/*"D",1*/
{0x00,0x00,0x00,0x00,0x7E,0x06,0x06,0x06,0x7E,0x06,0x06,0x06,0x7E,0x00,0x00,0x00},/*"E",2*/
{0x00,0x00,0x00,0x00,0xC3,0xC3,0x46,0x66,0x66,0x2C,0x3C,0x3C,0x18,0x00,0x00,0x00},/*"V",3*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},/*":",4*/
{0x00,0x00,0x00,0x1E,0x1E,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x7E,0x00,0x00,0x00},/*"l",5*/
{0x00,0x00,0x00,0x00,0x00,0x00,0xC3,0x46,0x66,0x6C,0x3C,0x3C,0x18,0x00,0x00,0x00},/*"v",6*/
{0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x66,0x66,0x7E,0x1E,0x06,0x7C,0xC2,0x66,0x3C},/*"g",7*/
{0x00,0x00,0x00,0x1E,0x1E,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x7E,0x00,0x00,0x00},/*"l",8*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00},/*"-",9*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x76,0x6E,0xC6,0x06,0x06,0x06,0x06,0x00,0x00,0x00},/*"r",10*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x66,0x46,0x7E,0x06,0x06,0x7C,0x00,0x00,0x00},/*"e",11*/
{0x00,0x00,0x00,0x1E,0x1E,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x7E,0x00,0x00,0x00},/*"l",12*/
{0x00,0x00,0x00,0x00,0x00,0x04,0x0E,0x18,0x70,0x60,0x38,0x1C,0x04,0x00,0x00,0x00},/*">",13*/
};
uint8_t strfile[][16] = 
{
{0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x18,0x0C,0x06,0x1C,0x30,0x20,0x00,0x00,0x00},/*"<",0*/
{0x00,0x00,0x00,0x00,0x7E,0x06,0x06,0x06,0x7E,0x06,0x06,0x06,0x06,0x00,0x00,0x00},/*"F",1*/
{0x00,0x00,0x00,0x00,0x7E,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x7E,0x00,0x00,0x00},/*"I",2*/
{0x00,0x00,0x00,0x00,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x7E,0x00,0x00,0x00},/*"L",3*/
{0x00,0x00,0x00,0x00,0x7E,0x06,0x06,0x06,0x7E,0x06,0x06,0x06,0x7E,0x00,0x00,0x00},/*"E",4*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},/*":",5*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x6F,0xDF,0xDB,0xDB,0xDB,0xDB,0xDB,0x00,0x00,0x00},/*"m",6*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x62,0x60,0x7C,0x66,0x66,0x5E,0x00,0x00,0x00},/*"a",7*/
{0x00,0x00,0x00,0x18,0x18,0x00,0x1E,0x18,0x18,0x18,0x18,0x18,0x7E,0x00,0x00,0x00},/*"i",8*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x6E,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00},/*"n",9*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},/*".",10*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x4C,0x06,0x06,0x06,0x4E,0x7C,0x00,0x00,0x00},/*"c",11*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x6E,0xC6,0xC6,0xC6,0x66,0x3E,0x06,0x06,0x06},/*"p",12*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x6E,0xC6,0xC6,0xC6,0x66,0x3E,0x06,0x06,0x06},/*"p",13*/
{0x00,0x00,0x00,0x00,0x00,0x04,0x0E,0x18,0x70,0x60,0x38,0x1C,0x04,0x00,0x00,0x00},/*">",14*/
};
uint8_t strdate[][16] = 
{
{0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x18,0x0C,0x06,0x1C,0x30,0x20,0x00,0x00,0x00},/*"<",0*/
{0x00,0x00,0x00,0x00,0x3E,0x72,0xC2,0xC2,0xC2,0xC2,0xE2,0x72,0x3E,0x00,0x00,0x00},/*"D",1*/
{0x00,0x00,0x00,0x00,0x38,0x3C,0x3C,0x2C,0x66,0x66,0x7E,0xC2,0xC3,0x00,0x00,0x00},/*"A",2*/
{0x00,0x00,0x00,0x00,0xFE,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00},/*"T",3*/
{0x00,0x00,0x00,0x00,0x7E,0x06,0x06,0x06,0x7E,0x06,0x06,0x06,0x7E,0x00,0x00,0x00},/*"E",4*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},/*":",5*/
{0x00,0x00,0x00,0x00,0x3C,0x76,0x60,0x60,0x30,0x38,0x0C,0x7E,0x7E,0x00,0x00,0x00},/*"2",6*/
{0x00,0x00,0x00,0x00,0x3C,0x76,0x60,0x60,0x30,0x38,0x0C,0x7E,0x7E,0x00,0x00,0x00},/*"2",7*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00},/*"-",8*/
{0x00,0x00,0x00,0x00,0x3C,0x66,0xC6,0xF3,0xDB,0xCF,0xC2,0x66,0x3C,0x00,0x00,0x00},/*"0",9*/
{0x00,0x00,0x00,0x00,0x7E,0x7E,0x60,0x30,0x30,0x18,0x18,0x0C,0x0C,0x00,0x00,0x00},/*"7",10*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00},/*"-",11*/
{0x00,0x00,0x00,0x00,0x18,0x1E,0x12,0x10,0x10,0x10,0x10,0x10,0x7E,0x00,0x00,0x00},/*"1",12*/
{0x00,0x00,0x00,0x00,0x3C,0x66,0x62,0x46,0x7E,0x5C,0x60,0x70,0x1E,0x00,0x00,0x00},/*"9",13*/
{0x00,0x00,0x00,0x00,0x00,0x04,0x0E,0x18,0x70,0x60,0x38,0x1C,0x04,0x00,0x00,0x00},/*">",14*/
};

#endif
