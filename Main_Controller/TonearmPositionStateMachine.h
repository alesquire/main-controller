#pragma once
#include "UnitStateMachine.h"
#include "Events.h"
#include "StateProcessor.h"

enum TonearmPositionEvents
{
	HOLDER_RISE,
	HOLDER_FALL,
	FIRST_TRACK_RISE,
	FIRST_TRACK_FALL,
	AUTOSTOP_RISE,
	AUTOSTOP_FALL
};

class TonearmPositionState
{
private:
	char* stateName;
	int stateOrderNumber;
	Events event; //reference to global event that will be called when state machine enters state
public:
	TonearmPositionState(char* _stateName, int _stateOrderNumber, Events _event) :
		stateName(_stateName), stateOrderNumber(_stateOrderNumber), event(_event) {};
	
	/*
		function is called to perform actions that should be performed when state macnhne enters new state
	*/
	virtual void apply()
	{
		StateProcessor::stateProcessor.processEvent(event);
	}

	int getStateOrderNumber() 
	{
		return stateOrderNumber;
	}

	char * getStateName() 
	{
		return stateName;
	}


	static TonearmPositionState* const OUTSIDE_HOLDER;
	static TonearmPositionState* const ON_HOLDER;
	static TonearmPositionState* const OVER_GAP;
	static TonearmPositionState* const OVER_DISK;
	static TonearmPositionState* const AUTOSTOP;
};

class TonearmPositionStateMachine: public UnitStateMachine<TonearmPositionEvents, TonearmPositionState>
{ 
	static TonearmPositionState* const transitionTable[5][6];

	virtual TonearmPositionState* getStateAtPosition(int stateNumber, int eventNumber)
	{
		return transitionTable[stateNumber][eventNumber];
	};

public:
	static TonearmPositionStateMachine tonearmPositionStateMachine;

	static void init()
	{
		if (TonearmState::isTonearmOnHolder())
			tonearmPositionStateMachine.initCurrentState(TonearmPositionState::ON_HOLDER);
		else
			tonearmPositionStateMachine.initCurrentState(TonearmPositionState::OUTSIDE_HOLDER);
	}
//todo- remove after debug
 virtual void processEvent(TonearmPositionEvents event)
 {
    UnitStateMachine::processEvent(event);
    debug(getCurrentState()->getStateName());
 }
};


