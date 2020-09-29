#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHAR_SIZE 30 // size of char array fields
#define LIST_SIZE 8 // size of Employee arrays

// typdef to create multiple of the same struct named Employee
typedef struct
{
	unsigned int employeeId;
	char name[CHAR_SIZE];
	char jobTitle[CHAR_SIZE];
} Employee;

// bubbleSort from Chapter 6's slides and Lab 5
void bubbleSort(Employee list[LIST_SIZE])
{
	unsigned int resize = LIST_SIZE - 1;
	unsigned int numSwaps;

	for (unsigned int pass = 1; pass < LIST_SIZE; pass++)
	{
		numSwaps = 0;

		for (size_t i = 0; i < resize; i++)
		{
			// compare the two names with strcmp
			if (strcmp(list[i].name, list[i + 1].name) > 0) // > 0 means that the first string goes after the second alphabetically
			{
				Employee hold = list[i];
				list[i] = list[i + 1];
				list[i + 1] = hold;
				numSwaps++;
			}
		}

		if (numSwaps == 0)
			break;

		resize--;
	}
}

void hw4p1(void)
{
	// create array of type Employees and initialize each to 0
	Employee list[LIST_SIZE] = { 0 };

	// create and load employees into list
	Employee emp1;
	emp1.employeeId = 10001;
	strcpy(emp1.name, "William");
	strcpy(emp1.jobTitle, "Accountant");
	list[0] = emp1;

	Employee emp2;
	emp2.employeeId = 10002;
	strcpy(emp2.name, "Susie");
	strcpy(emp2.jobTitle, "Human Resources Manager");
	list[1] = emp2;

	Employee emp3;
	emp3.employeeId = 10003;
	strcpy(emp3.name, "Will");
	strcpy(emp3.jobTitle, "Software Engineer");
	list[2] = emp3;

	Employee emp4;
	emp4.employeeId = 10004;
	strcpy(emp4.name, "Madeline");
	strcpy(emp4.jobTitle, "Business Associate");
	list[3] = emp4;

	Employee emp5;
	emp5.employeeId = 10005;
	strcpy(emp5.name, "David");
	strcpy(emp5.jobTitle, "CEO");
	list[4] = emp5;

	Employee emp6;
	emp6.employeeId = 10006;
	strcpy(emp6.name, "Catherine");
	strcpy(emp6.jobTitle, "VP");
	list[5] = emp6;

	Employee emp7;
	emp7.employeeId = 10007;
	strcpy(emp7.name, "George");
	strcpy(emp7.jobTitle, "Facilities");
	list[6] = emp7;

	Employee emp8;
	emp8.employeeId = 10008;
	strcpy(emp8.name, "Jessica");
	strcpy(emp8.jobTitle, "Receptionist");
	list[7] = emp8;

	// print list before bubble sort
	puts("List of employees before sorting names in descending order:");
	for (int i = 0; i < LIST_SIZE; i++)
	{
		printf("Employee ID: %d\tName: %s\tJob title: %s\n", list[i].employeeId, list[i].name, list[i].jobTitle);
	}

	bubbleSort(list); // sort list

	// print list after bubble sort
	puts("\nList of employees after sorting names in descending order:");
	for (int i = 0; i < LIST_SIZE; i++)
	{
		printf("Employee ID: %d\tName: %s\tJob title: %s\n", list[i].employeeId, list[i].name, list[i].jobTitle);
	}

	/*
		no sample cases
	*/
}

int main(void)
{
	hw4p1();
	return 0;
}