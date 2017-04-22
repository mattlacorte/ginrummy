
/* * * * * * * * * * * * * * * * * * * * * * * * *
 * Function Definitions
 *
 *
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
//  struct Card {
// 	int suit;
// 	int face;
// 	int val;

// 	Card(int progSuit, int progFace, int progVal) {
// 		suit = progSuit;
// 		face = progFace;
// 		val = progVal;
// 	}
// 	Card() {
// 		suit = 0;
// 		face = 0;
// 		val = 0;
// 	}

// 	friend bool operator < (const Card& AI, const Card& Human);
// 	friend bool operator > (const Card& AI, const Card& Human);
// 	friend bool operator == (const Card& AI, const Card& Human);
// 	friend ostream& operator << (ostream& outStream, const Card& hand);

// 	int knockCheck();
// };

// struct Hand {
// 	vector<Card> all;
// 	vector<Card> set;
// 	vector<Card> run;
// 	vector<Card> deadwood;
// 	int deadPoints;

// 	Hand() {
// 		for (int i = 0; i < 10; i++) {
// 			Card tempCard;

// 			all.push_back(tempCard);
// 		}
// 	}
// 	Hand(Card &c) {
// 		all.push_back(c);
// 	}
// };


	Card::Card(int progSuit, int progFace, int progVal) {
		suit = progSuit;
		face = progFace;
		val = progVal;
	}

	Card::Card() {
		suit = 0;
		face = 0;
		val = 0;
	}

	Hand::Hand() {
		for (int i = 0; i < 10; i++) {
			Card tempCard;

			all.push_back(tempCard);
		}
	}
	
	Hand::Hand(Card &c) {
		all.push_back(c);
	}

//overloaded less than
bool operator < (const Card& AI, const Card& Human) {
	return (AI.face < Human.face,
		AI.suit < Human.suit,
		AI.val < Human.val);
}
//overloaded greater than
bool operator > (const Card& AI, const Card& Human) {
	return (AI.face > Human.face,
		AI.suit > Human.suit,
		AI.val > Human.val);
}
//overloaded equal to
bool operator == (const Card& AI, const Card& Human) {
	return (AI.face == Human.face,
		AI.suit == Human.suit,
		AI.val == Human.val);
}
//overloaded cout
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
};

void orderedInit(vector<Card> &c) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
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

int myRandom(int i) {
	return rand() % i;
}

void vectorShuffle(vector<Card> &c) {
	random_shuffle(c.begin(), c.end(), myRandom);
}

int startingDraw(vector<Card> &c) {

	int userNum;
	int compNum;

	Card compCard;
	Card userCard;

	int winner;

	do {

		cout << "Choose a number between 1 and 52" << endl;
		cin >> userNum;

		compNum = rand() % 52 + 1;

	} while ((userNum == compNum) && ((1 <= userNum) && (userNum <= 52)));

	compCard = c.at(compNum);
	userCard = c.at(userNum);

	if (userCard > compCard) {
		winner = 1;
	}
	else if (compCard < userCard) {
		winner = 2;
	}


	return winner;
}

void dealCards(Hand &comp, Hand &user, vector<Card> &c) {
	int j = 51;
	for (int i = 0; i <= 10; i++, j = j - 2) {
		comp.all.push_back(c.back());
		c.pop_back();

		user.all.push_back(c.back());
		c.pop_back();
	}
}

void setDraw(vector<Card> &c, stack<Card> &d) {
	for (int i = 0; i < c.size(); i++) {
		d.push(c.back());

	}
}

void setDiscard(stack<Card> &draw, stack<Card> &discard) { 
	discard.push(draw.top());
	draw.pop();
}

void sortHand(Hand &h) {

	bool runTrue = false;	//records whether a run can begin
	bool repeat = false;		//records if there is a repeat of card vals

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


	//SET CHECK ---------------------------------------------------------------

	for (int i = 0; i < 10; i++) {	//iterates through all cards
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
			h.set.insert(h.set.end(), card1.begin(), card1.end());
			card1.clear();
		}
	}
	if (card2.size() > 2) {
		for (int i = 0; i < card2.size(); i++) {
			h.set.insert(h.set.end(), card2.begin(), card2.end());
			card2.clear();
		}
	}
	if (card3.size() > 2) {
		for (int i = 0; i < card3.size(); i++) {
			h.set.insert(h.set.end(), card3.begin(), card3.end());
			card3.clear();
		}
	}
	if (card4.size() > 2) {
		for (int i = 0; i < card4.size(); i++) {
			h.set.insert(h.set.end(), card4.begin(), card4.end());
			card4.clear();
		}
	}
	if (card5.size() > 2) {
		for (int i = 0; i < card5.size(); i++) {
			h.set.insert(h.set.end(), card5.begin(), card5.end());
			card5.clear();
		}
	}
	if (card6.size() > 2) {
		for (int i = 0; i < card6.size(); i++) {
			h.set.insert(h.set.end(), card6.begin(), card6.end());
			card6.clear();
		}
	}
	if (card7.size() > 2) {
		for (int i = 0; i < card7.size(); i++) {
			h.set.insert(h.set.end(), card7.begin(), card7.end());
			card7.clear();
		}
	}
	if (card8.size() > 2) {
		for (int i = 0; i < card8.size(); i++) {
			h.set.insert(h.set.end(), card8.begin(), card8.end());
			card8.clear();
		}
	}
	if (card9.size() > 2) {
		for (int i = 0; i < card9.size(); i++) {
			h.set.insert(h.set.end(), card9.begin(), card9.end());
			card9.clear();
		}
	}
	if (card10.size() > 2) {
		for (int i = 0; i < card10.size(); i++) {
			h.set.insert(h.set.end(), card10.begin(), card10.end());
			card10.clear();
		}
	}
	if (card11.size() > 2) {
		for (int i = 0; i < card11.size(); i++) {
			h.set.insert(h.set.end(), card11.begin(), card11.end());
			card11.clear();
		}
	}
	if (card12.size() > 2) {
		for (int i = 0; i < card12.size(); i++) {
			h.set.insert(h.set.end(), card12.begin(), card12.end());
			card12.clear();
		}
	}
	if (card13.size() > 2) {
		for (int i = 0; i < card13.size(); i++) {
			h.set.insert(h.set.end(), card13.begin(), card13.end());
			card13.clear();
		}
	}


	//add all remaining cards to a single vector
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


	//RUN CHECK --------------------------------------------------------------------------

	for (int i = 0; i < (checkRun.size()); i++) {	//iterates through all remaining cards

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
		}

	}

	for (int i = 0; i < heart.size() - 2; i++) {	//heart run check

		int j = i + 1;

		do {
			runTrue = false;

			if (heart.at(i).face == (heart.at(j).face - 1)) {
				runTrue = true;
				j++;
			}
		} while (runTrue);

			int size = (j - i) + 1;

		for (int k = 0; k < size; k++) {
			h.run.push_back(heart.at(k));
		}

	}

	for (int i = 0; i < diamond.size() - 2; i++) {	//diamond run check

		int j = i + 1;

		do {
			runTrue = false;

			if (diamond.at(i).face == (diamond.at(j).face - 1))  {
				runTrue = true;
				j++;
			}
		} while (runTrue);

			int size = (j - i) + 1;

		for (int k = 0; k < size; k++) {
			h.run.push_back(diamond.at(k));
		}
	}

	for (int i = 0; i < spade.size() - 2; i++) {	//spade run check

		int j = i + 1;

		do {
			runTrue = false;

			if (spade.at(i).face == (spade.at(j).face - 1)) {
				runTrue = true;
				j++;
			}
		} while (runTrue);

			int size = (j - i) + 1;

		for (int k = 0; k < size; k++) {
			h.run.push_back(spade.at(k));
		}
	}

	for (int i = 0; i < club.size() - 2; i++) {		//club run check

		int j = i + 1;

		do {
			runTrue = false;

			if (club.at(i).face == (club.at(j).face - 1)) {
			runTrue = true;
				j++;
			}
		} while (runTrue);

			int size = (j - i) + 1;

		for (int k = 0; k < size; k++) {
			h.run.push_back(club.at(k));
		}
	}


	//add all remaining cards to deadwood ------------------------------

	h.deadwood.insert(h.deadwood.end(), heart.begin(), heart.end());
	h.deadwood.insert(h.deadwood.end(), diamond.begin(), diamond.end());
	h.deadwood.insert(h.deadwood.end(), spade.begin(), spade.end());
	h.deadwood.insert(h.deadwood.end(), club.begin(), club.end());
}

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
