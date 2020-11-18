// SensorsState.h

#ifndef _SENSORSSTATE_h
#define _SENSORSSTATE_h
/*
	Interrupt-based sensors reading model showed it's instability. So- external events will be read using periodical sensor readout and compare with previous state.
*/
#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#else 
	#include "ArduinoStub.h"
#endif

#include "PinConstants.h"
#include "EventFunctions.h"
#include "DebugFunctions.h"

/*
	Enum describes all changes that we can subscribe on - all digital inputs.
	We can't subscrribe on analog inputs, so we should read them explicitly in a loop
*/
enum ChangeCondition
{
	RISES,
	FALLS,
	CHANGES
};

/*
	class is a listener configured on pin end event.
	desrcibes one sensor that we can subscribe on. instance reads pin state and compares it with previous 
	class instance is associated with pin and has listerer that is called when event 
	multiple class imstaces can be created for one pin
	it is assumed thar class instance has associated callback function, othervise it wouldn't be created
*/
typedef void(*callback)(void); // listener function
class SensorState
{
private:
	int pinNumber;
	ChangeCondition subscribed_event; //event that class instance subscribes on  
	callback listener = NULL; //function that is called when changes correspond to subscribed_event
	bool value = LOW; //value that was read from digital input
public:
	SensorState(int _pinNumber, callback _listener, ChangeCondition _event):
		pinNumber(_pinNumber),
		listener(_listener),
		subscribed_event(_event)
	{
		init();
	}

	void init()
	{
		value = digitalRead(pinNumber);
	}

	//reads pin value and if value is changed and correspondent for curent change  listener exists- calls listener.
	// previous value is replaced with new one
	void check()
	{
		bool newValue= digitalRead(pinNumber);
		//if value changes
		if (value != newValue)
		{
			debug("Pin changes :");
			debug(getPinNameByNumber(pinNumber));
			debug("\n");
			//value changes
			if (subscribed_event == CHANGES)
				listener();
		}
		//if value rises
		if (value == false && newValue == true)
		{
			debug("Pin rises :");
			debug(getPinNameByNumber(pinNumber));
			debug("\n");
			// value rises
			if (subscribed_event == RISES)
				listener();
		}
		//if value falls
		if (value == true && newValue == false)
		{
			debug("Pin falls :");
			debug(getPinNameByNumber(pinNumber));
			debug("\n");
			// value falls
			if (subscribed_event == FALLS)
				listener();
		}
		value = newValue;
	}
};
/*
	collection of all sensors and listeners
*/
class SensorsState
{
private:
	static SensorState sensorStates[13];

public:
	static SensorsState sensorsState;

	void init()
	{
		int size = sizeof(sensorStates) / sizeof(sensorStates[0]);
		for (int i = 0; i < size; i++)
		{
			sensorStates[i].init();
		}

	}

	void compare()
	{
		int size = sizeof(sensorStates) / sizeof(sensorStates[0]);
		for (int i = 0;  i < size; i++)
		{
			sensorStates[i].check();
		}
	}
};


#endif

