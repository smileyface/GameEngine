#pragma once

#include <mutex>
#include <functional>	// function
#include <chrono>		// steady_clock | duration_cast | duration
#include <vector>		// vector
#include <map>			// map
#include <string>		// string



class Time
{
	std::chrono::steady_clock::time_point previous_time;
	float step_length = -1.0f;
	void update_time();

	Time();
	std::function<void()> update = [] {};
	void change_step_hz(int hertz);
	void time_stop();
	void time_start();


	float overall_time_used;
	float elapsed_time;
};