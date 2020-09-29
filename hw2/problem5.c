#include <stdio.h>
#include <stdbool.h>
#include <string.h>

# define SIZE 1000 // size of waiting list
# define NAME_SIZE 11 // name is a maximum of 10 characters

static char names[SIZE][NAME_SIZE]; // list of size 1000, each element of 10 characters
static int size[SIZE]; // list of size 1000
int top = -1; // top of list

bool isEmpty(void) // checks if list is empty (top == -1)
{
	if (top == -1)
		return true;
	return false;
}

bool isFull(void) // checks if list is full (top == SIZE - 1)
{
	if (top == SIZE - 1)
		return true;
	return false;
}

void insert(char input[], int party) // inserts name and party size into waiting list
{
	if (party < 1)
		printf("|%s\n|\n", "Error: party size must be greater than 0."); // error message if party size is invalid
	else
	{
		if (!isFull()) // if waiting list isn't full
		{
			bool dup = false; // boolean for duplicate

			if (!isEmpty()) // if the list isnt empty
			{
				for (size_t i = 0; i <= top; i++)
					if (strcmp(names[i], input) == 0) // check if name is already in waiting list
					{
						printf("|Error: %s is already in waiting list.\n", input); // error message if there is a duplicate
						dup = true; // set dup to true
						break;
					}
			}

			if (!dup) // only add to waiting list if dup is false
			{
				top++; // increment top
				for (int i = 0; i < NAME_SIZE; i++)
				{
					names[top][i] = input[i]; // copy input name into list
				}
				size[top] = party; // then add party size
				printf("|%s's party size of size %u added succesfully!\n", input, party); // confirmation message
			}
		}
		else
			printf("|%s\n", "Error: waiting list is full."); // error message if waiting list is full
	}
}

void removeParty(int party) // removes oldest name and party from waiting list
{
	if (!isEmpty()) // if not empty waiting list
	{
		unsigned int index = -1; // index of first match
		for (size_t i = 0; i <= top; i++) // go from oldest to newest party
			if (size[i] == party)
			{
				index = i; // find size at index that matches the size of party to remove
				break; // exit after first occurrence
			}

		if (index == -1) // if index remains -1, then no matching party size
		{
			printf("|%s%u.\n", "Error: no party of size ", party); // then print error message
		}
		else // otherwise there is a match
		{
			printf("|%s's party of size %d removed successfully!\n", names[index], size[index]); // print confirmation message with information before removing
			for (int i = 0; i < NAME_SIZE; i++)
			{
				names[index][i] = 0; // set name to 0
			}
			size[index] = 0; // and size to 0

			for (size_t i = index; i < top; i++) // shifts list up if neccesary after removing party
			{
				for (int j = 0; j < NAME_SIZE; j++)
				{
					names[i][j] = names[i + 1][j]; // move all elements down
				}
				size[i] = size[i + 1]; // move size down
			}

			top--; // decrement top of list
		}
	}
	else
		printf("|%s\n", "Error: waiting list is empty."); // error message if waiting list is empty
}

void showList(void) // prints waiting list
{
	if (isEmpty())
		printf("|%s\n", "No waiting list."); // message if no waiting list
	else
	{
		printf("|%11s%15s\n|---------------------------\n", "Name", "Party Size");
		for (size_t i = 0; i <= top; i++)
			printf("|%11s%15d\n", names[i], size[i]); // loop from oldest to newest party and print their details
	}
}

void hw2p5(void)
{
	unsigned int party = 0, input = 0; // initialize input value

	while (input != 4) // sentinel case
	{
		char name[NAME_SIZE] = { "" }; // initialize name to all 0

		printf("|%s\n|%s\n|%s\n|%s\n|%s\n|%s", "Please input an option:", "Add party:\t1 Name PartySize", "Remove Party:\t2 PartySizeToRemove", "Print Parties:\t3", "Quit:\t\t4", ">");
		scanf_s("%u", &input); // scans in first value only

		if (input == 1) // if input 1, it is add party
			scanf_s(" %s %u", name, sizeof(name), &party); // scan in name and party size

		if (input == 2) // if input 2, it will be followed with another number
			scanf_s(" %u", &party); // scan in party size

		switch (input)
		{
		case 1:
			insert(name, party); // add name and party size
			break;
		case 2:
			removeParty(party); // remove party of input size
			break;
		case 3:
			showList(); // print the waiting list
			break;
		case '\t': // ignore cases
		case '\n':
		case ' ':
		default:
			break;
		}

		puts("|");
	}

	/*
		NOTE: This code is the same as the 'problem5_ec.c' code. See the comments in the removeParty function for the explanation.
		sample test cases:
		1.	1 ryan 2	- adds ryan with party 2
			3			- shows only ryan with party 2
			1 ryan 3	- gives error message due to name already in the waiting list
			3			- still only ryan with party 2
			2 2			- removes ryan with party 2
			3			- no waiting list message
			4			- quit

		2.	1 ryan 2	- adds ryan with party 2
			3			- shows only ryan with party 2
			1 neeraj 5	- shows ryan with party 2 and neeraj with party 5
			2 3			- gives error message because no party of size 3
			3			- no change
			2 2			- removes ryan with party 2
			3			- now only neeraj with party 5
			4			- quit

		3.	1 ryan 2	- adds ryan with party 2
			3			- shows only ryan with party 2
			1 neeraj 2	- adds neeraj with party 2
			3			- shows ryan with party 2 and neeraj with party 2
			2 2			- removes oldest party (ryan's)
			3			- now only neeraj with party 2
			4			- quit
	*/
}

int main(void)
{
	hw2p5();
	return 0;
}