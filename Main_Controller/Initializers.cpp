#include "StateProcessor.h"
#include "SensorsState.h"
#include "TonearmPositionStateMachine.h"

#ifndef _INITIALIZERS_H_
#define _INITIALIZERS_H_

Motor* const Motor::OFF = new Motor(LOW, LOW);
Motor* const Motor::Mode33 = new Motor(HIGH, LOW);
Motor* const Motor::Mode45 = new Motor(LOW, HIGH);

DiskLed* const DiskLed::OFF = new DiskLed(LOW, LOW, LOW);
DiskLed* const DiskLed::RED = new DiskLed(HIGH, LOW, LOW);
DiskLed* const DiskLed::GREEN = new DiskLed(LOW, HIGH, LOW);
DiskLed* const DiskLed::BLUE = new DiskLed(LOW, LOW, HIGH);

AutostopTimer* const AutostopTimer::ON = new  AutostopTimerON();
AutostopTimer* const AutostopTimer::OFF = new AutostopTimerOFF();

Microlift* const Microlift::UP = new Microlift(LOW, LOW, "UP");
Microlift* const Microlift::DOWN = new Microlift(LOW, HIGH, "DOWN");
Microlift* const Microlift::HOLD = new Microlift(HIGH, LOW, "HOLD");

Relays* const Relays::PLAY = new Relays(LOW, LOW);
Relays* const Relays::MOVE = new Relays(HIGH, HIGH);

SpeedButtons* const SpeedButtons::OFF = new SpeedButtons(LOW, LOW);
SpeedButtons* const SpeedButtons::LED33 = new SpeedButtons(HIGH, LOW);
SpeedButtons* const SpeedButtons::LED45 = new SpeedButtons(LOW, HIGH);

Stroboscope* const Stroboscope::OFF = new OffStroboscope();
Stroboscope* const Stroboscope::STROBO_33 = new Stroboscope33();
Stroboscope* const Stroboscope::STROBO_45 = new Stroboscope45();

TonearmButtons* const TonearmButtons::OFF = new TonearmButtons(LOW, LOW, LOW);
TonearmButtons* const TonearmButtons::PLAY = new TonearmButtons(HIGH, LOW, LOW);
TonearmButtons* const TonearmButtons::ROTATE = new TonearmButtons(LOW, HIGH, LOW);
TonearmButtons* const TonearmButtons::STOP = new TonearmButtons(LOW, LOW, HIGH);

TonearmState* const TonearmState::STOP = new StopMode();
TonearmState* const TonearmState::PLAY = new Play();
TonearmState* const TonearmState::MOVE = new Move();
TonearmState* const TonearmState::AUTOSTOP = new Autostop();
TonearmState* const TonearmState::HOLDER = new Holder();
TonearmState* const TonearmState::FULL_LEFT = new FullLeft();
TonearmState* const TonearmState::FULL_RIGHT = new FullRight();

TonearmPositionState* const TonearmPositionState::OUTSIDE_HOLDER = new TonearmPositionState("OUTSIDE_HOLDER", 0, Events::TonearmPositionHolder); //in this state event is never thrown as this state has no entrance- only exit
TonearmPositionState* const TonearmPositionState::ON_HOLDER = new TonearmPositionState("ON_HOLDER", 0, Events::TonearmPositionHolder);
TonearmPositionState* const TonearmPositionState::OVER_GAP = new TonearmPositionState("OVER_GAP", 0, Events::TonearmPositionOverGap);
TonearmPositionState* const TonearmPositionState::OVER_DISK = new TonearmPositionState("OVER_DISK", 0, Events::TonearmPositionOverDisk);
TonearmPositionState* const TonearmPositionState::AUTOSTOP = new TonearmPositionState("AUTOSTOP", 0, Events::TonearmPositionOnAutostop);

TonearmPositionStateMachine TonearmPositionStateMachine::tonearmPositionStateMachine;

