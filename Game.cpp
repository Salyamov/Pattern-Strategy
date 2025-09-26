#include "Game.h"
#include <iostream>

using std::cout;
using std::endl;

SDL_Renderer* renderer = 0;

Game::Game(int screenWidth, int screenHeight, bool fullscreen)
	: running(true)
{
	bool res = SDL_CreateWindowAndRenderer(screenWidth, screenHeight, fullscreen, &window, &renderer);
	if (res != 0)
	{
		std::cout << "error\n";
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	tanks.push_back(new LightTank(400, 200));
	tanks.push_back(new MediumTank(200, 400));
	tanks.push_back(new HeavyTank(300, 500));
	tanks.push_back(new MonumentTank(100, 500));
		
}

void Game::run()
{
	//тут будет бесконечный цикл
	while (running)
	{
		processInput();
		calculateObjects();
		draw();
		SDL_Delay(100);
	}
}

Game::~Game()
{
	//очищаем память от всех игровых объектов
	for (auto& v : tanks)
		delete v;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::draw()
{
	SDL_RenderClear(renderer);

	for (auto& v : tanks)
		v->draw();

	SDL_RenderPresent(renderer);
}

void Game::processInput()
{

	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			running = false;
		



	}
	
	
}

void Game::calculateObjects()
{
	for (auto& v : tanks)
		v->move();
}
