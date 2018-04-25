#pragma once



#include<vector>
#include<functional>

namespace JobManager
{
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
		std::function<void()> function;
		Job::JobPrority level;
	};

	void initalize();
	int return_one() { return 1; }
	void add(std::function<void()>, JobPrority level);
	void add(std::function<void()> function);
	void add_background(std::function<void()> function);

	static std::vector<std::vector<Job>> queue; //A Leveled queue where each level is a different ThreadLevel

}



