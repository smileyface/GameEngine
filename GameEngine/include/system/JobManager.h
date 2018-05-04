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
	void add(std::function<void()>, JobPrority level);
	void add(std::function<void(void)>);
	void add_background(std::function<void()> function);

	Job get_queued_job();

	extern std::priority_queue< Job, std::vector<Job>, JobCompare > queue; //A Leveled queue where each level is a different ThreadLevel

}



#endif // !JOBMANAGER_H

