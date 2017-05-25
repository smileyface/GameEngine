#pragma once

#include <memory>		// std::shared_ptr
#include <vector>		// std::vector



class Command
{
public:
	Command();
	~Command();
	long commanded_id;
};

namespace CommandInterface
{
	std::shared_ptr<Command> create_command();
}

