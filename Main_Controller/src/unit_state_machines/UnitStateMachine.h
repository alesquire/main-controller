#pragma once


template <typename EventType, class StateType>
class UnitStateMachine
{
private:
	StateType* currentState;

	/*
		should return item from two-dimensional array - transition table where first dimention (rows) corresponds to states and second dimension is an event 
	*/
	virtual StateType* getStateAtPosition(int stateNumber,int eventNumber) = 0;

	/*
		returns next state that corresponds to event applied to currenct state
		method can return null if event doesn't produce next state
	*/
	StateType* getNextState(EventType event)
	{
		int currentStateOrder = currentState->getStateOrderNumber();
		StateType *nextState = getStateAtPosition(currentStateOrder,event);
		return nextState;
	}

	void applyNextState(StateType* state)
	{
		state->apply();
	}
public:

	void processEvent(EventType event)
	{
		StateType *nextState = getNextState(event);
		if (nextState)
		{
			applyNextState(nextState);
			currentState = nextState;
		}
	}

	StateType* getCurrentState()
	{
		return currentState;
	}

};

