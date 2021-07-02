#pragma once

#include <Battery_Controller.h>

#define isMargin false
class ScreenController {
    public :
        void init();
        void splash_screen();
        void welcome_screen();
        void home();
        void check_input();
        static BatteryController batteryController;
        static int currentIcon;
    protected:
        static Adafruit_SSD1306 display;
        static bool atHome;
    private :
        void display_logo();
        void setup_display();
        void icons(int id);
        void show_arrows(int id);
        void scroll_animation(bool toLeft);
        void alert();
        const unsigned char* get_bit_array(int id);
};

