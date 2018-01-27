// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <sstream>
#include "ArduinoStub.h"
#include "..\Main_Controller\StateProcessor.h"
#include "..\Main_Controller\PinInitFunctions.cpp"
#include "..\Main_Controller\DueTimer.cpp"
#include "..\Main_Controller\EventFunctions.cpp"
#include "..\Main_Controller\DiskLed.cpp"
#include "..\Main_Controller\Microlift.cpp"
#include "..\Main_Controller\Motor.cpp"
#include "..\Main_Controller\Relays.cpp"
#include "..\Main_Controller\SpeedButtons.cpp"
#include "..\Main_Controller\TonearmButtons.cpp"
#include "..\Main_Controller\TonearmState.cpp"
#include "..\Main_Controller\AutostopTimer.cpp"
#include "..\Main_Controller\Stroboscope.cpp"
#include "..\Main_Controller\JoystickUpDownState.cpp"
#include "..\Main_Controller\State.cpp"
#include "..\Main_Controller\Initializers.cpp"
#include "..\Main_Controller\StateProcessor.cpp"
#include "..\Main_Controller\DebugFunctions.h"
#include "..\Main_Controller\DebugFunctions.cpp"
#include "..\Main_Controller\SensorsState.cpp"

#include "ArduinoInputPinSource.h"
template <typename Source, class Target>
void assert(Source* source, Target* target)
{
	if(source!=target)
		throw std::runtime_error("error");
}

void processEvent(Events _event)
{
	StateProcessor::stateProcessor.processEvent(_event);
	debug("________________________________________\n");
}

void processPinValue(int pin, int newValue)
{
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(pin, newValue);
	SensorsState::sensorsState.compare();
}


void assertState(State * targetState)
{
	State* currentState = StateProcessor::stateProcessor.getCurrentState();
	if (currentState==NULL)
		throw std::runtime_error("Current state is null");
	if (currentState != targetState)
	{
		std::stringstream response;
		response << "Target state =" << targetState->getStateName() << ", current state =" << currentState->getStateName();
		std::string errorMessage = response.str();
		throw std::runtime_error(errorMessage);
	}

}


void init()
{
	//tonearm is down
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_UPPER_SENSOR, LOW);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_LOWER_SENSOR, LOW);

	//and tonarm is not on a holder
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, HIGH);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_TONEARM_HOLDER, HIGH);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_AUTOSTOP, HIGH);

	//all buttons are not pressed
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_PLAY_BUTTON, LOW);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_ROTATE_BUTTON, LOW);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_STOP_BUTTON, LOW);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_33_BUTTON, LOW);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_45_BUTTON, LOW);

	SensorsState::sensorsState.init();
}

void automaticPlaybackTest()
{
	onPlayButtonPress();
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_TONEARM_HOLDER, HIGH);
	onHolderSensorRisingEvent();

	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, LOW);
	onFirstTrackSensorFallingEvent();
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, HIGH);
	onFirstTrackSensorRisingEvent();

	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_UPPER_SENSOR, LOW);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_LOWER_SENSOR, LOW);
	onMicroliftSensorEvent();

	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_AUTOSTOP, LOW);
	onAutostopSensorFallingEvent();

	onAutostopTimerEvent();

	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_UPPER_SENSOR, HIGH);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_LOWER_SENSOR, HIGH);
	onMicroliftSensorEvent();

	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_AUTOSTOP, HIGH);
	onAutostopSensorRisingEvent();

	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, LOW);
	onFirstTrackSensorFallingEvent();
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, HIGH);
	onFirstTrackSensorRisingEvent();

	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_TONEARM_HOLDER, LOW);
	onHolderSensorFallingEvent();//tonearm is on holder


}

void joystickMoveTest()
{
	processEvent(Events::RotateButtonPress);
	processEvent(Events::TonearmPositionOverGap);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_JOYSTICK_LEFT_RIGHT, 10);
	TonearmDirection direction = StateProcessor::stateProcessor.getCurrentState()->getTonearmState()->getDirection();
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_JOYSTICK_LEFT_RIGHT, 3000);
	direction = StateProcessor::stateProcessor.getCurrentState()->getTonearmState()->getDirection();
	StateProcessor::stateProcessor.onTimer();

}

