#include "Game.h"
#include "BitmapLoader.h"
#include "Background.h"
#include "RenderEngine.h"


Game::Game(RenderEngine* renderEngine)
{
	this->renderEngine = renderEngine ;
}


Game::~Game(void)
{

}

void Game::init(void)
{
	this->bitmapLoader =  new BitmapLoader() ;
	this->bitmapLoader->openGLBitmapInit() ;

	this->splashScreen = new Background(this->bitmapLoader->loadBitmapTexture("../Textures/splashScreenMain.bmp")) ;
	this->splashScreen->objloader("../OBJ/cube.obj") ;
	this->renderEngine->addToDrawList(this->splashScreen) ;
}