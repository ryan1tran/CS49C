#include <stdio.h>

// bit display function provided in Chapter 10's slides
void displayBits(int value)
{
	unsigned int displayMask = 1 << 31; // 10000000 00000000 00000000 00000000

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

// packs two characters into one unsigned int
void packCharacters(char char1, char char2)
{
	unsigned int characters = 0; // initialize to 0 to avoid garbage values
	characters = char1; // set int as first character
	characters <<= 8; // left shift 8 times to make room for the second character
	characters |= char2; // OR to load second character onto int without overwriting the first character

	// print characters in bits before packing
	puts("\nCharacters in bit form:");
	printf("%c = ", char1);
	displayBits(char1);
	printf("%c = ", char2);
	displayBits(char2);
	
	// print unsigned int that contains both characters after packing in bits
	puts("\nCharacters packed into unsigned int in bit form:");
	displayBits(characters);
}

void hw4p2(void)
{
	char char1, char2;
	printf("%s", "Please input two characters with a space inbetween them: ");
	scanf("%c %c", &char1, &char2);
	packCharacters(char1, char2);

	/*
		sample test cases
		- bit forms truncate leading 0's to save space
		
		Input	First input in bits		Second input in bits			Output in bits				Output as unsigned int
		------------------------------------------------------------------------------------------------------------------
		a b		01100001				01100010						01100001 01100010			24930
		! #		00100001				00100011						00100001 00100011			8483
		' P		00100111				01010000						00100111 01010000			10064
		? |		00111111				01111100						00111111 01111100			16252
		G g		01000111				01100111						01000111 01100111			18279
	*/
}

int main(void)
{
	hw4p2();
	return 0;
}