// 
// 
// 

#include "StateProcessor.h"
//#include "Initializers.cpp"


StateProcessor StateProcessor::stateProcessor;

void StateProcessor::applyNextState(State *state)
{
	if (state)
	{
		debug("Apply state ");
		debug(state->getStateName());
		debug("\n");
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

	if (!currentState)
	{
		debug("CurrentState is null\n");
		return;
	}
	int currentStateOrder = currentState->getStateOrderNumber();
	debug("Current state = ");
	debug(currentState->getStateName());
	debug("\n");
	debug("Processing Event: ");
	debug(eventNames[_event]);
	debug("\n");
	debug("Next state order= ");
	debug(currentStateOrder);
	debug("\n"); 
	debug("Next event order= ");
	debug(_event);
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
		debug("Event ");
		debug(eventNames[_event]);
		debug(" is ignored \n"); 
	}
}

void StateProcessor::init() 
{
	State::init();
	debug("init\n");
	initOutput(PIN_BOTTOM_CHASSIS_LIGHT);
	digitalWrite(PIN_BOTTOM_CHASSIS_LIGHT, HIGH);
	initOutput(PIN_UPPER_CHASSIS_LIGHT);
	digitalWrite(PIN_UPPER_CHASSIS_LIGHT, HIGH);
	//todo- remove after debug (when real tonearm position can be obtained
	//applyNextState(State::Stop33FullStop);
	// end todo
	//when all controller classes are initilaized- we start timer to read tonearm analog inputs
	
	
	//todo- commented tonearm interrupt
	//Timer1.attachInterrupt(onTonearmTimerEvent).start(TONEARM_ANALOG_PARAMS_READOUT_INTERVAL);
	
	//need to define where is the tonearm and pass it to default position
	initTonearmState();
}

void StateProcessor::initTonearmState()
{
	debug("Initialize Tonearm position\n");
	if (TonearmState::isTonearmOnHolder())
	{
		debug("applyNextState(State::Stop33PickupIsDown)\n");
		applyNextState(State::Stop33PickupIsDown);
	}
	else
	{
		debug("applyNextState(State::InitialPickupIsRaisingOutsideHolder)\n");
		applyNextState(State::InitialPickupIsRaisingOutsideHolder);
	}
}

void StateProcessor::scanTonearmState()
{
	//debug("scanTonearmState\n");
	//reads analog inputs - joystick left-right, antiscate and damper values and updates solenoid voltage
	currentState->getTonearmState()->apply();
    //reads joystick up-down position 
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
