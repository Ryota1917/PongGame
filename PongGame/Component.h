#pragma once

class Component {
public:
	Component(class Actor* owner);
	virtual ~Component();

	virtual void Update(float deltaTime);

private:
	class Actor* mOwner;
};