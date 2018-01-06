#include "ArduinoHeader.h"

void initInput(int pinNumber)
{
	pinMode(pinNumber, INPUT);
	digitalWrite(pinNumber, HIGH);
}

void initOutput(int pinNumber)
{
	pinMode(pinNumber, OUTPUT);
}