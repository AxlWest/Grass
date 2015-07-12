#include "Deck.h"
#include "Card.h"
#include <random>

//Deck creation functions
Deck::Deck(void)
{
	this->shuffled = false ;
	
	for(int i = 0 ; i < this->MAX_NO_OF_CARDS ; i++) //Initialize all cards to NULL
	{
		this->deck[i] = NULL ;
	}
}

Deck::~Deck(void)
{
	for(int i = 0 ; i < this->MAX_NO_OF_CARDS ; i++)
	{
		if(this->deck[i] != NULL) //Check each card if it is not equal to NULL delete it and set to NULL
		{
			delete this->deck[i] ;
			this->deck[i] = NULL ;
		}
	}
}

void Deck::init(void)
{
	//Create all peddle cards
	this->deck[0] = new Card() ;
	this->deck[0]->setType(Card::HOME_GROWN) ;
	this->deck[1] = new Card() ;
	this->deck[1]->setType(Card::HOME_GROWN) ;
	this->deck[2] = new Card() ;
	this->deck[2]->setType(Card::HOME_GROWN) ;
	this->deck[3] = new Card() ;
	this->deck[3]->setType(Card::HOME_GROWN) ;
	this->deck[4] = new Card() ;
	this->deck[4]->setType(Card::HOME_GROWN) ;
	this->deck[5] = new Card() ;
	this->deck[5]->setType(Card::HOME_GROWN) ;
	this->deck[6] = new Card() ;
	this->deck[6]->setType(Card::MEXICO) ;
	this->deck[7] = new Card() ;
	this->deck[7]->setType(Card::MEXICO) ;
	this->deck[8] = new Card() ;
	this->deck[8]->setType(Card::MEXICO) ;
	this->deck[9] = new Card() ;
	this->deck[9]->setType(Card::MEXICO) ;
	this->deck[10] = new Card() ;
	this->deck[10]->setType(Card::MEXICO) ;
	this->deck[11] = new Card() ;
	this->deck[11]->setType(Card::MEXICO) ;
	this->deck[12] = new Card() ;
	this->deck[12]->setType(Card::COLOMBIA) ;
	this->deck[13] = new Card() ;
	this->deck[13]->setType(Card::COLOMBIA) ;
	this->deck[14] = new Card() ;
	this->deck[14]->setType(Card::COLOMBIA) ;
	this->deck[15] = new Card() ;
	this->deck[15]->setType(Card::COLOMBIA) ;
	this->deck[16] = new Card() ;
	this->deck[16]->setType(Card::COLOMBIA) ;
	this->deck[17] = new Card() ;
	this->deck[17]->setType(Card::JAMAICA) ;
	this->deck[18] = new Card() ;
	this->deck[18]->setType(Card::JAMAICA) ;
	this->deck[19] = new Card() ;
	this->deck[19]->setType(Card::JAMAICA) ;
	this->deck[20] = new Card() ;
	this->deck[20]->setType(Card::JAMAICA) ;
	this->deck[21] = new Card() ;
	this->deck[21]->setType(Card::JAMAICA) ;
	this->deck[22] = new Card() ;
	this->deck[22]->setType(Card::PANAMA) ;
	this->deck[23] = new Card() ;
	this->deck[23]->setType(Card::PANAMA) ;
	this->deck[24] = new Card() ;
	this->deck[24]->setType(Card::PANAMA) ;
	this->deck[25] = new Card() ;
	this->deck[25]->setType(Card::PANAMA) ;
	this->deck[26] = new Card() ;
	this->deck[26]->setType(Card::PANAMA) ;
	this->deck[27] = new Card() ;
	this->deck[27]->setType(Card::DR_FEELGOOD) ;
	
	//Create all heat on cards
	this->deck[28] = new Card() ;
	this->deck[28]->setType(Card::BUST) ;
	this->deck[29] = new Card() ;
	this->deck[29]->setType(Card::BUST) ;
	this->deck[30] = new Card() ;
	this->deck[30]->setType(Card::BUST) ;
	this->deck[31] = new Card() ;
	this->deck[31]->setType(Card::DETAINED) ;
	this->deck[32] = new Card() ;
	this->deck[32]->setType(Card::DETAINED) ;
	this->deck[33] = new Card() ;
	this->deck[33]->setType(Card::DETAINED) ;
	this->deck[34] = new Card() ;
	this->deck[34]->setType(Card::FELONY) ;
	this->deck[35] = new Card() ;
	this->deck[35]->setType(Card::FELONY) ;
	this->deck[36] = new Card() ;
	this->deck[36]->setType(Card::FELONY) ;
	this->deck[37] = new Card() ;
	this->deck[37]->setType(Card::SEARCH_AND_SEIZURE) ;
	this->deck[38] = new Card() ;
	this->deck[38]->setType(Card::SEARCH_AND_SEIZURE) ;
	this->deck[39] = new Card() ;
	this->deck[39]->setType(Card::SEARCH_AND_SEIZURE) ;
	
	//Create all heat off cards
	this->deck[40] = new Card() ;
	this->deck[40]->setType(Card::IMMUNITY) ;
	this->deck[41] = new Card() ;
	this->deck[41]->setType(Card::IMMUNITY) ;
	this->deck[42] = new Card() ;
	this->deck[42]->setType(Card::IMMUNITY) ;
	this->deck[43] = new Card() ;
	this->deck[43]->setType(Card::IMMUNITY) ;
	this->deck[44] = new Card() ;
	this->deck[44]->setType(Card::IMMUNITY) ;
	this->deck[45] = new Card() ;
	this->deck[45]->setType(Card::A_BREEZE_TO_FLY) ;
	this->deck[46] = new Card() ;
	this->deck[46]->setType(Card::A_BREEZE_TO_FLY) ;
	this->deck[47] = new Card() ;
	this->deck[47]->setType(Card::A_BREEZE_TO_FLY) ;
	this->deck[48] = new Card() ;
	this->deck[48]->setType(Card::A_BREEZE_TO_FLY) ;
	this->deck[49] = new Card() ;
	this->deck[49]->setType(Card::A_BREEZE_TO_FLY) ;
	this->deck[50] = new Card() ;
	this->deck[50]->setType(Card::HEARSAY_EVIDENCE) ;
	this->deck[51] = new Card() ;
	this->deck[51]->setType(Card::HEARSAY_EVIDENCE) ;
	this->deck[52] = new Card() ;
	this->deck[52]->setType(Card::HEARSAY_EVIDENCE) ;
	this->deck[53] = new Card() ;
	this->deck[53]->setType(Card::HEARSAY_EVIDENCE) ;
	this->deck[54] = new Card() ;
	this->deck[54]->setType(Card::HEARSAY_EVIDENCE) ;
	this->deck[55] = new Card() ;
	this->deck[55]->setType(Card::CHARGES_DROPPED) ;
	this->deck[56] = new Card() ;
	this->deck[56]->setType(Card::CHARGES_DROPPED) ;
	this->deck[57] = new Card() ;
	this->deck[57]->setType(Card::CHARGES_DROPPED) ;
	this->deck[58] = new Card() ;
	this->deck[58]->setType(Card::CHARGES_DROPPED) ;
	this->deck[59] = new Card() ;
	this->deck[59]->setType(Card::CHARGES_DROPPED) ;
	this->deck[60] = new Card() ;
	this->deck[60]->setType(Card::PAY_FINE_HEAT_OFF) ;
	this->deck[61] = new Card() ;
	this->deck[61]->setType(Card::PAY_FINE_HEAT_OFF) ;
	this->deck[62] = new Card() ;
	this->deck[62]->setType(Card::PAY_FINE_HEAT_OFF) ;
	this->deck[63] = new Card() ;
	this->deck[63]->setType(Card::PAY_FINE_HEAT_OFF) ;
	
	//Create all nirvana cards
	this->deck[64] = new Card() ;
	this->deck[64]->setType(Card::STONEHIGH) ;
	this->deck[65] = new Card() ;
	this->deck[65]->setType(Card::STONEHIGH) ;
	this->deck[66] = new Card() ;
	this->deck[66]->setType(Card::STONEHIGH) ;
	this->deck[67] = new Card() ;
	this->deck[67]->setType(Card::STONEHIGH) ;
	this->deck[68] = new Card() ;
	this->deck[68]->setType(Card::STONEHIGH) ;
	this->deck[69] = new Card() ;
	this->deck[69]->setType(Card::EUPHORIA) ;
	
	//Create all protection cards
	this->deck[70] = new Card() ;
	this->deck[70]->setType(Card::LUST_CONQUERS_ALL) ;
	this->deck[71] = new Card() ;
	this->deck[71]->setType(Card::LUST_CONQUERS_ALL) ;
	this->deck[72] = new Card() ;
	this->deck[72]->setType(Card::GRAB_A_SNACK) ;
	this->deck[73] = new Card() ;
	this->deck[73]->setType(Card::GRAB_A_SNACK) ;
	this->deck[74] = new Card() ;
	this->deck[74]->setType(Card::CATCH_A_BUZZ) ;
	this->deck[75] = new Card() ;
	this->deck[75]->setType(Card::CATCH_A_BUZZ) ;
	
	//Create all paranoia cards
	this->deck[76] = new Card() ;
	this->deck[76]->setType(Card::SOLD_OUT) ;
	this->deck[77] = new Card() ;
	this->deck[77]->setType(Card::SOLD_OUT) ;
	this->deck[78] = new Card() ;
	this->deck[78]->setType(Card::SOLD_OUT) ;
	this->deck[79] = new Card() ;
	this->deck[79]->setType(Card::SOLD_OUT) ;
	this->deck[80] = new Card() ;
	this->deck[80]->setType(Card::DOUBLE_CROSSED) ;
	this->deck[81] = new Card() ;
	this->deck[81]->setType(Card::DOUBLE_CROSSED) ;
	this->deck[82] = new Card() ;
	this->deck[82]->setType(Card::DOUBLE_CROSSED) ;
	this->deck[83] = new Card() ;
	this->deck[83]->setType(Card::UTTERLY_WIPED_OUT) ;
	
	//Create all skim cards
	this->deck[84] = new Card() ;
	this->deck[84]->setType(Card::STEAL_YOUR_NEIGHBORS_POT) ;
	this->deck[85] = new Card() ;
	this->deck[85]->setType(Card::STEAL_YOUR_NEIGHBORS_POT) ;
	this->deck[86] = new Card() ;
	this->deck[86]->setType(Card::STEAL_YOUR_NEIGHBORS_POT) ;
	this->deck[87] = new Card() ;
	this->deck[87]->setType(Card::STEAL_YOUR_NEIGHBORS_POT) ;
	this->deck[88] = new Card() ;
	this->deck[88]->setType(Card::BANKER) ;
	
	//Create all market cards
	this->deck[89] = new Card() ;
	this->deck[89]->setType(Card::MARKET_OPEN) ;
	this->deck[90] = new Card() ;
	this->deck[90]->setType(Card::MARKET_OPEN) ;
	this->deck[91] = new Card() ;
	this->deck[91]->setType(Card::MARKET_OPEN) ;
	this->deck[92] = new Card() ;
	this->deck[92]->setType(Card::MARKET_OPEN) ;
	this->deck[93] = new Card() ;
	this->deck[93]->setType(Card::MARKET_OPEN) ;
	this->deck[94] = new Card() ;
	this->deck[94]->setType(Card::MARKET_OPEN) ;
	this->deck[95] = new Card() ;
	this->deck[95]->setType(Card::MARKET_OPEN) ;
	this->deck[96] = new Card() ;
	this->deck[96]->setType(Card::MARKET_OPEN) ;
	this->deck[97] = new Card() ;
	this->deck[97]->setType(Card::MARKET_OPEN) ;
	this->deck[98] = new Card() ;
	this->deck[98]->setType(Card::MARKET_OPEN) ;
	this->deck[99] = new Card() ;
	this->deck[99]->setType(Card::MARKET_CLOSED) ;
	this->deck[100] = new Card() ;
	this->deck[100]->setType(Card::MARKET_CLOSED) ;
	this->deck[101] = new Card() ;
	this->deck[101]->setType(Card::MARKET_CLOSED) ;
	this->deck[102] = new Card() ;
	this->deck[102]->setType(Card::MARKET_CLOSED) ;
	this->deck[103] = new Card() ;
	this->deck[103]->setType(Card::MARKET_CLOSED) ;
}

//Deck manipulation methods
void Deck::shuffleDeck(void)
{
	//RESEARCH CARD SHUFFLEING ALGORITHUM
}