// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ArduinoStub.h"
#include "..\Main_Controller\StateProcessor.h"
#include "..\Main_Controller\DiskLed.cpp"
#include "..\Main_Controller\Microlift.cpp"
#include "..\Main_Controller\Motor.cpp"
#include "..\Main_Controller\Relays.cpp"
#include "..\Main_Controller\SpeedButtons.cpp"
#include "..\Main_Controller\TonearmButtons.cpp"
#include "..\Main_Controller\TonearmState.cpp"
#include "..\Main_Controller\AutostopTimer.cpp"
#include "..\Main_Controller\JoystickUpDownState.cpp"
#include "..\Main_Controller\State.cpp"
#include "..\Main_Controller\StateProcessor.cpp"
#include "..\Main_Controller\DueTimer.cpp"

#include "ArduinoInputPinSource.h"

StateProcessor processor;
void processEvent(Events _event)
{
	printf("Processing event %i",_event);
	printf("\n");
	processor.processEvent(_event);
	printf("________________________________________\n");
}

void init()
{
	processor.init();
	processEvent(Events::TonearmLevelUp);//when turntable is powered on- microlift goes up until tonearm is up
	processEvent(Events::TonearmPositionHolder); // and moved to holder
}

void automaticPlaybackTest()
{
	processEvent(Events::TonearmLevelUp);
	processEvent(Events::TonearmPositionHolder);
	processEvent(Events::PlayButtonPress);
	processEvent(Events::TonearmPositionOverFirstTrack);
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
	TonearmDirection direction = processor.getCurrentState()->getTonearmState()->getDirection();
	ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_JOYSTICK_LEFT_RIGHT, 3000);
	direction = processor.getCurrentState()->getTonearmState()->getDirection();
	processor.onTimer();

}

int main()
{
	init();
	joystickMoveTest();
	return 0;
}

