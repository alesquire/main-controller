#pragma once
#include <map>    
#include <cstdlib>

#include "ArduinoStub.h"
#include "..\Main_Controller\PinConstants.h"

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
	std::map <int, InputPinValueGenerator> inputPins;

public:
	ArduinoInputPinSource()
	{
		inputPins[PIN_JOYSTICK_UP_DOWN] = RandomInputPinValueGenerator(0, ANALOG_RESOLUTION);
		inputPins[PIN_JOYSTICK_LEFT_RIGHT] = RandomInputPinValueGenerator(0, ANALOG_RESOLUTION);
		inputPins[PIN_ANTISCATE] = RandomInputPinValueGenerator(0, ANALOG_RESOLUTION);
		inputPins[PIN_DAMPER] = RandomInputPinValueGenerator(0, ANALOG_RESOLUTION);
	}

	int readValue(int pin)
	{
		if (inputPins.find(pin) == inputPins.end())
		{
			return -1; 
		}
		return inputPins[pin].readValue();
	}

	void setPinValue(int pin, int value)
	{
		ConstantInputPinValueGenerator constant(value);
		inputPins[pin] = constant;
	}

	static ArduinoInputPinSource arduinoInputPinSource;
};


#endif