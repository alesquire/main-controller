// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ArduinoStub.h"
#include "..\Main_Controller\Events.h"
#include "..\Main_Controller\DiskLed.h"
#include "..\Main_Controller\DiskLed.cpp"


int main()
{
	Events e = Events::RotateButtonPress;
	DiskLed l = DiskLed::BLUE;
	l.apply();
	return 0;
}

