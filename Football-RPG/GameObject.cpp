#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::register_control(Command command, void(*command_function)(void))
{
	control_map[command] = command_function;
}

void GameObject::add_step_command(Command command)
{
	step_commands.push_back(command);
}
