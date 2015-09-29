#include "Background.h"
#include "glut.h"

Background::Background(GLuint myTextureNum)
{
	this->myTextureNum = myTextureNum ;
}

Background::~Background(void)
{
}

void Background::draw(void)
{
	glPushMatrix() ;

	//Translate
	glTranslatef(0.0 , 0.0 , -10.0) ;

	//Scale
	glScalef(30.0 , 20.0 , 0.0) ;
	
	//Binds the Texture
	glBindTexture(GL_TEXTURE_2D , this->myTextureNum) ;

	Object_type::draw() ;

	glPopMatrix() ;
	
}

void Background::update(void)
{

}