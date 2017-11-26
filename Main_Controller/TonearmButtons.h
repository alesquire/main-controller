#pragma once

#ifndef _TONEARMBUTTONS_H
#define _TONEARMBUTTONS_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "PinConstants.h" 

#include "Appliable.h"
class TonearmButtons : public Appliable
{
private:
	bool pinPlayValue = LOW;
	bool pinRotateValue = LOW;
	bool pinStopValue = LOW;

public:
	TonearmButtons(bool _pinPlayValue, bool _pinRotateValue, bool _pinStopValue);

	void init();

	void apply();

	const static TonearmButtons OFF;
	const static TonearmButtons PLAY;
	const static TonearmButtons ROTATE;
	const static TonearmButtons STOP;

};
#endif
