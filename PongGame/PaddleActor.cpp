#include"PaddleActor.h"

PaddleActor::PaddleActor(class Game* game, float x, float y):
	Actor(game),
	mX(x), mY(y), mVelX(0), mVelY(0),mHeight(100),mWidth(15)
{}

void PaddleActor::UpdateActor(float deltaTime) {
	//yの予測される変化量
	float dY = deltaTime * mVelY;
	//Paddleがステージからでないとき移動させる
	if (mY + dY >= 25 && mY + dY <= 768 - 25) {
		mY += dY;
	}

}
void PaddleActor::Draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, new SDL_Rect{ static_cast<int>(mX-mWidth/2.0f),static_cast<int>(mY-mHeight/2.0f),mWidth, mHeight });
}
void PaddleActor::ProcessKeybord(const Uint8* keyState) {
	if (keyState[SDL_SCANCODE_W]) {
		mVelY = -100;
	}
	else if (keyState[SDL_SCANCODE_S]) {
		mVelY = 100;
	}
	else {
		mVelY = 0;
	}
}