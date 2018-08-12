/**
@author Kason

*/

#ifndef THREADMANAGER_H
#define THREADMANAGER_H



#include<thread>
#include<mutex>
#include<vector>
#include<atomic>
#include<JobManager/JobManager.h>



extern std::atomic_bool KILL_PROGRAM;

/**
@class ThreadManager
@brief Contains JobManager
*/
class ThreadManager{

protected:
	unsigned int number_of_threads=std::thread::hardware_concurrency(); //! Number of threads available to pool
	std::vector<std::thread> thread_pool;
	std::mutex tex;
	std::condition_variable pool_cv;
public:
	JobManager jobs; //! Manager for posting and popping jobs.
	ThreadManager();
};

#endif // !THREADMANAGER_H