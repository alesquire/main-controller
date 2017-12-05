// 
// 
// 

#include "StateProcessor.h"
void StateProcessor::applyNextState(State *state)
{
	if (state)
	{
		currentState = state;
		currentState->apply();
	}
}

State* StateProcessor::getCurrentState()
{
	return currentState;
}

void StateProcessor::processEvent(Events _event)
{
	int currentStateOrder = currentState->getStateOrderNumber();
	State *nextState = transitionTable[currentStateOrder][_event];
	if (nextState)// most of transition table items are nulls - as event shouldn't be processed on particular state
	{
		applyNextState(nextState);
	}
}

void StateProcessor::init() 
{
	State::init();
	pinMode(PIN_CHASSIS_LIGHT, OUTPUT);
	digitalWrite(PIN_CHASSIS_LIGHT, HIGH);
	applyNextState(State::InitialPickupIsRaisingOutsideHolder);//todo  - replace with correct state read-out and initialization
}

void StateProcessor::onTimer()
{
	currentState->getTonearmState()->apply();
	JoystickPositionPair joystickPositionPair= joystickUpDownState.getJoystickPositionPair();
	if (joystickPositionPair.current != joystickPositionPair.previous)
	{
		if (joystickPositionPair.current == UP)
		{
			processEvent(Events::UpJoystickPress);
		}
		else if (joystickPositionPair.current == DOWN)
		{
			processEvent(Events::DownJoystickPress);
		}
	}
}