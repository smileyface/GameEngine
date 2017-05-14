#pragma once



#include "Model.h"

class Game
{
public:
	Game();
	void startLoop();
	void pauseLoop();
	void stopLoop(); 
	~Game();
private:
	float gameTime;
	Model model;
};

