#pragma once

#include <vector>	// std::vector
#include <map>		// std::map
#include <thread>	// std::thread

#include "GameObject.h"
#include "Time.h"

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
	~Model();


private:
	void register_commands_with_objects(std::vector<int> commands);

	int state;
	std::vector<GameObject> objects;
	std::thread thread;

	std::map<long, int> object_id_to_list_id;
};

