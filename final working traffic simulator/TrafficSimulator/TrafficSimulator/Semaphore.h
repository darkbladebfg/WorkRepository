#pragma once

#include <SDL.h>

class Semaphore {


public:

	   int x;
	   int y;
	   int length;
	   int state;

	   int id;

	   void draw(SDL_Renderer*);
	 
};