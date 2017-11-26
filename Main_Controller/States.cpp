// 
// 
// 


#include "States.h"
States::States(Motor _motorState,
	Microlift _microliftStates,
	Relays _relaysState,
	TonearmState _tonearmState,
	TonearmButtons _tonearmButtons,
	SpeedButtons _speedButtons,
	DiskLed _diskLed,
	AutostopTimer _autostopTimer)
{
	motorState = &_motorState;
	microliftStates= &_microliftStates;
	relaysState = &_relaysState;
	tonearmState = &_tonearmState;
	tonearmButtons = &_tonearmButtons;
	speedButtons = &_speedButtons;
	diskLed = &_diskLed;
	autostopTimer = &_autostopTimer;
}



