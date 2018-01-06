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
	initOutput(PIN_33_LED);
	initOutput(PIN_45_LED);
	initInput(PIN_33_BUTTON);
	initInput(PIN_45_BUTTON);
}

void SpeedButtons::apply()
{
	digitalWrite(PIN_33_LED, pin33LedValue);
	digitalWrite(PIN_45_LED, pin45LedValue);
}


