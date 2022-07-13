#pragma once
#include<vector>
#include"SDL.h"

class Actor {
public:
	enum State {
		EActive,
		EPaused,
		EDead,
	};

	Actor(class Game* game);
	virtual ~Actor();

	// Update Actor
	void Update(float deltaTime);
	// Update all Components
	void UpdateComponents(float deltaTime);
	// Actor ì¡óLÇÃçXêV
	virtual void UpdateActor(float deltaTime);

	virtual void ProcessKeybord(const Uint8* keyState);
	virtual void Draw(SDL_Renderer* renderer);

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	State GetState() { return mState; }
	Game* GetGame() { return mGame; }
	void SetState(State state) { mState = state; }

private:
	State mState;

	std::vector<class Component*> mComponents;
	Game* mGame;
};