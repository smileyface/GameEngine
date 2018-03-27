#pragma once

#include<vector>
#include<functional>

struct Job
{
	std::function<void()> function;
	int level;
};

namespace ThreadHelpers
{
	enum ThreadLevel
	{
		BKGROUND, //Does not drop off the job list, but returns to the back of the queue
		LOW, //Is the last list to go
		MID,
		HIGH,
		NOW //Interupts current job and starts this one.
	};
}

class ThreadManager
{
public:
	//VARIABLES
	ThreadHelpers::ThreadLevel level;
	//METHODS
	ThreadManager();
	~ThreadManager();
	void add(Job job, int level);
	void add(Job job);
	void add_background(Job job);
private:
	std::vector<Job> now_queue;
	std::vector<Job> high_queue;
	std::vector<Job> mid_queue;
	std::vector<Job> low_queue;
	std::vector<Job> background_queue;
	std::vector<std::vector<Job>> queue;

	

};
