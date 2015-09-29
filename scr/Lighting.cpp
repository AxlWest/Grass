#include "Lighting.h"

//////////////////
//Class creation//
//////////////////

Lighting::Lighting(void)
{
    this->switchedOn = false ;
    
    this->lightSpotExponent = 0 ;
    this->lightSpotCutoff = 180 ;
    this->lightConstantAttenuation = 1 ;
    this->lightLinearAttenuation = 0 ;
    this->lightQuadraticAttenuation = 0 ;

    this->lightAmbient[0] = 0.0f ;
    this->lightAmbient[1] = 0.0f ;
    this->lightAmbient[2] = 0.0f ;
    this->lightAmbient[3] = 1.0f ;
    this->lightDiffuse[0] = 1.0f ;
    this->lightDiffuse[1] = 1.0f ;
    this->lightDiffuse[2] = 1.0f ;
    this->lightDiffuse[3] = 1.0f ;
    this->lightSpecular[0] = 1.0f ;
    this->lightSpecular[1] = 1.0f ;
    this->lightSpecular[2] = 1.0f ;
    this->lightSpecular[3] = 1.0f ;
    this->lightPosition[0] = 0.0f ;
    this->lightPosition[1] = 0.0f ;
    this->lightPosition[2] = 1.0f ;
    this->lightPosition[3] = 0.0f ;
    this->lightSpotDirection[0] = 0.0f ;
    this->lightSpotDirection[1] = 0.0f ;
    this->lightSpotDirection[2] = 0.0f ;
    this->lightSpotDirection[3] = -1.0f ;
}

Lighting::~Lighting()
{

}

void Lighting::createDirectionalLight(GLenum light)
{
    this->myLight = light ;

    glLightfv (light , GL_AMBIENT , this->lightAmbient) ;
    glLightfv (light , GL_DIFFUSE , this->lightDiffuse) ;
    glLightfv (light , GL_SPECULAR , this->lightSpecular) ;
    glLightfv (light , GL_POSITION , this->lightPosition) ;
}

void Lighting::createSpotlight(GLenum light)
{
    this->myLight = light ;

    glLightf(light , GL_SPOT_CUTOFF , this->lightSpotCutoff) ;
    glLightf(light , GL_SPOT_EXPONENT , this->lightSpotExponent) ;

    glLightfv (light , GL_AMBIENT , this->lightAmbient) ;
    glLightfv (light , GL_DIFFUSE , this->lightDiffuse) ;
    glLightfv (light , GL_SPECULAR , this->lightSpecular) ;
    glLightfv (light , GL_POSITION , this->lightPosition) ;
    glLightfv (light , GL_SPOT_DIRECTION , this->lightSpotDirection) ;
}

void Lighting::initLighting(void)
{
    glEnable(GL_LIGHTING) ;
}

//////////////////////
//End class creation//
//////////////////////

////////
//Gets//
////////

bool Lighting::getSwitchedOn(void)
{
    return this->switchedOn ;
}

GLfloat Lighting::getSpotCutoff(void)
{
    return this->lightSpotCutoff ;
}

GLfloat Lighting::getSpotExponent(void)
{
    return this->lightSpotExponent ;
}

GLfloat Lighting::getConstantAttenuation(void)
{
    return this->lightConstantAttenuation ;
}

GLfloat Lighting::getLinearAttenuation(void)
{
    return this->lightLinearAttenuation ;
}

GLfloat Lighting::getQuadraticAttenuation(void)
{
    return this->lightQuadraticAttenuation ;
}

GLfloat* Lighting::getAmbient(void)
{
    return this->lightAmbient ;
}

GLfloat* Lighting::getDiffuse(void)
{
    return this->lightDiffuse ;
}

GLfloat* Lighting::getSpecular(void)
{
    return this->lightSpecular ;
}

GLfloat* Lighting::getPosition(void)
{
    return this->lightPosition ;
}

GLfloat* Lighting::getSpotDirection(void)
{
    return this->lightSpotDirection ;
}

