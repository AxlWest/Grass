#include "Game.h"
#include "BitmapLoader.h"
#include "Background.h"
#include "RenderEngine.h"


Game::Game(RenderEngine* renderEngine)
{
	this->SplashScreenBool = true ;
	this->bitmapLoader = NULL ;
	this->splashScreen = NULL ;
	this->renderEngine = NULL ;

	this->renderEngine = renderEngine ;
}


Game::~Game(void)
{
	if(this->bitmapLoader != NULL)
	{
		delete this->bitmapLoader ;
		this->bitmapLoader = NULL ;
	}

	if(this->splashScreen != NULL)
	{
		delete this->splashScreen ;
		this->splashScreen = NULL ;
	}
}

void Game::init(void)
{
	this->bitmapLoader =  new BitmapLoader() ;
	this->bitmapLoader->openGLBitmapInit() ;

	this->splashScreen = new Background(this->bitmapLoader->loadBitmapTexture("../Textures/splashScreenMain.bmp")) ;
	this->splashScreen->objloader("../OBJ/cube.obj") ;
	this->renderEngine->addToDrawList(this->splashScreen) ;
}

void Game::gameInput(unsigned char key , int x , int y)
{
	if(this->SplashScreenBool == true)
	{}
}