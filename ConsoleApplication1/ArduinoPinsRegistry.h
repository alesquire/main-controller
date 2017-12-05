#include "ArduinoStub.h"
#include "..\Main_Controller\PinConstants.h"

#ifndef _ARDUINOPINSREGISTRY_H_
#define _ARDUINOPINSREGISTRY_H_

#define PINS_ARRAY_SIZE 100

struct PinState
{
	const char* name; //name of constant that corresponds to pin
	int number; //number in array
	int value;// value assigned to pin

	PinState() :name("error"), number(PINS_ARRAY_SIZE-1) 
	{
		value = -1;//error value, not allowed for pins
	};

	PinState(char* _name, int _number) : name(_name), number(_number) 
	{
		value = 0;//initial value
	}

};


class ArduinoPinsRegistry
{
private:
	PinState pins[PINS_ARRAY_SIZE];

	void printPinState(int pinNumber, int previousValue)
	{
		PinState& currentPin = pins[pinNumber];
		printf("Pin %s", currentPin.name);

		if (previousValue == 0)
		{
			printf("=%s", "OFF");
		}
		else if (previousValue == 1)
		{
			printf("=%s", "ON");
		}
		else if (previousValue == -1)
		{
			printf("=%s", "ERROR - currelt pin is not in use");
		}
		else
		{
			printf("= %i", previousValue);
		}


		int pinValue = currentPin.value;
		if (pinValue == 0)
		{
			printf("->%s", "OFF");
		}
		else if (pinValue == 1)
		{
			printf("->%s", "ON");
		}
		else if (pinValue == -1)
		{
			printf("->%s", "ERROR - currelt pin is not in use");
		}
		else
		{
			printf("-> %i", currentPin.value);
		}
		printf("\n");
	}

public: 
	ArduinoPinsRegistry()
	{

		pins[PIN_33_RPM] = PinState("PIN_33_RPM ", PIN_33_RPM);
		pins[PIN_45_RPM] = PinState("PIN_45_RPM ", PIN_45_RPM);

		pins[PIN_MICROLIFT_HOLD_OUTPUT] = PinState("PIN_MICROLIFT_HOLD_OUTPUT ", PIN_MICROLIFT_HOLD_OUTPUT);
		pins[PIN_MICROLIFT_UP_OUTPUT] = PinState("PIN_MICROLIFT_UP_OUTPUT ", PIN_MICROLIFT_UP_OUTPUT);

		pins[PIN_PLAY_LED] = PinState("PIN_PLAY_LED ", PIN_PLAY_LED);
		pins[PIN_ROTATE_LED] = PinState("PIN_ROTATE_LED ", PIN_ROTATE_LED);
		pins[PIN_STOP_LED] = PinState("PIN_STOP_LED ", PIN_STOP_LED);

		pins[PIN_33_LED] = PinState("PIN_33_LED ", PIN_33_LED);
		pins[PIN_45_LED] = PinState("PIN_45_LED ", PIN_45_LED);

		pins[PIN_RED_DISK_LED] = PinState("PIN_RED_DISK_LED ", PIN_RED_DISK_LED);
		pins[PIN_GREEN_DISK_LED] = PinState("PIN_GREEN_DISK_LED ", PIN_GREEN_DISK_LED);
		pins[PIN_BLUE_DISK_LED] = PinState("PIN_BLUE_DISK_LED ", PIN_BLUE_DISK_LED);

		pins[PIN_PICKUP_RELAY] = PinState("PIN_PICKUP_RELAY ", PIN_PICKUP_RELAY);
		pins[PIN_DAMPER_RELAY] = PinState("PIN_DAMPER_RELAY ", PIN_DAMPER_RELAY);

		pins[PIN_TONEARM_REFERENCE_OUTPUT] = PinState("PIN_TONEARM_REFERENCE_OUTPUT ", PIN_TONEARM_REFERENCE_OUTPUT);
		pins[PIN_TONEARM_VOLTAGE_OUTPUT] = PinState("PIN_TONEARM_VOLTAGE_OUTPUT ", PIN_TONEARM_VOLTAGE_OUTPUT);

		pins[PIN_STROBOSCOPE] = PinState("PIN_STROBOSCOPE ", PIN_STROBOSCOPE);
		pins[PIN_CHASSIS_LIGHT] = PinState("PIN_CHASSIS_LIGHT ", PIN_CHASSIS_LIGHT);

	}

	void printState() {};

	void printPinState(int pinNumber)
	{
		PinState& currentPin = pins[pinNumber];
		printf("Pin %s", currentPin.name);
		int pinValue = currentPin.value;
		if (pinValue == 0)
		{
			printf("=%s", "OFF");
		}
		else if (pinValue == 1)
		{
			printf("=%s", "ON");
		}
		else if (pinValue == -1)
		{
			printf("=%s", "ERROR - currelt pin is not in use");
		}
		else
		{
			printf("= %i", currentPin.value);
		}
		printf("\n");
	}



	int getPinValue(int pinNumber)
	{
		return pins[pinNumber].value;
	}

	void setPinValue(int pinNumber, int value)
	{
		int previousValue = pins[pinNumber].value;
		pins[pinNumber].value=value;
		printPinState(pinNumber, previousValue);
	}
	
	static  ArduinoPinsRegistry arduinoPinsRegistry;
};



#endif