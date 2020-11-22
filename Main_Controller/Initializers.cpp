#include "StateProcessor.h"
#include "SensorsState.h"

#ifndef _INITIALIZERS_H_
#define _INITIALIZERS_H_



Motor* const Motor::OFF = new Motor(LOW, LOW);
Motor* const Motor::Mode33 = new Motor(HIGH, LOW);
Motor* const Motor::Mode45 = new Motor(LOW, HIGH);

DiskLed* const DiskLed::OFF = new DiskLed(LOW, LOW, LOW);
DiskLed* const DiskLed::RED = new DiskLed(HIGH, LOW, LOW);
DiskLed* const DiskLed::GREEN = new DiskLed(LOW, HIGH, LOW);
DiskLed* const DiskLed::BLUE = new DiskLed(LOW, LOW, HIGH);

DelayTimer* const DelayTimer::ON = new  DelayTimerON();
DelayTimer* const DelayTimer::OFF = new DelayTimerOFF();

Microlift* const Microlift::UP = new Microlift(LOW, LOW, "UP");
Microlift* const Microlift::DOWN = new Microlift(LOW, HIGH, "DOWN");
Microlift* const Microlift::HOLD = new Microlift(HIGH, LOW, "HOLD");

Relays* const Relays::MOVE = new Relays(LOW, LOW);
Relays* const Relays::PLAY = new Relays(HIGH, HIGH);

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


// most of these items are auto-generated in Excel spreadsheet "States and Events v2"

