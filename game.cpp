#include <iostream>     //needed for cin>>
#include <stdlib.h>       //needed for rand() and srand()
#include <time.h>         //needed for time()
#include <string.h>       //needed for strcpy()
#include "game.h"

using namespace std;

Game::Game() {
	round = 1;
	dealCardIndex = 0;
	finish = false;
	needCheckBlackJack = false;
}

Game::~Game() {
	round = 0;
	dealCardIndex = 0;
	needCheckBlackJack = false;
	cout << "Game object destructor is called " << endl;
}

/*
 * The game starts with rule and cards shuffle
 */
void Game::start() {
	display.rules();
	cards.shuffle();
}

/*
 * The game starts to play, initializes two cards and game decide who to win
 */
void Game::play() {
	// deal twos cards to the players randomly

	// player gets the first card
	player.setCard1(dealCards());

	// dealer gets the fist card
	dealer.setCard1(dealCards());

	// player gets the second card
	player.setCard2(dealCards());

	// dealer gets the second card
	dealer.setCard2(dealCards());

	// player sees the cards and add two cards' value together
	player.addTotal();

	// dealer sees the cards and add two cards' value together
	dealer.addTotal();

	// display the result to the user
	display.result(player, dealer);

	// ask the user for further card if needed
	decideWhoWin();
}

/*
 *  Game deal cards
 */
int Game::dealCards() {
	// return a card in an array
	dealCardIndex = dealCardIndex + 1;
	return cards.getCard(dealCardIndex);
}

/*
 * Game decides who to win
 */
void Game::decideWhoWin() {

	if (!needCheckBlackJack) {
		if (player.gotBlackJack() && !dealer.gotBlackJack()) {
			display.blackJack(player);
			display.win();
			player.addWon();
			over();
		} else if (dealer.gotBlackJack() && !player.gotBlackJack()) {
			display.blackJack(dealer);
			display.lost();
			player.addLost();
			over();
		} else if (player.gotBlackJack() && dealer.gotBlackJack()) {
			display.tie();
			player.addTie();
			over();
		} else {
			// check the blackjack status for both player and dealer
			needCheckBlackJack = true;
			// show player current hands and check with him
			display.hitOrPass(&hitOrPass);
		}
	}

	// Player has option to hit or pass
	if (((hitOrPass == 'H') || (hitOrPass == 'h')) && needCheckBlackJack) {
		hit();
	} else if (((hitOrPass == 'P') || (hitOrPass == 'p')) && needCheckBlackJack) {
		pass();
	} else {
		cout << "Not valid input command. Please try again!" << endl;
		display.hitOrPass(&hitOrPass);
		decideWhoWin();
	}
}

/*
 * Game hits and let the player to get more cards
 */
void Game::hit() {
	int card = dealCards();

	cout << "You got hit card " << card << endl;
	player.addTotal(card);
	if (player.getScore() >= 22) {
		display.score(player, dealer);
		display.lost();
		player.addLost();
		over();
	} else if (player.getScore() == 21) {
		display.score(player, dealer);
		display.win();
		player.addWon();
		over();
	} else if (player.getScore() <= 20) {
		display.score(player, dealer);
		display.hitOrPass(&hitOrPass);
		decideWhoWin();
	}
}

/*
 * Game passes and let the player to pass. Dealer must hit 17
 */
void Game::pass() {
	while (dealer.getScore() <= 16) {
		// get new card
		int card = dealCards();
		dealer.addTotal(card);
		cout << "Dealer has " << dealer.getScore() << endl;
	}

	if (dealer.getScore() >= 22) {
		display.score(player, dealer);
		display.win();
		player.addWon();
		over();
	} else if (dealer.getScore() == 21) {
		display.score(player, dealer);
		display.lost();
		player.addLost();
		over();
	} else if ((dealer.getScore() > player.getScore())
			&& (dealer.getScore() <= 20)) {
		display.score(player, dealer);
		display.lost();
		player.addLost();
		over();
	} else if (dealer.getScore() == player.getScore()) {
		display.score(player, dealer);
		display.tie();
		player.addTie();
		over();
	} else if (dealer.getScore() < player.getScore()) {
		display.score(player, dealer);
		display.win();
		over();
	}
}

/*
 * Game maintains running state until player decides to quit
 */
void Game::maintain() {

}

/*
 * Game over - display the result of each hand
 */
void Game::over() {

	display.record(player, round);
	display.gameOver(&tryAgain);

	while ((tryAgain != 'Y') && (tryAgain != 'y') && (tryAgain != 'N')
			&& (tryAgain != 'n')) {
		cout << "****************************" << endl;
		cout << "Not valid input command. Please try again!" << endl;
		cin >> tryAgain;
	}

	if ((tryAgain == 'Y' || tryAgain == 'y')) {
		cout << "Start New Game....." << endl;
		needCheckBlackJack = false;
		player.reset();
		dealer.reset();
		// The deck is shuffled every 6 rounds
		if (round > 5) {
			cards.shuffle();
			cout << "Restart the round to zero." << endl;
			round = 0;
		}
		round++;
		play();
	} else {
		finish = true;
	}
}
