#include <stdio.h>

int main(void)
{
	int palin;

	printf("%s", "Problem 2: Input a 5-digit number to be determined if it is a palindrome: ");
	scanf_s("%d", &palin);

	if (((palin / 10000) == (palin % 10)) && (((palin / 1000) % 10) == ((palin % 100) / 10))) // compares 1st to 5th digit and 2nd to 4th digit in one line
																							  // 3rd digit does not affect if palindrome or not
		printf("%d %s\n", palin, "is a palindrome!");		// returns is palindrome
	else
		printf("%d %s\n", palin, "is not a palindrome.");	// or return not palindrome

	/*
		sample test cases:
		12321: palindrome
		15241: not palindrome
		11111: palindrome
		22122: palindrome
		32424: not palindrome
	*/

	puts("");

	return 0;
}