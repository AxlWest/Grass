#pragma once

#define NULL 0

class Drawable
{
    private :

        Drawable* next ;

    public :

        //Class creation
        Drawable(void) ; //Constructor
        ~Drawable(void) ; //Deconstrustor

        virtual void draw() = 0 ;
        virtual void update() = 0 ;

        //Gets
        Drawable* getNext(void) ;

        //Sets
        void setNext(Drawable* pointer) ;
} ;
