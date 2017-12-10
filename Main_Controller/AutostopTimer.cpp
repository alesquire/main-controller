// 
// 
// 

#include "AutostopTimer.h"

void AutostopTimerON :: apply()
{
	Timer0.executeOneTime(AUTOSTOP_DELAY);
}

AutostopTimer* const AutostopTimer::ON = new  AutostopTimerON();


void AutostopTimerOFF::apply()
{
	//nothing is performed when timer is off
}

AutostopTimer* const AutostopTimer::OFF = new AutostopTimerOFF();
