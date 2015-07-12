#include "Card.h"

class Deck
{
	private :
	
		static const int MAX_NO_OF_CARDS = 104 ; //The maximum number of cards in the deck
	
		bool shuffled ; //Marks if the deck has been shuffled or not
	
		Card* deck[MAX_NO_OF_CARDS] ; //An array that holds all the cards in the deck
		
	public :
	
		//Class creation methods
		Deck(void) ; //Constructor
		~Deck(void) ; //Destructor
		void init(void) ; //Creates the deck by creating all the cards in it
		
		//Deck manipulation methods
		void shuffleDeck(void) ; //Shuffles the deck of cards (can only be done once per deck)
		Card* getTopCard(void) ; //Returns the cart that is on top of the deck
} ;