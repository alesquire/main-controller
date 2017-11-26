// States.h

#ifndef _STATES_h
#define _STATES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Relays.h"
#include "Motor.h"
#include "Microlift.h"
#include "SpeedButtons.h"
#include "TonearmState.h"
#include "TonearmButtons.h"
#include "DiskLed.h"
#include "AutostopTimer.h"

class States
{
private:
	Motor* motorState;
	Microlift* microliftStates;
	Relays* relaysState;
	TonearmState* tonearmState;
	TonearmButtons* tonearmButtons;
	SpeedButtons* speedButtons;
	DiskLed* diskLed;
	AutostopTimer* autostopTimer;

public:
	States(Motor _motorState, 
			Microlift _microliftStates, 
		Relays _relaysState, 
		TonearmState _tonearmState, 
		TonearmButtons _tonearmButtons, 
		SpeedButtons _speedButtons, 
		DiskLed _diskLed, 
		AutostopTimer _autostopTimer);
};
#endif

