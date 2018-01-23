#include "EventFunctions.h"
#include "StateProcessor.h"
#include "TonearmPositionStateMachine.h"

void onAutostopTimerEvent() 
{
	StateProcessor::stateProcessor.processEvent(Events::AutostopTimerEvent);
}

void onTonearmTimerEvent()
{
	StateProcessor::stateProcessor.onTimer();
}

void onStopButtonPress()
{
	StateProcessor::stateProcessor.processEvent(Events::StopButtonPress);
}

void onRotateButtonPress()
{
	StateProcessor::stateProcessor.processEvent(Events::RotateButtonPress);
}

void onPlayButtonPress()
{
	StateProcessor::stateProcessor.processEvent(Events::PlayButtonPress);
}

void onSpeed33ButtonPress()
{
	StateProcessor::stateProcessor.processEvent(Events::Speed33ButtonPress);
}

void onSpeed45ButtonPress()
{
    StateProcessor::stateProcessor.processEvent(Events::Speed45ButtonPress);
}

void onMicroliftSensorEvent()
{
	bool upperSensorValue = digitalRead(PIN_MICROLIFT_UPPER_SENSOR);
	bool lowerSensorValue = digitalRead(PIN_MICROLIFT_LOWER_SENSOR);

  Serial.print(upperSensorValue);



  Serial.print(lowerSensorValue);

  
	if (upperSensorValue&&lowerSensorValue)
	{
		Serial.println("U");
		StateProcessor::stateProcessor.processEvent(Events::TonearmLevelUp);
	}
	else if (!upperSensorValue && !lowerSensorValue)
	{
    Serial.println("D");
		StateProcessor::stateProcessor.processEvent(Events::TonearmLevelDown);
	}
	else if (!upperSensorValue && lowerSensorValue)
	{
    Serial.println("M");
		StateProcessor::stateProcessor.processEvent(Events::TonearmLevelMiddle);
	}
}

void onHolderSensorRisingEvent()
{
  Serial.println("onHolderSensorRisingEvent()");
  TonearmPositionStateMachine::tonearmPositionStateMachine.processEvent(TonearmPositionEvents::HOLDER_RISE);
}

void onHolderSensorFallingEvent()
{
  Serial.println("onHolderSensorFallingEvent()");
  TonearmPositionStateMachine::tonearmPositionStateMachine.processEvent(TonearmPositionEvents::AUTOSTOP_FALL);
}

void onFirstTrackSensorRisingEvent()
{
  Serial.println("onFirstTrackSensorRisingEvent()");
  TonearmPositionStateMachine::tonearmPositionStateMachine.processEvent(TonearmPositionEvents::FIRST_TRACK_RISE);
}

void onFirstTrackSensorFallingEvent()
{
  Serial.println("onFirstTrackSensorFallingEvent()");
  TonearmPositionStateMachine::tonearmPositionStateMachine.processEvent(TonearmPositionEvents::FIRST_TRACK_FALL);
}

void onAutostopSensorRisingEvent()
{
  Serial.println("onAutostopSensorRisingEvent()");
  TonearmPositionStateMachine::tonearmPositionStateMachine.processEvent(TonearmPositionEvents::AUTOSTOP_RISE);
}

void onAutostopSensorFallingEvent()
{
  Serial.println("onAutostopSensorFallingEvent()");
  TonearmPositionStateMachine::tonearmPositionStateMachine.processEvent(TonearmPositionEvents::AUTOSTOP_FALL);
}

void onStroboscope()
{
	digitalWrite(PIN_STROBOSCOPE, HIGH);
	Timer3.executeOneTime(STROBO_PULSE_DURATION);
}

void turnOffStroboLed()
{
	digitalWrite(PIN_STROBOSCOPE, LOW);
}
