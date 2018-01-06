// 
// 
// 

#include "StateProcessor.h"
#include "Initializers.cpp"

StateProcessor StateProcessor::stateProcessor;

void StateProcessor::applyNextState(State *state)
{
	if (state)
	{
		currentState = state;
		int stateNumber = state->getStateOrderNumber();//debug
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
	debug("Current state = ");
	debug(currentState->getStateName());
	debug("\n");
	debug("Processing Event: ");
	debug(eventNames[_event]);
	debug("\n");

	State *nextState = transitionTable[currentStateOrder][_event];
	if (nextState)// most of transition table items are nulls - as event shouldn't be processed on particular state
	{
		debug("Next state = ");
		debug(nextState->getStateName());
		debug("\n");
		applyNextState(nextState);
	}
	else
	{
		debug("Event is ignored \n");
	}
}

void StateProcessor::init() 
{
	State::init();
	initOutput(PIN_BOTTOM_CHASSIS_LIGHT);
	digitalWrite(PIN_BOTTOM_CHASSIS_LIGHT, HIGH);
	initOutput(PIN_UPPER_CHASSIS_LIGHT);
	digitalWrite(PIN_UPPER_CHASSIS_LIGHT, HIGH);
	//todo- remove after debug (when real tonearm position can be obtained
	applyNextState(State::Stop33FullStop);
	// end todo
}

void StateProcessor::initTonearmState()
{
	if (TonearmState::isTonearmOnHolder())
		applyNextState(State::InitialPickupIsRaisingOnHolder);
	else
		applyNextState(State::InitialPickupIsRaisingOutsideHolder);
	//when all controller classes are initilaized- we start timer to read tonearm analog inputs
	Timer1.attachInterrupt(onTonearmTimerEvent).start(TONEARM_ANALOG_PARAMS_READOUT_INTERVAL);
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

TonearmDirection StateProcessor::getTonearmDirection() 
{
	return currentState->getTonearmState()->getDirection();
}