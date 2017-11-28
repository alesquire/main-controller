// SpeedButtons.h

#ifndef _SPEEDBUTTONS_h
#define _SPEEDBUTTONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif


#include "PinConstants.h" 

#include "Appliable.h"

class SpeedButtons : public Appliable
{
private:
	bool pin33LedValue = LOW;
	bool pin45LedValue = LOW;

public:
	SpeedButtons(bool _pin33LedValue, bool _pin45LedValue);

	virtual void init();

	virtual void apply();

	const static SpeedButtons OFF;
	const static SpeedButtons LED33;
	const static SpeedButtons LED45;
};

#endif

