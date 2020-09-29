#include <stdio.h>
#include <string.h>

char* decOneToTeen[] = // pointer array of values from one to nineteen
{
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE",
	"TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"
}; // pointer array of values of ten increments, leaving blanks for 0th and 1st index
char* decTens[] = { "", "", "TWENTY", "THIRTY", "FOURTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY" };

// conversion function
void convertToString(int value, int *stringPtr)
{
	if (value < 20) // simply add from decOneToTeen
	{
		strcat(stringPtr, " ");
		strcat(stringPtr, decOneToTeen[value]);
		return; // avoids other cases below
	}

	if (value < 100) // two digit values >= 20
	{
		strcat(stringPtr, " ");
		strcat(stringPtr, decTens[value / 10]); // add first digit from decTens
		if (value % 10 != 0) // if the second digit isn't 0
			convertToString(value % 10, stringPtr); // recursive call
		return;
	}

	if (value < 1000) // three digit values
	{
		strcat(stringPtr, " ");
		strcat(stringPtr, decOneToTeen[value / 100]); // add first value digit from decOneToTeen
		strcat(stringPtr, " HUNDRED"); // include the word HUNDRED
		if (value % 100 != 0) // if value after first digit isn't 0
			convertToString(value % 100, stringPtr); // recursive call
		return;
	}

	if (value < 1000000) // six digit values
	{
		convertToString(value / 1000, stringPtr); // convert first three digits, similar to three digit value case above
		strcat(stringPtr, " THOUSAND"); // add word THOUSAND
		if (value % 1000 != 0) // if values after first three digits isn't 0
			convertToString(value % 1000, stringPtr); // recursive call
		return;
	}

	// can be expanded to the millions, trillions, etc., and will follow the same structure as above
	// inputs will be limited to the current cases since numbers can be infinitely large and all cases cannot be handled
}

void hw3p5(void)
{
	double value;

	do
	{
		printf("%s", "Input an amount of money greater than or equal to $0.00 (up to 999999.99): "); // no invalid negative amounts
		scanf_s("%lf", &value);
		if (value < 0 || value > 999999.99)
			printf("%s\n", "Invalid input.");
	} while (value <0 || value > 999999.99); // max value of 999999.99; reasoning above in convertToString function
	
	int dollars = value / 1; // remove decimal values
	double cents = value - dollars; // take decimal value

	char textValue[100] = { "" }; // char array for dollars
	int stringPtr = textValue; // pointer to array

	convertToString(dollars, stringPtr); // convert to string method

	printf("In check format: %s and %.0lf/100\n", textValue, cents * 100); // print result

	/*
		sample test cases:
			Input		Output
		1.	10.34		TEN and 34/100
		2.	123.45		ONE HUNDRED TWENTY THREE and 45/100
		3.	0			ZERO and 0/100
		4.	999999.99	NINE HUNDRED NINETY NINE THOUSAND NINE HUNDRED NINETY NINE and 99/100
		5.	1.23		ONE and 23/100
		6.	12534.87	TWELVE THOUSAND FIVE HUNDRED THIRTY FOUR and 87/100
		7.	876543.21	EIGHT HUNDRED SEVENTY SIX THOUSAND FIVE HUNDRED FOURTY THREE and 21/100
		8.	00153.98	ONE HUNDRED FIFTY THREE and 98/100
	*/
}

int main(void)
{
	hw3p5();
	return 0;
}