#include"BallActor.h"
#include"Game.h"

BallActor::BallActor(Game* game, float x, float y, float velx, float vely, std::vector<class PaddleActor*> paddles):
	Actor(game),
	mX(x),mY(y),mVelX(velx),mVelY(vely),
	mPaddles(paddles)
{}

void BallActor::UpdateActor(float deltaTime) {
	//右との接触
	if (mX >= (1024.0f - 10) && mVelX > 0.0f)
	{
		mVelX *= -1;
	}

	//上との接触
	if (mY <= 10 && mVelY < 0.0f)
	{
		mVelY *= -1;
	}
	//下との接触
	else if (mY >= (768 - 10) && mVelY > 0.0f)
	{
		mVelY *= -1;
	}

	//パドルとの接触
	for (auto paddle : mPaddles) {
		float diff = mY - paddle->GetPositionY();
		diff = (diff > 0) ? diff : -diff;
		if (diff <= paddle->GetHight() / 2.0f && mX <= paddle->GetPositionX()+paddle->GetWidth()/2.0f && mX >= paddle->GetPositionX() && mVelX < 0.0f) {
			mVelX *= -1;
		}
	}

	mX += mVelX * deltaTime;
	mY += mVelY * deltaTime;

	//ボールが外に出たら，新しく作る
	//if (mX < -10) {
	//	GetGame()->AddActor(new BallActor(GetGame(), 200, 200, 100, 100, mPaddles));
	//	GetGame()->RemoveActor(this);
	//}
}

void BallActor::Draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Rect ball{
		static_cast<int>(mX - 8),
		static_cast<int>(mY - 8),
		16,16
	};
	SDL_RenderFillRect(renderer, &ball);
}