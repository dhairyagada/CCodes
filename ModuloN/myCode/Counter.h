#include "ErrorHandler.h"
#ifndef COUNTER_H_
#define COUNTER_H_

//Counter Structure
typedef struct
{
	unsigned int maxCount;
	unsigned int currentCount;

} counter_t;

//Print Option
typedef enum{
	PRINT_CURRENT,
	PRINT_MAX
} printOption;

typedef enum {
	OVERFLOW,
	NO_OVERFLOW
} overflowStatus;

//Sets the current count to zero and specifies maximum count value
errorCode_t initializeCounter(counter_t *const me, unsigned int maxCount);

//Increments the current count by 1, and in case of overflow makes it zero
overflowStatus incrementCounter(counter_t *const me);

//Print the current value
void printCounter(counter_t const *const me,printOption printOption);

#endif /* COUNTER_H_ */
