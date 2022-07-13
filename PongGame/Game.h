#pragma once
#include"SDL.h"

#include<vector>

struct Vector2 {
	float x;
	float y;
};

class Game {
public:
	Game();
	// Game logic
	bool Initialize();
	void RunLoop();
	void Shutdown();

	// Actor Controll
	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	//データロード
	void LoadData();
	void UnloadData();

	// all Actors
	std::vector<class Actor*> mActors;
	// all pending Actors
	std::vector<class Actor*> mPendingActors;
	bool mIsUpdatingActors;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	unsigned mTickCount;
	bool mIsRunning;
};