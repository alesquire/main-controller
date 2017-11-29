// 
// 
// 

#include "AutostopTimer.h"

class AutostopTimerON : public AutostopTimer
{
public:
	virtual void apply()
	{
		//todo : turn on timer
	}
};
AutostopTimer* const AutostopTimer::ON = new  AutostopTimerON();


class AutostopTimerOFF : public AutostopTimer
{
public:
	virtual void apply()
	{
		//todo : turn on timer
	}
};
AutostopTimer* const AutostopTimer::OFF = new AutostopTimerOFF();
