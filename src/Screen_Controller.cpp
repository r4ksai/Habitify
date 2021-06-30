#include <Screen_Controller.h>
#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Globals.h>
#include <Battery_Controller.h>

#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
String name = "Sai";
BatteryController ScreenController::batteryController ;
Adafruit_SSD1306 ScreenController::display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void ScreenController::init(){
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  batteryController.init(&display);
}


void ScreenController::setup_display(){
  if (isMargin)
    display.drawRect(MARGIN,MARGIN,SCREEN_WIDTH-(2*MARGIN),SCREEN_HEIGHT-(2*MARGIN),WHITE);
  batteryController.show_battery();
}

void ScreenController::splash_screen(){
  display.clearDisplay();

  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);

  display.display();;
}

void ScreenController::welcome_screen(){
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(3,18);
    display.cp437(true);
    display.print(F("Welcome"));
    display.setCursor(80,38);
    display.print(name);
    display.display();
}

void ScreenController::home(){
  display.clearDisplay();
  setup_display();
  display.display();
}

void ScreenController::alert(){

}
