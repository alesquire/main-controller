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


TonearmButtons* const TonearmButtons::OFF = new TonearmButtons(LOW, LOW, LOW);
TonearmButtons* const TonearmButtons::PLAY = new TonearmButtons(HIGH, LOW, LOW);
TonearmButtons* const TonearmButtons::ROTATE = new TonearmButtons(LOW, HIGH, LOW);
TonearmButtons* const TonearmButtons::STOP = new TonearmButtons(LOW, LOW, HIGH);

