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

Continues as long as the game is in a play state. 
*/
void Model::update_loop()
{
	while (Game::game_state == GameStates::play)
	{
		//get data from server
		//update time
		Model::update_time();
		//update game objects
	}
}


Model::~Model()
{
}

/*
Update the model time.

Will be the elapsed time from the last step to this step.
TODO: Will eventually come from a server.
*/
void Model::update_time()
{
	auto now_time = std::chrono::steady_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::duration<float>>(now_time- Model::previous_time);
	Model::time = elapsed_time.count();
	Model::previous_time = now_time;
}
