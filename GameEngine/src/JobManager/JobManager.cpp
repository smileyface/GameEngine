#include <JobManager\JobManager.h>


void JobManager::add(Job job)
{
	cur_frame.push(job);
}

void JobManager::remove(Job id)
{
	Frame temp_queue;
	while (!cur_frame.empty())
	{
		Job job = cur_frame.top();
		if (!(job == id))
		{
			temp_queue.push(cur_frame.top());
		}
		cur_frame.pop();
	}
	cur_frame = temp_queue;
}

Job JobManager::get_next_job()
{
	Job top = cur_frame.top();
	JobManager::cur_frame.pop();
	if (top.get_persistant())
	{
		next_frame.push(top);
	}
	if (cur_frame.empty())
	{
		end_frame();
	}
	return top;
}

void JobManager::end_frame()
{
	//TODO: Notify all

	//reset frame
	cur_frame = next_frame;
	while (!next_frame.empty())
	{
		next_frame.pop();
	}
}

int JobManager::registered_jobs()
{
	return cur_frame.size();
}