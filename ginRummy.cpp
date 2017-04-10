/* ginRummy.cpp : Defines the entry point for the console application.
 *
 * Matt LaCorte, Alrfred Joseph, Jacob Pasley
 *
 * ECGR 2104 Gin Rummy Final
 *
 */

#include "stdafx.h"
#include <iostream>

using namespace std;

class Card {
private:
	int suit;		//will store suit type as int. 1 = hearts, 2 = diamonds, 3 = spades, 4 = clubs
	int face;		//stores face of card as int. 1 = A, 2 = 2, 3 = 3, ..., 11 = J, 12 = Q, 13 = K
	int val;		//stores value of card. A = 1, 2 = 2, ..., JQK = 10
public:
	//sort function
	//deadwood check
	//knock check
	//gin check
};

int main()
{

	//Print the rules						-- JACOB
		//ask if you know the game first
		//single game or set of games


	//run function to decide who deals		-- MATT


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

