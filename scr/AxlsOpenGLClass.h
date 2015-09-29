#pragma once

#include "glut.h"
#include "RenderEngine.h"

class AxlsOpenGLClass
{
	private :

		RenderEngine* renderEngine ;

	public :

		//Class creation
		AxlsOpenGLClass(void) ; //Constructor
		~AxlsOpenGLClass(void) ; //Destructor
		void init(void) ;

		/////////
		//Enums//
		/////////
		enum XYZW {X = 0 , Y = 1 , Z = 2 , W = 3} ; //Enum for point/vectors
		/////////////
		//End enums//
		/////////////

		///////////////////////////////
		//Callback functions for GLUT//
		///////////////////////////////
		void resize(int width , int height) ; //Resizes the Screen
		void draw(void) ; //Draws the background and flips the buffers
		void basicUserInput(unsigned char key , int x , int y) ; //Responds to basic keybord keys
		void advancedUserInput(int key , int x , int y) ; //Responds to Special keybord keys
		//////////////////////////////////
		//End of GLUT callback functions//
		//////////////////////////////////

		//////////////////////////
		//Basic camera functions//
		//////////////////////////
		void positionCamera(GLdouble* lookAt) ; //Looks at a spesific point of the screen
		void positionCamera(GLdouble* eyeXYZ , GLdouble* centerXYX , GLdouble* orientationXYZ) ; //Overloaded function to look at a spesific point of the screen
		//////////////////////////////
		//End basic camera functions//
		//////////////////////////////

		RenderEngine* getRenderEngine(void) ; //Returns a pointer to the render engine (if there is not one it will create one then pass it back)
} ;

