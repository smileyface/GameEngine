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
	Game::game_state = GameStates::play;

	//render.start(model.get_objects);
	model.start();//TODO: add a function pointer to consume inputs
	//input.start();
}

void Game::pauseLoop()
{
	Game::game_state = GameStates::pause;
}

void Game::stopLoop()
{
	Game::game_state = GameStates::stop;
}


Game::~Game()
{
}
