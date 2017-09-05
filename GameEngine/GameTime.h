#pragma once

#include <chrono>		// steady_clock | duration_cast | duration

class Time
{
private:
	float time;
	std::chrono::steady_clock::time_point previous_time;

public:
	void update_time();
};