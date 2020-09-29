#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int lab1(void)
{
	float sp;
	float cp;
	float profit;

	printf("%s", "Problem 1: Please input the selling price and profit of 15 items separated by a space: ");
	scanf_s("%f %f", &sp, &profit);

	cp = (sp - profit) / 15;

	printf("%s %f\n\n", "The cost price of one item is ", cp);

	int input;
	int result;

	printf("%s", "Problem 2: Please input a 4 digit number: ");
	scanf_s("%d", &input);

	result = (input % 10 * 1000) + (input % 100 / 10 * 100) + (input % 1000 / 100 * 10) + (input / 1000);

	printf("%s %d\n", "The reversed number is ", result);

	return 0;
}

int lab2(void)
{
	printf("%s\n", "Problem 1: Printing 1 through 10 with 3 spaces inbetween each value:");

	unsigned int counter = 1;

	while (counter <= 10)
	{
		printf("%d   ", counter++);
	}
	puts("\n");

	printf("%s\n", "Problem 2: Running code 2.1 when x = 9 and y = 11:");

	unsigned int x = 9;
	unsigned int y = 11;

	if (x < 10)
		if (y > 10)
			printf("*****\n");
		else
			printf("#####\n");
	printf("$$$$$\n"); // this code will print *****\n followed by $$$$$\n
	puts("\n");

	printf("%s\n", "Problem 2: Running code 2.2 when x = 9 and y = 11:");

	if (x < 10) {
		if (y > 10)
			printf("*****\n");
	}
	else {
		printf("#####\n");
		printf("$$$$$\n");
	} // this code will print *****\n
	puts("\n");

	printf("%s\n", "Problem 2: Running code 2.1 when x = 11 and y = 9:");

	x = y;
	y = 9;

	if (x < 10)
		if (y > 10)
			printf("*****\n");
		else
			printf("#####\n");
	printf("$$$$$\n"); // this code will print $$$$$\n
	puts("\n");

	printf("%s\n", "Problem 2: Running code 2.2 when x = 11 and y = 9:");

	if (x < 10) {
		if (y > 10)
			printf("*****\n");
	}
	else {
		printf("#####\n");
		printf("$$$$$\n");
	} // this code will print #####\n followed by $$$$$\n
	puts("\n");

	printf("%s\n", "Problem 3: Printing multiples of 2 without termination:");

	unsigned int multTwo = 2;

	while (2)
	{
		printf("%d ", multTwo);
		multTwo *= 2;
	} // this while block will never end because the condition will always remain true since there are no conditional operators

	return 0;
}

int lab3(void)
{
	unsigned int input;

	printf("%s", "Problem 1: Input a positive value: n = ");
	scanf_s("%d", &input);

	for (int i = 1; i <= input; i++)
	{
		for (int j = 0; j < i; j++)
			printf("%s", "*");
		puts("");
	}

	puts("");

	printf("%s\n", "Problem 2: Pythagorean Triples");

	for (int hypotenuse = 1; hypotenuse <= 500; hypotenuse++)
		for (int side1 = 1; side1 < hypotenuse; side1++)
			for (int side2 = 1; side2 <= side1; side2++)
				if ((pow(side1, 2) + pow(side2, 2)) == pow(hypotenuse, 2))
					printf("%d\t%d\t%d\n", hypotenuse, side1, side2);

	printf("%s\n", "are all possible Pythagorean triples up to 500!");

	return 0;
}

void fibonacciInt(int n) // n = 47 max for int, 1836311903
{
	unsigned int first = 0;
	unsigned int second = 1;
	unsigned int next;

	if (n == 0)
	{
		printf("%d", first);
		return;
	}else if (n == 1)
	{
		printf("%d", second);
		return;
	}
	
	printf("%d, %d, ", first, second);

	for (int i = 2; i < n; i++)
	{
		next = first + second;
		printf("%d, ", next);
		first = second;
		second = next;	
	}
	printf("%s\n", "... ");
}

void fibonacciDouble()
{
	double first = 0;
	double second = 1;
	double next;

	printf("%.0lf, %.0lf, ", first, second);

	while (1 > 0)
	{
		next = first + second;
		printf("%.0lf, ", next);
		first = second;
		second = next;
	}
}

void lab4(void)
{
	unsigned int choice;
	printf("%s", "Problem 1: Fibonacci series. Choose the number of values you wish to compute: ");
	scanf_s("%u", &choice);
	puts("");
	fibonacciInt(choice);
}

void bubbleSort(int arr[], int SIZE)
{
	puts("Unsorted array:");
	for (size_t i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);

	unsigned int swapCount;
	unsigned int resize = SIZE - 1;

	for (unsigned int pass = 1; pass < SIZE; pass++)
	{
		swapCount = 0;

		for (size_t i = 0; i < resize; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapCount++;
			}
		}

		if (swapCount == 0)
			break;

		resize--;
	}

	puts("\n\nSorted array:");
	for (size_t i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
}

