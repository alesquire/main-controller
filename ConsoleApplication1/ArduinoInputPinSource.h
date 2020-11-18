#pragma once
#include <map>    
#include <cstdlib>

#include "ArduinoStub.h"
#include "..\Main_Controller\PinConstants.h"
#include "..\Main_Controller\DebugFunctions.h"
#ifndef _InputPinValueGenerator_h
#define _InputPinValueGenerator_h



class InputPinValueGenerator
{
public:
	virtual int readValue() { return -1; }
};

class RandomInputPinValueGenerator :public InputPinValueGenerator
{
	int min;
	int max;
	int interval;
public:
	RandomInputPinValueGenerator(int _min, int _max) : min(_min), max(_max) 
	{
		interval = max - min;
	}

	virtual int readValue()
	{
		return rand() % interval + min;
	}
};

class ConstantInputPinValueGenerator :public InputPinValueGenerator
{
private:
	int value;
public:
	ConstantInputPinValueGenerator(int _value) : value(_value) {}

	virtual int readValue()
	{
		return value;
	}

};

class ArduinoInputPinSource
{
private:
	std::map <int, InputPinValueGenerator* > inputPins;

public:
	ArduinoInputPinSource()
	{
		inputPins[PIN_JOYSTICK_UP_DOWN] = new RandomInputPinValueGenerator(0, ANALOG_RESOLUTION);
		inputPins[PIN_JOYSTICK_LEFT_RIGHT] = new RandomInputPinValueGenerator(0, ANALOG_RESOLUTION);
		inputPins[PIN_ANTISCATE] = new RandomInputPinValueGenerator(0, ANALOG_RESOLUTION);
		inputPins[PIN_DAMPER] = new RandomInputPinValueGenerator(0, ANALOG_RESOLUTION);
		inputPins[PIN_TONEARM_HOLDER] = new ConstantInputPinValueGenerator(LOW);
	}

	int readValue(int pin)
	{
		if (inputPins.find(pin) == inputPins.end())
		{
			debug("ERROR: attempt to read incorrect pin= ");
			debug(pin);
			debug("\n");
			return -1; 
		}
		int result = inputPins[pin]->readValue();
		debug("ERROR: attempt to read incorrect pin= ");
		debug(pin);
		debug("\n");
		return result;
	}

	/*
		if value already exists- it is replaced. if doesn't exist- new one is created
	*/
	void setPinValue(int pin, int value)
	{
		if (inputPins.find(pin) != inputPins.end())
		{
			InputPinValueGenerator* previous = inputPins[pin];
			delete previous;
		}

		ConstantInputPinValueGenerator* constant = new  ConstantInputPinValueGenerator(value);
		inputPins[pin] = constant;
	}

	static ArduinoInputPinSource arduinoInputPinSource;
};


#endif