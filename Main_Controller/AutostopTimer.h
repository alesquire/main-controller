// AutostopTimer.h

#ifndef _AUTOSTOPTIMER_h
#define _AUTOSTOPTIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

#include "Appliable.h"

class AutostopTimer : public Appliable
{
public:
	virtual void init()
	{
		//todo - init timer if necessary
	}

	virtual void apply()
	{
		//empty method - should be overridden in child classes with apply behavior
	}

	static const AutostopTimer ON;
	static const AutostopTimer OFF;
};

#endif

