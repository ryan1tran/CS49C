#include <stdlib.h>

float toCelsius(float fahrenheit) // name changed for more clarity
{
	return (fahrenheit - 32) * 5 / 9; // formula for conversion
}

float toFahrenheit(float celsius) // name changed for more clarity
{
	return (celsius * 9 / 5) + 32; // formula for conversion
}

void hw2p1(void)
{
	printf("%11s%15s\n----------------------------\n", "Fahrenheit", "Celsius"); // formatting for table format
	for (int i = 0; i <= 100; i++)
		printf("%11d%15.4f\n", i, toCelsius(i));

	puts("");

	printf("%8s%18s\n----------------------------\n", "Celsius", "Fahrenheit"); // formatting for table format
	for (int i = 32; i <= 212; i++)
		printf("%8d%18.4f\n", i, toFahrenheit(i));

	/*
		no sample cases
	*/
}

int main(void)
{
	hw2p1();
	return 0;
}