// Solenoid.h

#ifndef _SOLENOID_H
#define _SOLENOID_H

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
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

	static void init();

	virtual void apply();

	static Microlift* const UP;
	static Microlift* const DOWN;
	static Microlift* const HOLD;

};

#endif

