#pragma once
#include"Actor.h"
#include<vector>
#include "PaddleActor.h"

class BallActor :public Actor {
public:
	BallActor(class Game* game, float x,float y,float velx,float vely, std::vector<class PaddleActor*> paddles);
	void UpdateActor(float deltaTime)override;
	void Draw(SDL_Renderer* renderer)override;
	

private:
	float mX;
	float mY;
	float mVelX;
	float mVelY;
	std::vector<class PaddleActor*> mPaddles;
};