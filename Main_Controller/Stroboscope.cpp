// 
// 
// 

#include "Stroboscope.h"
void Stroboscope::init()
{
	pinMode(PIN_STROBOSCOPE, OUTPUT);
	Timer2.attachInterrupt(onStroboscope);
};

class OffStroboscope :public Stroboscope
{
public:
	virtual void apply()
	{
		Timer2.stop();
	}
};
Stroboscope* const Stroboscope::OFF = new OffStroboscope();

class Stroboscope33 :public Stroboscope
{
public:
	virtual void apply()
	{
		Timer2.start(SPEED_33_STROBO_INTERVAL);
	}
};
Stroboscope* const Stroboscope::STROBO_33 = new Stroboscope33();

class Stroboscope45 :public Stroboscope
{
public:
	virtual void apply()
	{
		Timer2.start(SPEED_45_STROBO_INTERVAL);
	}
};
Stroboscope* const Stroboscope::STROBO_45 = new Stroboscope45();
