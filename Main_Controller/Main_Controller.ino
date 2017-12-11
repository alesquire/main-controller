/*
 Name:		Main_Controller.ino
 Created:	27.11.2017 0:43:47
 Author:	Al
*/


#include "StateProcessor.h"

/*
Main documentation
_____________________________________________________

Timers:
	* Timer0 is used for autostop delayed function call. Autostop is ititiated not immediately after sensor is activated, but after interval for two reasons:
		- to simplify sensor position adjustment- sensor detects autostop somewhere near autostop position,
		- to play recordings in autostop trask (St.Peppers Lonly Hearts Club Band
	* Timer1 is used to periodicaly check tonearm analog controls that can't produce events (joystick, damper and antiscate regulators) and update solenoid output voltage. 

Buttons and switches
	
	* Buttons have HIGH voltage in board input when is not presed and LOW when buttn is pressed. 
	Main event for buttons is presion, so- interrupt FALLING

	* Microlift sensors produce HIGH level when tonearm is up and LOW when it is down

*/

StateProcessor processor;


void setup() 
{
	
	
	attachInterrupt(digitalPinToInterrupt(PIN_STOP_BUTTON), onStopButtonPress, FALLING);
	attachInterrupt(digitalPinToInterrupt(PIN_ROTATE_BUTTON), onRotateButtonPress, FALLING);
	attachInterrupt(digitalPinToInterrupt(PIN_PLAY_BUTTON), onPlayButtonPress, FALLING);

	attachInterrupt(digitalPinToInterrupt(PIN_MICROLIFT_UPPER_SENSOR), onMicroliftSensorEvent, CHANGE);
	attachInterrupt(digitalPinToInterrupt(PIN_MICROLIFT_LOWER_SENSOR), onMicroliftSensorEvent, CHANGE);


	processor.init();
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}

