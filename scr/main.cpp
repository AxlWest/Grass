#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "glut.h"
#include "AxlsOpenGLClass.h"
#include "Game.h"


using namespace std ;

float angle = 0.0 ;

AxlsOpenGLClass* openGLClass ;

Game* game ;

GLdouble camrea[3] = {0.0 , 0.0 , 10.0} ;
GLdouble center[3] = {0.0 , 0.0 , 0.0} ;
GLdouble orientation[3] = {0.0 , 1.0 , 0.0} ;

//////////////////
//Light settings//
//////////////////

GLfloat light_ambient[]= { 0.5f, 0.5f, 0.5f, 0.1f } ;
GLfloat light_diffuse[]= { 1.0f, 1.0f, 1.0f, 0.0f } ;
GLfloat light_specular[]= { 1.0f, 1.0f, 1.0f, 0.0f } ;
GLfloat light_position[]= { 0.0f, 0.0f, 20.0f, 0.0f } ;

//////////////////////
//Light settings end//
//////////////////////

//////////////////////
//Materials settings//
//////////////////////

GLfloat mat_ambient[]= { 1.0f, 1.0f, 1.0f, 0.0f } ;
GLfloat mat_diffuse[]= { 0.5f, 0.5f, 0.0f, 0.0f } ;
GLfloat mat_specular[]= { 1.0f, 1.0f, 1.0f, 0.0f } ;
GLfloat mat_shininess[]= { 1.0f } ;

//////////////////////////
//Materials settings end//
//////////////////////////

void reshape(int width , int height)
{
	openGLClass->resize(width , height) ;
}

void basicUserInput(unsigned char key , int x , int y)
{
	openGLClass->basicUserInput(key , x , y) ;
}

void draw(void)
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;

	//glClearColor(1.0f, 1.0f, 1.0f, 0.0f) ; //Sets backgroung colour to white

	//glLoadIdentity() ;

	//openGLClass->positionCamera(camrea , center , orientation) ;

	////////////////////////////////////////////////////////////
	openGLClass->draw() ;
	////////////////////////////////////////////////////////////

	//glutSwapBuffers() ;
}

void init()
{
	//Lights initialization and activation
    glLightfv (GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, light_specular);
    glLightfv (GL_LIGHT1, GL_POSITION, light_position);    
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);

    //Materials initialization and activation
	glMaterialfv (GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_specular);
    glMaterialfv (GL_FRONT, GL_POSITION, mat_shininess);    

	//Other initializations
    glShadeModel(GL_SMOOTH); // Type of shading for the polygons
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Texture mapping perspective correction
    glEnable(GL_TEXTURE_2D); // Texture mapping ON
    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL); // Polygon rasterization mode (polygon filled)
	glEnable(GL_CULL_FACE); // Enable the back face culling
    glEnable(GL_DEPTH_TEST); // Enable the depth test 

	openGLClass = new AxlsOpenGLClass() ;

	game = new Game(openGLClass->getRenderEngine()) ;
	game->init() ;
}

int main(int argc , char** argv)
{
	

	glutInit(&argc , argv) ;
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA) ;
	glutInitWindowSize(800 , 450) ;
	glutInitWindowPosition(450 , 200) ;
	glutCreateWindow("Grass") ;

	init() ;

	glutReshapeFunc(reshape) ;
	glutDisplayFunc(draw) ;
	glutIdleFunc(draw) ;
	glutKeyboardFunc(basicUserInput) ;
	

	glutMainLoop() ;

	if(openGLClass != NULL)
	{
		delete openGLClass ;
	}

	if(game != NULL)
	{
		delete game ;
	}

	return 0 ;
}