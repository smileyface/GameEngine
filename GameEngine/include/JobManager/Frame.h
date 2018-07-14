#ifndef FRAME_H
#define FRAME_H


#include <queue>

#include <JobManager/Job.h>


///@brief Compares jobs by priority
class JobCompare
{
	bool reverse;
public:
	JobCompare(const bool& revparam = false) noexcept;

	bool operator() (const Job& lhs, const Job&rhs) const
	{
		if (reverse) return (lhs.priority>rhs.priority);
		else return (lhs.priority<rhs.priority);
	}
};

/**
@typedef Frame
@brief A priority queue for holding jobs
*/

typedef std::priority_queue< Job, std::vector<Job>, JobCompare > Frame;

#endif // FRAME_H
