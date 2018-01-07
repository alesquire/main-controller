#include "ArduinoHeader.h"

void initInput(int pinNumber)
{
	pinMode(pinNumber, INPUT_PULLUP);
	digitalWrite(pinNumber, LOW);
}

void initOutput(int pinNumber)
{
	pinMode(pinNumber, OUTPUT);
}
