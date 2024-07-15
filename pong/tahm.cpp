#include "tahm/seek.h"

App app;
Window window;

int main(int argc, char* argv[])
{
	memset(&app, 0, sizeof(App));

	//if (start) start;

	window.initSDL();
	atexit(cleanup);

	while (1)
	{
		prepareScene();

		readInput();
		//clearKeys();

		//if (update) update();

		presentScene();

		SDL_Delay(16);
	}

	return 0;
}