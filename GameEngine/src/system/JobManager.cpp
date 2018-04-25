#include <system\JobManager.h>
#include <system\Statistic.h>

int JobManager::return_one()
{
	return 1;
}

void JobManager::add(std::function<void()> function, JobPrority level)
{
	JobManager::queue.push_back(std::make_pair(level, function));
}

void JobManager::add(std::function<void(void)> function)
{
	JobManager::add(function, JobManager::JobPrority::MID);
}

std::vector< std::pair< JobManager::JobPrority, std::function<void()> > > JobManager::queue;