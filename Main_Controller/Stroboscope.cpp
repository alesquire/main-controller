// 
// 
// 

#include "Stroboscope.h"
void Stroboscope::init()
{
	initOutput(PIN_STROBOSCOPE);
	Timer2.attachInterrupt(onStroboscope);
	Timer3.attachInterrupt(turnOffStroboLed);
};

void OffStroboscope::apply()
{
	Timer2.stop();
};


void Stroboscope33::apply()
{
	Timer2.start(SPEED_33_STROBO_INTERVAL);
};


void Stroboscope45::apply()
{
	Timer2.start(SPEED_45_STROBO_INTERVAL);
};

