// 
// 
// 

#include "PinConstants.h"
#include "Appliable.h"
#include "Microlift.h"
#include "DebugFunctions.h"

Microlift::Microlift(bool _pinHoldValue, bool _pinUpValue, char* _name)
{
	pinHoldValue = _pinHoldValue;
	pinUpValue = _pinUpValue;
	modeName=_name;
}

void Microlift::init()
{
	initOutput(PIN_MICROLIFT_HOLD_OUTPUT);
	initOutput(PIN_MICROLIFT_UP_OUTPUT);
	initInput(PIN_MICROLIFT_LOWER_SENSOR);
	initInput(PIN_MICROLIFT_UPPER_SENSOR);
}

void Microlift::apply()
{
	digitalWrite(PIN_MICROLIFT_HOLD_OUTPUT, pinHoldValue);
	digitalWrite(PIN_MICROLIFT_UP_OUTPUT, pinUpValue);
	debug("microlift mode=");
	debug(modeName);
	debug("\n");
}

