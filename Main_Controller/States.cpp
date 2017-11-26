// 
// 
// 


#include "States.h"
States::States(Motor _motorState,
	Microlift _microliftStates,
	Relays _relaysState,
	TonearmState _tonearmState,
	TonearmButtons _tonearmButtons,
	SpeedButtons _speedButtons,
	DiskLed _diskLed,
	AutostopTimer _autostopTimer)
{
	motorState = &_motorState;
	microliftStates= &_microliftStates;
	relaysState = &_relaysState;
	tonearmState = &_tonearmState;
	tonearmButtons = &_tonearmButtons;
	speedButtons = &_speedButtons;
	diskLed = &_diskLed;
	autostopTimer = &_autostopTimer;
}


// initialize states table
const States  States::Initial = States(Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::OFF, SpeedButtons::OFF, DiskLed::OFF, AutostopTimer::OFF);
const States  States::Stop33FullStop = States(Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF);
const States  States::Rotate33 = States(Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play33AutoMoveToFirstTrack = States(Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play33AutoLowerPickUP = States(Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play33Play = States(Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::GREEN, AutostopTimer::OFF);
const States  States::Play33ManualPickUPIsRaising = States(Motor::Mode33, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play33ManualPickUPMoveOverDisk = States(Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play33ManualPickUPMoveOverGap = States(Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play33ManualPickUPMoveAutostop = States(Motor::Mode33, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play33ManualPickUPFalls = States(Motor::Mode33, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Stop33PickUPOnAutostopPause = States(Motor::Mode33, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::ON);
const States  States::Stop33PickUPIsRaising = States(Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF);
const States  States::Stop33PickUPIsAutomaticallyMovingToHolder = States(Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED33, DiskLed::RED, AutostopTimer::OFF);
const States  States::Stop45FullStop = States(Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF);
const States  States::Rotate45 = States(Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::HOLDER, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play45AutoMoveToFirstTrack = States(Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_LEFT, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play45AutoLowerPickUP = States(Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play45Play = States(Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::GREEN, AutostopTimer::OFF);
const States  States::Play45ManualPickUPIsRaising = States(Motor::Mode45, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play45ManualPickUPMoveOverDisk = States(Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play45ManualPickUPMoveOverGap = States(Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::MOVE, TonearmButtons::ROTATE, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play45ManualPickUPMoveAutostop = States(Motor::Mode45, Microlift::HOLD, Relays::MOVE, TonearmState::AUTOSTOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Play45ManualPickUPFalls = States(Motor::Mode45, Microlift::DOWN, Relays::MOVE, TonearmState::STOP, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::BLUE, AutostopTimer::OFF);
const States  States::Stop45PickUPOnAutostopPause = States(Motor::Mode45, Microlift::DOWN, Relays::PLAY, TonearmState::PLAY, TonearmButtons::PLAY, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::ON);
const States  States::Stop45PickUPIsRaising = States(Motor::OFF, Microlift::UP, Relays::MOVE, TonearmState::STOP, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF);
const States  States::Stop45PickUPIsAutomaticallyMovingToHolder = States(Motor::OFF, Microlift::HOLD, Relays::MOVE, TonearmState::FULL_RIGHT, TonearmButtons::STOP, SpeedButtons::LED45, DiskLed::RED, AutostopTimer::OFF);



