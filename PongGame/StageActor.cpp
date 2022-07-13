#include"StageActor.h"

StageActor::StageActor(Game* game):Actor(game) {
	SDL_Rect wall1{ 0,0,1024,10 };
	SDL_Rect wall2{ 0,768-10,1024,10 };
	SDL_Rect wall3{ 1024 - 10,0,10,768 };
	mWalls.push_back(wall1);
	mWalls.push_back(wall2);
	mWalls.push_back(wall3);
}

void StageActor::Draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (auto wall : mWalls) {
		SDL_RenderFillRect(renderer, &wall);
	}
}
