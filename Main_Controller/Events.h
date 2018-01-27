// Events.h

#ifndef _EVENTS_h
#define _EVENTS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "ArduinoHeader.h"
#endif

enum Events 
{
	StopButtonPress,
	RotateButtonPress,
	PlayButtonPress,
	UpJoystickPress,
	DownJoystickPress,
	TonearmLevelUp,
	TonearmLevelMiddle,
	TonearmLevelDown,
	TonearmPositionHolder,
	TonearmPositionOverGap,
	TonearmPositionOverDisk,
	TonearmPositionOnAutostop,
	Speed33ButtonPress,
	Speed45ButtonPress,
	DelayTimerEvent //event is used to wait before autostop and to accelerate disk
};

static  char *  eventNames[15] = {
	"StopButtonPress",
	"RotateButtonPress",
	"PlayButtonPress",
	"UpJoystickPress",
	"DownJoystickPress",
	"TonearmLevelUp",
	"TonearmLevelMiddle",
	"TonearmLevelDown",
	"TonearmPositionHolder",
	"TonearmPositionOverGap",
	"TonearmPositionOverDisk",
	"TonearmPositionOnAutostop",
	"Speed33ButtonPress",
	"Speed45ButtonPress",
	"DelayTimerEvent" 
};


#endif

