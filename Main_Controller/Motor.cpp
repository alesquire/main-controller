// 
// 
// 

#include "Motor.h"
#include <Arduino.h>


Motor::Motor(bool _pin33Value, bool _pin45Value)
{
	pin33Value = _pin33Value;
	pin45Value = _pin45Value;
};

void Motor::init()
{
	pinMode(PIN_33_RPM, OUTPUT);
	pinMode(PIN_45_RPM, OUTPUT);
};

void Motor::apply(void)
{
	digitalWrite(PIN_33_RPM, pin33Value);
	digitalWrite(PIN_45_RPM, pin45Value);
};

const Motor Motor::OFF = Motor(LOW, LOW);
const Motor Motor::Mode33 = Motor(HIGH, LOW);
const Motor Motor::Mode45 = Motor(LOW, HIGH);
