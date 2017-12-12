// JoystickUpDownState.h

#ifndef _JOYSTICKUPDOWNSTATE_h
#define _JOYSTICKUPDOWNSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "ArduinoHeader.h"
#else 
#include "ArduinoStub.h"
#endif

#include "PinConstants.h"


enum JoystickPosition
{
	UP,
	MIDDLE,
	DOWN
};

struct JoystickPositionPair
{
	JoystickPosition previous;
	JoystickPosition current;
};

class JoystickUpDownState
{
private:
	JoystickPosition previousPosition = JoystickPosition::MIDDLE;

	int upThreshold = ANALOG_RESOLUTION*80/100;

	int downThreshold = (int)ANALOG_RESOLUTION*20/100;

public:
	
	JoystickPositionPair getJoystickPositionPair();
};
#endif

