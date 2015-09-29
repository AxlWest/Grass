#pragma once

#include "glut.h"
#include "GObjectLoader.h"

class Background : public Object_type
{
	private :

		GLuint myTextureNum ;

	public :

		Background(GLuint myTextureNum) ;
		~Background(void) ;

		void draw() ;
		void update() ;
} ;

