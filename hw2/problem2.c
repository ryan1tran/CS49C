#include <stdlib.h>
#include <time.h>

void hw2p2(void)
{
	srand((int)time(NULL)); // randomize the seed to the current time

	int rolls[13] = { 0 }; // for clarity, rolls[2] will represent sum of 2; therefore rolls[0] and rolls[1] are irrelevant values

	for (int i = 0; i <= 36000; i++)
	{
		rolls[(rand() % 6 + 1) + (rand() % 6 + 1)]++; // increment index of the sum value
	}

	printf("%4s%15s\n---------------------\n", "Sum", "Frequency"); // formatting for tabular format
	for (int i = 2; i < 13; i++) // ignore rolls[0] and rolls[1]
		printf("%4d%15d\n", i, rolls[i]);

	/*
		no sample cases
	*/
}

int main(void)
{
	hw2p2();
	return 0;
}