#ifndef _EVENTFUNCTIONS_H_
#define _EVENTFUNCTIONS_H_
#if defined(ARDUINO) && ARDUINO >= 100
  #include "ArduinoHeader.h"
#endif

void onDelayTimerEvent();

/*
	function that is called on regular basis to read tonerarm controls (joystick, autorsop and damper regulators
*/
void onTonearmTimerEvent();

void onStopButtonPress();

void onRotateButtonPress();

void onPlayButtonPress();

void onSpeed33ButtonPress();

void onSpeed45ButtonPress();
/*
	one listener funiction for all microlift-based events- to be called for both sensors (PIN_TONEARM_UPPER_SENSOR, PIN_TONEARM_LOWER_SENSOR)
*/
void onMicroliftSensorEvent();

void onHolderSensorRisingEvent();

void onHolderSensorFallingEvent();

void onFirstTrackSensorRisingEvent();

void onFirstTrackSensorFallingEvent();

void onAutostopSensorRisingEvent();

void onAutostopSensorFallingEvent();

void onStroboscope();

void turnOffStroboLed();


#endif // !_EVENTFUNCTIONS_H_

