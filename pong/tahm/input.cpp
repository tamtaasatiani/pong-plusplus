#include "seek.h"

#include "input.h"


/*

void pressKey(int key)
{
	for (int i = 0; i < KEY_AMOUNT; i++)
	{
		if (keysPressed[i].key != key)
		{
			continue;
		}

		keysPressed[i].pressed = true;
	}

}

void clearKeys()
{
	for (int i = 0; i < KEY_AMOUNT; i++)
	{
		keysPressed[i].pressed = false;
	}
}
*/

void readInput(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;

			default:
				//pressKey(event.type);
				break;
		}
	}
}