/* Matt LaCorte, Alfred Joseph, Jacob Pasley, Ludgi Eugene
 *
 * ECGR 2104 Gin Rummy Final Project
 *
 */

#include <iostream>

#include "functions.h"

using namespace std;



int main()
{
	//DEFINE ALL VARIABLES HERE -------------------------------------

	vector<Card> fullDeck(52);	//stores all cards

	stack<Card> draw[52];		//stores cards not yet drawn
	stack<Card> discard[52];	//stores cards discarded

	Hand compHand;				//stores comp's cards
	Hand userHand;				//stores user's cards

	int firstPlayer = 0;

	int compScore = 0;
	int userScore = 0;

	//END OF VARIABLES -----------------------------------------


	mainMenu();									//Print the rules


	orderedInit(fullDeck);						//initializes deck
	vectorShuffle(fullDeck);					//shuffles deck

	firstPlayer = startingDraw(fullDeck);		//decides who deals. 1 = user, 2 = comp

	dealCards(compHand, userHand, fullDeck);	//deal cards

	sortHand(compHand);							//sorts both hands for easy display
	sortHand(userHand);							//sorts both hands for easy display

	setDraw(fulldeck, draw);					//initializes draw pile
	setDiscard(draw, discard);					//initializes discard pile


	//non-dealer draws
		//must decide of discard pile or draw pile
			//AI must do a shit ton
				//if discard fits into hand, take discard. Else, take draw pile
				//sort hand. Determine sets and runs
				//determine what cards are DEADWOOD. Randomly discard one
	

	//function to store player points
	
	
	//to KNOCK, DEADWOOD ust be less than 10. Function to check this


	//to declare GIN, function to check

	endMenu(compScore, userScore);

    return 0;
}

