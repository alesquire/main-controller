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
	pinMode(PIN_SOLENOID_HOLD_OUTPUT, OUTPUT);
	pinMode(PIN_SOLENOID_UP_OUTPUT, OUTPUT);
}

void Microlift::apply()
{
	digitalWrite(PIN_SOLENOID_HOLD_OUTPUT, pinHoldValue);
	digitalWrite(PIN_SOLENOID_UP_OUTPUT, pinUpValue);
}

const Microlift Microlift::DOWN = Microlift(LOW, LOW);
const Microlift Microlift::UP = Microlift(LOW, HIGH);
const Microlift Microlift::HOLD = Microlift(HIGH, LOW);