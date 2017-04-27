#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
#include <time.h>
#include <cstdlib>

using namespace std;

struct Card {
	int suit;
	int face;
	int val;

	Card(int progSuit, int progFace, int progVal) {
		suit = progSuit;
		face = progFace;
		val = progVal;
	}
	Card() {
		suit = 0;
		face = 0;
		val = 0;
	}

	friend bool operator < (const Card& AI, const Card& Human);
	friend bool operator > (const Card& AI, const Card& Human);
	friend bool operator == (const Card& AI, const Card& Human);
	friend ostream& operator << (ostream& outStream, const Card& hand);
};

struct Hand {
	vector<Card> all;
	vector<Card> set;
	vector<Card> run;
	vector<Card> deadwood;

	int deadPoints;

	Hand() {
		for (int i = 0; i < 10; i++) {
			Card tempCard;

			all.push_back(tempCard);
		}
	}
	Hand(Card &c) {
		all.push_back(c);
	}
};

void orderedInit(vector<Card> &c);

void vectorShuffle(vector<Card> &c);

int startingDraw(vector<Card> &c);

void dealCards(Hand &comp, Hand &user, vector<Card> &c);

void setDraw(vector<Card> &c, stack<Card> &d);

void setDiscard(stack<Card> &draw, stack<Card> &discard);

void sortHand(Hand &h);

void mainMenu();

void instructions();

void clear();

void endMenu(int compScore, int userScore);

void pause();

bool userPick(Hand &h, stack<Card> &draw, stack<Card> &discard);

void dispHand(Hand &h);

void AIPick(Hand &h, stack <Card> &draw, stack <Card> &discard);

void AIDiscard(Hand &h, stack <Card> &discard);


int main()
{
	//DEFINE ALL VARIABLES HERE -------------------------------------

	vector<Card> fullDeck;	//stores all cards

	stack<Card> draw;		//stores cards not yet drawn
	stack<Card> discard;	//stores cards discarded

	Hand compHand;				//stores comp's cards
	Hand userHand;				//stores user's cards

	int firstPlayer = 0;

	int compScore = 0;
	int userScore = 0;

	bool userKnock = false;		//true if user decides to knock or if gin
	bool compKnock = false;		//true if computer knocks or if gin

	Card tempCard(2, 4, 2);

	//END OF VARIABLES -----------------------------------------


	mainMenu();

	orderedInit(fullDeck);

	vectorShuffle(fullDeck);
	clear();

	firstPlayer = startingDraw(fullDeck);		//1 if user, 2 if computer

	dealCards(compHand, userHand, fullDeck);
	cout << "inti hand   ";
//	dispHand(userHand);
	dispHand(compHand); //*************
	sortHand(compHand);
//	sortHand(userHand);


	cout << "init hand sort" << endl;

	setDraw(fullDeck, draw);

	cout << "set draw" << endl;

	setDiscard(draw, discard);

	cout << "set discard" << endl;

	cout << endl << endl;

	AIPick(compHand, draw, discard);
	AIDiscard(compHand, discard);

	//clear();

	//userKnock = userPick(userHand, draw, discard);
/*	sortHand(userHand);

	cout << "  This is your current hand  " << endl;
	cout << "=============================" << endl;
	dispHand(userHand);
	*/
	/*
	//cout << endl;

	if (firstPlayer == 1) {
	do {

	if (draw.empty()) {
	break;
	}

	sortHand(userHand);

	userKnock = userPick(userHand, draw, discard);

	if (userKnock) {
	break;
	}
	if (draw.empty()) {
	break;
	}

	//sortHand(compHand);

	//compKnock = compPick(compHand, draw, discard);		//===================================



	} while (!userKnock && !compKnock && !draw.empty());
	}

	else {
	do {

	} while (!userKnock && !compKnock);
	}
	*/

	//AIPick(compHand, draw, discard);
	cout << "back to main" << endl;

	return 0;
}



bool operator < (const Card& AI, const Card& Human) {
	return (AI.face < Human.face,
		AI.suit < Human.suit,
		AI.val < Human.val);
}

bool operator > (const Card& AI, const Card& Human) {
	return (AI.face > Human.face,
		AI.suit > Human.suit,
		AI.val > Human.val);
}

