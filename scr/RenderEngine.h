#pragma once

class Drawable ;

class RenderEngine
{
    private :

        Drawable* dFirst ; //Keeps track of the first element in the draw list
        Drawable* uFirst ; //Keeps track of the first element in the update list

    public :

        //Class creation
        RenderEngine(void) ; //Constructor
        ~RenderEngine(void) ; //Destructor

        //List methods
        void addToDrawList(Drawable* pointer) ; //Adds the passed in class to the end of the draw list
        void addToUpdateList(Drawable* pointer) ; //Adds the passed in class to the end of the update list
        void addToBothLists(Drawable* pointer) ; //Adds the passed in class to the end of both lists
        void removeFromDrawList(Drawable* pointer) ; //Removes the passed in class from the draw list (responsible for removing the element only not deleting it)
        void removeFromUpdateList(Drawable* pointer) ; //Removes the passed in class from the update list (responsible for removing the element only not deleting it)
        void removeFromBothLists(Drawable* pointer) ; //Removes the passed in class from both lists (responsible for removing the element only not deleting it)
        void drawList(void) ; //Calls the draw method for everything in the list
        void updateList(void) ; //Calls the update method for everything in the list
} ;
