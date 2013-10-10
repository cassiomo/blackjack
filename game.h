#ifndef _GAME_H
#define _GAME_H
#include "blackjackplayer.h"
#include "cards.h"
#include "display.h"
/*
 * Game - class defines the BlackJack game. It is responsbile to start, play,
 * dealCards, decideWhoWin, hit, pass, over and maintain the state of the game.
 *
 * Each game has two players - Dealer and Player.
 */
class Game {

private:
	int round;  // number of rounds that players and dealer play
	int dealCardIndex; // the dealcards index
	bool needCheckBlackJack; // check the blackjack state if two cards received
	char hitOrPass; // player option to hit or pass
	char tryAgain; // player option to tryAgain
	Player player; // Player class
	Dealer dealer; // Dealer class
	Display display; // Display class
	Cards cards; // Cards class

public:

	Game();
	bool finish;  // game finished flag
	void maintain();  // maintain state  - running forever until end
	void start(); // game starts
	void play();  // game plays
	int dealCards(); // deal cards
	void decideWhoWin(); // decide who win
	void hit();  // hit card function
	void pass(); // pass card fucntion
	void over(); // game over
	~Game();   // game destructor
};
#endif
