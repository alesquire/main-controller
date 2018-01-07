#include "EventFunctions.h"
#include "StateProcessor.h"

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
    Serial.println("33");
	StateProcessor::stateProcessor.processEvent(Events::Speed33ButtonPress);
}

void onSpeed45ButtonPress()
{
    Serial.println("45");
    StateProcessor::stateProcessor.processEvent(Events::Speed45ButtonPress);
}

void onMicroliftSensorEvent()
{
	bool upperSensorValue = digitalRead(PIN_MICROLIFT_UPPER_SENSOR);
	bool lowerSensorValue = digitalRead(PIN_MICROLIFT_LOWER_SENSOR);

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
  Serial.println(1);
	StateProcessor::stateProcessor.processEvent(Events::TonearmPositionOverGap);
}

void onHolderSensorFallingEvent()
{
  Serial.println(2);
  StateProcessor::stateProcessor.processEvent(Events::TonearmPositionHolder);
}

void onFirstTrackSensorRisingEvent()
{
  Serial.println(3);
  if(StateProcessor::stateProcessor.getTonearmDirection()==LEFT)
		StateProcessor::stateProcessor.processEvent(Events::TonearmPositionOverDisk);
}

void onFirstTrackSensorFallingEvent()
{
  Serial.println(4);
  if (StateProcessor::stateProcessor.getTonearmDirection() == RIGHT)
		StateProcessor::stateProcessor.processEvent(Events::TonearmPositionOverGap);
}

void onAutostopSensorRisingEvent()
{
  Serial.println(5);
  StateProcessor::stateProcessor.processEvent(Events::TonearmPositionOverDisk);
}

void onAutostopSensorFallingEvent()
{
  Serial.println(6);
  StateProcessor::stateProcessor.processEvent(Events::TonearmPositionOnAutostop);
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
