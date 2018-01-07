// TonearmState.h

#ifndef _TONEARMSTATE_h
#define _TONEARMSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

#include "PinConstants.h"
#include "Appliable.h"
#include "EventFunctions.h"

#define JOYSTICK_LEFT_RIGHT_ZERO_VALUE 2063
#define IDLE_TONEARM_OUTPUT_VALUE 2600 //value to be applied to DAC1 to have 0V on tonearm solenoid

//enum shows direction- where tonearm is moving now
enum TonearmDirection
{
	LEFT,
	RIGHT,
	IDLE,  //is returned when tonearm is not in PLAY mode and when it is nod moving
	ANTISCATE
};

/*
  tonearm movement logic requires to handle in a different way cases when tonearm position sensors are rising and falling. 
  Arduino doesn't allow to apply multiple interrupts on one pin on different events, so we should emulate interrupt by periodical reading of sensors value and comparing with previous state
  TonearmSensorsState reads current state,  compare it with previous one and produce events if some state was canged 
 */
class TonearmSensorsState
{
private:
  bool holderSensor;
  bool firstTrackSensor;
  bool autostopSensor;
  enum Change
  {
    RISES,
    FALLS,
    UNCHANGED
  };

  Change compare(bool oldValue, bool newValue)
  {
    if(oldValue==false and newValue==true)
      return RISES;
    if(oldValue==true and newValue==false)
      return FALLS;
    return UNCHANGED;   
  };
  
public:

  TonearmSensorsState()
  {
    holderSensor=digitalRead(PIN_TONEARM_HOLDER);
    firstTrackSensor=digitalRead(PIN_FIRST_TRACK);
    autostopSensor=digitalRead(PIN_AUTOSTOP);
  }

  TonearmSensorsState(TonearmSensorsState &tonearmSensorsState)
  {
    holderSensor=tonearmSensorsState.holderSensor;
    firstTrackSensor=tonearmSensorsState.firstTrackSensor;
    autostopSensor=tonearmSensorsState.autostopSensor; 
  }
  
  TonearmSensorsState & operator = (const TonearmSensorsState & tonearmSensorsState)
  {
    holderSensor=tonearmSensorsState.holderSensor;
    firstTrackSensor=tonearmSensorsState.firstTrackSensor;
    autostopSensor=tonearmSensorsState.autostopSensor; 

  }

  void printState()
  {
    Serial.print("holderSensor=");
    Serial.println(holderSensor);
    Serial.print("firstTrackSensor=");
    Serial.println(firstTrackSensor);
    Serial.print("autostopSensor=");
    Serial.println(autostopSensor);
    
  }


  void compare(TonearmSensorsState &newTonearmSensorsState)
  {
    switch (compare(holderSensor,newTonearmSensorsState.holderSensor))
    {
      case RISES:
      {
        onHolderSensorRisingEvent();
        break;  
      }
      case FALLS:
      {
        onHolderSensorFallingEvent();
        break;  
      }
    }
    switch (compare(firstTrackSensor,newTonearmSensorsState.firstTrackSensor))
    {
      case RISES:
      {
        onFirstTrackSensorRisingEvent();
        break;  
      }
      case FALLS:
      {
        onFirstTrackSensorFallingEvent();
        break;  
      }
    }
    switch (compare(autostopSensor,newTonearmSensorsState.autostopSensor))
    {
      case RISES:
      {
        onAutostopSensorRisingEvent();
        break;  
      }
      case FALLS:
      {
        onAutostopSensorFallingEvent();
        break;  
      }
    }
  }
  
};


/*
	Class applies voltage to solenoid according to mode. Two global modes defines - which input will drive solenoid voltage ( and force):
	1. Play mode- when tonearm is on disk. Antiscate voltage is applied
	2. Move mode- voltage is driven by joystick

  Tonearm is idle whenPIN_TONEARM_VOLTAGE_OUTPUT (DAC1) = 2600 and is moving right when value is >2600
  Joystick values:
  full right = 4095
  zero left-right postion (joystick is idle)- 2063 (JOYSTICK_LEFT_RIGHT_ZERO_VALUE)
  full left =0
  
  full up=313
  zero up-down position 2048
  full down = 4095
*/
class TonearmState : public Appliable
{
protected:

