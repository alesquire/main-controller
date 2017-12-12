/*
 Name:		Main_Controller.ino
 Created:	27.11.2017 0:43:47
 Author:	Al
*/


#include "StateProcessor.h"

/*
Main documentation
_____________________________________________________
Entire solution consists of three class levels, each aggregates/manages underlying level
Unit states. 
	Turntable itself is divided onto several almost independent units - Motor, Tonearm, Microlift etc. Every unit has associated Arduino input and output pins 
	that should be managed dyring turntable work cycle. Unit class encapsulates pin management logiñ for unit. 
	Unit has set of states - states of all pins. (For example when Play button is lit). Every such state is represented by Unit state class instance- static constant
	delivered together with class. 
	Unit classes are polyumorofhic and have two specific methods 
	- init. To ititialize pins (pinMode) - static method
	- apply. To set particular pin values that correspond to current unit state. 
	The following classes sre unit states:
	- Motor
	- TonearmState
	- DiskLed
	- Relays
	- SpeedButtons
	- TonearmButtons
	- TonearmState
	- Microlift
	- AutostopTimer
	
Global State
	Is represented by class State. Class aggregates particular instances of unit states into set of turntable global state. For example state when turntable is playing a record.
	Tohearm should be down, antiscate force should be applied, play button should lit etc. 
	See States and Events.xls for detailed list of states.

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

