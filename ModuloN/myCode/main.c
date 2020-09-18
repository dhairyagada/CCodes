#include <stdio.h>
#include "Counter.h"
#include "MultiDigitCounter.h"
#include "ErrorHandler.h"

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);

	//Initialize
	multiDigitCounter_t counter;
	errorCode_t code = initializeMultiDigitCounter(&counter, 0, 16);

	handleErrorCode(code);
	for (int i = 0; i < 18; i++)
	{
		printMultiDigitCounter(&counter);
		incrementMultiDigitCounter(&counter);

	}

}
