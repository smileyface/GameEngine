/**
@author Kason

*/

#include<thread>
#include<vector>
#include<JobManager/JobManager.h>

/**
@class ThreadManager
@brief Contains JobManager
*/
class ThreadManager{

protected:
	JobManager jobs; //! Manager for posting and popping jobs.
	short number_of_threads; //! Number of threads available to pool
	std::thread input_thread; //! Thread constantly polling for input.
public:
	ThreadManager();
	void register_input_job(); //TODO: register input polling job in the Control layer.
};