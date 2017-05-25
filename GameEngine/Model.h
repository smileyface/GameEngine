#pragma once

#include <vector>	// std::vector
#include <map>		// std::map
#include <thread>	// std::thread
#include <chrono>	// std::steady_clock

#include "GameObject.h"

const enum ModelStates {
	model_play,
	model_pause,
	model_stop
};

class Model
{
public:
	Model();
	void start();
	void pause();
	void stop();
	void update_loop();
	void register_game_object(GameObject object);
	void register_input_consumer_function(std::vector<int>(*consume_input)(void));
	~Model();


private:
	void update_time();
	void register_commands_with_objects(std::vector<int> commands);

	int state;
	std::vector<GameObject> objects;
	std::thread thread;
	float time;
	std::chrono::steady_clock::time_point previous_time;
	std::vector<int>(*consume_input)(void);
	std::map<long, int> object_id_to_list_id;
};

