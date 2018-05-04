#include <system\JobManager.h>
#include <system\Statistic.h>

int JobManager::return_one()
{
	return 1;
}

void JobManager::add(std::function<void()> function, JobPrority level)
{
	JobManager::queue.push(std::make_pair(level, function));
}

void JobManager::add(std::function<void(void)> function)
{
	JobManager::add(function, JobPrority::MID);
}

Job JobManager::get_queued_job()
{
	Job top = queue.top();
	JobManager::queue.pop();
	return top;
}

JobCompare::JobCompare(const bool& revparam)
{
	JobCompare::reverse = revparam;
}

std::priority_queue< Job, std::vector<Job>, JobCompare > JobManager::queue;