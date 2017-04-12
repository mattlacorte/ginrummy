#pragma once

/* * * * * * * * * * * * * * * * * * *
* Header Files
*
*
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H


//declare all functions here

class Card {		/*****UNSURE OF WHETHER OR NOT THIS SHOULD BE HERE*****/
private:
	int suit;		//will store suit type as int. 1 = hearts, 2 = diamonds, 3 = spades, 4 = clubs
	int face;		//stores face of card as int. 1 = A, 2 = 2, 3 = 3, ..., 11 = J, 12 = Q, 13 = K
	int val;		//stores value of card. A = 1, 2 = 2, ..., JQK = 10
public:
	Card(int progSuit, int progFace, int progVal);
	//sort function
	//deadwood check
	//knock check
	//gin check

	//overloaded >= operator
};

void OrderedInit(/*****VECTOR of type CARD*****/ vector<Card> &c);

void CardShuffle(/*****VECTOR of type CARD*****/ vector<Card> &c);

int startingDraw(/*****VECTOR of type CARD*****/ vector<Card> &c);

void dealCards();

string PrintCard(Card temp);






#endif

