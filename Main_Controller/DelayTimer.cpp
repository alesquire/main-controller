// 
// 
// 

#include "DelayTimer.h"

void DelayTimerON :: apply()
{
	Timer0.executeOneTime(WAIT_DELAY);
}



void DelayTimerOFF::apply()
{
	//nothing is performed when timer is off
}


