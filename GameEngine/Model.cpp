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
	Model::state = ModelStates::model_play;
	Model::thread = std::thread(&Model::update_loop, this);
}

void Model::pause()
{
	Model::state = ModelStates::model_pause;
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
	while (Model::state == ModelStates::model_play)
	{
		//consume input
		//update game objects
	}
}

/*
Add game object to the update list.

Adds the object to the end of the list
*/
void Model::register_game_object(GameObject object) // object to add to list
{
	objects.push_back(object);
	object_id_to_list_id[object.id] = objects.size() - 1;
}





Model::~Model()
{
}



//TODO: give this function more meat when command objects are created.
void Model::register_commands_with_objects(std::vector<int> commands)
{
	
}
