#pragma once

#include "glut.h"
#include <GL/gl.h>

class Lighting
{
    private :

        bool switchedOn ; //True if the light is enabled
        
        GLfloat lightSpotCutoff ; //The spotlight cutoff angle
        GLfloat lightSpotExponent ;
        GLfloat lightConstantAttenuation ;
        GLfloat lightLinearAttenuation ;
        GLfloat lightQuadraticAttenuation ;

        GLfloat lightAmbient[4] ; //Ambient RGBA intencity of the light
        GLfloat lightDiffuse[4] ; //Difuce RGBA intencity of the light
        GLfloat lightSpecular[4] ; //Specular RGBA intencity of the light
        GLfloat lightPosition[4] ; //The lights X, Y, Z and W position
        GLfloat lightSpotDirection[3] ; //The lights X,Y and Z position

        GLenum myLight ; //Stores the lights identity

    public :

        //Class creators
        Lighting(void) ; //Constructor
        ~Lighting(void) ; //Destructor
        void createDirectionalLight(GLenum light) ; //Gives OpenGL the lights infomation
        void createSpotlight(GLenum light) ; //Gives OpenGL the lights infomation
        static void initLighting(void) ; //Static functon to enable OpenGL lighting

        //Gets
        bool getSwitchedOn(void) ;
        GLfloat getSpotCutoff(void) ;
        GLfloat getSpotExponent(void) ;
        GLfloat getConstantAttenuation(void) ;
        GLfloat getLinearAttenuation(void) ;
        GLfloat getQuadraticAttenuation(void) ;
        GLfloat* getAmbient(void) ;
        GLfloat* getDiffuse(void) ;
        GLfloat* getSpecular(void) ;
        GLfloat* getPosition(void) ;
        GLfloat* getSpotDirection(void) ;

        //Sets
        void getSpotCutoff(GLfloat angle) ;
        void getSpotExponent(GLfloat factor) ;
        void getConstantAttenuation(GLfloat factor) ;
        void getLinearAttenuation(GLfloat factor) ;
        void getQuadraticAttenuation(GLfloat factor) ;
        void setAmbient(float r , float g , float b , float a) ;
        void setDiffuse(float r , float g , float b , float a) ;
        void setSpecular(float r , float g , float b , float a) ;
        void setPosition(float x , float y , float z , float w) ;
        void setSpotDirection(float x , float y , float z) ;
        
        //Toggle lighting
        void toggleLighting(void) ;

        //Use attenuation (Can also be used by changing its value using the sets methods)
        void useConstantAttenuation(void) ;
        void useLinearAttenuation(void) ;
        void useQuadraticAttenuation(void) ;
} ;
