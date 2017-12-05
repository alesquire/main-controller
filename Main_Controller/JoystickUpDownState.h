// JoystickUpDownState.h

#ifndef _JOYSTICKUPDOWNSTATE_h
#define _JOYSTICKUPDOWNSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "ArduinoHeader.h"
#else 
#include "ArduinoStub.h"
#endif

#include "PinConstants.h"


/*
	Nevertheless yoystick has analog output value for axis- it is used as a "button" - up - down.
	When joystick is moved up- there is a threshold. below the threshold it is considered ad MIDDLE- (i.e. it is not touched)
	After the threshold- it is considered as UP. I.e. value is "binarized" but to three values.

	Class JoystickUpDownState role is to detect when joystick events UpJoystickPress and DownJoystickPress are generated. But it doesn't perform this detection itself.
	It only reads current state from board and holds previous. External class that calls JoystickUpDownState will check if state is changeâ and will generate and event. 

*/
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

