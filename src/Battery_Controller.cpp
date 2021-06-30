#include <Arduino.h>
#include <Battery_Controller.h>
#include <Globals.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int BatteryController::charge ;
bool BatteryController::isCharging ;
Adafruit_SSD1306* BatteryController::display;
void BatteryController::init(Adafruit_SSD1306 *_display){
    display = _display;
    charge = 0;
    isCharging = false;
    pinMode(CHARGE_STATUS_PIN,INPUT_PULLUP);
}

void BatteryController::get_charge(){
    int _charge = analogRead(BATTERY_PIN);
    _charge = map(_charge,0,1023,0,100); 
    charge = constrain(map(_charge,MIN_VOLTAGE,MAX_VOLTAGE,0,100),0,100); // Convert the voltage reading between 3.7 to 4.2 --> 0% to 100%
}

void BatteryController::check_charging(){    
    if (digitalRead(CHARGE_STATUS_PIN)) // Pin change interrupt
    {
        isCharging = true;
        if (charge != 100)
            charge ++;
        else 
            charge = 0;
    }
    else 
    {   
        get_charge();
        isCharging = false;
    }
}

void BatteryController::show_battery(){
    display -> drawRect(BATTERY_X,BATTERY_Y,BATTERY_WIDTH,BATTERY_HEIGHT,WHITE);
    display -> drawRect(BATTERY_KNOB_X,BATTERY_KNOB_Y,BATTERY_KNOB_WIDTH,BATTERY_KNOB_HEIGHT,WHITE);
    display -> drawRect(BATTERY_CHARGE_X,BATTERY_CHARGE_Y,get_percentage(),2,WHITE);
}

int BatteryController::get_percentage(){
    check_charging();
    return charge/(100/(BATTERY_WIDTH-1));
}

void BatteryController::low_battery_alert(){
    
}