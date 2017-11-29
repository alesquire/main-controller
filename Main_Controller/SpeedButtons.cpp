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


SpeedButtons* const SpeedButtons::OFF = new SpeedButtons(LOW, LOW);
SpeedButtons* const SpeedButtons::LED33 = new SpeedButtons(HIGH, LOW);
SpeedButtons* const SpeedButtons::LED45 = new SpeedButtons(LOW, HIGH);