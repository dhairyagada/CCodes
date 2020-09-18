

#ifndef ERRORHANDLER_H_
#define ERRORHANDLER_H_

typedef enum
{
	SUCCESS, COUNTER_NULL, MAXCOUNT_ERROR, TYPE_ERROR
} errorCode_t;

//Error Handler
void handleErrorCode(errorCode_t code);
#endif /* ERRORHANDLER_H_ */
