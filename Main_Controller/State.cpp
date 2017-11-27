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
const State  State::Initial = State(1, Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, AutostopTimer::OFF);
const State  State::Stop33FullStop = State(2, Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF);
const State  State::Rotate33 = State(3, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33AutoMoveToFirstTrack = State(4, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33AutoLowerPickUP = State(5, Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33Play = State(6, Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::GREEN, AutostopTimer::OFF);
const State  State::Play33ManualPickUPIsRaising = State(7, Motor::Mode33, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33ManualPickUPMoveOverDisk = State(8, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33ManualPickUPMoveOverGap = State(9, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33ManualPickUPMoveAutostop = State(10, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play33ManualPickUPFalls = State(11, Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Stop33PickUPOnAutostopPause = State(12, Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::ON);
const State  State::Stop33PickUPIsRaising = State(13, Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF);
const State  State::Stop33PickUPIsAutomaticallyMovingToHolder = State(14, Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF);
const State  State::Stop45FullStop = State(15, Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF);
const State  State::Rotate45 = State(16, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45AutoMoveToFirstTrack = State(17, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45AutoLowerPickUP = State(18, Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45Play = State(19, Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::GREEN, AutostopTimer::OFF);
const State  State::Play45ManualPickUPIsRaising = State(20, Motor::Mode45, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45ManualPickUPMoveOverDisk = State(21, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45ManualPickUPMoveOverGap = State(22, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45ManualPickUPMoveAutostop = State(23, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Play45ManualPickUPFalls = State(24, Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const State  State::Stop45PickUPOnAutostopPause = State(25, Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::ON);
const State  State::Stop45PickUPIsRaising = State(26, Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF);
const State  State::Stop45PickUPIsAutomaticallyMovingToHolder = State(27, Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF);


