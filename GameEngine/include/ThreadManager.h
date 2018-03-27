#pragma once

#include<vector>

struct Job
{

};

enum ThreadLevel
{
	BKGROUND, //Does not drop off the job list, but returns to the back of the queue
	LOW, //Is the last list to go
	MID, 
	HIGH,
	NOW //Interupts current job and starts this one.
};

class ThreadManager
{
public:
	ThreadManager();
	~ThreadManager();
	void add(void(*job_function)(), int level);
private:
	std::vector<Job> now_queue();

};
