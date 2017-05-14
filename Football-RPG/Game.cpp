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
	Game::game_state = play;

	//render.start();
	model.start();
	//input.start();
}


Game::~Game()
{
}
