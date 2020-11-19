/*
 Name:		Main_Controller.ino
 Created:	27.11.2017 0:43:47
 Author:	Al
*/


#include "Controller.h"


void setup() 
{
//#if defined (DEBUG)	
	Serial.begin(115200);//debug 
//#endif
	debug("start\n");//debug
	Controller::controller.init();
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	//debug("loop\n");
	
	Controller::controller.process();
	delay(50);
}
