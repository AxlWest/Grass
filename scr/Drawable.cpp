#include "Drawable.h"

Drawable::Drawable(void)
{
    this->next = NULL ;
}

Drawable::~Drawable(void)
{

}

////////
//Gets//
////////

Drawable* Drawable::getNext(void)
{
    return this->next ;
}

////////////
//End gets//
////////////

////////
//Sets//
////////

void Drawable::setNext(Drawable* pointer)
{
    this->next = pointer ;
}

////////////
//End sets//
////////////
