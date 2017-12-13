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
	Stroboscope useû Timer 2
*/
class Stroboscope : public Appliable
{
public:
	static void init();

	virtual void apply() {};

	Stroboscope() {};

	static Stroboscope* const OFF;
	static Stroboscope* const STROBO_33;
	static Stroboscope* const STROBO_45;

};

#endif

