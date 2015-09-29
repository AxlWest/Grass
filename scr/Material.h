#pragma once

#include "glut.h"
#include <GL/gl.h>

class Material
{
    private :

        GLfloat materialShininess ;

        GLfloat materialAmbient[4] ;
        GLfloat materialDiffuse[4] ;
        GLfloat materialSpecular[4] ;
        GLfloat materialEmission[4] ;
        GLfloat materialColourIndexes[3] ;

    public :

        //Class creation
        Material(void) ;
        ~Material(void) ;
        void initMaterial(void) ;

        //Gets
        GLfloat getShininess(void) ;
        GLfloat* getAmbient(void) ;
        GLfloat* getDiffuse(void) ;
        GLfloat* getSpecular(void) ;
        GLfloat* getEmission(void) ;
        GLfloat* getColourIndexes(void) ;

        //Sets
        void setShininess(float s) ;
        void setAmbient(float r , float g , float b , float a) ;
        void setDiffuse(float r , float g , float b , float a) ;
        void setSpecular(float r , float g , float b , float a) ;
        void setEmission(float r , float g , float b , float a) ;
        void setColourIndexes(float r , float g , float b ) ;

        //Use aditional matirial types (can also be actavated by changing there values)
        void useEmission(void) ;
        void useColourIndexes(void) ;
} ;
