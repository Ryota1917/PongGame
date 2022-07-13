#pragma once
#include"Actor.h"

class PaddleActor :public Actor {
public:
	PaddleActor(class Game* game, float x, float y);

	void UpdateActor(float deltaTime)override;
	void Draw(SDL_Renderer* renderer)override;
	void ProcessKeybord(const Uint8* keyState)override;
	
	int GetHight() { return mHeight; }
	int GetWidth() { return mWidth; }
	float GetPositionX() { return mX; }
	float GetPositionY() { return mY; }

private:
	float mX;
	float mY;
	float mVelX;
	float mVelY;
	int mHeight;
	int mWidth;
};