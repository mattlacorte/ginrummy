#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

struct Card {
	int suit;
	int face;
	int val;

	Card(int progSuit, int progFace, int progVal);
	Card();

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

	Hand();
	Hand(Card &c);
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

#endif
