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
#include "ArduinoInputPinSource.h"

StateProcessor processor;

void init()
{
	processor.init();
	processor.processEvent(Events::TonearmLevelUp);//when turntable is powered on- microlift goes up until tonearm is up
	processor.processEvent(Events::TonearmPositionHolder); // and moved to holder
}

void automaticPlaybackTest()
{
	processor.processEvent(Events::TonearmLevelUp);
	processor.processEvent(Events::TonearmPositionHolder);
	processor.processEvent(Events::PlayButtonPress);
	processor.processEvent(Events::TonearmPositionOverFirstTrack);
	processor.processEvent(Events::TonearmLevelDown);
	processor.processEvent(Events::TonearmPositionOnAutostop);
	processor.processEvent(Events::AutostopTimerEvent);
	processor.processEvent(Events::TonearmLevelUp);
	processor.processEvent(Events::TonearmPositionHolder);
}

void joystickMoveTest()
{
	processor.processEvent(Events::RotateButtonPress);
	//ArduinoInputPinSource::arduinoInputPinSource.setPinValue(PIN_JOYSTICK_LEFT_RIGHT, 10);
	processor.onTimer();

}

int main()
{
	init();
	joystickMoveTest();
	return 0;
}

