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

bool inFunction = false;
void onRotateButtonPress()
{
	if (inFunction)
		return;
	inFunction = true;
	//noInterrupts();
	digitalWrite(13, !digitalRead(13));
	//Serial.print("void onRotateButtonPress()");
	StateProcessor::stateProcessor.processEvent(Events::RotateButtonPress);
	//interrupts();
	inFunction = false;

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

	if (upperSensorValue&&lowerSensorValue)
	{
		StateProcessor::stateProcessor.processEvent(Events::TonearmLevelUp);
	}
	else if (!upperSensorValue && !lowerSensorValue)
	{
		StateProcessor::stateProcessor.processEvent(Events::TonearmLevelDown);
	}
	else if (!upperSensorValue && lowerSensorValue)
	{
		StateProcessor::stateProcessor.processEvent(Events::TonearmLevelMiddle);
	}
}

void onHolderSensorRisingEvent()
{
	StateProcessor::stateProcessor.processEvent(Events::TonearmPositionOverGap);
}

void onHolderSensorFallingEvent()
{
	StateProcessor::stateProcessor.processEvent(Events::TonearmPositionHolder);
}

void onFirstTrackSensorRisingEvent()
{
	if(StateProcessor::stateProcessor.getTonearmDirection()==LEFT)
		StateProcessor::stateProcessor.processEvent(Events::TonearmPositionOverDisk);
}

void onFirstTrackSensorFallingEvent()
{
	if (StateProcessor::stateProcessor.getTonearmDirection() == RIGHT)
		StateProcessor::stateProcessor.processEvent(Events::TonearmPositionOverGap);
}

void onAutostopSensorRisingEvent()
{
	StateProcessor::stateProcessor.processEvent(Events::TonearmPositionOverDisk);
}

void onAutostopSensorFallingEvent()
{
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
