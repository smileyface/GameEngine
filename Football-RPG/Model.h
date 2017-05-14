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
	void loop();
	~Model();
private:
	std::vector<GameObject> board;
	std::thread thread;
	float time;
};

