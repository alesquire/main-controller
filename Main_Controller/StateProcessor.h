// StateProcessor.h

#ifndef _STATEPROCESSOR_h
#define _STATEPROCESSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

#include "Events.h"
#include "State.h"
#include "JoystickUpDownState.h"
#include "DebugFunctions.h"

#define TONEARM_ANALOG_PARAMS_READOUT_INTERVAL 1E5 //(0.1 ms)

class StateProcessor
{
private:
	State* currentState;

	State* getNextState(Events _event);

	JoystickUpDownState joystickUpDownState;

	State* const  transitionTable[29][15] = {
		{ NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33FullStop,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL, },
		{ NULL,	NULL,	NULL,	NULL,	NULL,	State::InitialPickupIsMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL, },
		{ NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33FullStop,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL, },
		{ NULL,	State::Rotate33,	State::Play33AutoMoveToFirstTrack,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop45FullStop,	NULL, },
		{ State::Stop33FullStop,	NULL,	State::Play33AutoMoveToFirstTrack,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play33ManualPickupMoveOverGap,	NULL,	NULL,	NULL,	State::Rotate45,	NULL, },
		{ State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play33AutoLowerPickup,	NULL,	NULL,	State::Play45AutoMoveToFirstTrack,	NULL, },
		{ State::Stop33PickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play33Play,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45AutoLowerPickup,	NULL, },
		{ State::Stop33PickupIsRaising,	NULL,	NULL,	State::Play33ManualPickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33PickupOnAutostopPause,	NULL,	State::Play45Play,	NULL, },
		{ State::Stop33PickupIsRaising,	NULL,	NULL,	NULL,	State::Play33ManualPickupFalls,	State::Play33ManualPickupMoveOverDisk,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45ManualPickupIsRaising,	NULL, },
		{ State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	State::Play33ManualPickupFalls,	NULL,	NULL,	NULL,	NULL,	State::Play33ManualPickupMoveOverGap,	NULL,	State::Play33ManualPickupMoveAutostop,	NULL,	State::Play45ManualPickupMoveOverDisk,	NULL, },
		{ State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Rotate33,	NULL,	State::Play33ManualPickupMoveOverDisk,	NULL,	NULL,	State::Play45ManualPickupMoveOverGap,	NULL, },
		{ State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play33ManualPickupMoveOverDisk,	NULL,	NULL,	State::Play45ManualPickupMoveAutostop,	NULL, },
		{ State::Stop33PickupIsRaising,	NULL,	NULL,	State::Play33ManualPickupIsRaising,	NULL,	NULL,	NULL,	State::Play33Play,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45ManualPickupFalls,	NULL, },
		{ State::Stop33PickupIsRaising,	NULL,	NULL,	State::Play33ManualPickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop45PickupOnAutostopPause,	State::Stop33PickupIsRaising, },
		{ NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop45PickupIsRaising,	NULL, },
		{ NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33FullStop,	NULL,	NULL,	NULL,	NULL,	State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL, },
		{ NULL,	State::Rotate45,	State::Play45AutoMoveToFirstTrack,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33FullStop,	NULL,	NULL, },
		{ State::Stop45FullStop,	NULL,	State::Play45AutoMoveToFirstTrack,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45ManualPickupMoveOverGap,	NULL,	NULL,	State::Rotate33,	NULL,	NULL, },
		{ State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45AutoLowerPickup,	NULL,	State::Play33AutoMoveToFirstTrack,	NULL,	NULL, },
		{ State::Stop45PickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45Play,	NULL,	NULL,	NULL,	NULL,	State::Play33AutoLowerPickup,	NULL,	NULL, },
		{ State::Stop45PickupIsRaising,	NULL,	NULL,	State::Play45ManualPickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop45PickupOnAutostopPause,	State::Play33Play,	NULL,	NULL, },
		{ State::Stop45PickupIsRaising,	NULL,	NULL,	NULL,	State::Play45ManualPickupFalls,	State::Play45ManualPickupMoveOverDisk,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play33ManualPickupIsRaising,	NULL,	NULL, },
		{ State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	State::Play45ManualPickupFalls,	NULL,	NULL,	NULL,	NULL,	State::Play45ManualPickupMoveOverGap,	NULL,	State::Play45ManualPickupMoveAutostop,	State::Play33ManualPickupMoveOverDisk,	NULL,	NULL, },
		{ State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Rotate45,	NULL,	State::Play45ManualPickupMoveOverDisk,	NULL,	State::Play33ManualPickupMoveOverGap,	NULL,	NULL, },
		{ State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45ManualPickupMoveOverDisk,	NULL,	State::Play33ManualPickupMoveAutostop,	NULL,	NULL, },
		{ State::Stop45PickupIsRaising,	NULL,	NULL,	State::Play45ManualPickupIsRaising,	NULL,	NULL,	NULL,	State::Play45Play,	NULL,	NULL,	NULL,	NULL,	State::Play33ManualPickupFalls,	NULL,	NULL, },
		{ State::Stop45PickupIsRaising,	NULL,	NULL,	State::Play45ManualPickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33PickupOnAutostopPause,	NULL,	State::Stop45PickupIsRaising, },
		{ NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33PickupIsRaising,	NULL,	NULL, }
	};

	void applyNextState(State *state);

	StateProcessor() {};

public:
	
	State* getCurrentState();

	void processEvent(Events _event);

	TonearmDirection getTonearmDirection();

	void init();

	/*
		joystick doesn't produce events because it is an analog input. To process joystick position change we should periodically check state and:
		- for up-down axis- check if joysticlk is up and down, and if it is so- produce event. But only once per position.
		- for left-right action we should call current TonearmState class instance to read joystick position input and write DAC pin output
		onTimer method itself should be caled externally

	*/
	void onTimer();

	//moves tonearm and other controls to initial state- tonearm on holder, microlift in HOLD state
	void initTonearmState();


	static StateProcessor stateProcessor;
};

#endif

