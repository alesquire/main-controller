// 
// 
// 


#include "State.h"
State::State(int _orderNumber,
	Motor* _motorState,
	Microlift* _microliftStates,
	Relays* _relaysState,
	TonearmState* _tonearmState,
	TonearmButtons* _tonearmButtons,
	SpeedButtons* _speedButtons,
	DiskLed* _diskLed,
	AutostopTimer* _autostopTimer,
	Stroboscope*  _stroboscope)
{
	stateOrderNumber = _orderNumber;
	motorState =_motorState;
	microliftStates= _microliftStates;
	relaysState = _relaysState;
	tonearmState = _tonearmState;
	tonearmButtons = _tonearmButtons;
	speedButtons = _speedButtons;
	diskLed = _diskLed;
	autostopTimer = _autostopTimer;
	stroboscope = _stroboscope;
}

void State::init()
{
	Motor::init();
	Microlift::init();
	Relays::init();
	TonearmState::init();
	TonearmButtons::init();
	SpeedButtons::init();
	DiskLed::init();
	AutostopTimer::init();
	Stroboscope::init();
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
	stroboscope->apply();
}

int State::getStateOrderNumber()
{
	return stateOrderNumber;
}

TonearmState* State::getTonearmState()
{
	return tonearmState;
}

// initialize states table
State* const  State::InitialPickupIsRaisingOnHolder = new State(0, Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, AutostopTimer::OFF, Stroboscope::OFF);
State* const  State::InitialPickupIsRaisingOutsideHolder = new State(1, Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, AutostopTimer::OFF, Stroboscope::OFF);
State* const  State::InitialPickupIsMovingToHolder = new State(2, Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, AutostopTimer::OFF, Stroboscope::OFF);
State* const  State::Stop33FullStop = new State(3, Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF, Stroboscope::OFF);
State* const  State::Rotate33 = new State(4, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33AutoMoveToFirstTrack = new State(5, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33AutoLowerPickup = new State(6, Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33Play = new State(7, Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::GREEN, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupIsRaising = new State(8, Motor::Mode33, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupMoveOverDisk = new State(9, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupMoveOverGap = new State(10, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupMoveAutostop = new State(11, Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Play33ManualPickupFalls = new State(12, Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Stop33PickupOnAutostopPause = new State(13, Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::ON, Stroboscope::STROBO_33);
State* const  State::Stop33PickupIsRaising = new State(14, Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Stop33PickupIsAutomaticallyMovingToHolder = new State(15, Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF, Stroboscope::STROBO_33);
State* const  State::Stop45FullStop = new State(16, Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF, Stroboscope::OFF);
State* const  State::Rotate45 = new State(17, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45AutoMoveToFirstTrack = new State(18, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45AutoLowerPickup = new State(19, Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45Play = new State(20, Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::GREEN, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupIsRaising = new State(21, Motor::Mode45, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupMoveOverDisk = new State(22, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupMoveOverGap = new State(23, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupMoveAutostop = new State(24, Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Play45ManualPickupFalls = new State(25, Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Stop45PickupOnAutostopPause = new State(26, Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::ON, Stroboscope::STROBO_45);
State* const  State::Stop45PickupIsRaising = new State(27, Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF, Stroboscope::STROBO_45);
State* const  State::Stop45PickupIsAutomaticallyMovingToHolder = new State(28, Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF, Stroboscope::STROBO_45);


