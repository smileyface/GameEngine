#pragma once

#include <chrono>		// steady_clock | duration_cast | duration
#include <vector>		// vector
#include <map>			// map
#include <string>		// string

class Time
{
public:
	virtual void update_time() = 0;
};

class RunningTime : public Time
{
private:
	std::chrono::steady_clock::time_point previous_time;
	float step_length = -1.0f;

public:
	RunningTime();
	void update_time();
	void change_step_hz(int hertz);

	float overall_time_used;
	float elapsed_time;
};

class StoppedTime : public Time
{
public:
	void update_time() {};
};

namespace Clocks
{
	RunningTime main_clock;
	std::vector<Time> time_pieces;
}