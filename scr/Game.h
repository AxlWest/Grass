#pragma once

class BitmapLoader ;
class RenderEngine ;
class Background ;

class Game
{
	private :

		bool SplashScreenBool ;

		BitmapLoader* bitmapLoader ;
		Background* splashScreen ;
		RenderEngine* renderEngine ;

	public :

		//Class creation
		Game(RenderEngine* renderEngine) ;
		~Game(void) ;
		void init(void) ;

		void gameInput(unsigned char key , int x , int y) ;
} ;

