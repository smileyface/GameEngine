#pragma once

#include "Model.h"
const enum GameStates {
	game_play,
	game_pause,
	game_stop
};

class Game
{
public:
	Game();
	void startLoop();
	void pauseLoop();
	void stopLoop(); 
	~Game();

	int state;
private:
	Model model;
};