State* const  State::InitialPickupIsRaisingOnHolder = new State(0, "InitialPickupIsRaisingOnHolder", Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, AutostopTimer::OFF, Stroboscope::OFF);
State* const  State::InitialPickupIsRaisingOutsideHolder = new State(1, "InitialPickupIsRaisingOutsideHolder", Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, AutostopTimer::OFF, Stroboscope::OFF);
State* const  State::InitialPickupIsMovingToHolder = new State(2, "InitialPickupIsMovingToHolder", Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, AutostopTimer::OFF, Stroboscope::OFF);
State* const  State::Stop33FullStop = new State(3, "Stop33FullStop", Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF, Stroboscope::OFF);
State* const  State::Rotate33 = new State(4, "Rotate33", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33AutoMoveToFirstTrack = new State(5, "Play33AutoMoveToFirstTrack", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33AutoLowerPickup = new State(6, "Play33AutoLowerPickup", Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33Play = new State(7, "Play33Play", Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::GREEN, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupIsRaising = new State(8, "Play33ManualPickupIsRaising", Motor::Mode33, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupMoveOverDisk = new State(9, "Play33ManualPickupMoveOverDisk", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupMoveOverGap = new State(10, "Play33ManualPickupMoveOverGap", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupMoveAutostop = new State(11, "Play33ManualPickupMoveAutostop", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupFalls = new State(12, "Play33ManualPickupFalls", Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Stop33PickupOnAutostopPause = new State(13, "Stop33PickupOnAutostopPause", Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::ON, Stroboscope::STROBO_33);
State* const  State::Stop33PickupIsRaising = new State(14, "Stop33PickupIsRaising", Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Stop33PickupIsAutomaticallyMovingToHolder = new State(15, "Stop33PickupIsAutomaticallyMovingToHolder", Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Stop45FullStop = new State(16, "Stop45FullStop", Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF, Stroboscope::OFF);
State* const  State::Rotate45 = new State(17, "Rotate45", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45AutoMoveToFirstTrack = new State(18, "Play45AutoMoveToFirstTrack", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45AutoLowerPickup = new State(19, "Play45AutoLowerPickup", Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45Play = new State(20, "Play45Play", Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::GREEN, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupIsRaising = new State(21, "Play45ManualPickupIsRaising", Motor::Mode45, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupMoveOverDisk = new State(22, "Play45ManualPickupMoveOverDisk", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupMoveOverGap = new State(23, "Play45ManualPickupMoveOverGap", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupMoveAutostop = new State(24, "Play45ManualPickupMoveAutostop", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupFalls = new State(25, "Play45ManualPickupFalls", Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Stop45PickupOnAutostopPause = new State(26, "Stop45PickupOnAutostopPause", Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::ON, Stroboscope::STROBO_45);
State* const  State::Stop45PickupIsRaising = new State(27, "Stop45PickupIsRaising", Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Stop45PickupIsAutomaticallyMovingToHolder = new State(28, "Stop45PickupIsAutomaticallyMovingToHolder", Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF, Stroboscope::STROBO_45);

TonearmPositionState* const TonearmPositionStateMachine::transitionTable[5][6] = {
	{ NULL,	TonearmPositionState::ON_HOLDER,	NULL,	NULL,	NULL,	NULL, },
	{ TonearmPositionState::OVER_GAP,	NULL,	NULL,	NULL,	NULL,	NULL, },
	{ NULL,	TonearmPositionState::ON_HOLDER,	TonearmPositionState::OVER_DISK,	NULL,	NULL,	NULL, },
	{ NULL,	NULL,	NULL,	TonearmPositionState::OVER_GAP,	NULL,	TonearmPositionState::AUTOSTOP, },
	{ NULL,	NULL,	NULL,	NULL,	TonearmPositionState::OVER_DISK,	NULL }
};


State* const  StateProcessor::transitionTable[29][15] = {
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

SensorState SensorsState::sensorStates[] =
{
	SensorState(PIN_STOP_BUTTON,onStopButtonPress,RISES),
	SensorState(PIN_PLAY_BUTTON, onPlayButtonPress, RISES),
	SensorState(PIN_ROTATE_BUTTON, onRotateButtonPress, RISES),
	SensorState(PIN_33_BUTTON, onSpeed33ButtonPress, RISES),
	SensorState(PIN_45_BUTTON, onSpeed45ButtonPress, RISES),
	SensorState(PIN_MICROLIFT_UPPER_SENSOR, onMicroliftSensorEvent, CHANGES),
	SensorState(PIN_MICROLIFT_LOWER_SENSOR, onMicroliftSensorEvent, CHANGES),
	SensorState(PIN_TONEARM_HOLDER,onHolderSensorRisingEvent,RISES),
	SensorState(PIN_TONEARM_HOLDER,onHolderSensorFallingEvent,FALLS),
	SensorState(PIN_FIRST_TRACK,onFirstTrackSensorRisingEvent,RISES),
	SensorState(PIN_FIRST_TRACK,onFirstTrackSensorFallingEvent,FALLS),
	SensorState(PIN_AUTOSTOP,onAutostopSensorRisingEvent,RISES),
	SensorState(PIN_AUTOSTOP,onAutostopSensorFallingEvent,FALLS)
};
SensorsState SensorsState::instance;
#endif
