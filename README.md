BlackJack Program

This is a command-line blackjack game using C++. 

Requirements.
1. Dealer must hit on soft 17
2. Single Deck. The deck is shuffled every 6 rounds.
3. Player is not allowed to split cards
4. Keep track of win percentage of the player.

Classes Description.

The program defines following classes:

BlackJackPlayer - Base class for the Player and Dealer
Player - Player class contains the player's functions and inherits from the BlackJackPlayer. 
Dealer - Dealer class contains the dealer's functions and inherits from the BlackJackPlayer.
Cards  - A deck of the cards contains 52 cards.
Card   - A single card that has name and value.
Display - Display utility function that is responsible for displaying the output
Game - BlackJack Game includes two players.

Header file defines the classes. Please review the defintion in each header files.

Program runs:

The program starts to display the rules. The cards are shuffled before it will be
used.  The Game initializes two dealed Cards to the BlackJackPlayer (Player and the Dealer). 
Once the cards are received by the BlackJackPlayer. BlackJackPlayer calculates 
the total of two cards. If blackjack is found, the program displays the winner and 
displays the winning percentage of the winner. 

Player has option to hit or pass and the Dealer must hit on soft 17. 

Environments:

This program is built on Mac OS 10. It used Esclipse CDT as a development tool.
An makefile is used to build the system. The final program is called blackjack. 
A pre-compiled Mac OS version of blackjack is built under Debug directory. You can run it by
doing following:

cd Debug
./blackjack

To recompile it, you need to perform following:

cd Debug.
make clean
make 

Improvement:

1. Card class is not fully implemented yet. It is an object that can improved to display
the name. The deck of cards should contains 52 cards with name and value. At this moment, 
the name function is not implemented yet, only the value is implemented.

2. Use Doxygen to generate the interface documentation.

3. Remove the Debug direction and build an individual makefile.

Sample output:

*********************************************************
Blackjack Program                  
Here are the rules: 
21 means an automatic win.
Deal must hit on soft 17.
Single deck card and the deck is shuffled every 6 rounds.
Player is not allowed to split cards.
*********************************************************
 Cards are shuffling
 Cards are shuffled.
*********************************************************
You got 3,10 Score: 13
Dealer got 9,10 Score: 19
*********************************************************
Would you like to Hit or Pass? Press (h/p)
h
You got hit card 5
*********************************************************
Your got 18
Dealer got 19
*********************************************************
Would you like to Hit or Pass? Press (h/p)
h
You got hit card 10
*********************************************************
Your got 28
Dealer got 19
You lost
*********************************************************
Your record:
*********************************************************
Round played: 1
Win:          0
Lose:         1
Tie:          0
Winning Percentage: 0 % 
*********************************************************
*********************************************************
Game Over. Wanna to try again? Press (y/n)
y
Start New Game.....
*********************************************************
You got 6,6 Score: 12
Dealer got 10,8 Score: 18
*********************************************************
Would you like to Hit or Pass? Press (h/p)
h
You got hit card 10
*********************************************************
Your got 22
Dealer got 18
You lost
*********************************************************
Your record:
*********************************************************
Round played: 2
Win:          0
Lose:         2
Tie:          0
Winning Percentage: 0 % 
*********************************************************
*********************************************************
Game Over. Wanna to try again? Press (y/n)
y
Start New Game.....
*********************************************************
You got 4,10 Score: 14
Dealer got 7,8 Score: 15
*********************************************************
Would you like to Hit or Pass? Press (h/p)
h
You got hit card 4
*********************************************************
Your got 18
Dealer got 15
*********************************************************
Would you like to Hit or Pass? Press (h/p)
p
Dealer has 22
*********************************************************
Your got 18
Dealer got 22
You win
*********************************************************
Your record:
*********************************************************
Round played: 3
Win:          1
Lose:         2
Tie:          0
Winning Percentage: 33 % 
*********************************************************
*********************************************************
Game Over. Wanna to try again? Press (y/n)
y
Start New Game.....
*********************************************************
You got 3,10 Score: 13
Dealer got 10,11 Score: 21
Dealer got BlackJack!!
You lost
*********************************************************
Your record:
*********************************************************
Round played: 4
Win:          1
Lose:         3
Tie:          0
Winning Percentage: 25 % 
*********************************************************
*********************************************************
Game Over. Wanna to try again? Press (y/n)
y
Start New Game.....
*********************************************************
You got 2,10 Score: 12
Dealer got 7,9 Score: 16
*********************************************************
Would you like to Hit or Pass? Press (h/p)
h
You got hit card 2
*********************************************************
Your got 14
Dealer got 16
*********************************************************
Would you like to Hit or Pass? Press (h/p)
h
You got hit card 9
*********************************************************
Your got 23
Dealer got 16
You lost
*********************************************************
Your record:
*********************************************************
Round played: 5
Win:          1
Lose:         4
Tie:          0
Winning Percentage: 20 % 
*********************************************************
*********************************************************
Game Over. Wanna to try again? Press (y/n)
y
Start New Game.....
*********************************************************
You got 5,4 Score: 9
Dealer got 5,8 Score: 13
*********************************************************
Would you like to Hit or Pass? Press (h/p)
h
You got hit card 9
*********************************************************
Your got 18
Dealer got 13
*********************************************************
Would you like to Hit or Pass? Press (h/p)
p
Dealer has 14
Dealer has 15
Dealer has 21
*********************************************************
Your got 18
Dealer got 21
You lost
*********************************************************
Your record:
*********************************************************
Round played: 6
Win:          1
Lose:         5
Tie:          0
Winning Percentage: 16 % 
*********************************************************
*********************************************************
Game Over. Wanna to try again? Press (y/n)
y
Start New Game.....
 Cards are shuffling
 Cards are shuffled.
Restart the round to zero.
*********************************************************
You got 10,3 Score: 13
Dealer got 5,10 Score: 15
*********************************************************
Would you like to Hit or Pass? Press (h/p)
h
You got hit card 1
*********************************************************
Your got 14
Dealer got 15
*********************************************************
Would you like to Hit or Pass? Press (h/p)
h
You got hit card 8
*********************************************************
Your got 22
Dealer got 15
You lost
*********************************************************
Your record:
*********************************************************
Round played: 1
Win:          1
Lose:         6
Tie:          0
Winning Percentage: 100 % 
*********************************************************
*********************************************************
Game Over. Wanna to try again? Press (y/n)

