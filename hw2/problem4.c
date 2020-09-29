#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isVowel(char input) // helper function to lessen code for vowel checking
{
	return (input == 'A' ||
		input == 'E' ||
		input == 'I' ||
		input == 'O' ||
		input == 'U' ||
		input == 'a' ||
		input == 'e' ||
		input == 'i' ||
		input == 'o' ||
		input == 'u');
}

// #include <string.h>
void hw2p4(void)
{
	char input[51] = { "" }; // 50 character input, not including termination character, so 51 total
	char result[54] = { "" }; // pig latin translation is potentially 3 characters longer if adding "yay"
	unsigned int resultIndex = 0;
	printf("%s ", "Input a word to translated into Pig Latin:");
	scanf_s("%s", input, sizeof(input));
	unsigned int length = strlen(input); // length of input string excluding termination character

	if (isVowel(input[0])) // if first character is a vowel
	{
		for (size_t i = 0; i < length; i++)
			result[resultIndex++] = input[i]; // copy input array into result array

		result[length] = 'y'; // add yay\0 to the end; strcat_s wouldn't work due to some error, so this was the less elegant alternative
		result[length + 1] = 'a';
		result[length + 2] = 'y';
		result[length + 3] = '\0';
	}
	else // otherwise first character is not a vowel
	{
		unsigned int index;
		for (size_t i = 1; i <= 4; i++) // limit of 4 consonants, starting at 1 to exclude the first character
		{
			if (isVowel(input[i]) || input[i] == 'y') // if the character is a vowel or y
			{
				if (input[i] == 'u' && input[i - 1] == 'q') // check that q is not followed by a u
					continue; // if it is, continue the loop

				index = i; // otherwise record the index of the new starting location
				break; // exit loop to stop changing index
			}
		}

		for (size_t i = index; i < length; i++) // copy from index to end of input array to result array
			result[resultIndex++] = input[i]; // strcpy_s didn't work either

		for (size_t i = 0; i < index; i++) // then copy from start to index of input array to result array
			result[resultIndex++] = input[i];

		result[length] = 'a'; // finally, add ay\0 to the end
		result[length + 1] = 'y';
		result[length + 2] = '\0';
	}

	printf("%s %s %s", input, "translated to Pig Latin:", result); // print the result

	/*
		sample test cases:
		all test cases given in the homework assignment
		Regular		Pig Latin
		--------------------------
		blue		ueblay
		Blue		ueBlay
		watermelon	atermelonway
		igloo		iglooyay
		yam			amyay
		Ryan		yanRay
	*/
}

int main(void)
{
	hw2p4();
	return 0;
}