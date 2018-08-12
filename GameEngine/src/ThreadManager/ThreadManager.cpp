#include <ThreadManager/ThreadManager.h>

std::atomic_bool KILL_PROGRAM=false;

ThreadManager::ThreadManager()
{
	for (unsigned int i = 0; i < number_of_threads; i++)
	{
		thread_pool.emplace_back(std::thread([&]()
		{

			std::unique_lock<std::mutex> lock(tex);
			while (KILL_PROGRAM==false)
			{
				Job j;

				while (jobs.queue_size()==0)
				{
					pool_cv.wait(lock);
				}
				if (KILL_PROGRAM==false)
				{

					j = jobs.get_next_job();
					j.execute();
				}
			}
		}));
	}
}


