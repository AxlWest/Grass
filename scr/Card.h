#pragma once

class Card
{
	private :
	
		int type ; //The cards type
		
		bool cardSet ; //Boolean to make sure that a card cannot change its type after it has been created
		
	public :
	
		//Class creation methods
		Card(void) ; //Constructor
		~Card(void) ; //Destructor
	
		//Enums for card types in the game
		enum {HOME_GROWN = 0 , MEXICO = 1 , COLOMBIA = 2 , JAMAICA = 3 , PANAMA = 4 , DR_FEELGOOD = 5} ; //Peddle cards
		enum {BUST = 6 , DETAINED = 7 , FELONY = 8 , SEARCH_AND_SEIZURE = 9} ; //Heat on cards
		enum {IMMUNITY = 10 , A_BREEZE_TO_FLY = 11 , HEARSAY_EVIDENCE = 12 , CHARGES_DROPPED = 13 , PAY_FINE_HEAT_OFF = 14} ; //Heat off cards
		enum {STONEHIGH = 15 , EUPHORIA = 16} ; //Nirvana cards
		enum {LUST_CONQUERS_ALL = 17 , GRAB_A_SNACK = 18 , CATCH_A_BUZZ = 19} ; //Protection cards
		enum {SOLD_OUT = 20 , DOUBLE_CROSSED = 21 , UTTERLY_WIPED_OUT = 22} ; //Paranoia cards
		enum {STEAL_YOUR_NEIGHBORS_POT = 23 , BANKER = 24 } ; //Skim cards
		enum {MARKET_OPEN = 25 , MARKET_CLOSED = 26} ; //Market cards
		
		//Gets and sets methods
		int getType(void) ; //Get the value of type
		void setType(int) ; //Set the value of type (This method will only work once then the cards type cannot be changed)
} ;