	int transformAntiscateToOutput(int input);

	int transformJoystickToOutput(int input);

	/*
		returns antiscate value read from input pin normalized value - in range -X/2..0..+X/2
		where X is analog resolution (ANALOG_RESOLUTIONS) set globally in PinConstants
	*/
	int readNormalizedAntiscateValue();


	/*
		returns jostick value read from input pin normalized value - in range -X/2..0..+X/2
		value < 0 coresponde to move left, >0 - to move right
		where X is analog resolution (ANALOG_RESOLUTIONS) set globally in PinConstants
	*/
	int readNormalizedJoystickValue();

	/*
		return voltage value theat corresponds to steady tonearm state
	*/
	int getZeroOutputValue();

	/*
		returns value to be applied to tonearm during automatic move left
	*/
	int returnFullLeftValue();

	/*
		returns value to be applied to tonearm during automatic move right
	*/
	int returnFullRightValue();

	/*
		to be defined in subclasses the correspond particular tonearm states
	*/
	virtual int defineValue() { return 0; };

	TonearmDirection getDirectionByOutputValue(int _value)
	{
		if (_value > getZeroOutputValue())
			return TonearmDirection::RIGHT;
		if (_value < getZeroOutputValue())
			return TonearmDirection::LEFT;
		return TonearmDirection::IDLE;
	}
 


	static const int tonearmReferenceOutput = 2000; //constant value to be applied on PIN_TONEARM_REFERENCE_OUTPUT (DAC0) that produces 1.61V. 

  static TonearmSensorsState state;
public:
	static void init();
 
	virtual void apply();
	
	virtual char* getTonearmStateName() 
	{
		return "Illegal state- parent class is used instead of child class";
	};

	virtual TonearmDirection getDirection()
	{
		int outputValue = defineValue();
		return getDirectionByOutputValue(outputValue);
	}

  //reads position sensors and produces events (calls functions) if position was canged
  void readSensors();

	/*
		method is used for initialization to define - is in necessary to move tonearm back to holder or not
	*/
	static bool isTonearmOnHolder();

	static TonearmState* const PLAY;			//tonearm is on plate, antiscate force is applied. joystick is ignored
	static TonearmState* const MOVE;			//tonearm can be moved to any side by joystick
	static TonearmState* const AUTOSTOP;		// tonearm is on autostop and can move only rightwards
	static TonearmState* const HOLDER;		// tonearm is on holder and can move only leftwards
	static TonearmState* const STOP;			//tonearm is steady in horyzontal plane			   
	static TonearmState* const FULL_RIGHT;	//automatic move right on full speed
	static TonearmState* const FULL_LEFT;	//automatic move left on full speed
};


class StopMode : public TonearmState
{
protected:
	virtual int defineValue();
	virtual TonearmDirection getDirection();
public:
	virtual char* getTonearmStateName();
};


//-----------------------------------------------------------------------------------
/*
Poickup is on disk- antiscate force is applied. joystick is ignored
*/
class Play : public TonearmState
{
protected:
	virtual int defineValue();
	virtual TonearmDirection getDirection();
public:
	virtual char* getTonearmStateName();
};


//-----------------------------------------------------------------------------------
/*
tonearm can be moved to any direction
*/
class Move : public TonearmState
{
protected:
	virtual int defineValue();
public:
	virtual char* getTonearmStateName();
};


//-----------------------------------------------------------------------------------

class Autostop : public TonearmState
{
protected:
	virtual int defineValue();
public:
	virtual char* getTonearmStateName();
};


//-----------------------------------------------------------------------------------

class Holder : public TonearmState
{
protected:
	virtual int defineValue();
public:
	virtual char* getTonearmStateName();
};


//-----------------------------------------------------------------------------------

class FullLeft : public TonearmState
{
protected:
	virtual int defineValue();
public:
	virtual char* getTonearmStateName();
};


//-----------------------------------------------------------------------------------

class FullRight : public TonearmState
{
protected:
	virtual int defineValue();
public:
	virtual char* getTonearmStateName();
};

#endif

