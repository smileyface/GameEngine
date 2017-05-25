#pragma once

#include<map>		// std::map
#include<vector>	// std::vector 

#include "Command.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void update(float step_time) {}; 
	void register_control(Command command, void(*)(void));
	void add_step_command(Command command);
	long id;

private:
	std::map<Command, void(*)(void)> control_map;
	std::vector<Command> step_commands;
};