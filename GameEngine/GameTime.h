#pragma once

#include <mutex>
#include <functional>	// function
#include <chrono>		// steady_clock | duration_cast | duration
#include <vector>		// vector
#include <map>			// map
#include <string>		// string



class Time
{
private:
	std::chrono::steady_clock::time_point previous_time;
	std::function<void()> update = [] {};
	float overall_time_used;
	float elapsed_time;
public:
	Time();
	float get_elapsed_time_percentage(int hertz);
	float get_elapsed_time();
	void time_stop();
	void time_start();
};