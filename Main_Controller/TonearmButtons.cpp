#include "TonearmButtons.h"

TonearmButtons::TonearmButtons(bool _pinPlayValue, bool _pinRotateValue, bool _pinStopValue)
{
	pinPlayValue = _pinPlayValue;
	pinRotateValue = _pinRotateValue;
	pinStopValue = _pinStopValue;
}

void TonearmButtons::init()
{
	pinMode(PIN_PLAY_LED, OUTPUT);
	pinMode(PIN_ROTATE_LED, OUTPUT);
	pinMode(PIN_STOP_LED, OUTPUT);
}

void TonearmButtons::apply()
{
	digitalWrite(PIN_PLAY_LED, pinPlayValue);
	digitalWrite(PIN_ROTATE_LED, pinRotateValue);
	digitalWrite(PIN_STOP_LED, pinStopValue);
}


const TonearmButtons TonearmButtons::OFF = TonearmButtons(LOW, LOW, LOW);
const TonearmButtons TonearmButtons::PLAY = TonearmButtons(HIGH, LOW, LOW);
const TonearmButtons TonearmButtons::ROTATE = TonearmButtons(LOW, HIGH, LOW);
const TonearmButtons TonearmButtons::STOP = TonearmButtons(LOW, LOW, HIGH);

