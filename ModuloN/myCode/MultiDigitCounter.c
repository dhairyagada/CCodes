#include <stdio.h>
#include "MultiDigitCounter.h"
#include "ErrorHandler.h"
#include "Counter.h"
#include <stdlib.h>

errorCode_t initializeMultiDigitCounter(multiDigitCounter_t *const me,
		int numberOfDigits, int counterType)
{

	if (me == NULL)
	{
		return COUNTER_NULL;
	}
	else if (numberOfDigits == 0 || counterType == 0)
	{
		return MAXCOUNT_ERROR;
	}
	else
	{

		//Assign Space to Counters
		counter_t *counters;
		counters = (counter_t*) malloc(numberOfDigits * sizeof(counter_t));

		me->counters = counters;
		me->counterType = counterType;
		me->numberOfDigits = numberOfDigits;

		for (int i = 0; i < numberOfDigits; i++)
		{

			//Initialize ith Counter
			errorCode_t errorCode = initializeCounter(&counters[i],
					counterType);

			//Handle if any error occurs for any iteration
			if (errorCode != SUCCESS)
			{
				printf("Error for Iteration %d", i);
				handleErrorCode(errorCode);
				break;
			}
		}

		return SUCCESS;
	}

}

incrementMultiDigitCounter(multiDigitCounter_t *const me)
{

	for (int i = 0; i < me->numberOfDigits; i++)
	{

		if (incrementCounter(&(me->counters[i])) == NO_OVERFLOW)
			break;

	}

}

void printMultiDigitCounter(multiDigitCounter_t *const me)
{
	for (int i = 0; i < me->numberOfDigits; i++)
	{
		printCounter(&(me->counters[me->numberOfDigits - i - 1]),
				PRINT_CURRENT);

	}
	printf("\n");
}
