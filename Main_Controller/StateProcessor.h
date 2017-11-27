// StateProcessor.h

#ifndef _STATEPROCESSOR_h
#define _STATEPROCESSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Events.h"
#include "State.h"
class StateProcessor
{
private:
	State* currentState;

	State* getNextState(Events _event);

	const State* transitionTable[27][16] = 
	{
		{ NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL, },
		{ NULL,	&State::Rotate33,	&State::Play33AutoMoveToFirstTrack,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Stop45FullStop,	NULL, },
		{ &State::Stop33FullStop,	NULL,	&State::Play33AutoMoveToFirstTrack,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play33ManualPickupMoveOverGap,	NULL,	NULL,	NULL,	NULL,	&State::Rotate45,	NULL, },
		{ &State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play33AutoLowerPickup,	NULL,	NULL,	NULL,	&State::Play45AutoMoveToFirstTrack,	NULL, },
		{ &State::Stop33PickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play33Play,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play45AutoLowerPickup,	NULL, },
		{ &State::Stop33PickupIsRaising,	NULL,	NULL,	&State::Play33ManualPickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Stop33PickupOnAutostopPause,	NULL,	&State::Play45Play,	NULL, },
		{ &State::Stop33PickupIsRaising,	NULL,	NULL,	NULL,	&State::Play33ManualPickupFalls,	&State::Play33ManualPickupMoveOverDisk,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play45ManualPickupIsRaising,	NULL, },
		{ &State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	&State::Play33ManualPickupFalls,	NULL,	NULL,	NULL,	NULL,	&State::Play33ManualPickupMoveOverGap,	NULL,	NULL,	&State::Play33ManualPickupMoveAutostop,	NULL,	&State::Play45ManualPickupMoveOverDisk,	NULL, },
		{ &State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Rotate33,	NULL,	NULL,	&State::Play33ManualPickupMoveOverDisk,	NULL,	NULL,	&State::Play45ManualPickupMoveOverGap,	NULL, },
		{ &State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play33ManualPickupMoveOverDisk,	NULL,	NULL,	&State::Play45ManualPickupMoveAutostop,	NULL, },
		{ &State::Stop33PickupIsRaising,	NULL,	NULL,	&State::Play33ManualPickupIsRaising,	NULL,	NULL,	NULL,	&State::Play33Play,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play45ManualPickupFalls,	NULL, },
		{ &State::Stop33PickupIsRaising,	NULL,	NULL,	&State::Play33ManualPickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Stop45PickupOnAutostopPause,	&State::Stop33PickupIsRaising, },
		{ NULL,	NULL,	NULL,	NULL,	NULL,	&State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Stop45PickupIsRaising,	NULL, },
		{ NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Stop33FullStop,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL, },
		{ NULL,	&State::Rotate45,	&State::Play45AutoMoveToFirstTrack,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Stop33FullStop,	NULL,	NULL, },
		{ &State::Stop45FullStop,	NULL,	&State::Play45AutoMoveToFirstTrack,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play45ManualPickupMoveOverGap,	NULL,	NULL,	NULL,	&State::Rotate33,	NULL,	NULL, },
		{ &State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play45AutoLowerPickup,	NULL,	NULL,	&State::Play33AutoMoveToFirstTrack,	NULL,	NULL, },
		{ &State::Stop45PickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play45Play,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play33AutoLowerPickup,	NULL,	NULL, },
		{ &State::Stop45PickupIsRaising,	NULL,	NULL,	&State::Play45ManualPickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Stop45PickupOnAutostopPause,	&State::Play33Play,	NULL,	NULL, },
		{ &State::Stop45PickupIsRaising,	NULL,	NULL,	NULL,	&State::Play45ManualPickupFalls,	&State::Play45ManualPickupMoveOverDisk,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play33ManualPickupIsRaising,	NULL,	NULL, },
		{ &State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	&State::Play45ManualPickupFalls,	NULL,	NULL,	NULL,	NULL,	&State::Play45ManualPickupMoveOverGap,	NULL,	NULL,	&State::Play45ManualPickupMoveAutostop,	&State::Play33ManualPickupMoveOverDisk,	NULL,	NULL, },
		{ &State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Rotate45,	NULL,	NULL,	&State::Play45ManualPickupMoveOverDisk,	NULL,	&State::Play33ManualPickupMoveOverGap,	NULL,	NULL, },
		{ &State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play45ManualPickupMoveOverDisk,	NULL,	&State::Play33ManualPickupMoveAutostop,	NULL,	NULL, },
		{ &State::Stop45PickupIsRaising,	NULL,	NULL,	&State::Play45ManualPickupIsRaising,	NULL,	NULL,	NULL,	&State::Play45Play,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Play33ManualPickupFalls,	NULL,	NULL, },
		{ &State::Stop45PickupIsRaising,	NULL,	NULL,	&State::Play45ManualPickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Stop33PickupOnAutostopPause,	NULL,	&State::Stop45PickupIsRaising, },
		{ NULL,	NULL,	NULL,	NULL,	NULL,	&State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	&State::Stop33PickupIsRaising,	NULL,	NULL }
	};

	void applyNextState(const State *state);

public:
	
	State* getCurrentState();

	void processEvent(Events _event);
};

#endif

