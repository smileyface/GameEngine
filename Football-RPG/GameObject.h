#pragma once

class GameObject
{
public:
	GameObject();
	~GameObject();

	//base function. Should never be accessed.
	virtual void update(float step_time) {}; 
};