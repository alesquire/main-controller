// 
// 
// 

#include "AutostopTimer.h"

class AutostopTimerON : public AutostopTimer
{
public:
	virtual void apply()
	{
		Timer1.executeOneTime(AUTOSTOP_DELAY);
	}
};
AutostopTimer* const AutostopTimer::ON = new  AutostopTimerON();


class AutostopTimerOFF : public AutostopTimer
{
public:
	virtual void apply()
	{
		//nothing is performed when timer is off
	}
};
AutostopTimer* const AutostopTimer::OFF = new AutostopTimerOFF();