void matrixMultiplication(int a[4][4], int b[4][4])
{
	puts("Matrix a");
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
			printf("%d\t", a[i][j]);

		puts("");
	}

	puts("\nMatrix b");
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
			printf("%d\t", b[i][j]);

		puts("");
	}

	int result[4][4];

	for (size_t i = 0; i < 4; i++)
		for (size_t j = 0; j < 4; j++)
		{
			int val = 0;
			for (size_t k = 0; k < 4; k++)
				val += a[i][k] * b[k][j];
			result[i][j] = val;
		}

	puts("\nMultiplication result of a * b:");

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
			printf("%d\t", result[i][j]);

		puts("");
	}
}

void lab5(void)
{
	puts("Problem 1: Bubble Sort");
	int arr[5] = { 5, 2, 3, 1, 4 };
	bubbleSort(arr, 5);

	puts("\n\nProblem 2: Matrix Multiplication\n");
	int a[4][4] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} };
	int b[4][4] = { {1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7} };
	matrixMultiplication(a, b);
}

void lab6p1(void)
{
	char charInput;
	printf("%s", "Problem 1: Input a character: ");
	charInput = getchar();
	printf("%s '%c' %s %s\n", "According to isblank:", charInput, isblank(charInput) ? "is a" : "is not a", "blank.");
	printf("%s '%c' %s %s\n", "According to isdigit:", charInput, isdigit(charInput) ? "is a" : "is not a", "digit.");
	printf("%s '%c' %s %s\n", "According to isalpha:", charInput, isalpha(charInput) ? "is an" : "is not an", "alphabetical letter.");
	printf("%s '%c' %s %s\n", "According to isnum:", charInput, isalnum(charInput) ? "is a" : "is not a", "number or letter.");
	printf("%s '%c' %s %s\n", "According to isxdigit:", charInput, isxdigit(charInput) ? "is a" : "is not a", "hexadecimal degit.");
	printf("%s '%c' %s %s\n", "According to islower:", charInput, islower(charInput) ? "is a" : "is not a", "lowercase letter.");
	printf("%s '%c' %s %s\n", "According to isupper:", charInput, isupper(charInput) ? "is an" : "is not an", "uppercase letter.");
	printf("%s '%c' %s %c.\n", "In lowercase (tolower):", charInput, "is", tolower(charInput));
	printf("%s '%c' %s %c.\n", "In uppercase (toupper):", charInput, "is", toupper(charInput));
	printf("%s '%c' %s %s\n", "According to isspace:", charInput, isspace(charInput) ? "is a" : "is not a", "whitespace character.");
	printf("%s '%c' %s %s\n", "According to iscontrl:", charInput, iscntrl(charInput) ? "is a" : "is not a", "control character.");
	printf("%s '%c' %s %s\n", "According to ispunct:", charInput, ispunct(charInput) ? "is a" : "is not a", "printing character other than a space, digit, or letter.");
	printf("%s '%c' %s %s\n", "According to isprint:", charInput, isprint(charInput) ? "is a" : "is not a", "printing character.");
	printf("%s '%c' %s %s\n", "According to isgraph:", charInput, isgraph(charInput) ? "is a" : "is not a", "printing character other than a space.");
	puts("");
}

void lab6p2(void)
{
	char fullInput[101] = {""};
	printf("%s", "Problem 2: Input up to 100 characters: ");
	fgets(fullInput, sizeof(fullInput), stdin);
	int wordCount = 0;
	
	char* tokenPtr = strtok(fullInput, " \n");
	while (tokenPtr != NULL)
	{
		wordCount++;
		tokenPtr = strtok(NULL, " \n");
	}

	printf("Number of words: %d\n", wordCount);
}

void lab7p1(void)
{
	union integer
	{
		char c;
		short s;
		int i;
		long b;
	};

	union integer container;

	printf("%s", "Please input a character: ");
	scanf("%c", &container.c);
	printf("char: %c, short: %d, int: %d, long: %ld\n", container.c, container.s, container.i, container.b);

	printf("\n%s", "Please input a short integer: ");
	scanf("%d", &container.s);
	printf("char: %c, short: %d, int: %d, long: %ld\n", container.c, container.s, container.i, container.b);

	printf("\n%s", "Please input an integer: ");
	scanf("%d", &container.i);
	printf("char: %c, short: %d, int: %d, long: %ld\n", container.c, container.s, container.i, container.b);

	printf("\n%s", "Please input a long: ");
	scanf("%ld", &container.b);
	printf("char: %c, short: %d, int: %d, long: %ld\n", container.c, container.s, container.i, container.b);
}

//void displayBits(int value)
//{
//	unsigned int displayMask = 1 << 31;
//
//	printf("%d = ", value);
//
//	for (int i = 1; i <= 32; i++)
//	{
//		putchar(value & displayMask ? '1' : '0');
//		value <<= 1;
//
//		if (i % 8 == 0)
//			putchar(' ');
//	}
//
//	putchar('\n');
//}

void lab7p2(void)
{
	int input;
	printf("%s", "Input an integer: ");
	scanf("%d", &input);
	puts("Before shift:");
	//displayBits(input);
	input >>= 4;
	puts("After shift:");
	//displayBits(input);
}

