#include <stdio.h>

#define metreToFeetConverter	0.3048;
#define metreToMileConverter 	1852;

float getInput()
{

	float inp;
	printf("Please Enter Values in Meters:");
	scanf("%f", &inp);

	return inp;
}

float getValidInput()
{
	float inp = 0.0;

	do
	{
		// Validate
		if (inp < 0)
		{
			printf("Only Positive Values Allowed!\n");
		}
		//Get Input
		inp = getInput();
	} while (inp < 0);

	return inp;
}

float convertToMiles(float metricVal)
{
	float convertedVal;

	// Convert to Miles
	convertedVal = (float) metricVal / metreToMileConverter;
	return convertedVal;

}
;
float convertToFeet(float metricVal)
{
	float convertedVal;

	// Convert to Feet
	convertedVal = (float) metricVal / metreToFeetConverter;
	return convertedVal;

}
;

int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);

	printf("Metric to English converter\n");

	//Get Valid Input
	float inp = getValidInput();

	//Conversion
	float valInMiles = convertToMiles(inp);
	float valInFeets = convertToFeet(inp);

	// Print Output
	printf("%f m = %f mile = %f ft", inp, valInMiles, valInFeets);
	return 0;

}
