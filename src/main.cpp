#include <Arduino.h>
#include <Screen_Controller.h>

ScreenController screenController ;

void setup() {
  
  Serial.begin(115200);
  screenController.init();

}

void loop(){
  
  screenController.splash_screen();
  // Serial.println("done");
}

