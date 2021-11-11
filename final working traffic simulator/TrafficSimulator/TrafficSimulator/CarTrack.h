#pragma once
#include <SDL.h>

class CarTrack {

private:

	int startPos;
	int endPos;
	int trackWidth;

public:

	void Draw(SDL_Renderer* renderer);

	int getStartPos();
	int getEndPos();
	int getTrackWidth();

	CarTrack(int,int,int);




};