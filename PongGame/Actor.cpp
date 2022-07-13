#include"Actor.h"
#include"Game.h"
#include"Component.h"

Actor::Actor(Game* game) :mGame(game),mState(Actor::EActive) {
	mGame->AddActor(this);
}

Actor::~Actor() {
	mGame->RemoveActor(this);
	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
}

void Actor::Update(float deltaTime) {
	if (mState == Actor::EActive) {
		UpdateActor(deltaTime);
		UpdateComponents(deltaTime);
	}
}

void Actor::UpdateComponents(float deltaTime) {
	for (auto component : mComponents) {
		component->Update(deltaTime);
	}
}

void Actor::UpdateActor(float deltaTime) {

}

void Actor::ProcessKeybord(const Uint8* keyState) {

}

void Actor::Draw(SDL_Renderer* renderer) {

}

void Actor::AddComponent(Component* component) {
	mComponents.emplace_back(component);
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		std::iter_swap(iter, mComponents.end() - 1);
		mComponents.pop_back();
	}
}