State* const  State::InitialPickupIsRaisingOutsideHolder = new State(0, "InitialPickupIsRaisingOutsideHolder", Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, DelayTimer::OFF, Stroboscope::OFF);
State* const  State::InitialPickupIsMovingToHolder = new State(1, "InitialPickupIsMovingToHolder", Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, DelayTimer::OFF, Stroboscope::OFF);
State* const  State::Stop33PickupIsUp = new State(2, "Stop33PickupIsUp", Motor::OFF, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, DelayTimer::OFF, Stroboscope::OFF);
State* const  State::Stop33PickupIsDown = new State(3, "Stop33PickupIsDown", Motor::OFF, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, DelayTimer::OFF, Stroboscope::OFF);
State* const  State::Rotate33PickupIsRising = new State(4, "Rotate33PickupIsRising", Motor::Mode33, Microlift::UP, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::OFF);
State* const  State::Rotate33RotateOnHolder = new State(5, "Rotate33RotateOnHolder", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33PickupIsRising = new State(6, "Play33PickupIsRising", Motor::Mode33, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::OFF);
State* const  State::Play33AccelerateDisk = new State(7, "Play33AccelerateDisk", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, DelayTimer::ON, Stroboscope::STROBO_33);
State* const  State::Play33AutoMoveToFirstTrack = new State(8, "Play33AutoMoveToFirstTrack", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33AutoLowerPickup = new State(9, "Play33AutoLowerPickup", Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33Play = new State(10, "Play33Play", Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::GREEN, DelayTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupIsRaising = new State(11, "Play33ManualPickupIsRaising", Motor::Mode33, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupMoveOverDisk = new State(12, "Play33ManualPickupMoveOverDisk", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupMoveOverGap = new State(13, "Play33ManualPickupMoveOverGap", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupMoveAutostop = new State(14, "Play33ManualPickupMoveAutostop", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupFalls = new State(15, "Play33ManualPickupFalls", Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Stop33PickupOnAutostopPause = new State(16, "Stop33PickupOnAutostopPause", Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::RED, DelayTimer::ON, Stroboscope::STROBO_33);
State* const  State::Stop33PickupIsRaising = new State(17, "Stop33PickupIsRaising", Motor::Mode33, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, DelayTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Stop33PickupIsAutomaticallyMovingToHolder = new State(18, "Stop33PickupIsAutomaticallyMovingToHolder", Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, DelayTimer::OFF, Stroboscope::OFF);
State* const  State::Stop45PickupIsUp = new State(19, "Stop45PickupIsUp", Motor::OFF, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, DelayTimer::OFF, Stroboscope::OFF);
State* const  State::Stop45PickupIsDown = new State(20, "Stop45PickupIsDown", Motor::OFF, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, DelayTimer::OFF, Stroboscope::OFF);
State* const  State::Rotate45PickupIsRising = new State(21, "Rotate45PickupIsRising", Motor::Mode45, Microlift::UP, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::OFF);
State* const  State::Rotate45RotateOnHolder = new State(22, "Rotate45RotateOnHolder", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45PickupIsRising = new State(23, "Play45PickupIsRising", Motor::Mode45, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::OFF);
State* const  State::Play45AccelerateDisk = new State(24, "Play45AccelerateDisk", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, DelayTimer::ON, Stroboscope::STROBO_45);
State* const  State::Play45AutoMoveToFirstTrack = new State(25, "Play45AutoMoveToFirstTrack", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45AutoLowerPickup = new State(26, "Play45AutoLowerPickup", Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45Play = new State(27, "Play45Play", Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::GREEN, DelayTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupIsRaising = new State(28, "Play45ManualPickupIsRaising", Motor::Mode45, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupMoveOverDisk = new State(29, "Play45ManualPickupMoveOverDisk", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupMoveOverGap = new State(30, "Play45ManualPickupMoveOverGap", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupMoveAutostop = new State(31, "Play45ManualPickupMoveAutostop", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupFalls = new State(32, "Play45ManualPickupFalls", Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, DelayTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Stop45PickupOnAutostopPause = new State(33, "Stop45PickupOnAutostopPause", Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::RED, DelayTimer::ON, Stroboscope::STROBO_45);
State* const  State::Stop45PickupIsRaising = new State(34, "Stop45PickupIsRaising", Motor::Mode45, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, DelayTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Stop45PickupIsAutomaticallyMovingToHolder = new State(35, "Stop45PickupIsAutomaticallyMovingToHolder", Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, DelayTimer::OFF, Stroboscope::OFF);


State* const  StateProcessor::transitionTable[36][15] = {
	{ NULL,	NULL,	NULL,	NULL,	NULL,	State::InitialPickupIsMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL, },
	{ NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33PickupIsUp,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL, },
	{ NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33PickupIsDown,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop45PickupIsUp,	NULL, },
	{ NULL,	State::Rotate33PickupIsRising,	State::Play33PickupIsRising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop45PickupIsDown,	NULL, },
	{ State::Stop33PickupIsDown,	NULL,	NULL,	NULL,	NULL,	State::Rotate33RotateOnHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Rotate45PickupIsRising,	NULL, },
	{ State::Stop33PickupIsUp,	NULL,	State::Play33AutoMoveToFirstTrack,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play33ManualPickupMoveOverGap,	NULL,	NULL,	NULL,	State::Rotate45RotateOnHolder,	NULL, },
	{ State::Stop33PickupIsDown,	NULL,	NULL,	NULL,	NULL,	State::Play33AccelerateDisk,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45PickupIsRising,	NULL, },
	{ State::Stop33PickupIsUp,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45AccelerateDisk,	State::Play33AutoMoveToFirstTrack, },
	{ State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play33AutoLowerPickup,	NULL,	NULL,	State::Play45AutoMoveToFirstTrack,	NULL, },
	{ State::Stop33PickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play33Play,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45AutoLowerPickup,	NULL, },
	{ State::Stop33PickupIsRaising,	NULL,	NULL,	State::Play33ManualPickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33PickupOnAutostopPause,	NULL,	State::Play45Play,	NULL, },
	{ State::Stop33PickupIsRaising,	NULL,	NULL,	NULL,	State::Play33ManualPickupFalls,	State::Play33ManualPickupMoveOverDisk,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45ManualPickupIsRaising,	NULL, },
	{ State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	State::Play33ManualPickupFalls,	NULL,	NULL,	NULL,	NULL,	State::Play33ManualPickupMoveOverGap,	NULL,	State::Play33ManualPickupMoveAutostop,	NULL,	State::Play45ManualPickupMoveOverDisk,	NULL, },
	{ State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Rotate33RotateOnHolder,	NULL,	State::Play33ManualPickupMoveOverDisk,	NULL,	NULL,	State::Play45ManualPickupMoveOverGap,	NULL, },
	{ State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play33ManualPickupMoveOverDisk,	NULL,	NULL,	State::Play45ManualPickupMoveAutostop,	NULL, },
	{ State::Stop33PickupIsRaising,	NULL,	NULL,	State::Play33ManualPickupIsRaising,	NULL,	NULL,	NULL,	State::Play33Play,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45ManualPickupFalls,	NULL, },
	{ State::Stop33PickupIsRaising,	NULL,	NULL,	State::Play33ManualPickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop45PickupOnAutostopPause,	State::Stop33PickupIsRaising, },
	{ NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop45PickupIsRaising,	NULL, },
	{ NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33PickupIsUp,	NULL,	NULL,	NULL,	NULL,	State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL, },
	{ NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop45PickupIsDown,	NULL,	NULL,	NULL,	NULL,	State::Stop33PickupIsUp,	NULL,	NULL, },
	{ NULL,	State::Rotate45PickupIsRising,	State::Play45PickupIsRising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33PickupIsDown,	NULL,	NULL, },
	{ State::Stop45PickupIsDown,	NULL,	NULL,	NULL,	NULL,	State::Rotate45RotateOnHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Rotate33PickupIsRising,	NULL,	NULL, },
	{ State::Stop45PickupIsUp,	NULL,	State::Play45AutoMoveToFirstTrack,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45ManualPickupMoveOverGap,	NULL,	NULL,	State::Rotate33RotateOnHolder,	NULL,	NULL, },
	{ State::Stop45PickupIsDown,	NULL,	NULL,	NULL,	NULL,	State::Play45AccelerateDisk,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play33PickupIsRising,	NULL,	NULL, },
	{ State::Stop45PickupIsUp,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play33AccelerateDisk,	NULL,	State::Play45AutoMoveToFirstTrack, },
	{ State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45AutoLowerPickup,	NULL,	State::Play33AutoMoveToFirstTrack,	NULL,	NULL, },
	{ State::Stop45PickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45Play,	NULL,	NULL,	NULL,	NULL,	State::Play33AutoLowerPickup,	NULL,	NULL, },
	{ State::Stop45PickupIsRaising,	NULL,	NULL,	State::Play45ManualPickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop45PickupOnAutostopPause,	State::Play33Play,	NULL,	NULL, },
	{ State::Stop45PickupIsRaising,	NULL,	NULL,	NULL,	State::Play45ManualPickupFalls,	State::Play45ManualPickupMoveOverDisk,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play33ManualPickupIsRaising,	NULL,	NULL, },
	{ State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	State::Play45ManualPickupFalls,	NULL,	NULL,	NULL,	NULL,	State::Play45ManualPickupMoveOverGap,	NULL,	State::Play45ManualPickupMoveAutostop,	State::Play33ManualPickupMoveOverDisk,	NULL,	NULL, },
	{ State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Rotate45RotateOnHolder,	NULL,	State::Play45ManualPickupMoveOverDisk,	NULL,	State::Play33ManualPickupMoveOverGap,	NULL,	NULL, },
	{ State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Play45ManualPickupMoveOverDisk,	NULL,	State::Play33ManualPickupMoveAutostop,	NULL,	NULL, },
	{ State::Stop45PickupIsRaising,	NULL,	NULL,	State::Play45ManualPickupIsRaising,	NULL,	NULL,	NULL,	State::Play45Play,	NULL,	NULL,	NULL,	NULL,	State::Play33ManualPickupFalls,	NULL,	NULL, },
	{ State::Stop45PickupIsRaising,	NULL,	NULL,	State::Play45ManualPickupIsRaising,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33PickupOnAutostopPause,	NULL,	State::Stop45PickupIsRaising, },
	{ NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop45PickupIsAutomaticallyMovingToHolder,	NULL,	NULL,	NULL,	NULL,	NULL,	NULL,	State::Stop33PickupIsRaising,	NULL,	NULL, },
};



//assign listeners on state changes
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
SensorsState SensorsState::sensorsState;
#endif
