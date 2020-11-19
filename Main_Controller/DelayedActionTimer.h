#pragma once

#ifndef _DELAYED_ACTION_TIMER_h
#define _DELAYED_ACTION_TIMER_h

#ifndef ARDUINO
	//#include <sys\time.h>
#endif

#include "DebugFunctions.h"

typedef void(*callback_fun)(void); // listener function
class DelayedActionTimer
{
private:
	int targetTimestamp=0;  //time when execution should be finished. 0= never
	callback_fun function= NULL;
#ifndef ARDUINO
	int testTime = 0;
#endif
public:
	void registerCallback(callback_fun _function)
	{
		function = _function;
	}
	
	void tick()
	{
		//debug("tick\n");
		if (!function) return;
		if (targetTimestamp==0) return;
		//debug("getCurrentTimeMillis = ");
		//debug(getCurrentTimeMillis());
		//debug("\n targetTimestamp=");
		debug(targetTimestamp);
		debug("\n");
		if (getCurrentTimeMillis() >= targetTimestamp)
		{
			debug("callback from DelayedActionTimer");
			function();
			targetTimestamp = 0;
		}

	}

	void postponeExecution(int milliseconds)
	{
		targetTimestamp = getCurrentTimeMillis() + milliseconds;
	}

	int getCurrentTimeMillis()
	{
#if defined ARDUINO
		return millis();
#else
		return testTime+=1000;//on Windows method doesn't return real time - it returns next second every time
#endif
	}

	static DelayedActionTimer delayedTimer;
};


#endif