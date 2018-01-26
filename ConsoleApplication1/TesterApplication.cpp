// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
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

void init()
{
	//tonearm is down
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_UPPER_SENSOR, LOW);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_LOWER_SENSOR, LOW);

	//and tonarm is not on a holder
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, HIGH);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_TONEARM_HOLDER, HIGH);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_AUTOSTOP, HIGH);

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
	SensorsState::getInstance().compare();
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_UPPER_SENSOR, LOW);
	SensorsState::getInstance().compare();
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_UPPER_SENSOR, HIGH);
	SensorsState::getInstance().compare();
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_UPPER_SENSOR, LOW);
	SensorsState::getInstance().compare();

}
void tonearmPositionTest()
{
	//initial state - tonearm is over disk
	SensorsState::getInstance().compare();
	assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OUTSIDE_HOLDER);
	//move to holder
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_TONEARM_HOLDER, LOW);
	SensorsState::sensorsState.compare();
	assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::ON_HOLDER);
	//move to center
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_TONEARM_HOLDER, HIGH);
	SensorsState::sensorsState.compare();
	assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OVER_GAP);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, LOW);
	SensorsState::getInstance().compare();
	assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OVER_GAP);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, HIGH);
	SensorsState::getInstance().compare();
	assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OVER_DISK);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_AUTOSTOP, LOW);
	SensorsState::getInstance().compare();
	assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::AUTOSTOP);
	//move to holder
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_AUTOSTOP, HIGH);
	SensorsState::getInstance().compare();
	assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OVER_DISK);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, LOW);
	SensorsState::getInstance().compare();
	assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OVER_GAP);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_FIRST_TRACK, HIGH);
	SensorsState::getInstance().compare();
	assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::OVER_GAP);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_TONEARM_HOLDER, LOW);
	SensorsState::getInstance().compare();
	assert(TonearmPositionStateMachine::tonearmPositionStateMachine.getCurrentState(), TonearmPositionState::AUTOSTOP);
}


int main()
{
	init();
	StateProcessor::stateProcessor.init();
	TonearmPositionStateMachine::tonearmPositionStateMachine.init();

	tonearmPositionTest();
	//sensorsStateTest();
	//automaticPlaybackTest();
	//joystickMoveTest();
	return 0;
}

