// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ArduinoStub.h"
#include "..\Main_Controller\StateProcessor.h"
#include "..\Main_Controller\DiskLed.cpp"
#include "..\Main_Controller\Microlift.cpp"


int main()
{
	Events e = Events::RotateButtonPress;
	DiskLed l = DiskLed::BLUE;
	l.apply();
	return 0;
}

