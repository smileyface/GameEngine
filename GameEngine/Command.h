#pragma once

#include <memory>		// std::shared_ptr
#include <vector>		// std::vector



class Command
{
public:
	Command();
	Command(int offset);
	~Command();
	long commanded_id;
	int command_offset;
};

namespace CommandInterface
{
	std::shared_ptr<Command> create_command();
	std::shared_ptr<Command> create_command(int offset);
}

