// StateProcessor.h

#ifndef _STATEPROCESSOR_h
#define _STATEPROCESSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

#include "Events.h"
#include "State.h"
#include "JoystickUpDownState.h"
#include "DebugFunctions.h"

#define TONEARM_ANALOG_PARAMS_READOUT_INTERVAL 1E5 // (0.1 s)

class StateProcessor
{
private:
	State* currentState;

	State* getNextState(Events _event);

	JoystickUpDownState joystickUpDownState;

	static State* const  transitionTable[36][15];

	void applyNextState(State *state);

	StateProcessor() {};

public:
	
	State* getCurrentState();

	void processEvent(Events _event);

	TonearmDirection getTonearmDirection();

	void init();

	/*
		joystick doesn't produce events because it is an analog input. To process joystick position change we should periodically check state and:
		- for up-down axis- check if joysticlk is up and down, and if it is so- produce event. But only once per position.
		- for left-right action we should call current TonearmState class instance to read joystick position input and write DAC pin output
		onTimer method itself should be caled externally

	*/
	void onTimer();

	//moves tonearm and other controls to initial state- tonearm on holder, microlift in HOLD state
	void initTonearmState();


	static StateProcessor stateProcessor;
};

#endif

