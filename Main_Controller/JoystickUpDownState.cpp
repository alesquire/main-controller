// 
// 
// 

#include "JoystickUpDownState.h"

JoystickPositionPair JoystickUpDownState::getJoystickPositionPair()
{
	int joystickValue = analogRead(PIN_JOYSTICK_UP_DOWN);
	JoystickPositionPair returnPair;
	returnPair.previous = previousPosition;
	JoystickPosition currentPosition;
	//up state correspond to small values, down position- to big values
	if (joystickValue < upThreshold)
	{
		currentPosition = JoystickPosition::UP;
	}
	else if(joystickValue > downThreshold)
	{
		currentPosition = JoystickPosition::DOWN;
	}
	else
	{
		currentPosition = JoystickPosition::MIDDLE;
	}
	previousPosition = currentPosition;
	returnPair.current = currentPosition;
	return returnPair;
}
