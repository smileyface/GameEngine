#include"include/JobManager/Job.h"

idType job_id_count = 0;

Job::Job(std::function<void(void)> func)
{
	function = func;
	job_id = job_id_count;
	set_priority(JobPriority::MID);
	set_persistant(false);
	job_id_count++;
}

void Job::execute()
{
	//todo add statistic counters
	function();
}

void Job::set_priority(JobPriority pri)
{
	priority = pri;
}

JobPriority Job::get_priority()
{
	return priority;
}

idType Job::get_job_id()
{
	return job_id;
}

void Job::set_persistant(bool persistence)
{
	is_persistant = persistence;
}

bool Job::get_persistant()
{
	return is_persistant;
}

bool Job::operator==(Job & obj)
{
	return job_id == obj.job_id;
}

const bool Job::operator==(const Job & obj) const
{
	return job_id == obj.job_id;
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
