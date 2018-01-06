// 
// 
// 


#include "State.h"
#include "DebugFunctions.h"
State::State(int _orderNumber,
	char* _stateName,
	Motor* _motorState,
	Microlift* _microliftStates,
	Relays* _relaysState,
	TonearmState* _tonearmState,
	TonearmButtons* _tonearmButtons,
	SpeedButtons* _speedButtons,
	DiskLed* _diskLed,
	AutostopTimer* _autostopTimer,
	Stroboscope*  _stroboscope)
{
	stateOrderNumber = _orderNumber;
	stateName = _stateName;
	motorState =_motorState;
	microliftStates= _microliftStates;
	relaysState = _relaysState;
	tonearmState = _tonearmState;
	tonearmButtons = _tonearmButtons;
	speedButtons = _speedButtons;
	diskLed = _diskLed;
	autostopTimer = _autostopTimer;
	stroboscope = _stroboscope;
}

void State::init()
{
	Motor::init();
	Microlift::init();
	Relays::init();
	TonearmState::init();
	TonearmButtons::init();
	SpeedButtons::init();
	DiskLed::init();
	AutostopTimer::init();
	Stroboscope::init();
}

void State::apply()
{
	motorState->apply();
	microliftStates->apply();
	relaysState->apply();
	tonearmState->apply();
	tonearmButtons->apply();
	speedButtons->apply();
	diskLed->apply();
	autostopTimer->apply();
	stroboscope->apply();
}

int State::getStateOrderNumber()
{
	return stateOrderNumber;
}

char * State::getStateName()
{
	return stateName;
}

TonearmState* State::getTonearmState()
{
	return tonearmState;
}
