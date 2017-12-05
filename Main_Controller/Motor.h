// Motor.h
#ifndef _MOTOR_H_
#define _MOTOR_H_


#include "PinConstants.h"
#include "Appliable.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

class Motor : virtual public Appliable
{
private:
	bool pin33Value = LOW;
	bool pin45Value = LOW;

public:


	Motor(bool _pin33Value, bool _pin45Value) : pin33Value(_pin33Value), pin45Value(_pin45Value) {};

	static void init();

	virtual void apply(void);

	static Motor * const OFF;
	static Motor * const Mode33;
	static Motor * const Mode45;

};
#endif