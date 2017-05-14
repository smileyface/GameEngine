#pragma once

#include <vector>	// std::vector
#include <thread>	// std::thread
#include <chrono>	// std::steady_clock


#include "Game.h"
#include "GameObject.h"

static const enum GameModeStates {

};

class Model
{
public:
	Model();
	void start();
	void update_loop();
	void register_game_object(GameObject object);
	void register_input_consumer_function(std::vector<int>(*consume_input)(void));
	~Model();


private:
	void update_time();
	void register_commands_with_objects(std::vector<int> commands);

	std::vector<GameObject> objects;
	std::thread thread;
	float time;
	std::chrono::steady_clock::time_point previous_time;
	std::vector<int>(*consume_input)(void)
};