bool operator == (const Card& AI, const Card& Human) {
	return ((AI.face== Human.face) &&
		(AI.suit == Human.suit) &&
		(AI.val == Human.val));
}

ostream& operator << (ostream& outStream, const Card& hand) {
	switch (hand.face) {
	case 1:
		outStream << "A";
		break;
	case 2:
		outStream << "2";
		break;
	case 3:
		outStream << "3";
		break;
	case 4:
		outStream << "4";
		break;
	case 5:
		outStream << "5";
		break;
	case 6:
		outStream << "6";
		break;
	case 7:
		outStream << "7";
		break;
	case 8:
		outStream << "8";
		break;
	case 9:
		outStream << "9";
		break;
	case 10:
		outStream << "10";
		break;
	case 11:
		outStream << "J";
		break;
	case 12:
		outStream << "Q";
		break;
	case 13:
		outStream << "K";
		break;
	default:
		outStream << "Printing Face doesn't work";
		break;
	}
	switch (hand.suit) {
	case 1:
		outStream << "H";
		break;
	case 2:
		outStream << "D";
		break;
	case 3:
		outStream << "S";
		break;
	case 4:
		outStream << "C";
		break;
	default:
		outStream << "Error in printing suit";
		break;
	}

	return outStream;
};

void orderedInit(vector<Card> &c) {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 13; j++) {
			int tempSuit;
			int tempFace;
			int tempVal;

			tempSuit = i;
			tempFace = j;

			if (j < 10) {
				tempVal = j;
			}
			else if (j >= 10) {
				tempVal = 10;
			}
			else {
				cout << "FIXME: Error in OrderedInit declaring card values" << endl;
			}

			c.push_back(Card(tempSuit, tempFace, tempVal));
		}
	}
}

void vectorShuffle(vector<Card> &c) {
	srand(time(NULL));
	int i = rand() % 100;

	random_shuffle(c.begin(), c.end());
}

int startingDraw(vector<Card> &c) {

	int userNum;
	int compNum;

	int compCardVal;
	int userCardVal;

	int winner = 1;

	do {
		do {

			cout << "Choose a number between 1 and 52: ";		//selects the corresponding card
			cin >> userNum;

			do {		//general check to make sure the numbers are not the same
				compNum = (rand() % 52);
			} while (compNum == userNum);

			if ((1 > userNum) || (userNum > 52)) {
				cout << "You chose a number that was out of bounds. Please learn to count, then run the program again" << endl;	//Passive aggressiveness
			}

		} while (((1 > userNum) && (userNum > 52)));

		compCardVal = c.at(compNum).val;
		userCardVal = c.at(userNum).val;


		if (c.at(userCardVal).val > c.at(compCardVal).val) {	//user wins
			winner = 1;
		}
		else if (compCardVal < userCardVal) {					//comp wins
			winner = 2;
		}
		else if (userCardVal == compCardVal) {					//draw
			cout << "That's unfortunate. You and the computer chose cards with the same value. Try again." << endl;
		}

	} while (userCardVal == compCardVal);



	return winner;
}

void dealCards(Hand &comp, Hand &user, vector<Card> &c) {
	comp.all.clear();
	user.all.clear();

	for (int i = 0; i < 10; i++) {
		comp.all.push_back(c.back());
		c.pop_back();

		user.all.push_back(c.back());
		c.pop_back();
	}
}

void setDraw(vector<Card> &c, stack<Card> &d) {
	for (int i = 0; i < c.size(); i++) {
		d.push(c.at(i));
	}
}

void setDiscard(stack<Card> &draw, stack<Card> &discard) {
	discard.push(draw.top());
	draw.pop();
}