typedef struct
{
	int real;
	int imaginary;
} complexNum;

complexNum addComplex(complexNum one, complexNum two)
{
	complexNum result;
	result.real = one.real + two.real;
	result.imaginary = one.imaginary + two.imaginary;

	return result;
}

void lab7p3(void)
{
	complexNum one;
	printf("%s", "Input real and imaginary value for the first complex number: ");
	scanf("%d %d", &one.real, &one.imaginary);

	complexNum two;
	printf("%s", "Input real and imaginary value for the second complex number: ");
	scanf("%d %d", &two.real, &two.imaginary);

	complexNum result = addComplex(one, two);

	printf("\nSum = %d + %d%c", result.real, result.imaginary, 'i');
}

void lab8(void)
{
	FILE* fPtr;

	if ((fPtr = fopen("datasize.dat", "wb")) == NULL)
		puts("Could not open/create 'datasize.dat'.");
	else
	{
		fprintf(fPtr, "%-50s%4s\n", "Data type", "Size");
		fprintf(fPtr, "%-50s%4d\n", "char", sizeof(char));
		fprintf(fPtr, "%-50s%4d\n", "unsigned char", sizeof(unsigned char));
		fprintf(fPtr, "%-50s%4d\n", "short int", sizeof(short int));
		fprintf(fPtr, "%-50s%4d\n", "unsigned short int", sizeof(unsigned short int));
		fprintf(fPtr, "%-50s%4d\n", "int", sizeof(int));
		fprintf(fPtr, "%-50s%4d\n", "unsigned int", sizeof(unsigned int));
		fprintf(fPtr, "%-50s%4d\n", "long int", sizeof(long int));
		fprintf(fPtr, "%-50s%4d\n", "unsigned long int", sizeof(unsigned long int));
		fprintf(fPtr, "%-50s%4d\n", "float", sizeof(float));
		fprintf(fPtr, "%-50s%4d\n", "double", sizeof(double));
		fprintf(fPtr, "%-50s%4d\n", "long double", sizeof(long double));

		fclose(fPtr);
		puts("Successfully wrote to 'datasize.dat'!");
	}
}

struct listNode
{
	char data;
	struct listNode* nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode* ListNodePtr;

ListNodePtr concatLinkedList(ListNodePtr sPtr1, ListNodePtr sPtr2)
{
	ListNodePtr currentPtr = sPtr1; // assign list 1 pointer as current node

	while (currentPtr != NULL && currentPtr->nextPtr != NULL) // loop until the very last, non-NULL node
		currentPtr = currentPtr->nextPtr;

	if (currentPtr != NULL) // if the node isn't NULL (not an empty list)
		currentPtr->nextPtr = sPtr2; // append list 2's first node as the next node

	sPtr2 = sPtr1; // for empty or non-empty list, set start of list 2 as start of list 1
	return sPtr2;
}

void lab9(void)
{
	// list 1 is a b c
	ListNodePtr list1i3Ptr = malloc(sizeof(ListNode)); // third item of list 1
	list1i3Ptr->data = 'c';
	list1i3Ptr->nextPtr = NULL;

	ListNodePtr list1i2Ptr = malloc(sizeof(ListNode)); // second item of list 1
	list1i2Ptr->data = 'b';
	list1i2Ptr->nextPtr = list1i3Ptr;

	ListNodePtr list1Ptr = malloc(sizeof(ListNode)); // first item of list 1
	list1Ptr->data = 'a';
	list1Ptr->nextPtr = list1i2Ptr;

	// list 2 is e f g
	ListNodePtr list2i3Ptr = malloc(sizeof(ListNode)); // third item of list 2
	list2i3Ptr->data = 'g';
	list2i3Ptr->nextPtr = NULL;

	ListNodePtr list2i2Ptr = malloc(sizeof(ListNode)); // second item of list 2
	list2i2Ptr->data = 'f';
	list2i2Ptr->nextPtr = list2i3Ptr;

	ListNodePtr list2Ptr = malloc(sizeof(ListNode)); // first item of list 2
	list2Ptr->data = 'e';
	list2Ptr->nextPtr = list2i2Ptr;

	list2Ptr = concatLinkedList(list1Ptr, list2Ptr); // concat together, resulting in one list beginning at start of list 1

	ListNodePtr currentPtr = list1Ptr; // set current pointer to start of list 1

	printf("%s", "Concatenated list from list 1's pointer: ");
	while (currentPtr != NULL) // until NULL
	{
		printf("%c ", currentPtr->data); // print the character at the current node; should print "a b c e f g"
		currentPtr = currentPtr->nextPtr; // move up a node
	}

	currentPtr = list2Ptr; // set current pointer to start of list 2 (which should now be start of list 1)

	printf("\n%s", "Concatenated list from list 2's pointer: ");
	while (currentPtr != NULL) // same as previous loop
	{
		printf("%c ", currentPtr->data); // should print "a b c e f g"
		currentPtr = currentPtr->nextPtr;
	}
}

int mainm(void)
{
	lab9();
	return 0;
}