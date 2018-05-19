#ifndef JOBMANAGER_H
#define JOBMANAGER_H



#include <vector>
#include <queue>
#include <utility>
#include<functional>

enum JobPrority
{
	BKGROUND, //Does not drop off the job list, but returns to the back of the queue
	LOW, //Is the last list to go
	MID,
	HIGH,
	NOW //Interupts current job and starts this one.
};

struct Job
{
	JobPrority priority;
	std::function<void(void)> function;
	int job_id;
};



class JobCompare
{
	bool reverse;
public:
	JobCompare(const bool& revparam = false);

	bool operator() (const Job& lhs, const Job&rhs) const
	{
		if (reverse) return (lhs.priority>rhs.priority);
		else return (lhs.priority<rhs.priority);
	}
};


namespace JobManager
{
	//Make a job with default priority and no id
	Job make_job(std::function<void(void)> function);
	//Make a job with no id
	Job make_job(std::function<void(void)> function, JobPrority priority);
	//Make a Job
	Job make_job(std::function<void(void)> function, JobPrority priority, int job_id);

	//Add a job to the queue
	void add(Job job);


	//Get the next job on the queue
	Job get_queued_job();

	//A priority queue that holds various jobs
	extern std::priority_queue< Job, std::vector<Job>, JobCompare > queue;

}
#endif // !JOBMANAGER_H

