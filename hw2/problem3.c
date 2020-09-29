#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void turtle(int input[], int size)
{
	int floor[50][50] = { 0 }; // floor of 50x50 initialized as 0

	bool penUp = true;
	enum direction { Up = 0, Right = 1, Down = 2, Left = 3 }; // using enum to set direction
	enum direction current = Right;
	int pos[2] = { 0 }; // turtle's position in 1x2 array form initialized at 0,0


	for (size_t i = 0; i < size; i++)
	{
		if (input[i] == 9) // sentinel case to end the looping
			break;

		unsigned int move;
		switch (input[i])
		{
		case 1: // pen up
			penUp = true;
			break;
		case 2: // pen down
			penUp = false;
			break;
		case 3: // turn right
			if (current == Left)
				current = Up;
			else
				current++;
			break;
		case 4: // turn left
			if (current == Up)
				current = Left;
			else
				current--;
			break;
		case 5: // move and draw
			i++;
			if (!penUp) // for when the pen is down
			{
				switch (current)
				{
				case Up:
					if (pos[0] - input[i] < 0) // check for out of bounds
						move = pos[0];
					else
						move = input[i];

					for (int i = 0; i < move; i++) // draw on the floor
					{
						floor[pos[0] - i][pos[1]] = 1;
					}
					break;
				case Right:
					if (pos[1] + input[i] > 49) // check for out of bounds
						move = 49 - pos[1];
					else
						move = input[i];

					for (int i = 0; i < move; i++) // draw on the floor
					{
						floor[pos[0]][pos[1] + i] = 1;
					}
					break;
				case Down:
					if (pos[0] + input[i] > 49) // check for out of bounds
						move = 49 - pos[0];
					else
						move = input[i];

					for (int i = 0; i < move; i++) // draw on the floor
					{
						floor[pos[0] + i][pos[1]] = 1;
					}
					break;
				case Left:
					if (pos[1] - input[i] < 0) // check for out of bounds
						move = pos[1];
					else
						move = input[i];

					for (int i = 0; i < move; i++) // draw on the floor
					{
						floor[pos[0]][pos[1] - i] = 1;
					}
					break;
				}
			}

			switch (current) // regardless of pen up or pen down, this part will execute to update turtle's position
			{
			case Up:
				if (pos[0] - input[i] < 0) // check for out of bounds
					pos[0] = 0;
				else
					pos[0] -= input[i] + 1;
				break;
			case Right:
				if (pos[1] + input[i] > 49) // check for out of bounds
					pos[1] = 49;
				else
					pos[1] += input[i] - 1;
				break;
			case Down:
				if (pos[0] + input[i] > 49) // check for out of bounds
					pos[0] = 49;
				else
					pos[0] += input[i] - 1;
				break;
			case Left:
				if (pos[1] - input[i] < 0) // check for out of bounds
					pos[1] = 0;
				else
					pos[1] -= input[i] + 1;
				break;
			}
			break;
		case 6: // print the floor
			for (size_t i = 0; i < 50; i++)
			{
				for (size_t j = 0; j < 50; j++)
				{
					if (floor[i][j] == 0)
						printf("%s ", " "); // space for 0's
					else
						printf("%s ", "*"); // asterisk for 1's
				}
				puts("");
			}
			break;
		case '\t': // ignore these cases as well as invalid inputs
		case '\n':
		case ' ':
		default:
			break;
		}
	}

	/*
		sample test cases:
		{2, 5, 12, 3, 5, 12, 3, 5, 12, 3, 5, 12, 1, 6, 9}, 15 - given in the textbook: prints a 12x12 border
		{2, 5, 1, 3, 5, 1, 3, 5, 1, 3, 5, 1, 1, 6, 9}, 15 - prints a 1x1, single asterisk
		{2, 5, 2, 3, 5, 2, 4, 5, 2, 3, 5, 2, 4, 5, 2, 3, 5, 2, 1, 6, 9}, 21 - moves in a diagonal line 2 steps at a time
		{5, 50, 3, 5, 50, 3, 2, 5, 50, 3, 5, 50, 1, 6, 9}, 15 - moves to bottom-right corner first and prints border on left and bottom
	*/
}

void hw2p3(void)
{
	int input[] = { 2, 5, 12, 3, 5, 12, 3, 5, 12, 3, 5, 12, 1, 6, 9 };
	turtle(input, 15);
}

int main(void)
{
	hw2p3();
	return 0;
}