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

	static void init();

	virtual void apply();

	static SpeedButtons* const OFF;
	static SpeedButtons* const LED33;
	static SpeedButtons* const LED45;
};

#endif

