#include <system\JobManager.h>
#include <system\Statistic.h>


void JobManager::add(Job job)
{
	queue.push(job);
}

Job JobManager::get_queued_job()
{
	Job top = queue.top();
	JobManager::queue.pop();
	if (top.priority == JobPrority::BKGROUND)
	{
		JobManager::add(top);
	}
	return top;
}

JobCompare::JobCompare(const bool& revparam)
{
	JobCompare::reverse = revparam;
}

std::priority_queue< Job, std::vector<Job>, JobCompare > JobManager::queue;


Job JobManager::make_job(std::function<void(void)> function)
{
	return make_job(function, JobPrority::MID);
}

Job JobManager::make_job(std::function<void(void)> function, JobPrority priority)
{
	return make_job(function, priority, -1);
}

Job JobManager::make_job(std::function<void(void)> function, JobPrority priority, int job_id)
{
	Job job;
	job.function = function;
	job.priority = priority;
	job.job_id = job_id;
	return job;
}
