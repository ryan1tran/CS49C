#include <stdio.h>
#include <math.h>

int main(void)
{
	unsigned int binVal, decVal = 0, base = 0;

	printf("%s", "Problem 1: Input a binary value to be converted to decimal: ");
	scanf_s("%u", &binVal);

	for (base; binVal > 0; base++) // loop until the binary value becomes 0, in which that value has no effect on the decimal value
	{
		unsigned int bit = binVal % 10;		// take last digit
		binVal /= 10;						// update binVal to reflect that
		decVal += bit * (int)pow(2, base);	// using bases to convert to decimal
	} // converts binary to decimal

	/* sample test cases:
		Binary		Decimal
		0			0
		10			2
		111			7
		1010		10
	*/

	printf("%s %u\n", "Decimal value: ", decVal);
	puts("");

	return 0;
}