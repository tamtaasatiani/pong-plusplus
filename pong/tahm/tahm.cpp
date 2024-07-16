#include "seek.h"

void Tahm::init(void)
{
    window->init();
    renderer->create(window->SDLwindow);
    renderer->init();
}

void Tahm::loop()
{
	renderer->prepare();

	input->read();

	//if (update) update();
	// 
	
	input->clear();

	//if (draw) draw();

	renderer->present();

	SDL_Delay(16);
}
