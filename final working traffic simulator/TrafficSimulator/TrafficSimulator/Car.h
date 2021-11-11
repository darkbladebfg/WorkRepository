#pragma once
#include <SDL.h>

class Car 
{

private:

	int car_speed=0;
	int car_width;
	int car_height;
	int x_pos;
	int y_pos;
	SDL_Rect fillRect;

public:

	int getCarSpeed();
	int getCarWidth();
	int getCarHeight();
	int getCarXPos();
	int getCarYPos();
	void spawn(int, int, SDL_Renderer* renderer);
	void move(int, SDL_Renderer*);
	void stop();
	void setCarSpeed(int);
	void setXPos(int);
	void setYpos(int);
	void setCarWidth(int);
	void setCarHeight(int);
	void setCarGeometry(SDL_Rect);
    SDL_Rect getCarGeometry();
};
