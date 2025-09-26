#include "Game.h"
#include <iostream>

int main(int argc, char** argv)
{
	
	{
		Game g(800, 600, 0);
		g.run();
	}

	std::cout << "Game over\n";

	return 0;
}