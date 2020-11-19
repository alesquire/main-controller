// 
// 
// 

#include "SpeedButtons.h"
//#include "DebugFunctions.h"

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
	//debug("LED33 value =");
	//debug(pin33LedValue);
	//debug("LED45 value =");
	//debug(pin45LedValue);
	digitalWrite(PIN_33_LED, pin33LedValue);
	digitalWrite(PIN_45_LED, pin45LedValue);
}


