/* * * * * * * * * * * * * * * * * * * * * * * * *
 * Function Definitions
 *
 *
 */
 
// #include "functions.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
 
 using namespace std;


 class Card {
 private:
	 int suit;		//will store suit type as int. 1 = hearts, 2 = diamonds, 3 = spades, 4 = clubs
	 int face;		//stores face of card as int. 1 = A, 2 = 2, 3 = 3, ..., 11 = J, 12 = Q, 13 = K
	 int val;		//stores value of card. A = 1, 2 = 2, ..., JQK = 10
 public:
	 Card(int progSuit, int progFace, int progVal){			//decleration with suit, face, and val
		 suit = progSuit;
		 face = progSuit;
		 val = progVal;
	 }
	 //sort function
	 //deadwood check
	 //knock check
	 //gin check

	 //overloaded >= operator
	 //overload == operator
 };

 void OrderedInit(vector<Card> &c){

	 //initialize 52 cards, in order
		//uses nested for loops

	 for (int i = 0; i < 4; i++) {
		 for (int j = 0; j < 13; j++) {
			 int tempSuit;
			 int tempFace;
			 int tempVal;

			 tempSuit = i;
			 tempFace = j;
			 
			 if (j < 10) {		//if elses to assign card value. If JQK, val = 10
				 tempVal = j;
			 }
			 else if (j >= 10) {
				 tempVal = 10;
			 }
			 else {
				 cout << "FIXME: Error in OrderedInit declaring card values" << endl;
			 }

			 c.push_back(Card(tempSuit, tempFace, tempVal)));		//inputs them into the passed vector
		 }
	 }
 }

 
 int startingDraw(vector<Card> &c){

	 //user chooses 1-52 as if picking a card from a hand
		//computer picks a card as well. NOT THE SAME AS USER
		//overloaded operator to determine which is higher val

	 //return user or comp
 }

 string PrintCard(Card temp) {

 }

 void clear() {
	 system("CLS");
 }

 void instructions() {
	 clear();

	 cout << endl;
	 cout << "GIN RUMMY INSTRUCTIONS" << endl;
	 cout << "*************************" << endl;
	 cout << endl;
	 cout << "Goal: Collect a hand where most or all of the cards can be combined" << endl;
	 cout << "      into runs or sets and there are few unmatched cards.         " << endl;
	 cout << endl;
	 cout << "      A 'run' consists of three or more cards of the same suit in  " << endl;
	 cout << "      consecuitve order such as: 4C 5C 6C.                         " << endl;
	 cout << endl;
	 cout << "      A 'set' consists of three or more cards of the same rank such" << endl;
	 cout << "      as: 7D 7H 7S.                                                " << endl;
	 cout << endl;
	 cout << "Play: First, draw a card from either the discard pile, or stock    " << endl;
	 cout << "      pile. The top card of the discard pile is visible, unlike the" << endl;
	 cout << "      stock pile.                                                  " << endl;
	 cout << "      Then, discard one card from your deck. If you took a card    " << endl;
	 cout << "      from the discard pile, it can not be discarded for the turn. " << endl;
	 cout << "      The round ends when the stock pile is reduced to 2 cards or a" << endl;
	 cout << "      player knocks.                                               " << endl;
	 cout << endl;

	 system("pause");
	 clear();

	 cout << endl;
	 cout << "GIN RUMMY INSTRUCTIONS" << endl;
	 cout << "*************************" << endl;
	 cout << endl;
	 cout << "Knocking: You can end the round on your turn if you have sufficient" << endl;
	 cout << "          cards to form at least one set or run and the remaining  " << endl;
	 cout << "          unmatched cards' total value is equal to or less than 10." << endl;
	 cout << "          Aces are worth 1, number cards are worth their given     " << endl;
	 cout << "          value, and face cards are worth 10.                      " << endl;
	 cout << "          If all the cards in your hand are part of a set or run,  " << endl;
	 cout << "          you've gone gin.                                         " << endl;
	 cout << endl;
	 cout << "Scoring:  Each player counts the value of their unmatched cards,   " << endl;
	 cout << "          also known as deadwood. If the value of the knocker's    " << endl;
	 cout << "          deadwood is lower, the knocker scores the difference     " << endl;
	 cout << "          between the two counts.                                  " << endl;
	 cout << "          If the counts are equal, or the the knocker's count is   " << endl;
	 cout << "          higher than their opponent, the opponent scores the      " << endl;
	 cout << "          difference plus a 10 point bonus.                        " << endl;
	 cout << "          If the knocker goes gin, they get a 20 point bonus plus  " << endl;
	 cout << "          the value of their opponent's deadwood.                  " << endl;
	 cout << "          The game is repeated until a player reaches 30 points.   " << endl;
	 cout << endl;
	 system("pause");
	 mainMenu();
 }

 void mainMenu() {
	 clear();

	 int mainMenuChoice;

	 cout << endl;
	 cout << "**************************" << endl;
	 cout << "   WELCOME TO GIN RUMMY   " << endl;
	 cout << "**************************" << endl;
	 cout << endl;
	 cout << "1. Begin Game" << endl;
	 cout << endl;
	 cout << "2. Instructions" << endl;
	 cout << endl;
	 cout << "3. Exit Menu" << endl;
	 cout << endl;
	 cin >> mainMenuChoice;

	 if (mainMenuChoice == 1) {
		 cout << "BEGINNING GAME" << endl; //ADD FUNCTION REQUEST THAT BEGINS GAME
	 }
	 else if (mainMenuChoice == 2) {
		 instructions();
	 }
	 else if (mainMenuChoice == 3) {
		 exit(1);
	 }
 }