void sortHand(Hand &h) {

	int sum = 0;			//calculates deadwood points

	bool runTrue = false;	//records whether a run can begin
	bool repeat = false;	//records if there is a repeat of card vals

	vector<Card> card1;		//A
	vector<Card> card2;		//2
	vector<Card> card3;		//3
	vector<Card> card4;		//4
	vector<Card> card5;		//5
	vector<Card> card6;		//6
	vector<Card> card7;		//7
	vector<Card> card8;		//8
	vector<Card> card9;		//9
	vector<Card> card10;	//10
	vector<Card> card11;	//J
	vector<Card> card12;	//Q
	vector<Card> card13;	//K

	vector<Card> checkRun;

	vector<Card> heart;
	vector<Card> diamond;
	vector<Card> spade;
	vector<Card> club;

	//CLEAR ALL SET & RUN & DEADWOOD ------------------------------------------

	h.set.clear();
	h.run.clear();
	h.deadwood.clear();

	//SET CHECK ---------------------------------------------------------------

	for (int i = 0; i < h.all.size(); i++) {	//iterates through all cards
		switch (h.all.at(i).face) {	//adds all cards to appropriate face vector
		case 1:
			card1.push_back(h.all.at(i));
			break;
		case 2:
			card2.push_back(h.all.at(i));
			break;
		case 3:
			card3.push_back(h.all.at(i));
			break;
		case 4:
			card4.push_back(h.all.at(i));
			break;
		case 5:
			card5.push_back(h.all.at(i));
			break;
		case 6:
			card6.push_back(h.all.at(i));
			break;
		case 7:
			card7.push_back(h.all.at(i));
			break;
		case 8:
			card8.push_back(h.all.at(i));
			break;
		case 9:
			card9.push_back(h.all.at(i));
			break;
		case 10:
			card10.push_back(h.all.at(i));
			break;
		case 11:
			card11.push_back(h.all.at(i));
			break;
		case 12:
			card12.push_back(h.all.at(i));
			break;
		case 13:
			card13.push_back(h.all.at(i));
			break;
		}
	}

	//If set (more than 3), add to the "set" vector in hand
	if (card1.size() > 2) {
		for (int i = 0; i < card1.size(); i++) {
			h.set.push_back(card1.at(i));

		}
		//h.set.insert(h.set.end(), card1.begin(), card1.end());
		card1.clear();

	}
	if (card2.size() > 2) {
		for (int i = 0; i < card2.size(); i++) {
			h.set.push_back(card2.at(i));
		}
		//h.set.insert(h.set.end(), card2.begin(), card2.end());
		card2.clear();

	}
	if (card3.size() > 2) {
		for (int i = 0; i < card3.size(); i++) {
			h.set.push_back(card3.at(i));
		}
		//h.set.insert(h.set.end(), card3.begin(), card3.end());
		card3.clear();

	}
	if (card4.size() > 2) {
		for (int i = 0; i < card4.size(); i++) {
			h.set.push_back(card4.at(i));
		}
		//h.set.insert(h.set.end(), card4.begin(), card4.end());
		card4.clear();

	}
	if (card5.size() > 2) {
		for (int i = 0; i < card5.size(); i++) {
			h.set.push_back(card5.at(i));
		}
		//h.set.insert(h.set.end(), card5.begin(), card5.end());
		card5.clear();

	}
	if (card6.size() > 2) {
		for (int i = 0; i < card6.size(); i++) {
			h.set.push_back(card6.at(i));
		}
		//h.set.insert(h.set.end(), card6.begin(), card6.end());
		card6.clear();

	}
	if (card7.size() > 2) {
		for (int i = 0; i < card7.size(); i++) {
			h.set.push_back(card7.at(i));
		}
		//h.set.insert(h.set.end(), card7.begin(), card7.end());
		card7.clear();

	}
	if (card8.size() > 2) {
		for (int i = 0; i < card8.size(); i++) {
			h.set.push_back(card8.at(i));
		}
		//h.set.insert(h.set.end(), card8.begin(), card8.end());
		card8.clear();

	}
	if (card9.size() > 2) {
		for (int i = 0; i < card9.size(); i++) {
			h.set.push_back(card9.at(i));
		}
		//h.set.insert(h.set.end(), card9.begin(), card9.end());
		card9.clear();

	}
	if (card10.size() > 2) {
		for (int i = 0; i < card10.size(); i++) {
			h.set.push_back(card10.at(i));
		}
		//h.set.insert(h.set.end(), card10.begin(), card10.end());
		card10.clear();

	}
	if (card11.size() > 2) {
		for (int i = 0; i < card11.size(); i++) {
			h.set.push_back(card11.at(i));
		}
		//h.set.insert(h.set.end(), card11.begin(), card11.end());
		card11.clear();

	}
	if (card12.size() > 2) {
		for (int i = 0; i < card12.size(); i++) {
			h.set.push_back(card12.at(i));
		}
		//h.set.insert(h.set.end(), card12.begin(), card12.end());
		card12.clear();

	}
	if (card13.size() > 2) {
		for (int i = 0; i < card13.size(); i++) {
			h.set.push_back(card13.at(i));
		}
		//h.set.insert(h.set.end(), card13.begin(), card13.end());
		card13.clear();

	}


	//add all remaining cards to a single vector
	/*
	checkRun.insert(checkRun.end(), card1.begin(), card1.end());
	checkRun.insert(checkRun.end(), card2.begin(), card2.end());
	checkRun.insert(checkRun.end(), card3.begin(), card3.end());
	checkRun.insert(checkRun.end(), card4.begin(), card4.end());
	checkRun.insert(checkRun.end(), card5.begin(), card5.end());
	checkRun.insert(checkRun.end(), card6.begin(), card6.end());
	checkRun.insert(checkRun.end(), card7.begin(), card7.end());
	checkRun.insert(checkRun.end(), card8.begin(), card8.end());
	checkRun.insert(checkRun.end(), card9.begin(), card9.end());
	checkRun.insert(checkRun.end(), card10.begin(), card10.end());
	checkRun.insert(checkRun.end(), card11.begin(), card11.end());
	checkRun.insert(checkRun.end(), card12.begin(), card12.end());
	checkRun.insert(checkRun.end(), card13.begin(), card13.end());
	*/

	for (int i = 0; i < card1.size(); i++) {
		checkRun.push_back(card1.at(i));
	}
	for (int i = 0; i < card2.size(); i++) {
		checkRun.push_back(card2.at(i));
	}
	for (int i = 0; i < card3.size(); i++) {
		checkRun.push_back(card3.at(i));
	}
	for (int i = 0; i < card4.size(); i++) {
		checkRun.push_back(card4.at(i));
	}
	for (int i = 0; i < card5.size(); i++) {
		checkRun.push_back(card5.at(i));
	}
	for (int i = 0; i < card6.size(); i++) {
		checkRun.push_back(card6.at(i));
	}
	for (int i = 0; i < card7.size(); i++) {
		checkRun.push_back(card7.at(i));
	}
	for (int i = 0; i < card8.size(); i++) {
		checkRun.push_back(card8.at(i));
	}
	for (int i = 0; i < card9.size(); i++) {
		checkRun.push_back(card9.at(i));
	}
	for (int i = 0; i < card10.size(); i++) {
		checkRun.push_back(card10.at(i));
	}
	for (int i = 0; i < card11.size(); i++) {
		checkRun.push_back(card11.at(i));
	}
	for (int i = 0; i < card12.size(); i++) {
		checkRun.push_back(card12.at(i));
	}
	for (int i = 0; i < card13.size(); i++) {
		checkRun.push_back(card13.at(i));
	}

	if (h.set.size() == checkRun.size()) {
		checkRun.clear();
	}
	else {

		for (int k = 0; k < h.set.size(); k++) {
			for (int l = checkRun.size() - 1; l >= 0; l--) {
				if (h.set.at(k) == checkRun.at(l)) {
					checkRun.erase(checkRun.begin() + l);
					//break;
				}
			}
		}
	}

	cout << "runCheck" << endl; //==========================
								//RUN CHECK --------------------------------------------------------------------------

	for (int i = 0; i < checkRun.size(); i++) {	//iterates through all remaining cards

		switch (checkRun.at(i).suit) {		//sorts cards into appropriate vector based on suit
		case 1:
			heart.push_back(checkRun.at(i));
			break;
		case 2:
			diamond.push_back(checkRun.at(i));
			break;
		case 3:
			spade.push_back(checkRun.at(i));
			break;
		case 4:
			club.push_back(checkRun.at(i));
			break;
		default:
			cout << "suit assign error" << i << endl;
			break;
		}
	}

	checkRun.clear();

	cout << "run: " << h.all.size() << endl;//==================================

	if (heart.size() > 2) {

		for (int i = 0; i < heart.size() - 2; i++) {
			checkRun.push_back(heart.at(i));
			checkRun.push_back(heart.at(i + 1));

			int j = i + 2;

			while (checkRun.at(checkRun.size() - 2).face == (checkRun.at(checkRun.size() - 1).face - 1)) {

				if (j < heart.size()) {
					checkRun.push_back(heart.at(j));
					j++;
				}
				else {
					break;
				}
			}
			if (checkRun.back().face != checkRun.at(checkRun.size() - 2).face + 1) {
				checkRun.pop_back();
			}

			if (checkRun.size() > 2) {
				for (int i = 0; i < checkRun.size(); i++) {
					h.run.push_back(checkRun.at(i));
				}
				//h.run.insert(h.run.end(), checkRun.begin(), checkRun.end());

				if (checkRun.size() == heart.size()) {
					heart.clear();
				}
				else {
					for (int k = 0; k < checkRun.size(); k++) {
						for (int l = heart.size() - 1; l >= 0; l--) {
							if (checkRun.at(k) == heart.at(l)) {
								heart.erase(heart.begin() + l);
								break;
							}
						}

					}
				}
			}

			checkRun.clear();

			if (heart.size() < 3) {
				break;
			}
		}
	}

	if (diamond.size() > 2) {

		for (int i = 0; i < diamond.size() - 2; i++) {
			checkRun.push_back(diamond.at(i));
			checkRun.push_back(diamond.at(i + 1));

			int j = i + 2;

			while (checkRun.at(checkRun.size() - 2).face == (checkRun.at(checkRun.size() - 1).face - 1)) {

				if (j < diamond.size()) {
					checkRun.push_back(diamond.at(j));
					j++;
				}
				else {
					break;
				}
			}

			if (checkRun.back().face != checkRun.at(checkRun.size() - 2).face + 1) {
				checkRun.pop_back();
			}

			if (checkRun.size() > 2) {
				for (int i = 0; i < checkRun.size(); i++) {
					h.run.push_back(checkRun.at(i));
				}
				//h.run.insert(h.run.end(), checkRun.begin(), checkRun.end());

				if (checkRun.size() == diamond.size()) {
					diamond.clear();
				}
				else {
					for (int k = 0; k < checkRun.size(); k++) {
						for (int l = diamond.size() - 1; l >= 0; l--) {
							if (checkRun.at(k) == diamond.at(l)) {
								diamond.erase(diamond.begin() + l);
								break;
							}
						}
					}
				}
			}

			checkRun.clear();

			if (diamond.size() < 3) {
				break;
			}
		}
	}

	if (spade.size() > 2) {

		for (int i = 0; i < spade.size() - 2; i++) {

			checkRun.push_back(spade.at(i));
			checkRun.push_back(spade.at(i + 1));

			int j = i + 2;

			while (checkRun.at(checkRun.size() - 2).face == (checkRun.at(checkRun.size() - 1).face - 1)) {

				if (j < spade.size()) {
					checkRun.push_back(spade.at(j));
					j++;
				}
				else {
					break;
				}
			}

			if (checkRun.back().face != checkRun.at(checkRun.size() - 2).face + 1) {
				checkRun.pop_back();
			}

			if (checkRun.size() > 2) {
				for (int i = 0; i < checkRun.size(); i++) {
					h.run.push_back(checkRun.at(i));
				}
				//h.run.insert(h.run.end(), checkRun.begin(), checkRun.end());

				if (checkRun.size() == spade.size()) {
					spade.clear();
				}
				else {
					for (int k = 0; k < checkRun.size(); k++) {
						for (int l = spade.size() - 1; l >= 0; l--) {
							if (checkRun.at(k) == spade.at(l)) {
								spade.erase(spade.begin() + l);
								break;
							}
						}
					}
				}
			}

			checkRun.clear();

			if (spade.size() < 3) {
				break;
			}

		}
	}

	if (club.size() > 2) {

		for (int i = 0; i < club.size() - 2; i++) {

			checkRun.push_back(club.at(i));
			checkRun.push_back(club.at(i + 1));

			int j = i + 2;

			while (checkRun.at(checkRun.size() - 2).face == (checkRun.at(checkRun.size() - 1).face - 1)) {

				if (j < club.size()) {
					checkRun.push_back(club.at(j));
					j++;
				}
				else {
					break;
				}
			}

			if (checkRun.back().face != checkRun.at(checkRun.size() - 2).face + 1) {
				checkRun.pop_back();
			}
			if (checkRun.size() > 2) {
				for (int i = 0; i < checkRun.size(); i++) {
					h.run.push_back(checkRun.at(i));
				}
				//h.run.insert(h.run.end(), checkRun.begin(), checkRun.end());

				if (checkRun.size() == club.size()) {
					club.clear();
				}
				else {
					for (int k = 0; k < checkRun.size(); k++) {
						for (int l = club.size() - 1; l >= 0; l--) {
							if (checkRun.at(k) == club.at(l)) {
								club.erase(club.begin() + l);
								break;
							}
						}
					}
				}
			}
			checkRun.clear();

			if (club.size() < 3) {
				break;
			}
		}
	}

	cout << "end sort" << endl;//===============

							   //add all remaining cards to deadwood ------------------------------

	for (int i = 0; i < heart.size(); i++) {
		h.deadwood.push_back(heart.at(i));
	}
	//h.deadwood.insert(h.deadwood.end(), heart.begin(), heart.end());
	for (int i = 0; i < diamond.size(); i++) {
		h.deadwood.push_back(diamond.at(i));
	}
	//h.deadwood.insert(h.deadwood.end(), diamond.begin(), diamond.end());
	for (int i = 0; i < spade.size(); i++) {
		h.deadwood.push_back(spade.at(i));
	}
	//h.deadwood.insert(h.deadwood.end(), spade.begin(), spade.end());
	for (int i = 0; i < club.size(); i++) {
		h.deadwood.push_back(club.at(i));
	}
	//h.deadwood.insert(h.deadwood.end(), club.begin(), club.end());

	cout << "all added to dead" << endl;//===============


										//deadPoints assigned. Iterate through and sum the val
	for (int i = 0; i < h.deadwood.size(); i++) {

		sum = sum + h.deadwood.at(i).val;
	}

	h.deadPoints = sum;

	cout << "dead calculated" << endl;

	//resorts ALL to be nice and orderly -------------------------------
	h.all.clear();

	if (!h.set.empty()) {
		for (int i = 0; i < h.set.size(); i++) {
			h.all.push_back(h.set.at(i));
		}
		//h.all.insert(h.all.end(), h.set.begin(), h.set.end());
	}
	if (!h.run.empty()) {
		for (int i = 0; i < h.run.size(); i++) {
			h.all.push_back(h.run.at(i));
		}
		//h.all.insert(h.all.end(), h.run.begin(), h.run.end());
	}
	if (!h.deadwood.empty()) {
		for (int i = 0; i < h.deadwood.size(); i++) {
			h.all.push_back(h.deadwood.at(i));
		}
		//h.all.insert(h.all.end(), h.deadwood.begin(), h.deadwood.end());
	}

	cout << "end sort" << endl;


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
	else {
		mainMenu();
	}
}

