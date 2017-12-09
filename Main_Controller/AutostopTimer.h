// AutostopTimer.h

#ifndef _AUTOSTOPTIMER_h
#define _AUTOSTOPTIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

#include "Appliable.h"
#include "DueTimer.h"

class AutostopTimer : public Appliable
{
public:
	static void init()
	{
		//todo - init timer if necessary
	}

	virtual void apply()
	{
		//empty method - should be overridden in child classes with apply behavior
	}

	static AutostopTimer * const ON;
	static AutostopTimer * const OFF;
};

#endif

