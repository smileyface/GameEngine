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

typedef std::pair<JobPrority, std::function<void()> > Job;

class JobCompare
{
	bool reverse;
public:
	JobCompare(const bool& revparam = false);

	bool operator() (const Job& lhs, const Job&rhs) const
	{
		if (reverse) return (lhs.first>rhs.first);
		else return (lhs.first<rhs.first);
	}
};


namespace JobManager
{
	int return_one();

	//Add a function with a non-default priority level 
	void add(std::function<void()>, JobPrority level);

	//Add a function with a default priority level (MID)
	void add(std::function<void(void)>);

	//Add a function with a background priority level
	void add_background(std::function<void()> function);

	//Get the next job on the queue
	Job get_queued_job();

	//A priority queue that holds various jobs
	extern std::priority_queue< Job, std::vector<Job>, JobCompare > queue;

}
#endif // !JOBMANAGER_H

