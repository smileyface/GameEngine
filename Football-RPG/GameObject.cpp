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
