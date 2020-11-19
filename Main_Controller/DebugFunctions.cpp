// 
// 
// 

#include "DebugFunctions.h"

#ifndef _DebugFunctions_cpp
#define _DebugFunctions_cpp

/*
	there is a bug somewhere in preprocessor directives. in some cases - this file is ignored, so it was included explicitly
	as #include "DebugFunctions.cpp"

*/
void debug(char* value)
{
#if defined (DEBUG)
	#if defined(ARDUINO)
		//noInterrupts(); // Disable interrupts
		Serial.print(value);
		//interrupts();    // Enable interrupts
	#else
		printf(value);
	#endif // (ARDUINO)
#endif //(DEBUG)
}

void debug(int value)
{
#if defined (DEBUG)
	#if defined(ARDUINO)
		//noInterrupts(); // Disable interrupts
		Serial.print(value);
		//interrupts();    // Enable interrupts
	#else
		printf("%i", value);
	#endif // (ARDUINO)
#endif //(DEBUG)
}

#endif
