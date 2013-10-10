#include <iostream>     //needed for cin>>
#include <stdlib.h>       //needed for rand() and srand()
#include <time.h>         //needed for time()
#include <string.h>       //needed for strcpy()
#include "cards.h"

using namespace std;

/*
 *  Cards constructor to initialize the all the cards value.
 */
Cards::Cards() {
	int index, l;

	//Spades
	for (index = 1; index <= 10; index++) {
		cards[index] = index;
	}

	cards[11] = 10; //Values for Jack Queen King
	cards[12] = 10;
	cards[13] = 10;

	l = 1;
	//Hearts
	for (index = 14; index <= 23; index++) {

		cards[index] = l;
		l++;
	}

	cards[24] = 10; //Values for Jack Queen King
	cards[25] = 10;
	cards[26] = 10;

	l = 1;
	//Diamonds
	for (index = 27; index <= 36; index++) {
		cards[index] = l;
		l++;
	}

	cards[37] = 10; //Values for Jack Queen King
	cards[38] = 10;
	cards[39] = 10;

	l = 1;
	//Club
	for (index = 40; index <= 49; index++) //Fills an array with values of the value Ace-10. Here Ace is 1.
			{
		cards[index] = l;
		l++;
	}

	cards[50] = 10; //Values for Jack Queen King
	cards[51] = 10;
	cards[52] = 10;
}

/*
 * Cards to get the shuffle cards
 */
int Cards::getCard(int cardIndex) {
	return cards[cardIndex];
}

/*
 * Cards shuffle the cards
 */
void Cards::shuffle() {
	int j, k, temp;

	cout << " Cards are shuffling" << endl;
	srand((unsigned) time(NULL)); //Seeds rand()

	j = 52;
	// put the algorithm to shuffle the card.
	// random value first and start to shuffle the card
	while (j > 0)
	{
		// random value between 1 and j
		k = rand() % j + 1;

		temp = cards[j];

		cards[j] = cards[k];

		cards[k] = temp;

		j--;
	}
	cout << " Cards are shuffled." << endl;
}
