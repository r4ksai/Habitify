#include <Screen_Controller.h>
#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Globals.h>
#include <Battery_Controller.h>

#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)


String username = "Sai";
bool ScreenController::atHome;
int ScreenController::currentIcon;
BatteryController ScreenController::batteryController ;
Adafruit_SSD1306 ScreenController::display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void ScreenController::init(){
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  currentIcon = 0;
  atHome = false;
  batteryController.init(&display,&atHome);

  //Set controlls 
  pinMode(RIGHT,INPUT_PULLUP);
  pinMode(LEFT,INPUT_PULLUP);
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
    display.setCursor(8,18);
    display.cp437(true);
    display.print(F("Welcome"));
    display.setCursor(84,38);
    display.print(username);
    display.display();
}

const unsigned char* ScreenController::get_bit_array(int id){
  switch (id) {
    case 0 : return sunrise_bmp;
    case 1 : return meditate_bmp;
    default: return sunrise_bmp;
  }
}


void ScreenController::icons(int id){
  display.drawCircle(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,25,WHITE);
  display.drawBitmap(
    (display.width()  - ICON_WIDTH ) / 2,
    (display.height() - ICON_HEIGHT) / 2,
    get_bit_array(id), ICON_WIDTH, ICON_HEIGHT, 1);
}

void ScreenController::show_arrows(int id){
  if (id != 0){
    // Left Arrow
    display.drawLine(5,SCREEN_HEIGHT/2,18,23,WHITE);
    display.drawLine(5,SCREEN_HEIGHT/2,18,SCREEN_HEIGHT-23,WHITE);
    display.drawLine(4,SCREEN_HEIGHT/2,18,22,WHITE);
    display.drawLine(4,SCREEN_HEIGHT/2,18,SCREEN_HEIGHT-22,WHITE);
  }
  if (id != MAX_ICONS - 1)
  {
    // Right Arrow
    display.drawLine(SCREEN_WIDTH-5,SCREEN_HEIGHT/2,SCREEN_WIDTH-18,23,WHITE);
    display.drawLine(SCREEN_WIDTH-5,SCREEN_HEIGHT/2,SCREEN_WIDTH-18,SCREEN_HEIGHT-23,WHITE);
    display.drawLine(SCREEN_WIDTH-4,SCREEN_HEIGHT/2,SCREEN_WIDTH-18,22,WHITE);
    display.drawLine(SCREEN_WIDTH-4,SCREEN_HEIGHT/2,SCREEN_WIDTH-18,SCREEN_HEIGHT-22,WHITE);

  }
}

void ScreenController::home(){
  atHome = true;
  display.clearDisplay();
  setup_display();
  icons(currentIcon);
  show_arrows(currentIcon);
  display.display();
}

void ScreenController::scroll_animation(){
  // TODO :- Scroll the current icon to the left and scroll the new icon to the left till center and take out the arrows and add the battery
}

void ScreenController::check_input(){ // TODO :- Polling right now, add interrupts
  if (atHome)
  {
    if (!digitalRead(LEFT)){
      scroll_animation();
      if (currentIcon < MAX_ICONS - 1)
        currentIcon++;
    }
    if (!digitalRead(RIGHT)){
      scroll_animation();
      if (currentIcon > 0)
        currentIcon--;
    }
  }
}

void ScreenController::alert(){

}

/*

  TODO :-
  1.Icos will have its own animation for complete and skipped - initially it can just be a tick or a cross (Update add small dots or crosses on the bottom bar)
  2.There are 2 buttons - Left and Right
  3.OK can be held down to clear the icon 
  4.If all the tasks are done then a new icon will be unlocked in the home 
  5.Once a task is done it will skip to the next task
  6.Add Sound 
  7.Add Animation
  8.PCB Design

*/