#include "Material.h"

//////////////////
//Class creation//
//////////////////

Material::Material(void)
{
    this->materialShininess = 0.0f ;

    this->materialAmbient[0] = 0.2f ;
    this->materialAmbient[1] = 0.2f ;
    this->materialAmbient[2] = 0.2f ;
    this->materialAmbient[3] = 1.0f ;
    this->materialDiffuse[0] = 0.8f ;
    this->materialDiffuse[1] = 0.8f ;
    this->materialDiffuse[2] = 0.8f ;
    this->materialDiffuse[3] = 1.0f ;
    this->materialSpecular[0] = 0.0f ;
    this->materialSpecular[1] = 0.0f ;
    this->materialSpecular[2] = 0.0f ;
    this->materialSpecular[3] = 1.0f ;
    this->materialEmission[0] = 0.0f ;
    this->materialEmission[1] = 0.0f ;
    this->materialEmission[2] = 0.0f ;
    this->materialEmission[3] = 1.0f ;
    this->materialColourIndexes[0] = 0.0f ;
    this->materialColourIndexes[0] = 1.0f ;
    this->materialColourIndexes[0] = 1.0f ;
}

Material::~Material()
{

}

void Material::initMaterial(void)
{
    glMaterialfv (GL_FRONT , GL_AMBIENT , this->materialAmbient) ;
    glMaterialfv (GL_FRONT , GL_DIFFUSE , this->materialDiffuse) ;
    glMaterialfv (GL_FRONT , GL_SPECULAR , this->materialSpecular) ;
    glMaterialfv (GL_FRONT , GL_SHININESS , &this->materialShininess) ;
}

//////////////////////
//End class creation//
//////////////////////

////////
//Gets//
////////

GLfloat Material::getShininess(void)
{
    return this->materialShininess ;
}

GLfloat* Material::getAmbient(void)
{
    return this->materialAmbient ;
}

GLfloat* Material::getDiffuse(void)
{
    return this->materialDiffuse ;
}

GLfloat* Material::getSpecular(void)
{
    return this->materialSpecular ;
}

GLfloat* Material::getEmission(void)
{
    return this->materialEmission ;
}

GLfloat* Material::getColourIndexes(void)
{
    return this->materialColourIndexes ;
}

////////////
//End gets//
////////////

////////
//Sets//
////////

void Material::setShininess(float s)
{
    this->materialShininess = s ;

    glMaterialfv (GL_FRONT , GL_SHININESS , &this->materialShininess) ;
}

void Material::setAmbient(float r , float g , float b , float a)
{
    this->materialAmbient[0] = r ;
    this->materialAmbient[1] = g ;
    this->materialAmbient[2] = b ;
    this->materialAmbient[3] = a ;

    glMaterialfv (GL_FRONT , GL_AMBIENT , this->materialAmbient) ;
}

void Material::setDiffuse(float r , float g , float b , float a)
{
    this->materialDiffuse[0] = r ;
    this->materialDiffuse[1] = g ;
    this->materialDiffuse[2] = b ;
    this->materialDiffuse[3] = a ;

    glMaterialfv (GL_FRONT , GL_DIFFUSE , this->materialDiffuse) ;
}

void Material::setSpecular(float r , float g , float b , float a)
{
    this->materialSpecular[0] = r ;
    this->materialSpecular[1] = g ;
    this->materialSpecular[2] = b ;
    this->materialSpecular[3] = a ;

    glMaterialfv (GL_FRONT , GL_SPECULAR , this->materialSpecular) ;
}

void Material::setEmission(float r , float g , float b , float a)
{
    this->materialEmission[0] = r ;
    this->materialEmission[1] = g ;
    this->materialEmission[2] = b ;
    this->materialEmission[3] = a ;

    glMaterialfv(GL_FRONT , GL_EMISSION , this->materialEmission) ;
}

void Material::setColourIndexes(float r , float g , float b)
{
    this->materialColourIndexes[0] = r ;
    this->materialColourIndexes[0] = g ;
    this->materialColourIndexes[0] = b ;

    glMaterialfv(GL_FRONT , GL_COLOR_INDEXES , this->materialColourIndexes) ;
}

////////////
//End sets//
////////////

/////////////////////////////////
//Use additional material types//
/////////////////////////////////

void Material::useEmission(void)
{
    glMaterialfv(GL_FRONT , GL_EMISSION , this->materialEmission) ;
}

void Material::useColourIndexes(void)
{
    glMaterialfv(GL_FRONT , GL_COLOR_INDEXES , this->materialColourIndexes) ;
}

/////////////////////////////////
//End additional material types//
/////////////////////////////////