////////////
//End gets//
////////////

////////
//Sets//
////////

void Lighting::getSpotCutoff(GLfloat angle)
{
    this->lightSpotCutoff = angle ;

    glLightf(this->myLight , GL_SPOT_CUTOFF , this->lightSpotCutoff) ;
}

void Lighting::getSpotExponent(GLfloat factor)
{
    this->lightSpotExponent = factor ;

    glLightf(this->myLight , GL_SPOT_EXPONENT , this->lightSpotExponent) ;
}

void Lighting::getConstantAttenuation(GLfloat factor)
{
    this->lightConstantAttenuation = factor ;

    glLightf(this->myLight , GL_CONSTANT_ATTENUATION , this->lightConstantAttenuation) ;
}

void Lighting::getLinearAttenuation(GLfloat factor)
{
    this->lightLinearAttenuation = factor ;

    glLightf(this->myLight , GL_LINEAR_ATTENUATION , this->lightLinearAttenuation) ;
}

void Lighting::getQuadraticAttenuation(GLfloat factor)
{
    this->lightQuadraticAttenuation = factor ;

    glLightf(this->myLight , GL_QUADRATIC_ATTENUATION , this->lightQuadraticAttenuation) ;
}

void Lighting::setAmbient(float r , float g , float b , float a)
{
    this->lightAmbient[0] = r ;
    this->lightAmbient[1] = g ;
    this->lightAmbient[2] = b ;
    this->lightAmbient[3] = a ;

    glLightfv (this->myLight , GL_AMBIENT , this->lightAmbient) ;
}

void Lighting::setDiffuse(float r , float g , float b , float a)
{
    this->lightDiffuse[0] = r ;
    this->lightDiffuse[1] = g ;
    this->lightDiffuse[2] = b ;
    this->lightDiffuse[3] = a ;

    glLightfv (this->myLight , GL_DIFFUSE , this->lightDiffuse) ;
}

void Lighting::setSpecular(float r , float g , float b , float a)
{
    this->lightSpecular[0] = r ;
    this->lightSpecular[1] = g ;
    this->lightSpecular[2] = b ;
    this->lightSpecular[3] = a ;

    glLightfv (this->myLight , GL_SPECULAR , this->lightSpecular) ;
}

void Lighting::setPosition(float x , float y , float z , float w)
{
    this->lightPosition[0] = x ;
    this->lightPosition[1] = y ;
    this->lightPosition[2] = z ;
    this->lightPosition[3] = w ;

    glLightfv (this->myLight , GL_POSITION , this->lightPosition) ;
}

void Lighting::setSpotDirection(float x , float y , float z)
{
    this->lightSpotDirection[0] = x ;
    this->lightSpotDirection[1] = y ;
    this->lightSpotDirection[2] = z ;

    glLightfv (this->myLight , GL_SPOT_DIRECTION , this->lightSpotDirection) ;
}

////////////
//End sets//
////////////

////////////////
//Toggle light//
////////////////

void Lighting::toggleLighting(void)
{
    if(this->switchedOn == true)
    {
        glDisable(this->myLight) ;

        this->myLight = false ;
    }
    else
    {
        glEnable(this->myLight) ;

        this->myLight = true ;
    }
}

////////////////////
//End toggle light//
////////////////////

///////////////////
//Use attenuation//
///////////////////

void Lighting::useConstantAttenuation(void)
{
    glLightf(this->myLight , GL_CONSTANT_ATTENUATION , this->lightConstantAttenuation) ;
}

void Lighting::useLinearAttenuation(void)
{
    glLightf(this->myLight , GL_LINEAR_ATTENUATION , this->lightLinearAttenuation) ;
}

void Lighting::useQuadraticAttenuation(void)
{
    glLightf(this->myLight , GL_QUADRATIC_ATTENUATION , this->lightQuadraticAttenuation) ;
}

///////////////////////
//End use attenuation//
///////////////////////
