#include "Command.h"



Command::Command()
{
}

Command::Command(int offset)
{
	Command::command_offset = offset;
}


Command::~Command()
{
}

/*
Create a command type
*/
std::shared_ptr<Command> CommandInterface::create_command()
{
	return std::make_shared<Command>();
}

/*
Create a command type

offset is in miliseconds
*/
std::shared_ptr<Command> CommandInterface::create_command(int offset)
{
	return std::make_shared<Command>(offset);
}
