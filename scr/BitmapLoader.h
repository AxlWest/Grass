#pragma once

#include <windows.h>
#include "glut.h"

#define BITMAP_ID 0x4D42

class BitmapLoader
{
	private :

		static const int TEXTURE_MAX = 9 ; //The maximum number of textures that can be stored
		
		int numberOfStoredTextures ; //The current number of stored textures

		unsigned char* bitmapData ;

		static GLuint texnum[TEXTURE_MAX] ; //Stores pointers to textures

		BITMAPINFOHEADER bitmapInfoHeader ;

		unsigned char* bitmapFileLoader(const char* imagePathway) ; //Private function that loads the data from the bitmap file

	public :

		BitmapLoader(void) ; //Constructor
		~BitmapLoader(void) ; //Destructor

		void openGLBitmapInit(void) ; //Sets up the bitmap loader for use in an openGL project

		GLuint loadBitmapTexture(const char* imagePathway) ; //This method loads a bitmap image from a given file pathway
		GLuint getTexnum(int) ; //Returns the texture pointer for the integer that you pass in
} ;

