#include "GameTime.h"

/*
Default Constructor

sets previous time to time of construction. 
*/
RunningTime::RunningTime()
{
	previous_time = std::chrono::steady_clock::now();
	step_length = -1.0f;
}

/*
Update the model time.

Elapsed time from the last step to this step.
*/
void RunningTime::update_time()
{
	auto current_time = std::chrono::steady_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::duration<float>>(current_time - RunningTime::previous_time);
	RunningTime::elapsed_time = elapsed_time.count;
	RunningTime::overall_time_used += elapsed_time.count();
	RunningTime::previous_time = current_time;
}

/*
Set the step length to the hertz.
*/
void RunningTime::change_step_hz(int hertz)
{
	RunningTime::step_length = 1.0f / hertz;
}



