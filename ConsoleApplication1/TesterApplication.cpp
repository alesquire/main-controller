// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ArduinoStub.h"
#include "..\Main_Controller\StateProcessor.h"
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
#include "..\Main_Controller\StateProcessor.cpp"
#include "..\Main_Controller\DebugFunctions.h"
#include "..\Main_Controller\DebugFunctions.cpp"

#include "ArduinoInputPinSource.h"


void processEvent(Events _event)
{
	StateProcessor::stateProcessor.processEvent(_event);
	debug("________________________________________\n");
}

void init()
{
	StateProcessor::stateProcessor.init();
	
	//emulate that microlidt sensor all are in tonearm up position
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_UPPER_SENSOR, HIGH);
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_MICROLIFT_LOWER_SENSOR, HIGH);
	onMicroliftSensorEvent(); //tonearm is up
	onHolderSensorFallingEvent();//tonearm is on holder
}

void automaticPlaybackTest()
{
	processEvent(Events::TonearmLevelUp);
	processEvent(Events::TonearmPositionHolder);
	processEvent(Events::PlayButtonPress);
	processEvent(Events::TonearmPositionOverDisk);
	processEvent(Events::TonearmLevelDown);
	processEvent(Events::TonearmPositionOnAutostop);
	processEvent(Events::AutostopTimerEvent);
	processEvent(Events::TonearmLevelUp);
	processEvent(Events::TonearmPositionHolder);
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

int main()
{
	init();
	//joystickMoveTest();
	return 0;
}

