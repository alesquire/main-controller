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
//#include "PinInitFunctions.cpp"
/*

*/





void setup() 
{
//#if defined (DEBUG)	
	Serial.begin(115200);//debug 
//#endif
	debug("start\n") ;//debug
	StateProcessor::stateProcessor.init();
	/*
	attachInterrupt(digitalPinToInterrupt(PIN_STOP_BUTTON), onStopButtonPress, FALLING);
	attachInterrupt(digitalPinToInterrupt(PIN_ROTATE_BUTTON), onRotateButtonPress, CHANGE);
	attachInterrupt(digitalPinToInterrupt(PIN_PLAY_BUTTON), onPlayButtonPress, FALLING);

	attachInterrupt(digitalPinToInterrupt(PIN_MICROLIFT_UPPER_SENSOR), onMicroliftSensorEvent, CHANGE);
	attachInterrupt(digitalPinToInterrupt(PIN_MICROLIFT_LOWER_SENSOR), onMicroliftSensorEvent, CHANGE);

	attachInterrupt(digitalPinToInterrupt(PIN_33_BUTTON), onSpeed33ButtonPress, RISING);
	attachInterrupt(digitalPinToInterrupt(PIN_45_BUTTON), onSpeed45ButtonPress, RISING);
	*/
	//debug - uncomment when all sensors are configured
	//StateProcessor::stateProcessor.initTonearmState();

}

// the loop function runs over and over again until power down or reset
void loop() 
{
	SensorsState::getInstance().compare();
	delay(100);
  
  
  /*
  Microlift::UP->apply();
  delay(5000);
  Microlift::HOLD->apply();
  delay(5000);
  Microlift::DOWN->apply();
  delay(5000);
  digitalWrite(13,HIGH);
  DiskLed::RED->apply();
  TonearmButtons::STOP->apply();
  delay(1000);  
  digitalWrite(13,LOW);
  DiskLed::GREEN->apply();
  TonearmButtons::PLAY->apply(); 
  delay(1000);
  DiskLed::BLUE->apply();
  TonearmButtons::ROTATE->apply(); 
  delay(1000);
  //Serial.println(digitalRead(PIN_ROTATE_BUTTON));
  //delay(100);*/

}

