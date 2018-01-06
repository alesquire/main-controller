// 
// 
// 

#include "PinConstants.h"
#include "Appliable.h"
#include "Microlift.h"


Microlift::Microlift(bool _pinHoldValue, bool _pinUpValue)
{
	pinHoldValue = _pinHoldValue;
	pinUpValue = _pinUpValue;
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
}

Microlift* const Microlift::DOWN = new Microlift(LOW, LOW);
Microlift* const Microlift::UP = new Microlift(LOW, HIGH);
Microlift* const Microlift::HOLD = new Microlift(HIGH, LOW);