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

