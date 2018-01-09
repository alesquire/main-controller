// 
// 
// 


#include "State.h"
State::State(int _orderNumber,
	char* _stateName,
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
	stateName = _stateName;
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
	initStates();
}

void State::apply()
{
	Serial.print("motorState=");
	Serial.print((int)motorState);
	Serial.print('\n');

	Serial.print("tonearmState=");
	Serial.print((int)tonearmState);
	Serial.print('\n');

	Serial.print("tonearmButtons=");
	Serial.print((int)tonearmButtons);
	Serial.print('\n');

	Serial.print("speedButtons=");
	Serial.print((int)speedButtons);
	Serial.print('\n');	
	
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

char * State::getStateName()
{
	return stateName;
}

TonearmState* State::getTonearmState()
{
	return tonearmState;
}

// initialize states table
void State::initStates()
{
/*	State* const  InitialPickupIsRaisingOnHolder = new State(0, "InitialPickupIsRaisingOnHolder", Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, AutostopTimer::OFF, Stroboscope::OFF);
	State* const  InitialPickupIsRaisingOutsideHolder = new State(1, "InitialPickupIsRaisingOutsideHolder", Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, AutostopTimer::OFF, Stroboscope::OFF);
	State* const  InitialPickupIsMovingToHolder = new State(2, "InitialPickupIsMovingToHolder", Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, AutostopTimer::OFF, Stroboscope::OFF);
	State* const  Stop33FullStop = new State(3, "Stop33FullStop", Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF, Stroboscope::OFF);
	State* const  Rotate33 = new State(4, "Rotate33", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
	State* const  Play33AutoMoveToFirstTrack = new State(5, "Play33AutoMoveToFirstTrack", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
	State* const  Play33AutoLowerPickup = new State(6, "Play33AutoLowerPickup", Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
	State* const  Play33Play = new State(7, "Play33Play", Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::GREEN, AutostopTimer::OFF, Stroboscope::STROBO_33);
	State* const  Play33ManualPickupIsRaising = new State(8, "Play33ManualPickupIsRaising", Motor::Mode33, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
	State* const  Play33ManualPickupMoveOverDisk = new State(9, "Play33ManualPickupMoveOverDisk", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
	State* const  Play33ManualPickupMoveOverGap = new State(10, "Play33ManualPickupMoveOverGap", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
	State* const  Play33ManualPickupMoveAutostop = new State(11, "Play33ManualPickupMoveAutostop", Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
	State* const  Play33ManualPickupFalls = new State(12, "Play33ManualPickupFalls", Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_33);
	State* const  Stop33PickupOnAutostopPause = new State(13, "Stop33PickupOnAutostopPause", Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::ON, Stroboscope::STROBO_33);
	State* const  Stop33PickupIsRaising = new State(14, "Stop33PickupIsRaising", Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF, Stroboscope::STROBO_33);
	State* const  Stop33PickupIsAutomaticallyMovingToHolder = new State(15, "Stop33PickupIsAutomaticallyMovingToHolder", Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF, Stroboscope::STROBO_33);
	State* const  Stop45FullStop = new State(16, "Stop45FullStop", Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF, Stroboscope::OFF);
	State* const  Rotate45 = new State(17, "Rotate45", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
	State* const  Play45AutoMoveToFirstTrack = new State(18, "Play45AutoMoveToFirstTrack", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
	State* const  Play45AutoLowerPickup = new State(19, "Play45AutoLowerPickup", Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
	State* const  Play45Play = new State(20, "Play45Play", Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::GREEN, AutostopTimer::OFF, Stroboscope::STROBO_45);
	State* const  Play45ManualPickupIsRaising = new State(21, "Play45ManualPickupIsRaising", Motor::Mode45, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
	State* const  Play45ManualPickupMoveOverDisk = new State(22, "Play45ManualPickupMoveOverDisk", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
	State* const  Play45ManualPickupMoveOverGap = new State(23, "Play45ManualPickupMoveOverGap", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
	State* const  Play45ManualPickupMoveAutostop = new State(24, "Play45ManualPickupMoveAutostop", Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
	State* const  Play45ManualPickupFalls = new State(25, "Play45ManualPickupFalls", Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF, Stroboscope::STROBO_45);
	State* const  Stop45PickupOnAutostopPause = new State(26, "Stop45PickupOnAutostopPause", Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::ON, Stroboscope::STROBO_45);
	State* const  Stop45PickupIsRaising = new State(27, "Stop45PickupIsRaising", Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF, Stroboscope::STROBO_45);
	State* const  Stop45PickupIsAutomaticallyMovingToHolder = new State(28, "Stop45PickupIsAutomaticallyMovingToHolder", Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF, Stroboscope::STROBO_45);
	*/
};
//todo- refactor- attempt to fix initialization sequence problem

