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
	class desrcibes one sensor that we can subscribe on. instance reads pin state and compares it with previous 
	class instance is associated with pin and has listerer that is called when event 
	multiple class imstaces can be created for one pin
*/
typedef void(*callback)(void); // listener function
class SensorState
{
private:
	int pinNumber;
	callback listener=NULL;
	ChangeCondition event;
	bool value = LOW; //value that was read from digital input
public:
	SensorState(int _pinNumber, callback _listener, ChangeCondition _event):
		pinNumber(_pinNumber),
		listener(_listener),
		event(_event)
	{
		value = digitalRead(pinNumber);
	}

	//reads pin value and if value is changed and correspondent for curent change  listener exists- calls listener.
	// previous value is replaced with new one
	void check()
	{
		bool newValue= digitalRead(pinNumber);
		if (value != newValue)
		{
			debug("Pin changes :");
			debug(pinNumber);
			debug("\n");
			//value changes
			if (event == CHANGES)
				listener();
		}
		if (value == false && newValue == true)
		{
			debug("Pin rises :");
			debug(pinNumber);
			debug("\n");
			// value rises
			if (event == RISES)
				listener();
		}
		if (value == true && newValue == false)
		{
			debug("Pin falls :");
			debug(pinNumber);
			debug("\n");
			// value falls
			if (event == FALLS)
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
	static SensorsState instance;
public:
	static SensorsState& getInstance()
	{
		return instance;
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

