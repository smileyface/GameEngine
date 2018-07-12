/**
@author Kason

*/

#include<thread>
#include<vector>
#include"JobManager.h"

/**
@class ThreadManager
@brief Contains JobManager
*/
class ThreadManager{

protected:
	JobManager jobs; //! Manager for posting and popping jobs.
	short number_of_threads; //! Number of threads available to pool
public:
	ThreadManager();
};