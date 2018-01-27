// AutostopTimer.h

#ifndef _AUTOSTOPTIMER_h
#define _AUTOSTOPTIMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif


#include "Appliable.h"
#include "DueTimer.h"
#include "EventFunctions.h"
#include "DebugFunctions.h"

#define WAIT_DELAY 5E6 //delay in microseconde 

/*
	class is used to delay operation execution:
	- pickup rising on autostop
	- tonearm move to first track (to accelerate disk)
*/
class DelayTimer : public Appliable
{
protected:

public:
	static void init()
	{
		Timer0.attachInterrupt(onDelayTimerEvent);
	}

	virtual void apply()
	{
		//empty method - should be overridden in child classes with apply behavior
	}

	static DelayTimer * const ON;
	static DelayTimer * const OFF;
};

class DelayTimerON : public DelayTimer
{
public:
	virtual void apply();
};


class DelayTimerOFF : public DelayTimer
{
public:
	virtual void apply();
};


#endif

