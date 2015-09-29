#include <stdio.h>
#include "BitmapLoader.h"

GLuint BitmapLoader::texnum[BitmapLoader::TEXTURE_MAX] ;

BitmapLoader::BitmapLoader(void)
{
	this->numberOfStoredTextures = 0 ;
}

BitmapLoader::~BitmapLoader(void)
{
}

void BitmapLoader::openGLBitmapInit(void)
{
	glEnable(GL_TEXTURE_2D) ;

	glGenTextures(8 , texnum) ;
}

GLuint BitmapLoader::loadBitmapTexture(const char* imagePathway)
{
	if(this->numberOfStoredTextures < this->TEXTURE_MAX) //Checks to see if there are not to many textures already
	{
		this->bitmapData = this->bitmapFileLoader(imagePathway) ;

		glBindTexture(GL_TEXTURE_2D , texnum[this->numberOfStoredTextures]) ;

		glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER, GL_NEAREST) ;
		glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER, GL_NEAREST) ;

		glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGB , bitmapInfoHeader.biWidth , bitmapInfoHeader.biHeight , 0 , GL_RGB , GL_UNSIGNED_BYTE , bitmapData) ;

		this->numberOfStoredTextures++ ; //Increments the number of textures that are stored
	}
	return this->texnum[(this->numberOfStoredTextures -1)] ;
}

unsigned char* BitmapLoader::bitmapFileLoader(const char* imagePathway)
{
	FILE *filePtr ;
	
	BITMAPFILEHEADER	bitmapFileHeader;		// bitmap file header
	unsigned char		*bitmapImage;			// bitmap image data
	int					imageIdx = 0;		// image index counter
	unsigned char		tempRGB;				// swap variable

	// open filename in "read binary" mode
	filePtr = fopen(imagePathway, "rb") ;

	if (filePtr == NULL)
	{
		return NULL ;
	}

	// read the bitmap file header
	fread(&bitmapFileHeader , sizeof(BITMAPFILEHEADER) , 1 , filePtr) ;
	
	// verify that this is a bitmap by checking for the universal bitmap id
	if(bitmapFileHeader.bfType != BITMAP_ID)
	{
		fclose(filePtr) ;
		return NULL ;
	}

	// read the bitmap information header
	fread(&bitmapInfoHeader , sizeof(BITMAPINFOHEADER) , 1 , filePtr);

	// move file pointer to beginning of bitmap data
	fseek(filePtr , bitmapFileHeader.bfOffBits , SEEK_SET);

	// allocate enough memory for the bitmap image data
	bitmapImage = (unsigned char*)malloc(bitmapInfoHeader.biSizeImage);

	// verify memory allocation
	if (!bitmapImage)
	{
		free(bitmapImage);
		fclose(filePtr);
		return NULL;
	}

	// read in the bitmap image data
	fread(bitmapImage, 1, bitmapInfoHeader.biSizeImage, filePtr);

	// make sure bitmap image data was read
	if (bitmapImage == NULL)
	{
		fclose(filePtr) ;
		return NULL ;
	}

	// swap the R and B values to get RGB since the bitmap color format is in BGR
	for (imageIdx = 0; imageIdx < bitmapInfoHeader.biSizeImage; imageIdx+=3)
	{
		tempRGB = bitmapImage[imageIdx] ;
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2] ;
		bitmapImage[imageIdx + 2] = tempRGB ;
	}

	// close the file and return the bitmap image data
	fclose(filePtr) ;

	return bitmapImage ;
}

GLuint BitmapLoader::getTexnum(int num)
{
	if(num < this->TEXTURE_MAX)
	{
		return this->texnum[num] ;
	}
}