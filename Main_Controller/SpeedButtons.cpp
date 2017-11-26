// 
// 
// 

#include "SpeedButtons.h"

SpeedButtons::SpeedButtons(bool _pin33LedValue, bool _pin45LedValue)
{
	pin33LedValue = _pin33LedValue;
	pin45LedValue = _pin45LedValue;
}

void SpeedButtons::init()
{
	pinMode(PIN_33_LED, OUTPUT);
	pinMode(PIN_45_LED, OUTPUT);
}

void SpeedButtons::apply()
{
	digitalWrite(PIN_33_LED, pin33LedValue);
	digitalWrite(PIN_45_LED, pin45LedValue);
}


const SpeedButtons SpeedButtons::OFF = SpeedButtons(LOW, LOW);
const SpeedButtons SpeedButtons::LED33 = SpeedButtons(HIGH, LOW);
const SpeedButtons SpeedButtons::LED45 = SpeedButtons(LOW, HIGH);