#include "GameTime.h"

/*
Default Constructor

sets previous time to time of construction. 
*/
Time::Time()
{
	previous_time = std::chrono::steady_clock::now();
}

float Time::get_elapsed_time_percentage(int hertz)
{
	return elapsed_time* hertz;
}

float Time::get_elapsed_time()
{
	return elapsed_time;
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
		Time::elapsed_time = elapsed_time.count();
		Time::overall_time_used += elapsed_time.count();
		Time::previous_time = current_time;
	};
}