#ifndef screen_controller_library
#define screen_controller_library

#include <Adafruit_SSD1306.h>

// #pragma once

class Battery {
    public :
        Battery(Adafruit_SSD1306* _d);
        void show_battery();
        void check_charging();

    private :
        static int charge;
        static Adafruit_SSD1306* _display;
        int get_charge();
        void charging(bool _isCharging);
        int get_percentage();
        static bool isCharging;
};

#endif