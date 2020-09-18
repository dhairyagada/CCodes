#include <stdio.h>
#include "Counter.h"
#include "ErrorHandler.h"
//Sets the current count to zero and specifies maximum count value
errorCode_t initializeCounter(counter_t *const me, unsigned int maxCount)
{

	if (me == NULL)
	{
		return COUNTER_NULL;
	}
	else if (maxCount == 0)
	{
		return MAXCOUNT_ERROR;
	}
	else
	{

		me->maxCount = maxCount;
		me->currentCount = 0;
		return SUCCESS;
	}

}

//Increments the current count by 1, and in case of overflow makes it zero
overflowStatus incrementCounter(counter_t *const me)
{

	me->currentCount = (me->currentCount + 1) % (me->maxCount);

	if(me->currentCount == 0){
		return OVERFLOW;

	}else{
		return NO_OVERFLOW;
	}
}

//Print the current value
void printCounter(counter_t const *const me, printOption printOption)
{

	if (printOption == PRINT_CURRENT)
	{
		if(me->currentCount <10){
			printf("%d", me->currentCount);
		}else{
			printf("%c",(char)me->currentCount-10+65);
		}

	}
	else if (printOption == PRINT_MAX)
	{
		printf("Max Value : %d\n", me->maxCount);
	}

}
