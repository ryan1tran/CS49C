#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void hw3p1(void)
{
	srand((int)time(NULL)); // randomize seed
	char* article[SIZE] = { "the", "a", "one", "some", "any" };
	char* noun[SIZE] = { "boy", "girl", "dog", "town", "car" };;
	char* verb[SIZE] = { "drove", "jumped", "ran", "walked", "skipped" };
	char* preposition[SIZE] = { "to", "from", "over", "under", "on" };

	for (int i = 0; i < 20; i++) // loop 20 times for 20 sentences
	{
		char sentence[50] = { "" }; // initialize/clear char array for sentence each loop

		strcat(sentence, article[rand() % 5]); // random article
		sentence[0] = toupper(sentence[0]); // capitalize first letter
		strcat(sentence, " "); // spacing after each word
		strcat(sentence, noun[rand() % 5]); // random noun
		strcat(sentence, " ");
		strcat(sentence, verb[rand() % 5]); // random verb
		strcat(sentence, " ");
		strcat(sentence, preposition[rand() % 5]); // random preposition
		strcat(sentence, " ");
		strcat(sentence, article[rand() % 5]); // random article
		strcat(sentence, " ");
		strcat(sentence, noun[rand() % 5]); // random noun
		strcat(sentence, "."); // end sentence with a period

		puts(sentence);
	}

	/*
		no sample cases
	*/
}

int main(void)
{
	hw3p1();
	return 0;
}