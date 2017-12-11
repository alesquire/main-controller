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