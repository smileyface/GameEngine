#pragma once

#include<map> //	std::map

#include "Command.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	//base function. Should never be accessed.
	virtual void update(float step_time) {}; 
	long id;

private:
	std::map<Command, void(*)(void)> controlMap;
};