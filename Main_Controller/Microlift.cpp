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
	pinMode(PIN_MICROLIFT_HOLD_OUTPUT, OUTPUT);
	pinMode(PIN_MICROLIFT_UP_OUTPUT, OUTPUT);
	pinMode(PIN_TONEARM_DOWN, INPUT);
	pinMode(PIN_TONEARM_UP, INPUT);
}

void Microlift::apply()
{
	digitalWrite(PIN_MICROLIFT_HOLD_OUTPUT, pinHoldValue);
	digitalWrite(PIN_MICROLIFT_UP_OUTPUT, pinUpValue);
}

Microlift* const Microlift::DOWN = new Microlift(LOW, LOW);
Microlift* const Microlift::UP = new Microlift(LOW, HIGH);
Microlift* const Microlift::HOLD = new Microlift(HIGH, LOW);