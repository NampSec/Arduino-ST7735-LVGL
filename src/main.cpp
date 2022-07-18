/*
1.8寸LCD屏幕驱动和LVGL移植
*/

#include <Arduino.h>
#include "../lib/LCD/lcd.h"
#include "../lib/GPIO/gpio.h"
#include "../lib/SPI/spi_lcd.h"
#include "../lib/LVGL/lvgl.h"
#include "../lib/PORT/lv_port_disp.h"
#include "../lib/PORT/example.h"
#include <SPI.h>
SPIClass * vspi = NULL;


void setup() {
	vspi = new SPIClass(VSPI);
	Serial.begin(9600);
    lv_init();
	lcd_init();
	lv_port_disp_init();
	lv_example_get_started_1();
}

void loop() {
	delay(500);
	lv_timer_handler();
    
    
    // lv_obj_t * btn = lv_btn_create(lv_scr_act());     /*Add a button the current screen*/
    // lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
    // lv_obj_set_size(btn, 120, 50);                          /*Set its size*/
    // lv_obj_t * label = lv_label_create(btn);          /*Add a label to the button*/
    // lv_label_set_text(label, "Button");                     /*Set the labels text*/
    // lv_obj_center(label);



	// lcd_draw_rectangle(0,0,WIDTH,HEIGHT,WHITE);
	// delay(3000);
	// lcd_draw_rectangle(0,0,WIDTH,HEIGHT,BLACK);
	// delay(3000);
	// lcd_draw_rectangle(0,0,WIDTH,HEIGHT,BLUE);
	// delay(3000);
	// lcd_draw_rectangle(0,0,WIDTH,HEIGHT,GREEN);
	// delay(3000);
}
