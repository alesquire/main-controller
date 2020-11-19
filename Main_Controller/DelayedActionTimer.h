#pragma once

#ifndef _DELAYED_ACTION_TIMER_h
#define _DELAYED_ACTION_TIMER_h

#ifndef ARDUINO
	//#include <sys\time.h>
#endif

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
		if (!function) return;
		if (targetTimestamp==0) return;
		if (getCurrentTimeMillis() >= targetTimestamp)
			function();
		targetTimestamp = 0;
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
		return testTime++;
#endif
	}

	static DelayedActionTimer delayedTimer;
};

DelayedActionTimer DelayedActionTimer::delayedTimer;
#endif