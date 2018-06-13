/**
@file JobManager.h
*/

#ifndef JOBMANAGER_H
#define JOBMANAGER_H



#include <vector>
#include <queue>
#include <utility>
#include <functional>

/**
@brief How urgently the job needs done within this frame. 
@todo Add PERSISTANT and give it the functionality of BKGROUND. 
*/
enum JobPrority
{
	BKGROUND, 
	LOW, /*!<Is the last in the queue to go*/
	MID, /*!<Default Priority*/
	PERSISTANT,
	HIGH, /*!<Starts before default*/
	NOW /*!<Interupts current job and starts this one.*/
};


/**
@brief All information needed to execute a job.
@see @ref DEF_0001
*/
struct Job
{
	/**
	@brief How urgent this task is
	*/
	JobPrority priority;
	/**
	@brief The task
	*/
	std::function<void(void)> function;
	/**
	@brief The id of the task

	This is mainly used to kill Background tasks
	*/
	int job_id;
};


///@brief Compares jobs by priority
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

/**
	@brief Manage jobs given by the rest of the system and deliver them to the ThreadManager
*/
class JobManager
{
private:
	//A priority queue that holds various jobs
	std::priority_queue< Job, std::vector<Job>, JobCompare > queue;



public:

	//number of jobs on the queue
	int registered_jobs();

	/**
	Make a job with default priority and no id
	@satisfy{@req{0002}}
	*/
	Job make_job(std::function<void(void)> function);
	/**
	Make a job with no id
	@satisfy{@req{0002}}
	*/
	Job make_job(std::function<void(void)> function, JobPrority priority);
	/**
	Make a job with no id
	@satisfy{@req{0002}}
	*/
	Job make_job(std::function<void(void)> function, JobPrority priority, int job_id);

	/**
	This is the basic executive that schedules processes.
	@satisfy{@req{0001}}
	*/
	void add(Job job);

	/**
	Remove a job by id
	@satisfy{@req{0003}}
	*/
	void remove(int id);

	//Get the next job on the queue
	/**
		Get the next job on the queue
		@satisfy{@req{0004}}
	*/
	Job get_queued_job();

	int queue_size() { return JobManager::queue.size(); }


};
#endif // !JOBMANAGER_H

