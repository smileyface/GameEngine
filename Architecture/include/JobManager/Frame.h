#ifndef FRAME_H
#define FRAME_H


#include <queue>

#include <JobManager/Job.h>


/**
@typedef Frame
@brief A priority queue for holding jobs
*/

typedef std::priority_queue< Job, std::vector<Job>> Frame;

#endif // FRAME_H
