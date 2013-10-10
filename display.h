#ifndef _DISPLAY_H
#define _DISPLAY_H
#include "BlackJackPlayer.h"
class Display {

   // no contructor, use default
   public:
      void rules();
      void hitOrPass(char *wantCard);
      void gameOver(char *tryAgain);
      void win();
      void lost();
      void tie();
      void bye();
      void result(Player player, Dealer dealer);
      void record(Player player, int round);
      void score(Player player, Dealer dealer);
      void blackJack(BlackJackPlayer blackjackplayer);
};
#endif
