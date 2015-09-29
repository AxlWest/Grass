#include "Card.h"

//Class creation methods
Card::Card(void)
{
	this->type = 27 ; //Set to a non card type
	
	this->cardSet = false ; //Card type has not been set
}

Card::~Card(void)
{}

//Gets and sets methods
void Card::setType(int type)
{
	if(this->cardSet == false) //Checks to see if the type has been set yet
	{
		this->type = type ;
	}
	else
	{
		//The type has been set do nothing
	}
}

int Card::getType(void)
{
	return this->type ;
}