#include "GameTime.h"

/*
Default Constructor

sets previous time to time of construction. 
*/
Time::Time()
{
	previous_time = std::chrono::steady_clock::now();
	step_length = -1.0f;
}

/*
Update the model time.

Elapsed time from the last step to this step.
*/
void Time::update_time()
{
	auto current_time = std::chrono::steady_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::duration<float>>(current_time - Time::previous_time);
	Time::elapsed_time = elapsed_time.count;
	Time::overall_time_used += elapsed_time.count();
	Time::previous_time = current_time;
}

/*
Set the step length to the hertz.
*/
void Time::change_step_hz(int hertz)
{
	Time::step_length = 1.0f / hertz;
}

void Time::time_stop()
{
	Time::update = []() {};
}

void Time::time_start()
{
	update = [this] ()
	{
		auto current_time = std::chrono::steady_clock::now();
		auto elapsed_time = std::chrono::duration_cast<std::chrono::duration<float>>(current_time - Time::previous_time);
		Time::elapsed_time = elapsed_time.count;
		Time::overall_time_used += elapsed_time.count();
		Time::previous_time = current_time;
	};
}