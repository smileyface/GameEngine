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
	Frame cur_frame;
	Frame next_frame;

	void end_frame();
	void add_to_next_frame(Job job);


public:

	//number of jobs on the queue
	int registered_jobs();

	/**
	This is the basic executive that schedules processes.
	*/
	void add(Job job);

	/**
	Remove a job by id
	*/
	void remove(Job id);

	/**
		Get the next job on the queue
	*/
	Job get_next_job();

	int queue_size() { return JobManager::cur_frame.size(); }


};
#endif // !JOBMANAGER_H

