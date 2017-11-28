#include "ArduinoStub.h"
#include "..\Main_Controller\PinConstants.h"

#ifndef _ARDUINOPINSREGISTRY_H_
#define _ARDUINOPINSREGISTRY_H_

#define PINS_ARRAY_SIZE 100

struct PinState
{
	const char* name; //name of constant that corresponds to pin
	int number; //number in array
	float value=0;// value assigned to pin

	PinState() :name("error"), number(PINS_ARRAY_SIZE-1) {};

	PinState(char* _name, int _number) : name(_name), number(_number) {}

};


class ArduinoPinsRegistry
{
private:
	PinState pins[PINS_ARRAY_SIZE];

public: 
	ArduinoPinsRegistry()
	{

		pins[PIN_33_RPM] = PinState("PIN_33_RPM ", PIN_33_RPM);
		pins[PIN_45_RPM] = PinState("PIN_45_RPM ", PIN_45_RPM);

		pins[PIN_SOLENOID_HOLD_OUTPUT] = PinState("PIN_SOLENOID_HOLD_OUTPUT ", PIN_SOLENOID_HOLD_OUTPUT);
		pins[PIN_SOLENOID_UP_OUTPUT] = PinState("PIN_SOLENOID_UP_OUTPUT ", PIN_SOLENOID_UP_OUTPUT);

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

		pins[PIN_TONEARM_VOLTAGE_OUTPUT] = PinState("PIN_TONEARM_VOLTAGE_OUTPUT ", PIN_TONEARM_VOLTAGE_OUTPUT);

		pins[PIN_ANTISCATE] = PinState("PIN_ANTISCATE ", PIN_ANTISCATE);
		pins[PIN_DAMPER] = PinState("PIN_DAMPER ", PIN_DAMPER);
		pins[PIN_JOYSTICK_UP_DOWN] = PinState("PIN_JOYSTICK_UP_DOWN ", PIN_JOYSTICK_UP_DOWN);
		pins[PIN_JOYSTICK_LEFT_RIGHT] = PinState("PIN_JOYSTICK_LEFT_RIGHT ", PIN_JOYSTICK_LEFT_RIGHT);



	}
	void printState() {};

	void printPinState(int pinNumber)
	{
		PinState& currentPin = pins[pinNumber];
		printf("Pin %s", currentPin.name);
		printf("= %2.1f", currentPin.value);
		printf("\n");
	}

	float getPinValue(int pinNumber)
	{
		return pins[pinNumber].value;
	}

	void setPinValue(int pinNumber, float value)
	{
		pins[pinNumber].value=value;
		printPinState(pinNumber);
	}
	
	static  ArduinoPinsRegistry arduinoPinsRegistry;
};



#endif