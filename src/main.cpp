/*
1.8寸LCD屏幕驱动和LVGL移植
*/
#include <Arduino.h>
#include "../lib/LCD/lcd.h"
#include "../lib/GPIO/gpio.h"
#include "../lib/SPI/spi_lcd.h"
// #if USE_LVGL
// #include "../lib/LVGL/lvgl.h"
// #include "../lib/PORT/lv_port_disp.h"
// #include "../lib/PORT/example.h"
// #endif
#include <SPI.h>
#include "../lib/LCD/font.h"
#include <WiFi.h>
SPIClass * vspi = NULL;
WiFiServer server(1227);

void setup() {
	vspi = new SPIClass(VSPI);
	Serial.begin(9600);
	// #if USE_LVGL
    // lv_init();
	// #endif
	lcd_init();
	WiFi.begin("RedmiNote8", "a1b2c3d4");
	while (WiFi.status() != WL_CONNECTED) {
		Serial.print("."); // Keep the serial monitor lit!
		delay(500);
	}

	// #if USE_LVGL
	// lv_port_disp_init();
	// lv_example_get_started_1();
	// #endif
	lcd_draw_rectangle(0,0,WIDTH,HEIGHT,WHITE);
	delay(500);
	server.begin();
	// font_16_print(strdate,sizeof(strdate)/sizeof(uint8_t),0,10);//该函数调用时一定注意不要超出范围
	// font_16_print(strfile,sizeof(strfile)/sizeof(uint8_t),0,30);
	// font_16_print(strdev,sizeof(strdev)/sizeof(uint8_t),0,50);

}

void loop() {
	delay(5000);
	// #if USE_LVGL
	// lv_timer_handler();
    // #endif

	uint8_t x,y = 0;
	uint8_t buf[34];
    // Use WiFiClient class to create TCP connections
	WiFiClient client = server.available();
    while (client) {
		if(client.available()) 
		{             // if there's bytes to read from the client,
        client.readBytes(buf,34);             // read bytes
		// uint8_t len = buf[0];
        // read line till
	  	// uint8_t * ptr = &buf[1];
		if(buf[0] >= 0 && buf[0] <= 128)//可以后续在这里添加特定的命令
		{
			font_16_print_char(buf[0],buf[1],&buf[2]);
		}
		// remove space, to check if the line is end of headers
		buf[0] = 0;
		}


    }
	// client.stop();
	// Serial.println("Client Disconnected.");

	  

	  

	
	


//下面是屏幕测试代码
	// lcd_draw_rectangle(0,0,WIDTH,HEIGHT,WHITE);
	// delay(3000);
	// lcd_draw_rectangle(0,0,WIDTH,HEIGHT,BLACK);
	// delay(3000);
	// lcd_draw_rectangle(0,0,WIDTH,HEIGHT,BLUE);
	// delay(3000);
	// lcd_draw_rectangle(0,0,WIDTH,HEIGHT,GREEN);
	// delay(3000);
}
