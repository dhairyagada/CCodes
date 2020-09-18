#include "Counter.h"
#include "ErrorHandler.h"

#ifndef MULTIDIGITCOUNTER_H_
#define MULTIDIGITCOUNTER_H_

// Struct
typedef struct
{
	unsigned int numberOfDigits;
	unsigned int counterType;		//Modulo Value
	counter_t *counters;	//Array of Modulo Counters

} multiDigitCounter_t;

//Initialize All Counters
errorCode_t initializeMultiDigitCounter(multiDigitCounter_t *const me,
		int numberOfDigits, int counterType);

//Increment Counter Value
void incrementMultiDigitCounter(multiDigitCounter_t *const me);

//Print
void printMultiDigitCounter(multiDigitCounter_t *const me);
#endif /* MULTIDIGITCOUNTER_H_ */
