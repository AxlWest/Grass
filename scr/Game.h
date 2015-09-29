#pragma once

class BitmapLoader ;
class RenderEngine ;
class Background ;

class Game
{
	private :

		BitmapLoader* bitmapLoader ;
		Background* splashScreen ;
		RenderEngine* renderEngine ;

	public :

		//Class creation
		Game(RenderEngine* renderEngine) ;
		~Game(void) ;
		void init(void) ;
} ;

