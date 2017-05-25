#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::register_control(std::shared_ptr<Command> command, void(*command_function)(void))
{
	control_map[command] = command_function;
}

void GameObject::add_step_command(std::shared_ptr<Command> command)
{
	step_commands.push_back(command);
}
