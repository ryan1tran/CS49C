#include <stdio.h>

// bit display function provided in Chapter 10's slides
void displayBits(int value)
{
	unsigned int displayMask = 1 << 31;

	printf("%d = ", value);

	for (int i = 1; i <= 32; i++)
	{
		putchar(value & displayMask ? '1' : '0');
		value <<= 1;

		if (i % 8 == 0)
			putchar(' ');
	}

	putchar('\n');
}

// unpacks one unsigned int into two characters
void unpackCharacters(unsigned int input)
{
	char char1, char2;
	unsigned int maskAndInput;
	unsigned int mask = 65280; // 00000000 00000000 11111111 00000000

	maskAndInput = mask & input; // store as int before converting to char
	char1 = (char)(maskAndInput >> 8); // shift right by 8, then cast into char

	mask >>= 8; // 00000000 00000000 00000000 11111111 = 255
	char2 = mask & input;

	// print unsigned int in bits before unpacking
	puts("\nUnsigned int in bit form:");
	displayBits(input);

	// print characters in bits after unpacking
	puts("\nCharacters unpacked from unsigned int:");
	printf("%c = ", char1);
	displayBits(char1);
	printf("%c = ", char2);
	displayBits(char2);
}

void hw4p3(void)
{	
	unsigned int input;
	printf("%s", "Please input a packed unsigned int: ");
	scanf("%u" ,&input);
	unpackCharacters(input);

	/*
		sample test cases
		- bit forms truncate leading 0's to save space
		- using final unsigned int outputs of problem2 as intial unsigned int inputs

		Input		Input in bits			First character		Second character
		------------------------------------------------------------------------
		24930		01100001 01100010		01100001 = a		01100010 = b
		8483		00100001 00100011		00100001 = !		00100011 = #
		10064		00100111 01010000		00100111 = '		01010000 = P
		16252		00111111 01111100		00111111 = ?		01111100 = |
		18279		01000111 01100111		01000111 = G		01100111 = g
	*/
}

int main(void)
{
	hw4p3();
	return 0;
}