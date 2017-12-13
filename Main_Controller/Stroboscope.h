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

#define SPEED_33_STROBO_INTERVAL	2E6 //todo - specify strobo values
#define SPEED_45_STROBO_INTERVAL	1E6 //todo - specify strobo values
#define STROBO_PULSE_DURATION		1E5 //todo - specify strobo values

/*
	Stroboscope uses Timer 2 to switch on stroboscope LED and Timer 3 to turn it off
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

