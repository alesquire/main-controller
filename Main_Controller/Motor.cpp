// 
// 
// 

#include "Motor.h"
//#include <Arduino.h>




void Motor::init()
{
	initOutput(PIN_33_RPM);
	initOutput(PIN_45_RPM);

	//hack. don't know why- motor doesn't start from firs time
	digitalWrite(PIN_33_RPM, LOW);
	digitalWrite(PIN_45_RPM, LOW);
	digitalWrite(PIN_33_RPM, HIGH);
	delay(100);
	digitalWrite(PIN_33_RPM, LOW);
	delay(100);
	digitalWrite(PIN_33_RPM, HIGH);
	delay(100);
	digitalWrite(PIN_33_RPM, LOW);
};

void Motor::apply(void)
{
	digitalWrite(PIN_33_RPM, pin33Value);
	digitalWrite(PIN_45_RPM, pin45Value);
};

