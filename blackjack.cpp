#include <iostream>     //needed for cin>>
#include <stdlib.h>       //needed for rand() and srand()
#include <time.h>         //needed for time()
#include <string.h>       //needed for strcpy()
#include "Game.h";

using namespace std;

/*
 * Main program that starts the Game.
 */
int main() {

	Game game;
	game.start();
	game.play();
	while (!game.finish) {
		game.maintain();
	}
	return 0;

}
