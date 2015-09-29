#include "AxlsOpenGLClass.h"

#define NULL 0

AxlsOpenGLClass::AxlsOpenGLClass(void)
{
	this->renderEngine = NULL ;
}

AxlsOpenGLClass::~AxlsOpenGLClass(void)
{
	if(this->renderEngine != NULL)
	{
		delete this->renderEngine ;
		this->renderEngine = NULL ;
	}
}

void AxlsOpenGLClass::init(void)
{
	this->renderEngine = new RenderEngine() ;
}

///////////////////////////
//GLUT callback functions//
///////////////////////////
void AxlsOpenGLClass::resize(int width , int height)
{
	if(height == 0)
	{
		height = 1 ;
	}

	float ratio =  width * 1.0 / height ;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION) ;

	// Reset Matrix
	glLoadIdentity() ;

	// Set the viewport to be the entire window
	glViewport(0, 0, width , height) ;

	// Set the correct perspective.
	gluPerspective(45 , ratio , 1 , 100) ;

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW) ;
}

void AxlsOpenGLClass::draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;

	glLoadIdentity() ;

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f) ; //Sets backgroung colour to white

	gluLookAt(	0.0 , 0.0 , 10.0 , 0.0 , 0.0 ,  0.0 , 0.0 , 1.0 ,  0.0 ) ;

	this->renderEngine->drawList() ;

	glutSwapBuffers() ;
}

void AxlsOpenGLClass::basicUserInput(unsigned char key , int x , int y)
{

}

void AxlsOpenGLClass::advancedUserInput(int key , int x , int y)
{

}
//////////////////////////////////
//End of GLUT callback functions//
//////////////////////////////////

//////////////////////////
//Basic camera functions//
//////////////////////////
void AxlsOpenGLClass::positionCamera(GLdouble* lookAt)
{
	gluLookAt(lookAt[X] , lookAt[Y] , lookAt[Z] , lookAt[3] , lookAt[4] , lookAt[5] , lookAt[6] , lookAt[7] , lookAt[8]) ;
}

void AxlsOpenGLClass::positionCamera(GLdouble* eyeXYZ , GLdouble* centerXYX , GLdouble* orientationXYZ)
{
	gluLookAt(eyeXYZ[X] , eyeXYZ[Y] , eyeXYZ[Z] , centerXYX[X] , centerXYX[Y] , centerXYX[Z] , orientationXYZ[X] , orientationXYZ[Y] , orientationXYZ[Z]) ;
}
//////////////////////////////
//End basic camera functions//
//////////////////////////////

RenderEngine* AxlsOpenGLClass::getRenderEngine(void)
{
	if(this->renderEngine == NULL)
	{
		this->renderEngine = new RenderEngine ;

		return this->renderEngine ;
	}
	else
	{
		return this->renderEngine ;
	}
}