#include "../ThreadManager.h"



ThreadManager::ThreadManager()
{
	for(int i = 0; i< ThreadHelpers::NOW; i++)
		ThreadManager::queue.push_back(std::vector<Job>());
}


ThreadManager::~ThreadManager()
{
}

