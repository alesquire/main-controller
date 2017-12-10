#include "EventFunctions.h"
#include "StateProcessor.h"

void onAutostopTimerEvent() 
{
	StateProcessor::stateProcessor.processEvent(Events::AutostopTimerEvent);
}
