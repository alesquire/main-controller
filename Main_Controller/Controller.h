#pragma once

#include "SensorsState.h"
#include "DebugFunctions.h"
#include "Stroboscope.h"
#include "StateProcessor.h"
#include "SensorsState.h"

class Controller
{
public:
	void init()
	{
		//init all button and other sensors
		SensorsState::sensorsState.init();

		//initial state
		StateProcessor::stateProcessor.init();
	}

	void process()
	{
		//process button clicks and changes from previous cycle (replaces interrupts with checks)
		SensorsState::sensorsState.compare();
		//process actoins related to tonearm
		StateProcessor::stateProcessor.scanTonearmState();
		//process actions to be performed by time (delays)
		DelayedActionTimer::delayedTimer.tick();
	}
	static Controller controller;
};

