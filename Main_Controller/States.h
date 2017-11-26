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
	When state is changed - apply method should be called to set new walues of outputs 
*/


class States : public Appliable
{
private:
	Motor*  motorState ;
	Microlift*  microliftStates;
	Relays*  relaysState;
	TonearmState*  tonearmState;
	TonearmButtons*  tonearmButtons;
	SpeedButtons*  speedButtons;
	DiskLed*  diskLed;
	AutostopTimer*  autostopTimer;

public:
	States(Motor _motorState, 
			Microlift _microliftStates, 
			Relays _relaysState, 
			TonearmState _tonearmState, 
			TonearmButtons _tonearmButtons, 
			SpeedButtons _speedButtons, 
			DiskLed _diskLed, 
			AutostopTimer _autostopTimer);
	virtual void init()
	{
		motorState->init();
		microliftStates->init();
		relaysState->init();
		tonearmState->init();
		tonearmButtons->init();
		speedButtons->init();
		diskLed->init();
		autostopTimer->init();
	}

	virtual void apply()
	{
		motorState->apply();
		microliftStates->apply();
		relaysState->apply();
		tonearmState->apply();
		tonearmButtons->apply();
		speedButtons->apply();
		diskLed->apply();
		autostopTimer->apply();
	}

	const static States Initial;
	const static States Stop33FullStop;
	const static States Rotate33;
	const static States Play33AutoMoveToFirstTrack;
	const static States Play33AutoLowerPickUP;
	const static States Play33Play;
	const static States Play33ManualPickUPIsRaising;
	const static States Play33ManualPickUPMoveOverDisk;
	const static States Play33ManualPickUPMoveOverGap;
	const static States Play33ManualPickUPMoveAutostop;
	const static States Play33ManualPickUPFalls;
	const static States Stop33PickUPOnAutostopPause;
	const static States Stop33PickUPIsRaising;
	const static States Stop33PickUPIsAutomaticallyMovingToHolder;
	const static States Stop45FullStop;
	const static States Rotate45;
	const static States Play45AutoMoveToFirstTrack;
	const static States Play45AutoLowerPickUP;
	const static States Play45Play;
	const static States Play45ManualPickUPIsRaising;
	const static States Play45ManualPickUPMoveOverDisk;
	const static States Play45ManualPickUPMoveOverGap;
	const static States Play45ManualPickUPMoveAutostop;
	const static States Play45ManualPickUPFalls;
	const static States Stop45PickUPOnAutostopPause;
	const static States Stop45PickUPIsRaising;
	const static States Stop45PickUPIsAutomaticallyMovingToHolder;

};
#endif

