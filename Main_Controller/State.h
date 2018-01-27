// States.h

#ifndef _STATES_h
#define _STATES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

#include "Appliable.h"
#include "Relays.h"
#include "Motor.h"
#include "Microlift.h"
#include "SpeedButtons.h"
#include "TonearmState.h"
#include "TonearmButtons.h"
#include "DiskLed.h"
#include "DelayTimer.h"
#include "Stroboscope.h"
/*
	Class declares all consistent state that can be in turntable. State is a set of all outputs - leds, motor driver, relays etc  (and some auxiliary elements as timers). 
	When state is changed - apply method should be called to set new walues of outputs.

	All events are numbered in source Excel to simplify state transition map creation
*/


class State : public Appliable
{
public:  //debug- remove publuic - change to private 
	int stateOrderNumber; 
	char* stateName;
	Motor*  motorState ;
	Microlift*  microliftStates;
	Relays*  relaysState;
	TonearmState*  tonearmState;
	TonearmButtons*  tonearmButtons;
	SpeedButtons*  speedButtons;
	DiskLed*  diskLed;
	DelayTimer*  autostopTimer;
	Stroboscope*  stroboscope;
public:

	State(int _orderNumber,
			char* stateName,
			Motor* _motorState,
			Microlift* _microliftStates, 
			Relays* _relaysState, 
			TonearmState* _tonearmState, 
			TonearmButtons* _tonearmButtons, 
			SpeedButtons* _speedButtons, 
			DiskLed* _diskLed, 
			DelayTimer* _autostopTimer,
			Stroboscope*  _stroboscope);
	
	/*
		Initializes all child classes
	*/
	static void init();

	static void initStates();

	virtual void apply();

	int getStateOrderNumber();

	char * getStateName();

	TonearmState* getTonearmState();

	static State* const  InitialPickupIsRaisingOnHolder;
	static State* const  InitialPickupIsRaisingOutsideHolder;
	static State* const  InitialPickupIsMovingToHolder;
	static State* const  Stop33FullStop;
	static State* const  Rotate33;
	static State* const  Play33AccelerateDisk;
	static State* const  Play33AutoMoveToFirstTrack;
	static State* const  Play33AutoLowerPickup;
	static State* const  Play33Play;
	static State* const  Play33ManualPickupIsRaising;
	static State* const  Play33ManualPickupMoveOverDisk;
	static State* const  Play33ManualPickupMoveOverGap;
	static State* const  Play33ManualPickupMoveAutostop;
	static State* const  Play33ManualPickupFalls;
	static State* const  Stop33PickupOnAutostopPause;
	static State* const  Stop33PickupIsRaising;
	static State* const  Stop33PickupIsAutomaticallyMovingToHolder;
	static State* const  Stop45FullStop;
	static State* const  Rotate45;
	static State* const  Play45AccelerateDisk;
	static State* const  Play45AutoMoveToFirstTrack;
	static State* const  Play45AutoLowerPickup;
	static State* const  Play45Play;
	static State* const  Play45ManualPickupIsRaising;
	static State* const  Play45ManualPickupMoveOverDisk;
	static State* const  Play45ManualPickupMoveOverGap;
	static State* const  Play45ManualPickupMoveAutostop;
	static State* const  Play45ManualPickupFalls;
	static State* const  Stop45PickupOnAutostopPause;
	static State* const  Stop45PickupIsRaising;
	static State* const  Stop45PickupIsAutomaticallyMovingToHolder;

};
#endif

