#pragma once
#include "UnitStateMachine.h"

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
public:
	TonearmPositionState(char* _stateName, int _stateOrderNumber) :
		stateName(_stateName), stateOrderNumber(_stateOrderNumber) {};
	
	/*
		function is called to perform actions that should be performed when state macnhne enters new state
	*/
	virtual void apply()=0;

	int getStateOrderNumber() 
	{
		return stateOrderNumber;
	}

	char * getStateName() 
	{
		return stateName;
	}
	static TonearmPositionState* const ON_HOLDER;
	static TonearmPositionState* const OVER_GAP;
	static TonearmPositionState* const OVER_DISK;
	static TonearmPositionState* const AUTOSTOP;
};


class TonearmPositionStateMachine: UnitStateMachine<TonearmPositionEvents, TonearmPositionState>
{ 
	static TonearmPositionState* transitionTable[4][6];
	static TonearmPositionStateMachine* tonearmPositionStateMachine;
	virtual TonearmPositionState* getStateAtPosition(int stateNumber, int eventNumber)
	{
		return transitionTable[stateNumber][eventNumber];
	};

public:
	
};

