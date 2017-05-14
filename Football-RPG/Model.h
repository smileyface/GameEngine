#pragma once

#include<vector>	// std::vector
#include <thread>	// std::thread
#include <chrono>	// std::steady_clock

#include"GameObject.h"
class Model
{
public:
	Model();
	void start();
	void update_loop();
	~Model();
private:
	void update_time();

	std::vector<GameObject> board;
	std::thread thread;
	float time;
	std::chrono::steady_clock::time_point previous_time;
};

