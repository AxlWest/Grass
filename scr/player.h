class Card ;
class Deck ;

class Player
{
	protected :
		
		static const int MAX_HAND_SIZE = 7 ; //The maximum number of cards in your hand at any time is 7
		
		Card* hand[MAX_HAND_SIZE] ; //Stores the cards that are in your hand

	public :

		Player(void) ; //Constructor
		~Player(void) ; //Destructor
} ;