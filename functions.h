#pragma once

/* * * * * * * * * * * * * * * * * * *
* Header Files
*
*
*/

//Random Comment

#ifndef FUNCTIONS_H
#define FUNCTIONS_H


//declare all functions here

class Card {
private:
	int suit;
	int face;
	int val;
public:
	Card(int progSuit, int progFace, int progVal);
	Card();
	
	//sort function
	//deadwoodCheck(vector<Card> &c);
	//knockCheck(vector<Card> &c);
	//ginCheck(vector<Card> &c);

	//overloaded >= operator
	//overloaded == operator
	//overloaded << operator
	//overloaded = operator
};

class Hand {
private:
	vector<Card> all(10);
	vector<Card> set;
	vector<Card> run;
	vector<Card> deadwood;
	int deadPoints;
public:
	Hand(Card &c);


};

Card::Card(int progSuit, int progFace, int progVal);

Card::Card();

Hand::Hand(Card &c)

//sort function

//Card::deadwoodCheck();

//Card::knockCheck();

//Card::ginCheck();


void OrderedInit(vector<Card> &c);

int myRandom(int i);

void vectorShuffle(vector<Card> &c);

int startingDraw(vector<Card> &c);

void dealCards(Hand &comp, Hand &user, vector<Card> &c);

void setDraw(vector<Card> &c, stack<Card> &d);

void setDiscard(stack<Card> &draw, stack<Card> &discard);

void sortHand(Hand &h);

void mainMenu();

void instructions();

void clear();

#endif