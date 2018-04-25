#ifndef JOBMANAGER_H
#define JOBMANAGER_H



#include <vector>
#include <utility>
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

	int return_one();
	void add(std::function<void()>, JobPrority level);
	void add(std::function<void(void)>);
	void add_background(std::function<void()> function);

	extern std::vector< std::pair< JobPrority, std::function<void()> > > queue; //A Leveled queue where each level is a different ThreadLevel

}

#endif // !JOBMANAGER_H

