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
			Motor* _motorState, 
			Microlift* _microliftStates, 
			Relays* _relaysState, 
			TonearmState* _tonearmState, 
			TonearmButtons* _tonearmButtons, 
			SpeedButtons* _speedButtons, 
			DiskLed* _diskLed, 
			AutostopTimer* _autostopTimer);
	
	/*
		Initializes all child classes
	*/
	static void init();

	virtual void apply();

	int getStateOrderNumber();

	TonearmState* getTonearmState();

	static State* const  InitialPickupIsRaisingOnHolder;
	static State* const  InitialPickupIsRaisingOutsideHolder;
	static State* const  InitialPickupIsMovingToHolder;
	static State* const  Stop33FullStop;
	static State* const  Rotate33;
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

