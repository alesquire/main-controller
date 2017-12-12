// Stroboscope.h

#ifndef _STROBOSCOPE__h
#define _STROBOSCOPE__h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

#include "PinConstants.h"
#include "Appliable.h"
#include "DueTimer.h"
#include "EventFunctions.h"

#define SPEED_33_STROBO_INTERVAL
#define SPEED_45_STROBO_INTERVAL
#define STROBO_PULSE_DURATION

/*
	Stroboscope used Timer 2
*/
class Stroboscope : public Appliable
{
public:
	static void init()
	{
		pinMode(PIN_STROBOSCOPE, OUTPUT);
		Timer2.attachInterrupt(onStroboscope);
	};

	virtual void apply() {};

	Stroboscope() {};

	static Stroboscope* const OFF;
	static Stroboscope* const STROBO_33;
	static Stroboscope* const STROBO_45;

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
#endif

