#pragma once

#include <memory>		// std::shared_ptr

struct CommandCompare
{
	bool operator() (const Command& lhs, const Command& rhs) const
	{
		return lhs.command_id > rhs.command_id;
	}
};



class Command
{
public:
	Command();
	~Command();
	long command_id;
	long object_id;
};

