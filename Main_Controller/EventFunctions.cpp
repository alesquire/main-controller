#include "EventFunctions.h"
#include "StateProcessor.h"

void onDelayTimerEvent() 
{
	StateProcessor::stateProcessor.processEvent(Events::DelayTimerEvent);
}

void onTonearmTimerEvent()
{
	StateProcessor::stateProcessor.onTimer();
}

void onStopButtonPress()
{
	debug(StateProcessor::stateProcessor.getCurrentState()->getStateName());
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
		debug("Microlift = UP");
		StateProcessor::stateProcessor.processEvent(Events::TonearmLevelUp);
	}
	else if (!upperSensorValue && !lowerSensorValue)
	{
    debug("Microlift = Down");
		StateProcessor::stateProcessor.processEvent(Events::TonearmLevelDown);
	}
	else if (!upperSensorValue && lowerSensorValue)
	{
    debug("Microlift =Middle");
		StateProcessor::stateProcessor.processEvent(Events::TonearmLevelMiddle);
	}
}

void onHolderSensorRisingEvent()
{
  debug("onHolderSensorRisingEvent()");
	StateProcessor::stateProcessor.processEvent(Events::TonearmPositionOverGap);
}

void onHolderSensorFallingEvent()
{
  debug("onHolderSensorFallingEvent()");
  StateProcessor::stateProcessor.processEvent(Events::TonearmPositionHolder);
}

void onFirstTrackSensorRisingEvent()
{
  debug("onFirstTrackSensorRisingEvent()");
  if(StateProcessor::stateProcessor.getTonearmDirection()==LEFT)
		StateProcessor::stateProcessor.processEvent(Events::TonearmPositionOverDisk);
}

void onFirstTrackSensorFallingEvent()
{
  debug("onFirstTrackSensorFallingEvent()");
  if (StateProcessor::stateProcessor.getTonearmDirection() == RIGHT)
		StateProcessor::stateProcessor.processEvent(Events::TonearmPositionOverGap);
}

void onAutostopSensorRisingEvent()
{
  debug("onAutostopSensorRisingEvent()");
  StateProcessor::stateProcessor.processEvent(Events::TonearmPositionOverDisk);
}

void onAutostopSensorFallingEvent()
{
  debug("onAutostopSensorFallingEvent()");
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
