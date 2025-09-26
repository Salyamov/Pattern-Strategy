#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Tank.h"

extern SDL_Renderer* renderer;

class Game
{
public:
	Game(int screenWidth, int screenHeight, bool fullscreen);
	void run();
	~Game();
private:
	
	SDL_Window* window;
	bool running;


	//внутренние функции игры
	void draw();
	void processInput();
	void calculateObjects();

	std::vector<Tank*> tanks;

};

