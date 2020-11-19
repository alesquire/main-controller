// 
// 
// 

#include "DelayTimer.h"

void DelayTimerON :: apply()
{
	debug("init delayed timer \n");
	Timer6.executeOneTime(WAIT_DELAY);
}



void DelayTimerOFF::apply()
{
	//nothing is performed when timer is off
}


