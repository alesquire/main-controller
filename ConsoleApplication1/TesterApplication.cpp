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
#include "..\Main_Controller\State.cpp"
#include "..\Main_Controller\StateProcessor.cpp"
#include "..\Main_Controller\TonearmButtons.cpp"
#include "..\Main_Controller\TonearmState.cpp"
#include "..\Main_Controller\AutostopTimer.cpp"

int main()
{
	//StateProcessor processor;
	//processor.init();
	State* initialState = &State::Initial;
	initialState->apply();
	//Motor motor = Motor::Mode33;
	//Motor *motorPtr = &motor;
	//motor.apply();
	//motorPtr->apply();
	return 0;
}

