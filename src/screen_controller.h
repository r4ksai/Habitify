#pragma once

#include <Battery_Controller.h>

#define isMargin false
class ScreenController {
    public :
        void init();
        void splash_screen();
        void welcome_screen();
        void home();
        static BatteryController batteryController;
    protected:
        static Adafruit_SSD1306 display;
    private :
        void display_logo();
        void setup_display();
        void alert();
};

