#ifndef _CARDS_H
#define _CARDS_H

using namespace std;
/*
 * Card - need to implement the name and used in the future.
 */
class Card {

private:
	int value;  // card's value
	char name;  // card's name

public:
	Card();
    char getName() const
    {
        return name;
    }

    int getValue() const
    {
        return value;
    }

    void setName(char name)
    {
        this->name = name;
    }

    void setValue(int value)
    {
        this->value = value;
    }
	~Card() {};
};

/*
 * Cards class that performs two functions
 * 1. Shuffles.
 * 2. getCards.
 */
class Cards {

	// array of cards' values
	//Spades, Hearts, Clubs, Diamonds,
	//Ace =1, Jack-Queen-King=10
	int cards[53];
	//Card cards[53];

public:
	Cards();
	void shuffle();
	int getCard(int cardIndex);
	~Cards() {};
};
#endif
