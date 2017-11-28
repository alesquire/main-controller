// 
// 
// 

#include "StateProcessor.h"
void StateProcessor::applyNextState(const State *state)
{
	if (state)
	{
		currentState = const_cast<State*>(state);
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
	const State *nextState = transitionTable[currentStateOrder][_event];
	if (nextState)// most of transition table items are nulls - as event shouldn't be processed on particular state
	{
		applyNextState(nextState);
	}
}

void StateProcessor::init() //todo - replace with correct state read-out and initialization
{
	applyNextState(&State::Initial);
}