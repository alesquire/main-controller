/*
 Name:		Main_Controller.ino
 Created:	27.11.2017 0:43:47
 Author:	Al
*/


#include "SensorsState.h"
#include "DebugFunctions.h"
#include "Stroboscope.h"
#include "StateProcessor.h"
#include "SensorsState.h"


void setup() 
{
//#if defined (DEBUG)	
	Serial.begin(115200);//debug 
//#endif
	debug("start\n") ;//debug
	//initialize pinMode, read current value and setup listeners
	SensorsState::sensorsState.init();

	StateProcessor::stateProcessor.init();
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	debug("loop\n");
	SensorsState::sensorsState.compare();
	StateProcessor::stateProcessor.scanTonearmState();
	delay(200);
}
