#include <iostream>     //needed for cin>>
#include <stdlib.h>       //needed for rand() and srand()
#include <time.h>         //needed for time()
#include <string.h>       //needed for strcpy()
#ifndef _BLACKJACKPLAYER_H
#define _BLACKJACKPLAYER_H
class BlackJackPlayer {

protected:
	int score; // sum of the two cards
	int win; // how many time the player won the game
	int lose; // how many time the player lost the game
	int tie; // how many time the player tie the game
	int card1; // player's card 1
	int card2; // player's card 2
	bool gotAce; //check to see got Ace
	char* name;  // player's name
	double winning;

public:
	BlackJackPlayer();
    bool gotBlackJack();
    void addTotal();
    void addTotal(int card);
    void addWon();
    void addLost();
    void addTie();
    void reset();
	int winPercent(int round);
    char *getName() const;
    virtual ~BlackJackPlayer();

    int getLose() const
    {
        return lose;
    }

    int getTie() const
    {
        return tie;
    }

    int getWin() const
    {
        return win;
    }

    double getWinning() const
    {
        return winning;
    }

    int getCard1() const
    {
        return card1;
    }

    int getCard2() const
    {
        return card2;
    }

    int getScore() const
    {
        return score;
    }

    bool isGotAce() const
    {
        return gotAce;
    }

    void setCard1(int card1)
    {
        this->card1 = card1;
    }

    void setCard2(int card2)
    {
        this->card2 = card2;
    }

    void setGotAce(bool gotAce)
    {
        this->gotAce = gotAce;
    }

    void setScore(int score)
    {
        this->score = score;
    }

};
#endif

#ifndef _PLAYER_H
#define _PLAYER_H
/*
 * Player class that contains all the player wants..
 * It derived from the BlackJackPlayer and currently used all the function
 * in the BlackJackPlayer. It can create it own function to handle specific
 * for the player such as eat buffet dinner after winning blackjack.
 */
class Player: public BlackJackPlayer {

public:
	Player();
	~Player();
};
#endif

#ifndef _DEALER_H
#define _DEALER_H
/*
 * Dealer class that contains all the dealer wants..
 * It derived from the BlackJackPlayer and currently used all the function
 * in the BlackJackPlayer. It can create it own function to handle specific
 * for the player such as get tip from the player if player wins.
 */
class Dealer: public BlackJackPlayer {

public:
	Dealer();
	~Dealer();
};
#endif
