// States.h

#ifndef _STATES_h
#define _STATES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Appliable.h"
#include "Relays.h"
#include "Motor.h"
#include "Microlift.h"
#include "SpeedButtons.h"
#include "TonearmState.h"
#include "TonearmButtons.h"
#include "DiskLed.h"
#include "AutostopTimer.h"
/*
	Class declares all consistent state that can be in turntable. State is a set of all outputs - leds, motor driver, relays etc  (and some auxiliary elements as timers). 
	When state is changed - apply method should be called to set new walues of outputs.

	All events are numbered in source Excel to simplify state transition map creation
*/


class State : public Appliable
{
private:
	int stateOrderNumber; 
	Motor*  motorState ;
	Microlift*  microliftStates;
	Relays*  relaysState;
	TonearmState*  tonearmState;
	TonearmButtons*  tonearmButtons;
	SpeedButtons*  speedButtons;
	DiskLed*  diskLed;
	AutostopTimer*  autostopTimer;
	
public:
	State(int _orderNumber,
			Motor _motorState, 
			Microlift _microliftStates, 
			Relays _relaysState, 
			TonearmState _tonearmState, 
			TonearmButtons _tonearmButtons, 
			SpeedButtons _speedButtons, 
			DiskLed _diskLed, 
			AutostopTimer _autostopTimer);
	
	virtual void init();

	virtual void apply();

	int getStateOrderNumber();

	const static State Initial;
	const static State Stop33FullStop;
	const static State Rotate33;
	const static State Play33AutoMoveToFirstTrack;
	const static State Play33AutoLowerPickUP;
	const static State Play33Play;
	const static State Play33ManualPickUPIsRaising;
	const static State Play33ManualPickUPMoveOverDisk;
	const static State Play33ManualPickUPMoveOverGap;
	const static State Play33ManualPickUPMoveAutostop;
	const static State Play33ManualPickUPFalls;
	const static State Stop33PickUPOnAutostopPause;
	const static State Stop33PickUPIsRaising;
	const static State Stop33PickUPIsAutomaticallyMovingToHolder;
	const static State Stop45FullStop;
	const static State Rotate45;
	const static State Play45AutoMoveToFirstTrack;
	const static State Play45AutoLowerPickUP;
	const static State Play45Play;
	const static State Play45ManualPickUPIsRaising;
	const static State Play45ManualPickUPMoveOverDisk;
	const static State Play45ManualPickUPMoveOverGap;
	const static State Play45ManualPickUPMoveAutostop;
	const static State Play45ManualPickUPFalls;
	const static State Stop45PickUPOnAutostopPause;
	const static State Stop45PickUPIsRaising;
	const static State Stop45PickUPIsAutomaticallyMovingToHolder;

};
#endif

