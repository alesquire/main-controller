// 
// 
// 

#include "DebugFunctions.h"

#ifndef _DebugFunctions_cpp
#define _DebugFunctions_cpp
#define DEBUG

/*
	there is a bug somewhere in preprocessor directives. in some cases - this file is ignored, so it was included explicitly
	as #include "DebugFunctions.cpp"

*/
void debug(char* value)
{
#if defined (DEBUG)
	#if defined(ARDUINO)
		Serial.print(value);
		Serial.print("\n");
#else
		printf(value);
		printf("\n");
#endif // (ARDUINO)
#endif //(DEBUG)
}

void debug(int value)
{
#if defined (DEBUG)
	#if defined(ARDUINO)
		Serial.print(value);
		Serial.print("\n");
#else
		printf("%i", value);
		printf("\n");
#endif // (ARDUINO)
#endif //(DEBUG)
}

#endif
