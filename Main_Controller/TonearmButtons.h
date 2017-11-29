#pragma once

#ifndef _TONEARMBUTTONS_H
#define _TONEARMBUTTONS_H

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
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

	static TonearmButtons* const OFF;
	static TonearmButtons* const PLAY;
	static TonearmButtons* const ROTATE;
	static TonearmButtons* const STOP;

};
#endif
