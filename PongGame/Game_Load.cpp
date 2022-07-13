#include"Game.h"
#include"Actor.h"
#include"StageActor.h"
#include"BallActor.h"
#include"PaddleActor.h"

void Game::LoadData() {
	AddActor(new StageActor(this));
	std::vector<PaddleActor*> paddles;
	paddles.push_back(new PaddleActor(this, 5, 100));


	AddActor(new BallActor(this, 300, 100, -80, 100, paddles));
	AddActor(new BallActor(this, 100, 100, 50, 100, paddles));

	for (auto paddle : paddles) {
		AddActor(paddle);
	}
}

void Game::UnloadData() {

}