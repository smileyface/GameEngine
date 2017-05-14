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
}
/*
Actions taken in each step of the simulation.
*/
void Model::loop()
{
	//update time
	//update game objects
}


Model::~Model()
{
}

void Model::update_time()
{
	auto now_time = std::chrono::steady_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::duration<float>>(now_time- Model::previous_time);
	Model::time = elapsed_time.count();
	Model::previous_time = now_time;
}
