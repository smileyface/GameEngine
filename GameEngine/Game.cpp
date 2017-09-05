#include "Game.h"

Game::Game()
{
}
/*
Starts the game loop

Starts the loops in the following orders
Render, Model, Input, 
*/
void Game::startLoop()
{
	Game::state = GameStates::game_play;

	//render.start(model.get_objects);
	model.start();//TODO: add a function pointer to consume inputs
	//input.start();
}

/*
Set the state of the game loop to pause
*/
void Game::pauseLoop()
{
	Game::state = GameStates::game_pause;

	model.pause();
}
/*
stops the game loop
restarts the state of the model
*/
void Game::stopLoop()
{
	Game::state = GameStates::game_stop;
}


Game::~Game()
{
}
