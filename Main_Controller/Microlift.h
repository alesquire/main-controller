// Solenoid.h

#ifndef _SOLENOID_H
#define _SOLENOID_H

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
 
#include "PinConstants.h"
#include "Appliable.h"

class Microlift : public Appliable
{
private:
	bool pinHoldValue = LOW;
	bool pinUpValue = LOW;
	Microlift() {};
public:
	Microlift(bool _pinHoldValue, bool _pinUpValue);

	virtual void init();

	virtual void apply();

	const static Microlift UP;
	const static Microlift DOWN;
	const static Microlift HOLD;

};

#endif

