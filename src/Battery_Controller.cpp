#include <Arduino.h>
#include <Battery_Controller.h>
#include <Globals.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int BatteryController::charge ;
bool BatteryController::isCharging ;
Adafruit_SSD1306* BatteryController::display;
bool BatteryController::wasAlerted ;
bool* BatteryController::atHome ;

void BatteryController::init(Adafruit_SSD1306 *_display, bool *_atHome){
    display = _display;
    charge = 0;
    isCharging = false;
    wasAlerted = false;
    pinMode(CHARGE_STATUS_PIN,INPUT_PULLUP); // This pin is low when charging
}

void BatteryController::get_charge(){
    int _charge = analogRead(BATTERY_PIN);
    _charge = map(_charge,0,1023,0,100); 
    charge = constrain(map(_charge,MIN_VOLTAGE,MAX_VOLTAGE,0,100),0,100); // Convert the voltage reading between 3.7 to 4.2 --> 0% to 100%
}

void BatteryController::check_charging(){    
    if (!digitalRead(CHARGE_STATUS_PIN)) // TODO:- Add pin change interrupt for no lag charging detection
    {
        isCharging = true;
        if (charge != 100) // Charging animation 
            charge ++;
        else 
            charge = 0;
    }
    else 
    {   
        get_charge();
        if (isCharging) // check if the device got removed from charging
            wasAlerted = false; // Activate alert if charging stoped 
        isCharging = false;
        if (charge < ALERT_TRESHOLD)
        {
            if (!wasAlerted)
            {
                low_charge_alert();
            }
        }
        else 
            wasAlerted = false; // Activate alert if battery is above the treshold
    }
}

void BatteryController::show_battery(){
    display -> drawRect(BATTERY_X,BATTERY_Y,BATTERY_WIDTH,BATTERY_HEIGHT,WHITE);
    display -> drawRect(BATTERY_KNOB_X,BATTERY_KNOB_Y,BATTERY_KNOB_WIDTH,BATTERY_KNOB_HEIGHT,WHITE);
    display -> drawRect(BATTERY_CHARGE_X,BATTERY_CHARGE_Y,get_percentage(),2,WHITE); // Draw the charge percentage
}

int BatteryController::get_percentage(){
    check_charging();
    return charge/(100/(BATTERY_WIDTH-1));
}


void BatteryController::low_charge_alert(){
    *atHome = false; // Screen Controller variable that tracks if the user is at home screen
    while(digitalRead(RIGHT) && digitalRead(LEFT) && (digitalRead(CHARGE_STATUS_PIN))) // Show alert till plugged for charge or pressed ok
    {
        display -> clearDisplay();
        display -> drawRect(2,2,SCREEN_WIDTH-4,SCREEN_HEIGHT-4,WHITE);
        display -> setTextSize(2);
        display -> setTextColor(WHITE);
        display -> setCursor(37,18);
        display -> cp437(true);
        display -> print(F("ALERT"));
        display -> setCursor(32,38);
        display -> setTextSize(1);
        display -> print(F("BATTERY LOW"));
        display -> display();
    }
    wasAlerted = true;
    show_battery();
}