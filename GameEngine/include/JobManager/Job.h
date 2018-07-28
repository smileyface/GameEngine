#ifndef JOB_H
#define JOB_H

#include <functional>

typedef unsigned int idType;
/**
@brief How urgently the job needs done within this frame.
*/
enum JobPriority
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
*/
class Job
{
private:
	/**
	@brief How urgent this task is
	*/
	JobPriority priority;
	/**
	@brief The task
	*/
	std::function<void(void)> function;
	/**
	@brief The id of the task

	This is mainly used to kill Background tasks
	*/
	idType job_id = 0;
public:
	Job(std::function<void(void) > function);
	void execute();
	void set_priority(JobPriority);
	JobPriority get_priority();
	idType get_job_id();

	/**
	@brief compare equivalence by id
	*/
	bool operator == (Job &obj);
	const bool operator == (const Job & obj) const;
	/**
	@brief compare lesser priority
	*/
	bool operator < (Job &obj);
	const bool operator <(const Job & obj) const;
	bool operator > (Job &obj);
	const bool operator >(const Job & obj) const;
};


#endif JOB_H