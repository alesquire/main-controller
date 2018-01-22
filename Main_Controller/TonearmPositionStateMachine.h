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
TonearmPositionState* const TonearmPositionState::OUTSIDE_HOLDER = new TonearmPositionState("OUTSIDE_HOLDER", 0,Events::TonearmPositionHolder ); //in this state event is never thrown as this state has no entrance- only exit
TonearmPositionState* const TonearmPositionState::ON_HOLDER = new TonearmPositionState("ON_HOLDER", 0, Events::TonearmPositionHolder);
TonearmPositionState* const TonearmPositionState::OVER_GAP = new TonearmPositionState("OVER_GAP", 0, Events::TonearmPositionOverGap);
TonearmPositionState* const TonearmPositionState::OVER_DISK = new TonearmPositionState("OVER_DISK", 0, Events::TonearmPositionOverDisk);
TonearmPositionState* const TonearmPositionState::AUTOSTOP = new TonearmPositionState("AUTOSTOP", 0, Events::TonearmPositionOnAutostop);

class TonearmPositionStateMachine: UnitStateMachine<TonearmPositionEvents, TonearmPositionState>
{ 
	static TonearmPositionState* const transitionTable[5][6];

	virtual TonearmPositionState* getStateAtPosition(int stateNumber, int eventNumber)
	{
		return transitionTable[stateNumber][eventNumber];
	};

public:
	static TonearmPositionStateMachine* tonearmPositionStateMachine;

	static void init()
	{
		if (TonearmState::isTonearmOnHolder())
			tonearmPositionStateMachine->initCurrentState(TonearmPositionState::ON_HOLDER);
		else
			tonearmPositionStateMachine->initCurrentState(TonearmPositionState::OUTSIDE_HOLDER);
	}
};

TonearmPositionState* const TonearmPositionStateMachine::transitionTable[5][6] = {
	{ NULL,	TonearmPositionState::ON_HOLDER,	NULL,	NULL,	NULL,	NULL, },
	{ TonearmPositionState::OVER_GAP,	NULL,	NULL,	NULL,	NULL,	NULL, },
	{ NULL,	TonearmPositionState::ON_HOLDER,	TonearmPositionState::OVER_DISK,	NULL,	NULL,	NULL, },
	{ NULL,	NULL,	NULL,	TonearmPositionState::OVER_GAP,	NULL,	TonearmPositionState::AUTOSTOP, },
	{ NULL,	NULL,	NULL,	NULL,	TonearmPositionState::OVER_DISK,	NULL }
};

