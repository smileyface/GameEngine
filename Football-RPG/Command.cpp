#include "Command.h"



Command::Command()
{
}


Command::~Command()
{
}

std::shared_ptr<Command> CommandInterface::create_command()
{
	return std::shared_ptr<Command>();
}
