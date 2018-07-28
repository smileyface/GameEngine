#include"include/JobManager/Job.h"

idType job_id_count = 0;

Job::Job(std::function<void(void)> function)
{
	Job::function = function;
	Job::job_id = job_id_count;
	Job::set_priority(JobPriority::MID);
	job_id_count++;
}

void Job::execute()
{
	//todo add statistic counters
	Job::function();
}

void Job::set_priority(JobPriority priority)
{
	Job::priority = priority;
}

JobPriority Job::get_priority()
{
	return Job::priority;
}

idType Job::get_job_id()
{
	return Job::job_id;
}

bool Job::operator==(Job & obj)
{
	return Job::job_id == obj.job_id;
}

const bool Job::operator==(const Job & obj) const
{
	return Job::job_id == obj.job_id;
}

bool Job::operator<(Job & obj)
{
	return priority<obj.priority;
}
const bool  Job::operator<(const Job & obj) const
{
	return priority < obj.priority;
}
bool Job::operator>(Job & obj)
{
	return priority > obj.priority;
}

const bool  Job::operator>(const Job & obj) const
{
	return priority > obj.priority;
}
