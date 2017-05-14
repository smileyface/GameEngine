#pragma once

#include "Model.h"

static const enum GameStates {
	play,
	pause,
	stop
};

class Game
{
public:
	Game();
	void startLoop();
	void pauseLoop();
	void stopLoop(); 
	~Game();

	static int game_state;
private:
	float gameTime;
	Model model;
};

