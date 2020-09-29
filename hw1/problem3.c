#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	char choice;

	printf("%s\n", "Problem 3: Rock paper scissors!"); // R is 2, P is 1, S is 3
	unsigned int random, wins = 0, comWins = 0;

	srand((int)time(NULL)); // called once before any usage of rand()
	for (int i = 0; i < 10; i++) // loop 10 times as the problem instructed
	{
		printf("%s", "Choose Rock (R), Paper (P), or Scissors (S): ");
		scanf_s(" %c", &choice); // space left of %c is necessary to avoid accepting newline character and causing a bug

		random = rand() % 3 + 1; // chooses a number from 1 - 3

		switch (choice) // switch block for all relevant cases
		{
		case 'R': // R falls through to r for the same case; same situation for other letters
		case 'r':
			if (random == 1)
			{
				printf("%s\n\n", "Computer chose paper. You lost.");
				comWins++;
			}
			else if (random == 2)
				printf("%s\n\n", "Computer chose rock. You tied.");
			else {
				printf("%s\n\n", "Computer chose scissors. You won!");
				wins++;
			}
			break;
		case 'P':
		case 'p':
			if (random == 1)
				printf("%s\n\n", "Computer chose paper. You tied.");
			else if (random == 2) {
				printf("%s\n\n", "Computer chose rock. You won!");
				wins++;
			}
			else
			{
				printf("%s\n\n", "Computer chose scissors. You lost.");
				comWins++;
			}
			break;
		case 'S':
		case 's':
			if (random == 1) {
				printf("%s\n\n", "Computer chose paper. You won!");
				wins++;
			}
			else if (random == 2)
			{
				printf("%s\n\n", "Computer chose rock. You lost.");
				comWins++;
			}
			else
				printf("%s\n\n", "Computer chose scissors. You tied.");
			break;
		default:
			break;
		}
	} // loops and takes inputs 10 times while keeping track of and deciding whether you or computer wins

	printf("%s %d\n%s %d\n", "Your wins:", wins, "Computer wins:", comWins);
	if (wins > comWins)
		printf("%s\n", "You won!");
	else if (wins < comWins)
		printf("%s\n", "You lost.");
	else
		printf("%s\n", "You tied.");

	/*
		no possible sample test cases; just play the game!
		(or just spam one letter over and over like I do)
	*/

	return 0;
}