void pause() {
	system("pause");
}

void endMenu(int compScore, int userScore) {
	clear();

	int tmpCompScore = compScore;
	int tmpUserScore = userScore;

	string tmpWinner = " ";
	char playAgainChoice = ' ';

	if (tmpCompScore > tmpUserScore) {
		tmpWinner = "The Computer Has Won!";
	}
	else if (tmpUserScore > tmpCompScore) {
		tmpWinner = "You Beat the Computer!";
	}

	cout << endl;
	cout << "*********************************" << endl;
	cout << tmpWinner << endl;
	cout << "*********************************" << endl;
	cout << endl;
	cout << "Final Scores:" << endl;
	cout << endl;
	cout << "You ----------- " << tmpUserScore << endl;
	cout << "Computer ------ " << tmpCompScore << endl;
	cout << endl << endl;
	cout << "Would you like to play again? [Y/N]" << endl;
	cout << endl;
	cin >> playAgainChoice;

	if (playAgainChoice == 'Y' || 'y') {
		mainMenu();
	}
	else if (playAgainChoice == 'N' || 'n') {
		exit(1);
	}

}

bool userPick(Hand &h, stack<Card> &draw, stack<Card> &discard) {
	char userKnockChoice = '?';
	char userDiscardChoice = '?';

	bool knockChoice = false;	//true if user wants to knock, or if GIN(deadwood = 0;)
	bool discardChoice;		//true if user chose from discard

	int userCardDrop;		//stores the card number for the user to drop

	Card tempUserCard;


	cout << "  This is your current hand  " << endl;
	cout << "=============================" << endl;

	dispHand(h);

	//============================deadwood check================================

	//if deadwood = 0, gin is reached. The user is forced to knock
	if (h.deadPoints == 0) {
		cout << "You have achieved gin! You must knock now." << endl;

		knockChoice = true;
	}

	//if deadwood is 10 or less, the user can knock if they want
	else if (h.deadPoints < 11) {
		cout << "You have a total of " << h.deadPoints << " points in your deadwood pile. Would you like to knock? [Y/N]" << endl;
		cin >> userKnockChoice;

		if (userKnockChoice == ('y' || 'Y')) {
			knockChoice = true;
		}
	}

	if (knockChoice) {
		return knockChoice;
	}
	//if deadwood > 10 or user does not want to knock
	else {

		cout << "The current card on top of the discard pile is " << discard.top() << ". Would you like to choose it? [Y/N]" << endl;

		cin >> userDiscardChoice;

		if ((userDiscardChoice == 'y') || (userDiscardChoice == 'Y')) {
			tempUserCard = discard.top();

			discard.pop();
			discardChoice = true;
		}
		else if ((userDiscardChoice == 'n') || (userDiscardChoice == 'N')) {
			tempUserCard = draw.top();

			cout << "Drawn Card: " << tempUserCard << endl;
			draw.pop();
			discardChoice = false;
		}

		if (discardChoice) {
			cout << "You may not get rid of the card you just drew. Please pick a card [1 - 10] from your hand to add to the discard pile." << endl;
			cin >> userCardDrop;
		}
		else {
			cout << "Please pick a card [1 - 10] from your hand, or the card that you just drew [11], to be added to the discard pile." << endl;
			cin >> userCardDrop;
		}

		if (userCardDrop < 11) {
			discard.push(h.all.at(userCardDrop - 1));

			h.all.erase(h.all.begin() + (userCardDrop - 1));

			h.all.push_back(tempUserCard);
		}
		else if (userCardDrop == 11) {
			discard.push(tempUserCard);
		}

		//sortHand(h);

		clear();
	}
}

