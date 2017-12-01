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

int main()
{
	StateProcessor processor;
	processor.init();
	processor.processEvent(Events::TonearmLevelUp);
	processor.processEvent(Events::TonearmPositionHolder);
	processor.processEvent(Events::PlayButtonPress);
	processor.processEvent(Events::TonearmPositionOverFirstTrack);
	processor.processEvent(Events::TonearmLevelDown);
	processor.processEvent(Events::TonearmPositionOnAutostop);
	processor.processEvent(Events::AutostopTimerEvent);
	processor.processEvent(Events::TonearmLevelUp);
	processor.processEvent(Events::TonearmPositionHolder);


	return 0;
}

