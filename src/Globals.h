#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define MARGIN 2

// Keys
#define LEFT 4
#define RIGHT 3

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{   
    B00000000, B11000000,
    B00000001, B11000000,
    B00000001, B11000000,
    B00000011, B11100000,
    B11110011, B11100000,
    B11111110, B11111000,
    B01111110, B11111111,
    B00110011, B10011111,
    B00011111, B11111100,
    B00001101, B01110000,
    B00011011, B10100000,
    B00111111, B11100000,
    B00111111, B11110000,
    B01111100, B11110000,
    B01110000, B01110000,
    B00000000, B00110000 };

#define MAX_ICONS 2

#define ICON_WIDTH 50
#define ICON_HEIGHT 50

/*
	Resize images using 	:- https://www.reduceimages.com/
	Create Icons using 	:- https://www.pixilart.com/draw
	Convert to bitmap using 	:- https://diyusthad.com/image2cpp
	
*/

static const unsigned char PROGMEM sunrise_bmp[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x06, 0x40, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0, 0xc0, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x80, 
	0xc0, 0x1d, 0xc0, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x07, 0x20, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x02, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x02, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x80, 0x00, 0x00, 
	0x00, 0x00, 0xe0, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x70, 0xc3, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x38, 0xc3, 0x00, 0x00, 0x00, 0x00, 0x40, 0x10, 0x06, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x02, 
	0x01, 0x80, 0x00, 0x00, 0x18, 0x07, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x0e, 0x0c, 0x0e, 0x0c, 0x00, 
	0x00, 0x00, 0x03, 0x38, 0xf3, 0x38, 0x00, 0x00, 0x00, 0x00, 0x20, 0x19, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x60, 0x0d, 0x80, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x80, 
	0x00, 0x40, 0x00, 0x00, 0x00, 0x7e, 0x80, 0x00, 0x5f, 0x80, 0x00, 0x00, 0x7e, 0x80, 0x00, 0x5f, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 
	0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    static const unsigned char PROGMEM meditate_bmp[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xfe, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x0f, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x0c, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x98, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 
	0xe0, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x01, 0xbf, 0xff, 0xd8, 0x00, 
	0x00, 0x00, 0x03, 0x1f, 0xff, 0x8c, 0x00, 0x00, 0x00, 0x06, 0x3f, 0xff, 0xc4, 0x00, 0x00, 0x00, 
	0x04, 0x4f, 0xff, 0x76, 0x00, 0x00, 0x00, 0x0c, 0x8f, 0xdf, 0x13, 0x00, 0x00, 0x00, 0x08, 0x8f, 
	0x8f, 0x11, 0x00, 0x00, 0x00, 0x18, 0xff, 0x07, 0xf1, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x03, 
	0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x00, 
	0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x0f, 0xff, 0x0f, 0xe0, 0x00, 0x01, 0xe1, 0xff, 0xff, 
	0xff, 0xb0, 0x00, 0x03, 0xc0, 0x78, 0x00, 0xf8, 0x90, 0x00, 0x02, 0x40, 0x30, 0x00, 0xf0, 0x90, 
	0x00, 0x03, 0x60, 0x1c, 0x03, 0xc1, 0xf0, 0x00, 0x01, 0xb0, 0x07, 0x0f, 0x03, 0xc0, 0x00, 0x00, 
	0xfc, 0x01, 0xfc, 0x03, 0x80, 0x00, 0x00, 0x3e, 0x00, 0x38, 0x0e, 0x00, 0x00, 0x00, 0x03, 0xff, 
	0xff, 0xf8, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x07, 0xfe, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x01, 0xfc, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};



    static const unsigned char PROGMEM running_bmp[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xfe, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x0f, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x0c, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x98, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 
	0xe0, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x01, 0xbf, 0xff, 0xd8, 0x00, 
	0x00, 0x00, 0x03, 0x1f, 0xff, 0x8c, 0x00, 0x00, 0x00, 0x06, 0x3f, 0xff, 0xc4, 0x00, 0x00, 0x00, 
	0x04, 0x4f, 0xff, 0x76, 0x00, 0x00, 0x00, 0x0c, 0x8f, 0xdf, 0x13, 0x00, 0x00, 0x00, 0x08, 0x8f, 
	0x8f, 0x11, 0x00, 0x00, 0x00, 0x18, 0xff, 0x07, 0xf1, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x03, 
	0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x00, 
	0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x0f, 0xff, 0x0f, 0xe0, 0x00, 0x01, 0xe1, 0xff, 0xff, 
	0xff, 0xb0, 0x00, 0x03, 0xc0, 0x78, 0x00, 0xf8, 0x90, 0x00, 0x02, 0x40, 0x30, 0x00, 0xf0, 0x90, 
	0x00, 0x03, 0x60, 0x1c, 0x03, 0xc1, 0xf0, 0x00, 0x01, 0xb0, 0x07, 0x0f, 0x03, 0xc0, 0x00, 0x00, 
	0xfc, 0x01, 0xfc, 0x03, 0x80, 0x00, 0x00, 0x3e, 0x00, 0x38, 0x0e, 0x00, 0x00, 0x00, 0x03, 0xff, 
	0xff, 0xf8, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x07, 0xfe, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x01, 0xfc, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};