void dispHand(Hand &h) {
	for (int i = 0; i < h.all.size(); i++) {
		cout << h.all.at(i) << " ";
	}

	/*
	if (h.set.size() > 0) {
	for (int i = 0; i < h.set.size(); i++) {
	cout << h.set.at(i) << " ";
	}
	}


	if (h.run.size() > 0) {
	for (int i = 0; i < h.run.size(); i++) {
	cout << h.run.at(i) << " ";
	}
	}

	if (h.deadwood.size() > 0) {
	for (int i = 0; i < h.deadwood.size(); i++) {
	cout << h.deadwood.at(i) << " ";
	}
	}
	*/


	cout << endl;
}

void AIPick(Hand &h, stack <Card> &draw, stack <Card> &discard) {
	Hand TempHand;
	int deadwoodCount, deadwoodSort;

	sortHand(h);
	cout << "all is " << h.all.size();
	deadwoodCount = h.deadwood.size();
	cout << "set is " << h.set.size();
	cout << "run is " << h.run.size();
	cout << "deadwoodcount is " << deadwoodCount; //**********

	memcpy(&TempHand, &h, sizeof Hand);

	dispHand(TempHand);	//*********

	TempHand.all.push_back(discard.top());

	dispHand(TempHand);				//**************
	cout << "pt 1" << endl; //===============

	sortHand(TempHand);

	cout << "part 1" << endl;

	dispHand(TempHand);			//******************

	deadwoodSort = TempHand.deadwood.size();

	cout << "Part 2" << endl; //================
	cout << "Deadwood After size is " << deadwoodSort; //*************

	if (deadwoodSort > deadwoodCount) {
		h.all.push_back(draw.top());
		cout << "Draw"; //************
	}
	else {
		h.all.push_back(discard.top());
		cout << "Discard "; //************8
		discard.pop();
		cout << "First position is " << h.deadwood.size();
	}

	cout << "Part 3" << " ";		//******************
	dispHand(h);					//******************
	cout << "end ai" << endl;
}

//Code for the AI discarding 

void AIDiscard(Hand &h, stack <Card> &discard) {
	cout << "Part 3.5"; //*************
	int position = h.deadwood.size();
	cout << "Position is " << position;
	discard.push(h.deadwood.at(position-1));
	cout << "Part 3.6"; //*************
	h.deadwood.pop_back();
	cout << "Part 4" << " ";		//******************
	dispHand(h);					//******************
}
