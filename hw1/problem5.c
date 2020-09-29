#include <stdio.h>

int main(void)
{
	unsigned int input;

	printf("%s\n%s", "Problem 5: Pyramid pattern.", "Input a positive integer: ");
	scanf_s("%u", &input);

	unsigned int temp, counter = 0;
	for (int i = 2; i < input + 2; i++) // loop starting from 2 until input+2
	{
		for (int j = 2; j <= i; j++) // loop starting from initial i (which is 2) until equal to i
		{
			if (i % 2 == 0)			// if the current row is even
			{
				printf("%u", ++counter);	// print the preincremented counter value
				temp = counter + i;			// then set temp as the counter + i (will be used for odd rows)
			}
			else {					// if current row is odd
				printf("%u", temp--);	// print postdecrement of temp
				counter++;				// then increment counter to continue keeping track
			}

			if (j + 1 <= i)			// if the next value of j is still within the conditions of the second loop, print *
				printf("%s", "*");
		}

		puts("");
	} // prints specific number order based on row number; additional visual explanation below

	/*
		visual explanation:		row # (i)
		6:	1					| 0		when row is even, leftmost value of next row is highest value + i + 2
			3*2					| 1		when row is odd, leftmost value of next row is highest value + 1
			4*5*6				| 2
			10*9*8*7			| 3		therefore, the 0th row as the 2nd row removes the need to add +2 for even rows
			11*12*13*14*15		| 4
			21*20*19*18*17*16	| 5
	*/

	/*
		sample test cases:
		0:

		1:	1

		2:	1
			3*2

		3:	1
			3*2
			4*5*6

		4:	1
			3*2
			4*5*6
			10*9*8*7

		5:	1
			3*2
			4*5*6
			10*9*8*7
			11*12*13*14*15

		6:	1
			3*2
			4*5*6
			10*9*8*7
			11*12*13*14*15
			21*20*19*18*17*16
	*/

	return 0;
}