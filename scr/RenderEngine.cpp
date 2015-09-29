#include "RenderEngine.h"
#include "Drawable.h"

#define NULL 0

RenderEngine::RenderEngine(void)
{
    this->dFirst = NULL ;
}

RenderEngine::~RenderEngine(void)
{

}

void RenderEngine::addToDrawList(Drawable* pointer)
{
    if(this->dFirst == NULL)
    {
        this->dFirst = pointer ;

        return ;
    }

    Drawable* temp = this->dFirst->getNext() ; //Set temp to the next element in the list

    while(temp->getNext() != NULL)
    {
        //Not at the end of the list
        temp = temp->getNext() ; //Make temp equal to the next element in the list
    }
    //temp is now equal to the last element in the list
    temp->setNext(pointer) ;
}

void RenderEngine::addToUpdateList(Drawable* pointer)
{
    if(this->uFirst == NULL)
    {
        this->uFirst = pointer ;

        return ;
    }

    Drawable* temp = this->uFirst->getNext() ; //Set temp to the next element in the list

    while(temp->getNext() != NULL)
    {
        //Not at the end of the list
        temp = temp->getNext() ; //Make temp equal to the next element in the list
    }
    //temp is now equal to the last element in the list
    temp->setNext(pointer) ;
}

void RenderEngine::addToBothLists(Drawable* pointer)
{
    this->addToDrawList(pointer) ;
    this->addToUpdateList(pointer) ;
}

void RenderEngine::removeFromDrawList(Drawable* pointer)
{
    if(this->dFirst == NULL)
    {
        return ; //Return because the list is empty
    }

    Drawable* temp = NULL ;

    if(this->dFirst == pointer)//Check to
    {
        //Need to remove the first element of the list
        if(this->dFirst->getNext() == NULL) //Need to check if the list has a second element
        {
            this->dFirst = NULL ; //It did so only need to remove first element
        }
        else //There is more than one element in the list
        {
            dFirst = dFirst->getNext() ; //Set the first element of the list to the second
        }
        //The element has been removed from the list
    }
    else
    {
        temp = dFirst->getNext() ; //Set temp to the next element in the list

        if(temp == pointer) //Check to see if temp is the element we need to remove
        {
            if(dFirst->getNext()->getNext() != NULL) //Check to see if there are more that 2 elements in the list
            {
                dFirst->setNext(dFirst->getNext()->getNext()) ;  //Set the second element in the list to the third
            }
            else //There are only two
            {
                dFirst->setNext(NULL) ; //Remove the second element
            }
        }
        else //It was not
        {
            while(temp->getNext() != NULL) //Loop while there are still more elements in the list
            {
                if(temp->getNext() == pointer) //Check to see if the next element is the one we are looking for
                {
                    if(temp->getNext()->getNext() != NULL) //Check to see if there are any more elements after the one we need to remove
                    {
                        temp->setNext(temp->getNext()->getNext()) ;

                        return ; //the element has been removed from the list
                    }
                    else //There where not
                    {
                        temp->setNext(NULL) ;

                        return ; //the element has been removed from the list
                    }
                }
                else //It was not
                {
                    temp = temp->getNext() ; //Set temp to the next element in the list
                }
            }
        }
    }
    //The element was not in the list
}

void RenderEngine::removeFromUpdateList(Drawable* pointer)
{
    if(this->uFirst == NULL)
    {
        return ; //Return because the list is empty
    }

    Drawable* temp = NULL ;

    if(this->uFirst == pointer)//Check to
    {
        //Need to remove the first element of the list
        if(this->uFirst->getNext() == NULL) //Need to check if the list has a second element
        {
            this->uFirst = NULL ; //It did so only need to remove first element
        }
        else //There is more than one element in the list
        {
            uFirst = uFirst->getNext() ; //Set the first element of the list to the second
        }
        //The element has been removed from the list
    }
    else
    {
        temp = uFirst->getNext() ; //Set temp to the next element in the list

        if(temp == pointer) //Check to see if temp is the element we need to remove
        {
            if(uFirst->getNext()->getNext() != NULL) //Check to see if there are more that 2 elements in the list
            {
                uFirst->setNext(uFirst->getNext()->getNext()) ;  //Set the second element in the list to the third
            }
            else //There are only two
            {
                uFirst->setNext(NULL) ; //Remove the second element
            }
        }
        else //It was not
        {
            while(temp->getNext() != NULL) //Loop while there are still more elements in the list
            {
                if(temp->getNext() == pointer) //Check to see if the next element is the one we are looking for
                {
                    if(temp->getNext()->getNext() != NULL) //Check to see if there are any more elements after the one we need to remove
                    {
                        temp->setNext(temp->getNext()->getNext()) ;

                        return ; //the element has been removed from the list
                    }
                    else //There where not
                    {
                        temp->setNext(NULL) ;

                        return ; //the element has been removed from the list
                    }
                }
                else //It was not
                {
                    temp = temp->getNext() ; //Set temp to the next element in the list
                }
            }
        }
    }
    //The element was not in the list
}

void RenderEngine::removeFromBothLists(Drawable *pointer)
{
    this->removeFromDrawList(pointer) ;
    this->removeFromUpdateList(pointer) ;
}

void RenderEngine::drawList(void)
{
    if(dFirst->getNext() == NULL) //Check to see if there is more than one element in the list
    {
        dFirst->draw() ;
    }
    else //There is
    {
        Drawable* temp = dFirst->getNext() ;
        temp->draw() ;

        while(temp->getNext() != NULL)
        {
             temp = temp->getNext() ;
             temp->draw() ;
        }
    }
    //Everything in the list has been drawn
}

void RenderEngine::updateList(void)
{
    if(uFirst->getNext() == NULL) //Check to see if there is more than one element in the list
    {
        uFirst->update() ;
    }
    else //There is
    {
        Drawable* temp = uFirst->getNext() ;
        temp->update() ;

        while(temp->getNext() != NULL)
        {
             temp = temp->getNext() ;
             temp->update() ;
        }
    }
    //Everything in the list has been updated
}
