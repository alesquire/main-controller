#include "TonearmButtons.h"

TonearmButtons::TonearmButtons(bool _pinPlayValue, bool _pinRotateValue, bool _pinStopValue)
{
	pinPlayValue = _pinPlayValue;
	pinRotateValue = _pinRotateValue;
	pinStopValue = _pinStopValue;
}

void TonearmButtons::init()
{
	initOutput(PIN_PLAY_LED);
	initOutput(PIN_ROTATE_LED);
	initOutput(PIN_STOP_LED);
	initInput(PIN_PLAY_BUTTON);
	initInput(PIN_ROTATE_BUTTON);
	initInput(PIN_STOP_BUTTON);
}

void TonearmButtons::apply()
{
	digitalWrite(PIN_PLAY_LED, pinPlayValue);
	digitalWrite(PIN_ROTATE_LED, pinRotateValue);
	digitalWrite(PIN_STOP_LED, pinStopValue);
}


