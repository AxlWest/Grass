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
		enum {homeGrown = 0 , mexico = 1 , colombia = 2 , jamaica = 3 , panama = 4 , drFeelgood = 5} ; //Peddle cards
		enum {bust = 6 , detained = 7 , felony = 8 , searchAndSeizure = 9} ; //Heat on cards
		enum {immunity = 10 , aBreezeToFly = 11 , hearsayEvidence = 12 , chargesDropped = 13 , payFineHeatOff = 14} ; //Heat off cards
		enum {stonehigh = 15 , euphoria = 16} ; //Nirvana cards
		enum {lustConquersAll = 17 , grabASnack = 18 , catchABuzz = 19} ; //Protection cards
		enum {soldOut = 20 , doubleCrossed = 21 , utterlyWipedOut = 22} ; //Paranoia cards
		enum {stealYourNeighborsPot = 23 , banker = 24 } ; //Skim cards
		enum {marketOpen = 25 , marketClosed = 26} ; //Market cards
		
		//Gets and sets methods
		int getType(void) ; //Get the value of type
		void setType(int) ; //Set the value of type (This method will only work once then the cards type cannot be changed)
} ;