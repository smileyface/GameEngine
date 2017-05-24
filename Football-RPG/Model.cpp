#include "Model.h"

Model::Model()
{
}
/*
Start model simulation.

Starts the sim thread (thread)
*/
void Model::start()
{
	Model::thread = std::thread(&Model::update_loop);
}

/*
Actions taken in each step of the simulation.
The steps taken are as follows:
1. Update time
2. Consume Input
3. Update Game Objects

Continues as long as the game is in a play state. 
*/
void Model::update_loop()
{
	while (Game::game_state == GameStates::play)
	{
		//update time
		Model::update_time();
		//consume input
		auto commands = consume_input();
		Model::register_commands_with_objects(commands);
		//update game objects
		for (auto value : Model::objects)
		{
			value.update(time);
		}
	}
}

/*
Add game object to the update list.

Adds the object to the end of the list
*/
void Model::register_game_object(GameObject object) // object to add to list
{
	objects.push_back(object);
	object_id_to_list_id[object.id] = objects.size - 1;
}

/*
Registers the input consume function from input object to this object.

TODO: Change this from ints to commands once commands are written
*/
void Model::register_input_consumer_function(std::vector<int>(*consume_input)(void))// function pointer to the consume input function of the input class associated with this model
{
	Model::consume_input = consume_input;
}



Model::~Model()
{
}

/*
Update the model time.

Elapsed time from the last step to this step.
*/
void Model::update_time()
{
	auto now_time = std::chrono::steady_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::duration<float>>(now_time- Model::previous_time);
	Model::time = elapsed_time.count();
	Model::previous_time = now_time;
}

//TODO: give this function more meat when command objects are created.
void Model::register_commands_with_objects(std::vector<int> commands)
{
	
}
