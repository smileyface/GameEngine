/**
@file JobManager.h
*/

#ifndef JOBMANAGER_H
#define JOBMANAGER_H



#include <vector>
#include <queue>
#include <utility>

#include <JobManager/Job.h>
#include <JobManager/Frame.h>


/**
	@typedef Frame
	@brief A priority queue for holding jobs
*/


/**
	@brief Manage jobs given by the rest of the system and deliver them to the ThreadManager
*/
class JobManager
{
private:
	//A priority queue that holds various jobs
	Frame queue;
	Frame nextFrame;

	void end_frame();


public:

	//number of jobs on the queue
	int registered_jobs();

	/**
	Make a job with default priority and no id
	*/
	Job make_job(std::function<void(void)> function);
	/**
	Make a job with no id
	*/
	Job make_job(std::function<void(void)> function, JobPrority priority);
	/**
	Make a job with no id
	*/
	Job make_job(std::function<void(void)> function, JobPrority priority, int job_id);

	/**
	This is the basic executive that schedules processes.
	*/
	void add(Job job);

	/**
	Remove a job by id
	*/
	void remove(int id);

	/**
		Get the next job on the queue
	*/
	Job get_queued_job();

	int queue_size() { return JobManager::queue.size(); }


};
#endif // !JOBMANAGER_H

