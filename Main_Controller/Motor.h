// Motor.h
#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "PinConstants.h"
#include "Appliable.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Motor : public Appliable
{
private:
	bool pin33Value = LOW;
	bool pin45Value = LOW;

public:

	Motor(bool _pin33Value, bool _pin45Value);

	virtual void init();

	virtual void apply(void);

	static const Motor OFF;
	static const Motor Mode33;
	static const Motor Mode45;

};
#endif