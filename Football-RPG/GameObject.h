#pragma once

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void update() {}; //base function. Should never be accessed.
};