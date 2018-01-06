// 
// 
// 

#include "AutostopTimer.h"

void AutostopTimerON :: apply()
{
	Timer0.executeOneTime(AUTOSTOP_DELAY);
}



void AutostopTimerOFF::apply()
{
	//nothing is performed when timer is off
}


