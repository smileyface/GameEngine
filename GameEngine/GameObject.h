#pragma once

#include<map>		// std::map
#include<vector>	// std::vector 
#include<memory>	// std::shared_ptr
#include<climits>	// LONG_MIN

#include "Command.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void update(float step_time); 
	void register_control(std::shared_ptr<Command> command, void(*)(void));
	void add_step_command(std::shared_ptr<Command> command);

	long id;

private:
	std::map<std::shared_ptr<Command>, void(*)(void)> control_map;
	std::vector<std::shared_ptr<Command>> step_commands;
};

namespace GameObjectInterface
{
	static long id = LONG_MIN;
	GameObject create_game_object();
}