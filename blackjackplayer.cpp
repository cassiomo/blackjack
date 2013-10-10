#include <iostream>     //needed for cin>>
#include <stdlib.h>       //needed for rand() and srand()
#include <time.h>         //needed for time()
#include <string.h>       //needed for strcpy()
#include "blackjackplayer.h"

using namespace std;

Player::Player() {
	name = "You";
}

Player::~Player() {

}

Dealer::Dealer() {
	name = "Dealer";
}

Dealer::~Dealer() {
}

BlackJackPlayer::BlackJackPlayer() {
	score = 0; // sum of the two cards
	win = 0; // how any time the player won the game
	lose = 0; // how many time the player lost the game
	tie = 0; // how many time the player tie the game
	card1 = 0;  // card 1
	card2 = 0; // card2
	gotAce = false; //check to see got Ace
}

BlackJackPlayer::~BlackJackPlayer() {
}

/*
 * BlackJackPlayer adding the winning number
 */
void BlackJackPlayer::addWon() {
	win = win + 1;
}

/*
 * BlackJackPlayer adding the losing number
 */
void BlackJackPlayer::addLost() {
	lose = lose + 1;
}

/*
 * BlackJackPlayer gets the name of the player
 */
char *BlackJackPlayer::getName() const
{
    return name;
}

/*
 * BlackJackPlayer calculates the winning percentage.
 */
int BlackJackPlayer::winPercent(int round) {
	double winning = ((double) win) / round;
	return winning * 100;
}

/*
 * BlackJackPlayer resets when the new game starts
 */
void BlackJackPlayer::reset() {
	score = 0;
	card1 = 0;
	card2 = 0;
	gotAce = false;
}

/*
 * BlackJackPlayer adding tie number
 */
void BlackJackPlayer::addTie() {
	tie = tie + 1;
}

/*
 * BlackJackPlayer, adding additional cards up.
 */
void BlackJackPlayer::addTotal(int card) {

	if (card == 1) {
		if (score <= 10) {
			gotAce = true;
			score = score + 11;
		} else {
			score = score + 1;
		}
	} else {
		score = score + card;
	}

	// show bigger && gotAce
	if ((score >= 22) && (gotAce)) {
		score = score - 10;
		gotAce = false;
	}
}
/*
 *  BlackJack Player, adding initial two cards value up.
 */
void BlackJackPlayer::addTotal() {
	score = card1 + card2;
	// card1 ace, make it 11
	if (card1 == 1) {
		gotAce = true; // got Ace in the first card
		card1 = card1 + 10;
		score = card1 + card2;
	}

	// card2 ace, decide to make 1 or 11
	if (card2 == 1) {
		if (card1 != 11) {
			gotAce = true;
			card2 = card2 + 10;
			score = card1 + card2;
		} else {
			card2 = 1;
			score = card1 + card2;
		}
	}
}

/*
 * BlackJackPlayer detemines whether the player got blackjack
 */
bool BlackJackPlayer::gotBlackJack() {
	if (score == 21) {
		return true;
	}
	return false;
}

