#pragma once
#ifndef _ARDUINO_HEADER_H
#define _ARDUINO_HEADER_H




#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "ArduinoStub.h"
#endif

//init functions

void initInput(int pinNumber);

void initOutput(int pinNumber);
#endif
