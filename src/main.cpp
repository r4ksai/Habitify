#include <Arduino.h>
#include <Screen_Controller.h>

#define OK 3

ScreenController screenController ;

void setup() {
  
  Serial.begin(115200);
  pinMode(OK,INPUT_PULLUP);
  screenController.init();

  screenController.splash_screen();
  delay(1000);
  screenController.welcome_screen();
  delay(2000);

}

void loop(){
  screenController.home();
  screenController.check_input();
  // Serial.println("done");
}

