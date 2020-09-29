#include <stdio.h>

int main(void)
{
	printf("%s\n", "Problem 4: Printing a diamond shape with asterisks:");

	unsigned int numStars = 1;	// number of asterisks to print on a given line; starts as 1
	for (int i = 1; i <= 9; i++)	// loops 9 times for 9 rows
	{
		unsigned int spacing = (9 - numStars) / 2;	// number of spacing on both sides of the asterisks
		for (int j = 1; j <= 9; j++)	// loops 9 times for 9 characters in a rows
		{
			if (j > spacing&& j <= spacing + numStars)		// check if j is at an index that is not for spacing
				printf("%s", "*");		// if so, print an asterisk
			else
				printf("%s", " ");		// if it is, print a space
		}

		if (i < 5)	// if the row is not the middle row
			numStars += 2;		// increment by two for the next row
		else
			numStars -= 2;		// else subtract two for the next row

		puts("");
	}

	/*
		no sample test cases
	*/

	return 0;
}