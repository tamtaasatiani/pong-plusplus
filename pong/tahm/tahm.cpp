#include "seek.h"

extern Tahm tahm;



void Tahm::init(void)
{
	window = new Window;
	renderer = new Renderer;
	input = new Input;


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

Tahm::~Tahm()
{
	delete window, renderer, input;
}


void cleanup(void)
{
	SDL_DestroyRenderer(tahm.renderer->SDLrenderer);

	SDL_DestroyWindow(tahm.window->SDLwindow);

	SDL_Quit();
}