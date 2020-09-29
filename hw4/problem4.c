#include <stdio.h>

#define SIZE 100 // max size of hardware inventory list
#define NAME 20 // max size of item name
#define INITIAL_LIST 8 // initial amount of items in the list

// struct for tool data
typedef struct
{
	unsigned int recordNum;
	char toolName[NAME];
	unsigned int quantity;
	double cost;
} Tool;

// function to print options and scan input
unsigned int enterChoice(void)
{
	unsigned int input;
	printf("%s\n%s\n%s\n%s\n%s\n%s\n>",
		"Please input a choice number:",
		"1: Input a new tool",
		"2. Delete a tool",
		"3. Update a tool",
		"4. List tools",
		"5. Exit");
	scanf("%u", &input);

	return input;
}

void hw4p4(void)
{
	Tool list[INITIAL_LIST] = { 0 }; // list of initial tools provided by the problem
	FILE* fPtr; // file pointer

	if ((fPtr = fopen("hardware.dat", "wb")) == NULL) // opens/creates 'hardware.dat' for writing
		puts("Could not open 'hardware.dat'.");
	else
	{
		Tool blankTool = {0, "", 0, 0}; // blank tool is created

		for (int i = 0; i < SIZE; i++) // 100 blank records created in random-access structure
			fwrite(&blankTool, sizeof(Tool), 1, fPtr);

		// initialize and assign initial tools to the list
		Tool electricSander = { 3, "Electric sander", 7, 57.98 };
		list[0] = electricSander;
		Tool hammer = { 17, "Hammer", 76, 11.99 };
		list[1] = hammer;
		Tool jigSaw = { 24, "Jig saw", 21, 11.00 };
		list[2] = jigSaw;
		Tool lawnMower = { 39, "Lawn mower", 3, 79.50 };
		list[3] = lawnMower;
		Tool powerSaw = { 56, "Power saw", 18, 99.99 };
		list[4] = powerSaw;
		Tool screwdriver = { 66, "Screwdriver", 106, 6.99 };
		list[5] = screwdriver;
		Tool sledgeHammer= { 77, "Sledge hammer", 11, 21.50 };
		list[6] = sledgeHammer;
		Tool wrench = { 83, "Wrench", 34, 7.50 };
		list[7] = wrench;

		for (int i = 0; i < INITIAL_LIST; i++)
		{
			fseek(fPtr, (list[i].recordNum - 1) * sizeof(Tool), SEEK_SET); // store them based on their record number
			fwrite(&list[i], sizeof(Tool), 1, fPtr);
		}

		fclose(fPtr); // close the file pointer
	}

	if ((fPtr = fopen("hardware.dat", "rb+")) == NULL) // reopens file pointer to 'hardware.dat', but for updating
		puts("Could not open 'hardware.dat'.");
	else
	{
		unsigned int input;

		while ((input = enterChoice()) != 5) // while loop until exiting condition reached
		{
			Tool tool = { 0, "", 0, 0 }; // blank tool created each loop
			unsigned int record = 0; // input record number set to 0 each loop
			
			switch (input)
			{
				case 1:
					printf("%s", "Please input the recordNumber of the tool to be added (range of 1- 100): ");
					scanf("%u", &record); // takes in record number

					if (record > 0 && record <= 100) // if the input record number is within bounds
					{
						fseek(fPtr, (record - 1) * sizeof(Tool), SEEK_SET); // finds the location of the record number
						fread(&tool, sizeof(Tool), 1, fPtr); // reads the contents

						if (tool.recordNum == 0) // if the record there is empty, add the tool
						{
							printf("%s", "Please input the fields separated by a space: toolName (one word only), quantity, cost\n");
							scanf("%s %u %lf", &tool.toolName, &tool.quantity, &tool.cost); // takes in new fields
							tool.recordNum = record; // set the tool's record number to the input record number

							fseek(fPtr, (record - 1) * sizeof(Tool), SEEK_SET); // place the file pointer back to the same spot
							fwrite(&tool, sizeof(Tool), 1, fPtr); // write the tool to the file

							printf("Tool #%u successfully added!\n", tool.recordNum); // successful adding message
						}
						else
							printf("Tool %%u already exists.\n", tool.recordNum);
					}
					else
						puts("Invalid record number.");
					break;
				case 2:
					printf("%s", "Please input the recordNumber of the tool to be deleted (range of 1- 100): ");
					scanf("%u", &record);

					if (record > 0 && record <= 100) // if the input record number is within bounds
					{
						fseek(fPtr, (record - 1) * sizeof(Tool), SEEK_SET); // search for it
						fwrite(&tool, sizeof(Tool), 1, fPtr); // and replace the existing tool with a blank one

						printf("Tool #%u successfully deleted!\n", record);
					}
					else
						puts("Invalid record number.");
					break;
				case 3:
					printf("%s", "Please input the recordNumber of the tool to be updated (range of 1- 100): ");
					scanf("%u", &record);

					if (record > 0 && record <= 100) // if the input record number is within bounds
					{
						fseek(fPtr, (record - 1) * sizeof(Tool), SEEK_SET); // searches for the record number
						fread(&tool, sizeof(Tool), 1, fPtr); // reads the contents

						if (&tool.recordNum != 0) // if the tool does exist, update it
						{
							printf("%s", "Please input the updated fields separated by a space: toolName (one word only), quantity, cost\n");
							scanf("%s %u %lf", &tool.toolName, &tool.quantity, &tool.cost); // takes in new fields
							tool.recordNum = record;

							fseek(fPtr, (tool.recordNum - 1) * sizeof(Tool), SEEK_SET); // searches for the record number
							fwrite(&tool, sizeof(Tool), 1, fPtr); // and replaces existing tool with an updated tool

							printf("Tool #%u successfully updated!\n", tool.recordNum);
						}
						else
							printf("No tool of record number %u exists.\n", record);
					}
					else
						puts("Invalid record number.");
					break;
				case 4:
					rewind(fPtr); // bring file pointer back to the start
					printf("\n %-14s %22s %10s %10s \n-------------------------------------------------------------\n", "recordNumber", "toolName", "quantity", "cost");
					for (int i = 0; i < SIZE; i++) // prints the entire list of tools, excluding the blank ones
					{
						fread(&tool, sizeof(Tool), 1, fPtr);
						if (tool.recordNum != 0)
							printf(" %-14u %22s %10u %10.2lf \n", tool.recordNum, tool.toolName, tool.quantity, tool.cost);
					}
					break;
				default:
					puts("Invalid choice.");
			}

			puts("-----------------------------------");
		}

		fclose(fPtr);
	}

	/*
		sample test cases
		- NOTE: Due to the how strings work when being scanned in, multiple words mean the need for multiple char arrays.
				In order to avoid this issue of not knowing how many words will be in a tool name, all inputted names must be only one word.
				If multiple words are input, the program will not work and loop endlessly.
			Case 1:
			>4							 recordNumber                 toolName   quantity       cost
										-------------------------------------------------------------
										 3                     Electric sander          7      57.98
										 17                             Hammer         76      11.99
										 24                            Jig saw         21      11.00
										 39                         Lawn mower          3      79.50
										 56                          Power saw         18      99.99
										 66                        Screwdriver        106       6.99
										 77                      Sledge hammer         11      21.50
										 83                             Wrench         34       7.50
			>1
			10
			Cement 10 45.99
			>4							 recordNumber                 toolName   quantity       cost
										-------------------------------------------------------------
										 3                     Electric sander          7      57.98
										 10                             Cement         10      45.99    <-- cemenet with the correct details added
										 17                             Hammer         76      11.99
										 24                            Jig saw         21      11.00
										 39                         Lawn mower          3      79.50
										 56                          Power saw         18      99.99
										 66                        Screwdriver        106       6.99
										 77                      Sledge hammer         11      21.50
										 83                             Wrench         34       7.50

			Case 2:
			>4							 recordNumber                 toolName   quantity       cost
										-------------------------------------------------------------
										 3                     Electric sander          7      57.98
										 17                             Hammer         76      11.99    <-- hammer to be removed
										 24                            Jig saw         21      11.00
										 39                         Lawn mower          3      79.50
										 56                          Power saw         18      99.99
										 66                        Screwdriver        106       6.99
										 77                      Sledge hammer         11      21.50
										 83                             Wrench         34       7.50
			>2
			17
			>4							 recordNumber                 toolName   quantity       cost
										-------------------------------------------------------------
										 3                     Electric sander          7      57.98
										 24                            Jig saw         21      11.00    <-- no more hammer
										 39                         Lawn mower          3      79.50
										 56                          Power saw         18      99.99
										 66                        Screwdriver        106       6.99
										 77                      Sledge hammer         11      21.50
										 83                             Wrench         34       7.50
			
			Case 3:
			>4							 recordNumber                 toolName   quantity       cost
										-------------------------------------------------------------
										 3                     Electric sander          7      57.98
										 17                             Hammer         76      11.99
										 24                            Jig saw         21      11.00
										 39                         Lawn mower          3      79.50
										 56                          Power saw         18      99.99
										 66                        Screwdriver        106       6.99    <-- screwdriver to be updated
										 77                      Sledge hammer         11      21.50
										 83                             Wrench         34       7.50
			>3
			66
			Screwdriver 20 5.99
			>4							 recordNumber                 toolName   quantity       cost
										-------------------------------------------------------------
										 3                     Electric sander          7      57.98
										 17                             Hammer         76      11.99
										 24                            Jig saw         21      11.00
										 39                         Lawn mower          3      79.50
										 56                          Power saw         18      99.99
										 66                        Screwdriver         20       5.99    <-- quantity and cost updated correctly
										 77                      Sledge hammer         11      21.50
										 83                             Wrench         34       7.50
			
			Case 4:
			>1
			101							Invalid record number.

			Case 5:
			>5							Exits
	*/
}

int main(void)
{
	hw4p4();
	return 0;
}