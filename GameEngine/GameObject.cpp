#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::update(float step_time)
{
	//TODO: Add command handling.
}

void GameObject::register_control(std::shared_ptr<Command> command, void(*command_function)(void))
{
	control_map[command] = command_function;
}

void GameObject::add_step_command(std::shared_ptr<Command> command)
{
	step_commands.push_back(command);
}

GameObject GameObjectInterface::create_game_object()
{
	GameObject obj;
	obj.id = GameObjectInterface::id;
	GameObjectInterface::id++;
	return obj;
}
