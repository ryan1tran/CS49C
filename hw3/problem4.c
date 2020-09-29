#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// strcpy using array subscripting
char* strcpyArr(char s1[], char s2[])
{
	for (int i = 0; i < strlen(s2) + 1; i++) // strlen(s2) + 1 accounts for terminating character
		s1[i] = s2[i]; // copy s2 to s1
	return s1;
}

// strcpy using pointers and pointer arithmetic
char* strcpyPtr(char* s1, char* s2)
{
	for (int i = 0; i < strlen(s2) + 1; i++) // same as Arr version
		*(s1 + i) = *(s2 + i); // except copy s2's dereferenced pointer values to s1
	return s1;
}

// strncpy using array subscripting
char* strncpyArr(char s1[], char s2[], size_t n)
{
	for (int i = 0; i < n; i++) // take first n characters of s2
		s1[i] = s2[i]; // and copy from s2 to s1
	s1[strlen(s1)] = '\0'; // append terminating character after the last character
	return s1;
}

// strncpy using pointers and pointer arithmetic
char* strncpyPtr(char* s1, char* s2, size_t n)
{
	for (int i = 0; i < n; i++) // same as Arr version
		*(s1 + i) = *(s2 + i); // except copy s2's dereferenced pointer values to s1 
	*(&s1 + 1) = '\0'; // append terminating character after the last character
	return s1;
}

// strcat using array subscripting
char* strcatArr(char s1[], char s2[])
{
	int originalLength = strlen(s1); // keep original length of s1
	for (int i = 0; i < strlen(s2) + 1; i++) // strlen(s2) + 1 accounts for the s2's terminating character
		s1[originalLength + i] = s2[i]; // concatenate s2 to end of s1
	return s1;
}

// strcat using pointers and pointer arithmetic
char* strcatPtr(char* s1, char* s2)
{
	int originalLength = strlen(s1); // keep original length of s1
	for (int i = 0; i < strlen(s2) + 1; i++) // same as Arr version
		*(s1 + originalLength + i) = *(s2 + i); // except concatentates s2's dereferenced pointer values to the end of s1 
	return s1;
}

// strncat using array subscripting
char* strncatArr(char s1[], char s2[], size_t n)
{
	int originalLength = strlen(s1); // keep original length of s1
	for (int i = 0; i < n; i++) // take first n characters of s2
		s1[originalLength + i] = s2[i]; // concatenate s2 to the end of s1
	s1[strlen(s1)] = '\0'; // append terminating character after the last character
	return s1;
}

// strncat using pointers and pointer arithmetic
char* strncatPtr(char* s1, char* s2, size_t n)
{
	int originalLength = strlen(s1); // keep original length of s1
	for (int i = 0; i < n; i++) // same as Arr version
		*(s1 + originalLength + i) = *(s2 + i); // except concatentates s2's dereferenced pointer values to the end of s1 
	*(&s1 + 1) = '\0'; // append terminating character after the last character
	return s1;
}

void hw3p4(void)
{
	char string1[] = {"problem "};
	char string2[] = { "four" };
	char string3[20] = { "" }; // char array for testing array subscripting functions
	char string4[20] = { "" }; // char array for testing pointer and pointer arithmetic functions

	printf("Original values:\nstring1: %s\nstring2: %s\nstring3: %s\nstring4: %s\n\n", string1, string2, string3, string4);

	strcpyArr(string3, string1); // copies "problem " to "" -> string3 = "problem "
	printf("Copying string1 to string3 using array subscripting:\nstring1: %s\nstring2: %s\nstring3: %s\nstring4: %s\n\n", string1, string2, string3, string4);
	strcpyPtr(string4, string1); // copies "problem " to "" -> string4 = "problem "
	printf("Copying string1 to string4 using pointers:\nstring1: %s\nstring2: %s\nstring3: %s\nstring4: %s\n\n", string1, string2, string3, string4);

	strncpyArr(string3, string2, 2); // copies "fo" to "problem " -> string3 = "fooblem "
	printf("Copying 2 characters of string2 to string3 using array subscripting:\nstring1: %s\nstring2: %s\nstring3: %s\nstring4: %s\n\n", string1, string2, string3, string4);
	strncpyPtr(string4, string2, 2); // copies "fo" to "problem " -> string4 = "fooblem "
	printf("Copying 2 characters of string2 to string4 using pointers:\nstring1: %s\nstring2: %s\nstring3: %s\nstring4: %s\n\n", string1, string2, string3, string4);

	strcatArr(string3, string2); // concats "four" to "fooblem " -> string3 = "fooblem four"
	printf("Concatenating string2 to string3 using array subscripting:\nstring1: %s\nstring2: %s\nstring3: %s\nstring4: %s\n\n", string1, string2, string3, string4);
	strcatPtr(string4, string2); // concats "four" to "fooblem " -> string4 = "fooblem four"
	printf("Concatenating string2 to string4 using pointers:\nstring1: %s\nstring2: %s\nstring3: %s\nstring4: %s\n\n", string1, string2, string3, string4);

	strncatArr(string3, string1, 3); // concats "pro" to "fooblem four" -> string3 = "fooblem fourpro"
	printf("Concatenating 3 characters of string1 to string3 using array subscripting:\nstring1: %s\nstring2: %s\nstring3: %s\nstring4: %s\n\n", string1, string2, string3, string4);
	strncatPtr(string4, string1, 3); // concats "pro" to "fooblem four" -> string4 = "fooblem fourpro"
	printf("Concatenating 3 characters of string1 to string4 using pointers:\nstring1: %s\nstring2: %s\nstring3: %s\nstring4: %s\n\n", string1, string2, string3, string4);

	if (strcmp(string3, string4) == 0) // print message if strings are equal or not
		printf("\"%s\" = \"%s\": Functions successful!\n", string3, string4);
	else
		printf("\"%s\" = \"%s\": Functions unsuccessful.\n", string3, string4);

	/*
		no sample cases
	*/
}

int main(void)
{
	hw3p4();
	return 0;
}