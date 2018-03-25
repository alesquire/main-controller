// 
// 
// 

#include "TonearmState.h"
#include "DebugFunctions.h"

int TonearmState::transformAntiscateToOutput(int input)
{
	//todo: implement transformation table
	debug("Antiscate control value=");
	debug(input);
  debug("\n");
	return IDLE_TONEARM_OUTPUT_VALUE+input/50;
}

int TonearmState::transformJoystickToOutput(int input)
{
	//todo: implement transformation table
	int value =IDLE_TONEARM_OUTPUT_VALUE+input/10;
  if(value>returnFullRightValue()) return returnFullRightValue();
  if(value<returnFullLeftValue()) return returnFullLeftValue();
	return value;
}

/*
	returns antiscate value read from input pin normalized value - in range 0..analog_resolution
	where X is analog resolution (ANALOG_RESOLUTIONS) set globally in PinConstants
*/
int TonearmState::readNormalizedAntiscateValue()
{
	return analogRead(PIN_ANTISCATE);
}


/*
	returns jostick value read from input pin normalized value - in range -X/2..0..+X/2
	value < 0 coresponde to move left, >0 - to move right
	where X is analog resolution (ANALOG_RESOLUTIONS) set globally in PinConstants
*/
int TonearmState::readNormalizedJoystickValue()
{
	return analogRead(PIN_JOYSTICK_LEFT_RIGHT)- JOYSTICK_LEFT_RIGHT_ZERO_VALUE;
}

/*
	return voltage value theat corresponds to steady tonarm state
*/
int TonearmState::getZeroOutputValue()
{
	return IDLE_TONEARM_OUTPUT_VALUE;//todo- calculate value for damper and antiscate
}

/*
	returns value to be applied to tonearm during automatic move left
*/
int TonearmState::returnFullLeftValue()
{
	return IDLE_TONEARM_OUTPUT_VALUE-100;
}

/*
	returns value to be applied to tonearm during automatic move right
*/
int TonearmState::returnFullRightValue()
{
	return IDLE_TONEARM_OUTPUT_VALUE+100;//ANALOG_RESOLUTION-1;
}

void TonearmState::init()
{
	initOutput(PIN_TONEARM_VOLTAGE_OUTPUT);
	initOutput(PIN_TONEARM_REFERENCE_OUTPUT);
	initInput(PIN_ANTISCATE);
	initInput(PIN_DAMPER);
	initInput(PIN_JOYSTICK_LEFT_RIGHT);
	initInput(PIN_JOYSTICK_UP_DOWN);
	initInput(PIN_TONEARM_HOLDER);
	initInput(PIN_FIRST_TRACK);
	initInput(PIN_AUTOSTOP);
	analogReadResolution(12);
  analogWriteResolution(12);
	analogWrite(PIN_TONEARM_REFERENCE_OUTPUT,tonearmReferenceOutput);
}

bool TonearmState::isTonearmOnHolder()
{
	return !digitalRead(PIN_TONEARM_HOLDER); //when tonearm is on holder- optical path of optosensor is shaded and output level is LOW
}

void TonearmState::apply()
{
	int outputValue = defineValue();
	analogWrite(PIN_TONEARM_VOLTAGE_OUTPUT, outputValue);
}

//-----------------------------------------------------------------------------------
/*
	Tonearm is not moving despite on joystick state
*/

int StopMode::defineValue()
{
	return getZeroOutputValue();
};

TonearmDirection StopMode::getDirection()
{
	return IDLE;
};

char* StopMode::getTonearmStateName() 
{
	return "StopMode";
};

//-----------------------------------------------------------------------------------
/*
	Poickup is on disk- antiscate force is applied. joystick is ignored
*/
int Play::defineValue()
{
	return transformAntiscateToOutput(readNormalizedAntiscateValue());
};

TonearmDirection Play::getDirection()
{
	return ANTISCATE;
};

char* Play::getTonearmStateName()
{
	return "Play";
};

//-----------------------------------------------------------------------------------
/*
	tonearm can be moved to any direction
*/
int Move::defineValue()
{
  int value =transformJoystickToOutput(readNormalizedJoystickValue());
  //debug
  Serial.print("t=");
  Serial.print(value);
  Serial.print('\n'); 
  //debug   
	return value;
};

char* Move::getTonearmStateName()
{
	return "Move";
};

//-----------------------------------------------------------------------------------

int Autostop::defineValue()
{
	int value = readNormalizedJoystickValue();
	if (value < 0) // try to move left
		return getZeroOutputValue();
	else
		return transformJoystickToOutput(value);
};

char* Autostop::getTonearmStateName()
{
	return "Autostop";
};

//-----------------------------------------------------------------------------------

int Holder::defineValue()
{
	int value = readNormalizedJoystickValue();
	if (value > 0)  // try to move right
		return getZeroOutputValue();
	else
		return transformJoystickToOutput(value);
};

char* Holder::getTonearmStateName()
{
	return "Holder";
};

//-----------------------------------------------------------------------------------

int FullLeft::defineValue()
{
  return returnFullLeftValue();
};

char* FullLeft::getTonearmStateName()
{
	return "FullLeft";
};


//-----------------------------------------------------------------------------------

int FullRight::defineValue()
{
	return returnFullRightValue();
};

char* FullRight::getTonearmStateName()
{
	return "FullRight";
};

