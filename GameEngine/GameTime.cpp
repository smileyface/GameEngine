#include "GameTime.h"

/*
Default Constructor

sets previous time to time of construction. 
*/
Time::Time()
{
	previous_time = std::chrono::steady_clock::now();
}

/*
Updates the clock
Gets the elapsed time as a percentage of a cycle
*/
float Time::get_elapsed_time_percentage(int hertz)
{
	update();
	return elapsed_time* (hertz / 1000.0f);
}

/*
Updates the clock
Get raw elapsed time.
*/
float Time::get_elapsed_time()
{
	update();
	return elapsed_time;
}

/*
Sets the update function to {}, so it can be called, but it will not do anything
*/
void Time::time_stop()
{
	Time::update = []() {};
}

/*
Set the update function to a lambda that updates the elapsed time.
*/
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

void Time::time_restart()
{
	elapsed_time = 0.0f;
	overall_time_used = 0.0f;
}

