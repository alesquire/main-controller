// DebugFunctions.h

#ifndef _DEBUGFUNCTIONS_h
#define _DEBUGFUNCTIONS_h
#define DEBUG

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
#endif

void debug(char* value);

void debug(int value);


#endif

