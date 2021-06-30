#pragma once

#include <Globals.h>

#define BATTERY_HEIGHT 4
#define BATTERY_WIDTH 15
#define BATTERY_KNOB_HEIGHT 2
#define BATTERY_KNOB_WIDTH 1
#define BATTERY_X SCREEN_WIDTH - BATTERY_WIDTH - MARGIN - BATTERY_KNOB_WIDTH
#define BATTERY_Y MARGIN
#define BATTERY_KNOB_X BATTERY_X+BATTERY_WIDTH
#define BATTERY_KNOB_Y BATTERY_Y+((BATTERY_HEIGHT/2) - (BATTERY_KNOB_HEIGHT/2))
#define BATTERY_CHARGE_X BATTERY_X + 1
#define BATTERY_CHARGE_Y BATTERY_KNOB_Y
#define BATTERY_DIVIDER BATTERY_WIDTH
#define MIN_VOLTAGE 74  // 74 --> 3.7/5 * 100 %
#define MAX_VOLTAGE 84  // 84 --> 4.2/5 * 100 %
#define ALERT_TRESHOLD 20
#define BATTERY_PIN A0
#define CHARGE_STATUS_PIN 2

class BatteryController {
    public :
        void init(Adafruit_SSD1306* _display);
        void show_battery();
    private :
        static int charge;
        static bool isCharging;
        int get_percentage();
        void get_charge();
        void check_charging();
        void low_charge_alert();
        static bool alerted;
        static Adafruit_SSD1306* display;
};