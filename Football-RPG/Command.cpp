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

std::shared_ptr<Command> CommandInterface::create_command()
{
	return std::shared_ptr<Command>();
}

/*
offset is in miliseconds
*/
std::shared_ptr<Command> CommandInterface::create_command(int offset)
{
	return std::shared_ptr<Command>(offset);
}
