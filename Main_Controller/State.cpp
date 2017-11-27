// 
// 
// 


#include "State.h"
State::State(int _orderNumber,
	Motor _motorState,
	Microlift _microliftStates,
	Relays _relaysState,
	TonearmState _tonearmState,
	TonearmButtons _tonearmButtons,
	SpeedButtons _speedButtons,
	DiskLed _diskLed,
	AutostopTimer _autostopTimer)
{
	stateOrderNumber = _orderNumber;
	motorState = &_motorState;
	microliftStates= &_microliftStates;
	relaysState = &_relaysState;
	tonearmState = &_tonearmState;
	tonearmButtons = &_tonearmButtons;
	speedButtons = &_speedButtons;
	diskLed = &_diskLed;
	autostopTimer = &_autostopTimer;
}

void State::init()
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

void State::apply()
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

int State::getStateOrderNumber()
{
	return stateOrderNumber;
}

// initialize states table
const State  State::Initial = State(0, Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, AutostopTimer::OFF);
const State  State::Stop33FullStop = State(1, Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF);
const State  State::Rotate33 = State(2, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33AutoMoveToFirstTrack = State(3, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33AutoLowerPickup = State(4, Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33Play = State(5, Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::GREEN, AutostopTimer::OFF);
const State  State::Play33ManualPickupIsRaising = State(6, Motor::Mode33, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33ManualPickupMoveOverDisk = State(7, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33ManualPickupMoveOverGap = State(8, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33ManualPickupMoveAutostop = State(9, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33ManualPickupFalls = State(10, Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Stop33PickupOnAutostopPause = State(11, Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::ON);
const State  State::Stop33PickupIsRaising = State(12, Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF);
const State  State::Stop33PickupIsAutomaticallyMovingToHolder = State(13, Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF);
const State  State::Stop45FullStop = State(14, Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF);
const State  State::Rotate45 = State(15, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45AutoMoveToFirstTrack = State(16, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45AutoLowerPickup = State(17, Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45Play = State(18, Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::GREEN, AutostopTimer::OFF);
const State  State::Play45ManualPickupIsRaising = State(19, Motor::Mode45, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45ManualPickupMoveOverDisk = State(20, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45ManualPickupMoveOverGap = State(21, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45ManualPickupMoveAutostop = State(22, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45ManualPickupFalls = State(23, Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Stop45PickupOnAutostopPause = State(24, Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::ON);
const State  State::Stop45PickupIsRaising = State(25, Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF);
const State  State::Stop45PickupIsAutomaticallyMovingToHolder = State(26, Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF);


