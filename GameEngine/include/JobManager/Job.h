#ifndef JOB_H
#define JOB_H

#include <functional>
/**
@brief How urgently the job needs done within this frame.
*/
enum JobPrority
{
	BKGROUND, /*!<Runs over multiple frames.*/
	LOW, /*!<Is the last in the queue. Not guarenteed this frame*/
	MID, /*!<Default Priority*/
	PERSISTANT, /*!<Will run, then be placed on next frame*/
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
	int job_id = -1;
};


#endif JOB_H