void sensorsStateTest()
{
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_UPPER_SENSOR, HIGH);
	SensorsState::sensorsState.compare();
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_UPPER_SENSOR, LOW);
	SensorsState::sensorsState.compare();
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_UPPER_SENSOR, HIGH);
	SensorsState::sensorsState.compare();
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_UPPER_SENSOR, LOW);
	SensorsState::sensorsState.compare();

}
void tonearmPositionTest()
{
	//initial state - tonearm is over disk
	SensorsState::sensorsState.compare();
	//assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OUTSIDE_HOLDER);
	//move to holder
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_TONEARM_HOLDER, LOW);
	SensorsState::sensorsState.compare();
	//assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::ON_HOLDER);
	//move to center
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_TONEARM_HOLDER, HIGH);
	SensorsState::sensorsState.compare();
	//assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OVER_GAP);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, LOW);
	SensorsState::sensorsState.compare();
	//assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OVER_GAP);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, HIGH);
	SensorsState::sensorsState.compare();
	//assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OVER_DISK);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_AUTOSTOP, LOW);
	SensorsState::sensorsState.compare();
	//assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::AUTOSTOP);
	//move to holder
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_AUTOSTOP, HIGH);
	SensorsState::sensorsState.compare();
	//assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OVER_DISK);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, LOW);
	SensorsState::sensorsState.compare();
	//assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OVER_GAP);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, HIGH);
	SensorsState::sensorsState.compare();
	//assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OVER_GAP);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_TONEARM_HOLDER, LOW);
	SensorsState::sensorsState.compare();
	//assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::AUTOSTOP);
}

void goToInitialPosition()
{

	assert(StateProcessor::stateProcessor.getCurrentState(), State::InitialPickupIsRaisingOutsideHolder);

	//tonearm is up
	processPinValue(PIN_MICROLIFT_UPPER_SENSOR, HIGH);
	processPinValue(PIN_MICROLIFT_LOWER_SENSOR, HIGH);
	assertState(State::InitialPickupIsMovingToHolder);

	//tonearm is on holder
	processPinValue(PIN_TONEARM_HOLDER, LOW);
	assertState(State::Stop33FullStop);

	//play button is pressed (and unpressed)
	processPinValue(PIN_PLAY_BUTTON, HIGH);
	assertState(State::Play33AutoMoveToFirstTrack);
	processPinValue(PIN_PLAY_BUTTON, LOW);
	assertState(State::Play33AutoMoveToFirstTrack);

	//go to first track
	processPinValue(PIN_TONEARM_HOLDER, HIGH);
	processPinValue(PIN_FIRST_TRACK, LOW);
	assertState(State::Play33AutoMoveToFirstTrack);
	processPinValue(PIN_FIRST_TRACK, HIGH);
	assertState(State::Play33AutoLowerPickup);
	processPinValue(PIN_MICROLIFT_UPPER_SENSOR, LOW);
	processPinValue(PIN_MICROLIFT_LOWER_SENSOR, LOW);
	assertState(State::Play33Play);

	//play
	processPinValue(PIN_MICROLIFT_UPPER_SENSOR, LOW);
	processPinValue(PIN_MICROLIFT_LOWER_SENSOR, LOW);
	assertState(State::Play33Play);
	processPinValue(PIN_AUTOSTOP, LOW);
	assertState(State::Stop33PickupOnAutostopPause);

	//return to first track
	onAutostopTimerEvent();
	assertState(State::Stop33PickupIsRaising);
	processPinValue(PIN_MICROLIFT_UPPER_SENSOR, HIGH);
	processPinValue(PIN_MICROLIFT_LOWER_SENSOR, HIGH);
	assertState(State::Stop33PickupIsAutomaticallyMovingToHolder);
	processPinValue(PIN_AUTOSTOP, HIGH);
	assertState(State::Stop33PickupIsAutomaticallyMovingToHolder);
	processPinValue(PIN_FIRST_TRACK, HIGH);
	assertState(State::Stop33PickupIsAutomaticallyMovingToHolder);
	processPinValue(PIN_FIRST_TRACK, LOW);
	assertState(State::Stop33PickupIsAutomaticallyMovingToHolder);
	processPinValue(PIN_FIRST_TRACK, HIGH);
	assertState(State::Stop33PickupIsAutomaticallyMovingToHolder);
	processPinValue(PIN_TONEARM_HOLDER, LOW);
	assertState(State::Stop33FullStop);

}

int main()
{
	init();
	StateProcessor::stateProcessor.init();
	goToInitialPosition();

	//tonearmPositionTest();
	//sensorsStateTest();
	automaticPlaybackTest();
	//joystickMoveTest();
	return 0;
}

