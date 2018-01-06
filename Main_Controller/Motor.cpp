// 
// 
// 

#include "Motor.h"
//#include <Arduino.h>




void Motor::init()
{
	initOutput(PIN_33_RPM);
	initOutput(PIN_45_RPM);
};

void Motor::apply(void)
{
	digitalWrite(PIN_33_RPM, pin33Value);
	digitalWrite(PIN_45_RPM, pin45Value);
};

Motor* const Motor::OFF = new Motor(LOW, LOW);
Motor* const Motor::Mode33 = new Motor(HIGH, LOW);
Motor* const Motor::Mode45 = new Motor(LOW, HIGH);
