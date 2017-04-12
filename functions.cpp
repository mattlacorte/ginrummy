/* * * * * * * * * * * * * * * * * * * * * * * * *
 * Function Definitions
 *
 *
 */
 
// #include "functions.h"
#include <iostream>
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

 void OrderedInit(/*****VECTOR of type CARD*****/ vector<Card> &c){

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

 void CardShuffle(/*****VECTOR of type CARD*****/ vector<Card> &c){

	 vector<Card> temp(52);		//creates second vector as temp storage
		
	 for (int i = 0; i < 52; i++) {		//temp = init vector
		 temp[i] = c[i];
		}

		//randomly assign temp vals to the passed vector

	 int shuffledOrder[52];
	 int tempShuffleVal;
	 bool checkRepeat;

	 for (int i = 0; i < 52; i++) {					//RECHECK THIS FOR LOGIC ERRORS***************************

		 do {

			 tempShuffleVal = (rand() % 52) + 1;

			 for (int j = 0; j < i; j++) {
				 if (tempShufleVal = shuffleOrder[i]) {
					 checkRepeat = true;
					 break;
				 }
			 }
		 } while (checkRepeat);	//checkRepeat = true if there is a repeat

		 shuffledOrder[i] = tempShuffleVal;

		 //assign new card order to shuffled vector


 }
 
 int startingDraw(/*****VECTOR of type CARD*****/ vector<Card> &c){

	 //user chooses 1-52 as if picking a card from a hand
		//computer picks a card as well. NOT THE SAME AS USER
		//overloaded operator to determine which is higher val

	 //return user or comp
 }

 void dealCards(vector<Card> &AI, vector<Card> &Human, vector<Card> &c) {
	 int j = 0;
	 for (int i = 0; i <= 10; i++, j = j + 2) {			//iterates 10 times to fill the hand of the AI
		 AI.at(i) = Card.at(j);
	 }
	 int g = 1;
	 for (int k = 1; k <= 10; k++, g = g + 2) {		    //iterates 10 times to fill the hand of the Human
		 Human.at(k) = Card.at(g);
	 }
	 //Add funtion for printing out Human Hand													
 }

 string PrintCard(Card temp) {

 }

