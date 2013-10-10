#include <iostream>     //needed for cin>>
#include <stdlib.h>       //needed for rand() and srand()
#include <time.h>         //needed for time()
#include <string.h>       //needed for strcpy()
#include "display.h"

using namespace std;

void Display::rules() {
	cout << "*********************************************************" << endl;
	cout << "Blackjack Program                  " << endl;
	cout << "Here are the rules: " << endl;
	cout << "21 means an automatic win." << endl;
	cout << "Deal must hit on soft 17." << endl;
	cout << "Single deck card and the deck is shuffled every 6 rounds." << endl;
	cout << "Player is not allowed to split cards." << endl;
	cout << "*********************************************************" << endl;
}

void Display::result(Player player, Dealer dealer) {
	cout << "*********************************************************" << endl;
	cout << "You got " << player.getCard1() << "," << player.getCard2()
		 <<	" Score: "  << player.getScore() << endl;
	cout << "Dealer got " << dealer.getCard1() << "," << dealer.getCard2()
	     << " Score: " << dealer.getScore() << endl;
}

void Display::hitOrPass(char *wantCard) {
	cout << "*********************************************************" << endl;
	cout << "Would you like to Hit or Pass? Press (h/p)" << endl;
	cin >> *wantCard;
}

void Display::gameOver(char *tryAgain) {
	cout << "*********************************************************" << endl;
	cout << "Game Over. Wanna to try again? Press (y/n)" << endl;
	cin >> *tryAgain;
}

void Display::score(Player player, Dealer dealer) {
	cout << "*********************************************************" << endl;
	cout << "Your got " << player.getScore() << endl;
	cout << "Dealer got " << dealer.getScore() << endl;
}

void Display::blackJack(BlackJackPlayer player) {
	cout << player.getName() << " got BlackJack!!" << endl;
}

void Display::win() {
	cout << "You win" << endl;
}

void Display::lost() {
	cout << "You lost" << endl;
}

void Display::tie() {
	cout << "It's tie!" << endl;
}

void Display::bye() {
	cout << "Bye... Thanks for playing" << endl;
}

void Display::record(Player player, int round) {
	cout << "*********************************************************" << endl;
	cout << "Your record:" << endl;
	cout << "*********************************************************" << endl;
	cout << "Round played: " << round << endl;
	cout << "Win:          " << player.getWin() << endl;
	cout << "Lose:         " << player.getLose() << endl;
	cout << "Tie:          " << player.getTie() << endl;
	cout << "Winning Percentage: " << player.winPercent(round) <<  " % " << endl;
	cout << "*********************************************************" << endl;
}

