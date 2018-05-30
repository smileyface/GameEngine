#include <system\JobManager.h>
#include <system\Statistic.h>


void JobManager::add(Job job)
{
	queue.push(job);
}

void JobManager::remove(int id)
{
	std::priority_queue< Job, std::vector<Job>, JobCompare > temp_queue;
	while (!queue.empty())
	{
		Job job = queue.top();
		if (!(job.job_id == id))
		{
			temp_queue.push(queue.top());
		}
		queue.pop();
	}
	queue = temp_queue;
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


int JobManager::registered_jobs()
{
	return queue.size();
}

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
