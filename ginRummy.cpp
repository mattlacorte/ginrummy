/* ginRummy.cpp : Defines the entry point for the console application.
 *
 * Matt LaCorte, Alfred Joseph, Jacob Pasley
 *
 * ECGR 2104 Gin Rummy Final
 *
 */

#include <iostream>
#include <stack>

#include "functions.h"

using namespace std;



int main()
{
	//DEFINE ALL VARIABLES HERE

	vector<Card> fullDeck(52);	//stores all cards

	stack<Card> remaining(52);		//stores cards not yet drawn
	stack<Card> discard(52);		//stores cards discarded
	
	Hand compHand;		//stores the comp's cards
	Hand userHand;		//stores user's cards

	int firstPlayer = 0;

	//END OF VARIABLES


	mainMenu();		//Print the rules


	orderedInit(fullDeck);		//initializes deck
	vectorShuffle(fullDeck);	//shuffles deck

	firstPlayer = startingDraw(fullDeck);		//decides who deals. 1 = user, 2 = comp
			
		//ask user to pick 1-52
		//comp picks 1-52 excluding user choice
		//compare cards


	//deal cards							-- ALFRED


	//start discard pile


	//start draw pile


	//non-dealer draws
		//must decide of discard pile or draw pile
			//AI must do a shit ton
				//if discard fits into hand, take discard. Else, take draw pile
				//sort hand. Determine sets and runs
				//determine what cards are DEADWOOD. Randomly discard one
	

	//function to store player points
	
	
	//to KNOCK, DEADWOOD ust be less than 10. Function to check this


	//to declare GIN, function to check

    return 0;
}

