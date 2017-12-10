// AutostopTimer.h

#ifndef _AUTOSTOPTIMER_h
#define _AUTOSTOPTIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif


#include "Appliable.h"
#include "DueTimer.h"
#include "EventFunctions.h"

#define AUTOSTOP_DELAY 5E6 //delay in microseconde 

class AutostopTimer : public Appliable
{
protected:

public:
	static void init()
	{
		Timer1.attachInterrupt(onAutostopTimerEvent);
	}

	virtual void apply()
	{
		//empty method - should be overridden in child classes with apply behavior
	}

	static AutostopTimer * const ON;
	static AutostopTimer * const OFF;
};

#endif

