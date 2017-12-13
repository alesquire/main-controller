// 
// 
// 

#include "DebugFunctions.h"

void debug(char* value)
{
#if defined(ARDUINO)
	Serial.print(value);
#else
	printf(value);
#endif // (ARDUINO)
}

void debug(int value)
{
#if defined(ARDUINO)
	Serial.print(value);
#else
	printf("%i", value);
#endif // (ARDUINO)
}