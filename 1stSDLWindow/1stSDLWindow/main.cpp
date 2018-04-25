#include "SDL.h"
#include "game.h"

Game *game = nullptr;

int main(int argc, char *argv[]) //game loop
{
	const int FPS = 60;                 // capping the frame rate
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("SwordBreak", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false); // divide by 32

	while (game->running()) 
	{

		// Get current running time in mill secs when frame first starts
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart; // This giving us the time of how long it all takes

		//do we need to deplay?
		if (frameDelay > frameTime) 
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}

	game->clean();

	return 0;
}