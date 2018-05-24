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


class JobManager
{
private:
	//A priority queue that holds various jobs
	std::priority_queue< Job, std::vector<Job>, JobCompare > queue;



public:

	//number of jobs on the queue
	int registered_jobs();

	//Make a job with default priority and no id
	Job make_job(std::function<void(void)> function);
	//Make a job with no id
	Job make_job(std::function<void(void)> function, JobPrority priority);
	//Make a Job
	Job make_job(std::function<void(void)> function, JobPrority priority, int job_id);

	//Add a job to the queue
	void add(Job job);

	//remove a job by job id
	void remove(int id);

	//Get the next job on the queue
	Job get_queued_job();

	int queue_size() { return JobManager::queue.size(); }


};
#endif // !JOBMANAGER_H

