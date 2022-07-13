#pragma once
#include"Actor.h"
#include<vector>


class StageActor :public Actor {
public:
	StageActor(Game* game);
	void Draw (SDL_Renderer* renderer)override;

private:
	std::vector<SDL_Rect> mWalls;
};