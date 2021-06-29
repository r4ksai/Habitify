#include <Adafruit_SSD1306.h>
#include <screen_controller.h>

#define batteryLength 4
#define batteryWidth 15
#define batteryX 128 - batteryWidth - 2 -1 // 110
#define batteryY 2
#define batteryKnobX batteryX+batteryWidth
#define batteryKnobY batteryY+1
#define batteryChargeX batteryX + 1
#define batteryChargeY batteryKnobY
#define batteryDivider batteryWidth

static bool Battery::isCharging = false;
static Adafruit_SSD1306* Battery::_display ;
static int Battery::charge = 0;


Battery::Battery(Adafruit_SSD1306* _d){
    charge = get_charge();
    _display = _d;
}

int Battery::get_charge(){
    // _charge = 50;
    return 10; // Returns a vaue between 0,100
}

void Battery::charging(bool _isCharging){
    
    if (_isCharging)
    {
        isCharging = true;
        if (charge != 100)
            charge ++;
        else 
            charge = 0;
    }
    else 
    {

    }
}

void Battery::check_charging(){
    if (true)
        charging(true);
    else 
        charging(false);
}

void Battery::show_battery(){
    _display -> drawRect(batteryX,batteryY,batteryWidth,batteryLength,WHITE);
    _display -> drawRect(batteryKnobX,batteryKnobY,1,2,WHITE);
    _display -> drawRect(batteryChargeX,batteryChargeY,get_percentage(),2,WHITE);

}

int Battery::get_percentage(){
    get_charge();
    return charge/(100/(batteryWidth-1));
}