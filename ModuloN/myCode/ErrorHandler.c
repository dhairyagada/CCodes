#include "ErrorHandler.h"

void handleErrorCode(errorCode_t code)
{

	switch (code)
	{
	SUCCESS: break;

	COUNTER_NULL: printf("Counter Null");
	break;

	MAXCOUNT_ERROR: printf("Max Count Cannot Be Zero");
	break;

	}
}
