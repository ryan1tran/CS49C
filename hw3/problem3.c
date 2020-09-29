#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 71

void hw3p3(void)
{
	char positionLine[SIZE]; // char array for position line
	int tortoisePos = 0; // tortoise position tracker
	int harePos = 0; // hare position tracker
	bool won = false; // tracks if there is a win or not, checking if the race needs to loop again

	for (size_t i = 0; i <= SIZE - 2; i++) // set first 70 characters to hyphens
		positionLine[i] = '-';
	positionLine[SIZE - 1] = '\0'; // set last character as terminating character

	int percentage; // movement chance for both tortoise and hare
	srand((int)time(NULL)); // randomize seed

	printf("%s\n%s\n", "BANG !!!!!", "AND THEY'RE OFF !!!!!");

	int raceDuration = 100; // interations/seconds of the race

	while (!won) // loops while neither tortoise nor hare have won
	{
		for (int i = 0; i < raceDuration; i++)
		{
			printf("%s\n", positionLine); // print current position line

			for (size_t i = 0; i <= SIZE - 2; i++) // reset line in preparation for potentially new positions
				positionLine[i] = '-';

			percentage = rand() % 10 + 1; // random number from 1 - 10 for both tortoise and hare

			switch (percentage) // switch case for tortoise
			{
			case 1: // 1-5 is fast plod (+3)
			case 2:
			case 3:
			case 4:
			case 5:
				if (tortoisePos + 3 > SIZE - 2)
					tortoisePos = SIZE - 2;
				else
					tortoisePos += 3;
				break;
			case 6: // 6-7 is slip (-6)
			case 7:
				if (tortoisePos - 6 < 0)
					tortoisePos = 0;
				else
					tortoisePos -= 6;
				break;
			case 8: // 8-10 is slow plod (+1)
			case 9:
			case 10:
				tortoisePos += 1;
				break;
			default:
				break;
			}

			switch (percentage) // switch case for hare
			{
				case 3: // 3-4 is big hop (+9)
				case 4:
					if (harePos + 9 > SIZE - 2)
						harePos = SIZE - 2;
					else
						harePos += 9;
					break;
				case 5: // 5 is big slip (-12)
					if (harePos - 12 < 0)
						harePos = 0;
					else
						harePos -= 12;
					break;
				case 6: // 6-8 is small hop (+1)
				case 7:
				case 8:
					harePos += 1;
					break;
				case 9: // 9-10 is small slip (-2)
				case 10:
					if (harePos - 2 < 0)
						harePos = 0;
					else
						harePos -= 2;
					break;
				default: // 1-2 is sleep (+0), so case is omitted
					break;
			}

			// change positionLine for each animal
			if (tortoisePos == harePos) // if tortoise and hare are in the same position, print OUCH!!!
			{
				int ouchInt = tortoisePos; // temporary variable for tortoisePos

				if (ouchInt + 6 > SIZE - 2) // if printing OUCH!!! will be out of bounds
					ouchInt = SIZE - 2 - 6; // set temporary variable to first position that it will not be out of bounds
			
				positionLine[ouchInt] = 'O'; // then set the next 7 indexes to OUCH!!!
				positionLine[ouchInt+1] = 'U';
				positionLine[ouchInt+2] = 'C';
				positionLine[ouchInt+3] = 'H';
				positionLine[ouchInt+4] = '!';
				positionLine[ouchInt+5] = '!';
				positionLine[ouchInt+6] = '!';
			}
			else // otherwise mark with their letter
			{
				positionLine[tortoisePos] = 'T';
				positionLine[harePos] = 'H';
			}

			if (i == (raceDuration - 1) && tortoisePos < 70 && harePos < 70) // if neither hare nor tortoise have not won by the end of the race
			{
				printf("%s\n\n", "It's a stalemate. Racing again!"); // print message for neither have won

				positionLine[tortoisePos] = '-'; // reset both positions to '-' to prepare for next race
				positionLine[harePos] = '-';

				break; // exit for loop
			}


			if (tortoisePos >= SIZE - 2 || harePos >= SIZE - 2) // if either have won
			{
				if (tortoisePos > harePos) // if tortoise's position is ahead
					puts("TORTOISE WINS!!! YAY!!!"); // tortoise wins

				if (tortoisePos < harePos) // if hare's position is ahead
					puts("Hare wins. Yuch."); // hare wins

				if (tortoisePos == harePos) // if both are at the same position
					puts("It's a tie."); // tie

				won = true; // set won to true
				break; // exit for loop
			}
		}
	}

}

int main(void)
{
	hw3p3();
	return 0;
}