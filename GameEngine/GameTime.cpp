#include "GameTime.h"

/*
Update the model time.

Elapsed time from the last step to this step.
*/
void Time::update_time()
{
	auto now_time = std::chrono::steady_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::duration<float>>(now_time - Time::previous_time);
	Time::time _+= elapsed_time.count();
	Time::previous_time = now_time;
}

void Time::update_time(int hertz)
{
	double hz = 1.0 / hertz;
}
