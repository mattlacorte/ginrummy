
/* * * * * * * * * * * * * * * * * * * * * * * * *
 * Function Definitions
 *
 *lol
 */
 
// #include "functions.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
 
 using namespace std;

 //class to store card suit, face, and value
 class Card {
 private:
	 int suit;		//will store suit type as int. 1 = hearts, 2 = diamonds, 3 = spades, 4 = clubs
	 int face;		//stores face of card as int. 1 = A, 2 = 2, 3 = 3, ..., 11 = J, 12 = Q, 13 = K
	 int val;		//stores value of card. A = 1, 2 = 2, ..., JQK = 10
 public:
	 Card(int progSuit, int progFace, int progVal){			//decleration with suit, face, and val
		 suit = progSuit;
		 face = progFace;
		 val = progVal;
	 }
	 Card() {
		 suit = 0;
		 face = 0;
		 val = 0;
	 }

	 //sort(vector<Card> &c);
	 //deadwood check
	 //knock check
	 //gin check

	 //overload > operator
	 //overload < operator
	 //overload == operator
	 //overload << operator
	 //overload = operator
 };

class Hand {
private:
	vector<Card> all(10);
	vector<Card> set;
	vector<Card> run;
	vector<Card> deadwood;
	int deadPoints;
public:
	Hand(Card &c) {
		all.push_back(c);
	}


};

 //initializes a deck of sorted cards
 void orderedInit(vector<Card> &c){

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

 //random generator function
 int myRandom(int i) {
	 return rand() % i;
 }

 //using a vector algorithm, cards get shuffled
 void vectorShuffle(vector<Card> &c) {
	 random_shuffle(c.begin(), c.end(), MyRandom);
 }
 
 //decided if user or computer will go first
 int startingDraw(vector<Card> &c){

	 int userNum;	//stores user num between 1 and 52
	 int compNum;	//stores comp num between 1 and 52

	 int winner;

	 do {

		 cout << "Choose a number between 1 and 52" << endl;
		 cin >> userNum;			//user's inputted num

		 compNum = rand() % 52 + 1;		//comp num between 1 and 52

	 } while ((userNum == compNum) && ((1 <= userNum) && (userNum <= 52)));		//loop for as long as user and comp numbers are the same, and not 1 <= userNum <= 52

	//overloaded operator to determine which is higher val
	 compCard = c(compNum);
	 userCard = c(userNum);

	 if (userCard > compCard) {
		 winner = 1;
	 }
	 else if (compCard < userCard) {
		 winner = 2;
	 }
	

	 return winner;
 }

//deals 10 cards to each player
 void dealCards(Hand &comp, Hand &user, vector<Card> &c) {
	 int j = 51;
	 for (int i = 0; i <= 10; i++, j = j - 2) {			//iterates 10 times
		 comp.all(c(j));								//fills comp hand	
		 user.all(c(j - 1));							//fills user hand
		 c.pop_back(j);
		 c.pop_back(j - 1);
	 }
	 //Add funtion for printing out Human Hand													
}

//sets the draw pile
void setDraw(vector<Card> &c, stack<Card> &d) {
	for (int i = 0; i < c.end(); i++) {
		d.push_back(c.end());
	}
}

//sets the discard pile
void setDiscard(stack<Card> &draw, stack<Card> &discard) {
	dicard.push_back(draw.end());
	draw.pop_back();
}

//clears screen
 void clear() {
	 system("CLS");
 }

//prints instructions
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

//prints main menu
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
