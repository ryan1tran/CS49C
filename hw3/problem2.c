#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND 5

// bubble sort algorithm from slides
void bubble(int cardValue[], int size)
{
	int swaps = 0; // counter of swaps

	// loop to control passes
	for (unsigned int pass = 1; pass < size; pass++)
	{
		for (size_t i = 0; i < size - 1; i++) // loop through array
		{
			if (cardValue[i] > cardValue[i + 1]) // swap if larger value first
			{
				int hold = cardValue[i];
				cardValue[i] = cardValue[i + 1];
				cardValue[i + 1] = hold;

				swaps++; // increment swaps
			}
		}

		if (swaps == 0) // if no swaps, already sorted, so exit
			break;
	}
}

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
	// for each of the cards, choose slot of deck randomly
	for (size_t card = 1; card <= HAND; card++)
	{
		size_t row; // row number
		size_t column; // column number

		// choose new random location until unoccupied slot found
		do
		{
			row = rand() % SUITS;
			column = rand() % FACES;
		} while (wDeck[row][column] != 0);

		// place card number in chosen slot of deck
		wDeck[row][column] = card;
	}
}

// determines what poker hand you have
void determineHand(int cardValue[HAND], int cardSuit[HAND], const char* wFace[], const char* wSuit[])
{
	// loop for every pair and print if matched
	for (size_t i = 0; i < HAND; i++)
		for (size_t j = i + 1; j < HAND; j++)
			if (cardValue[i] == cardValue[j])
				printf("You have a pair: %s of %s and %s of %s!\n", wFace[cardValue[i]], wSuit[cardSuit[i]], wFace[cardValue[j]], wSuit[cardSuit[j]]);

	// loop for three cards and print if matched
	for (size_t i = 0; i < HAND; i++)
		for (size_t j = i + 1; j < HAND; j++)
			for (size_t k = j + 1; k < HAND; k++)
				if (cardValue[i] == cardValue[j] && cardValue[j] == cardValue[k])
					printf("You have a three of a kind: %s of %s, %s of %s, and %s of %s!\n", wFace[cardValue[i]], wSuit[cardSuit[i]], wFace[cardValue[j]], wSuit[cardSuit[j]], wFace[cardValue[k]], wSuit[cardSuit[k]]);

	// loop for four cards and print if matched
	for (size_t i = 0; i < HAND; i++)
		for (size_t j = i + 1; j < HAND; j++)
			for (size_t k = j + 1; k < HAND; k++)
				for (size_t l = k + 1; l < HAND; l++)
					if (cardValue[i] == cardValue[j] && cardValue[j] == cardValue[k] && cardValue[k] == cardValue[l])
						printf("You have a four of a kind: %s of %s, %s of %s, %s of %s, and %s of %s!\n", wFace[cardValue[i]], wSuit[cardSuit[i]], wFace[cardValue[j]], wSuit[cardSuit[j]], wFace[cardValue[k]], wSuit[cardSuit[k]], wFace[cardValue[l]], wSuit[cardSuit[l]]);

	// loop for whole hand and check if all same suits
	int suitVal = cardSuit[0]; // take suit of first card
	for (size_t i = 1; i < HAND; i++)
	{
		if (cardSuit[i] != suitVal) // break on first mismatch
			break;

		if (i == HAND - 1) // if reached the end of the loop, success and print
			printf("You have a flush: %s, %s, %s, %s, and %s of %s!\n", wFace[cardValue[0]], wFace[cardValue[1]], wFace[cardValue[2]], wFace[cardValue[3]], wFace[cardValue[4]], wSuit[0]);
	}

	// sort the card values in ascending order first to simply process
	bubble(cardValue, HAND);
	
	// check if the hand is consecutive
	if (cardValue[0] == (cardValue[1] - 1) && cardValue[1] == (cardValue[2] - 1) && cardValue[2] == (cardValue[3] - 1) && cardValue[3] == (cardValue[4] - 1))
		printf("You have a straight: %s of %s, %s of %s, %s of %s, %s of %s, and %s of %s!\n", wFace[cardValue[0]], wSuit[cardSuit[0]], wFace[cardValue[1]], wSuit[cardSuit[1]], wFace[cardValue[2]], wSuit[cardSuit[2]], wFace[cardValue[3]], wSuit[cardSuit[3]], wFace[cardValue[4]], wSuit[cardSuit[4]]);
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES], const char* wFace[], const char* wSuit[])
{
	int cardValue[HAND] = { 0 };
	unsigned int valueCount = 0;
	int cardSuit[HAND] = { 0 };
	unsigned int suitCount = 0;

	bool esc = false; // condition to exit inner two loops

	printf("%s\n", "Your hand:");

	// deal a five-card poker hand
	for (size_t card = 1; card <= HAND; card++)
	{
		esc = false; // reset condition on start of loop

		// loop through rows of wDeck
		for (size_t row = 0; row < SUITS; row++)
		{
			// loop through columns of wDeck for current row
			for (size_t column = 0; column < FACES; column++)
			{
				// if slot contains current card, display card
				if (wDeck[row][column] == card)
				{
					cardValue[valueCount++] = column;
					cardSuit[suitCount++] = row;
					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t'); // 2-column format (prints 5 card hand)
					esc = true; // card found, exiting two loops
				}

				if (esc)
					break; // exit first loop
			}

			if (esc)
				break; // exit second loop
		}
	}

	puts("");

	determineHand(cardValue, cardSuit, wFace, wSuit);
}

void hw3p2(void)
{
	srand((int)time(NULL)); // seed random-number generator

	const char* suit[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* face[FACES] =
	{
		"Ace", "Two", "Three", "Four",
		"Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King"
	};

	//for (int i = 0; i < 100; i++)
	//{
		// initialize deck array
		unsigned int deck[SUITS][FACES] = { 0 }; // when used in loop, resets deck to all 0's to avoid repeated cards from previous hands
		shuffle(deck); // shuffle the deck
		deal(deck, face, suit);
		puts("");
	//}

	/*
		no sample cases, but feel free to use the commented-out loop to test many hands
	*/
}

int main(void)
{
	hw3p2();
	return 0;
}