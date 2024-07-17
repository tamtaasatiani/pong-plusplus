#include "seek.h"

extern Tahm tahm;



void Tahm::init(void)
{
	running = true;
	window = new Window;
	renderer = new Renderer;
	input = new Input;


    window->init();
    renderer->create(window->SDLwindow);
    renderer->init();
}

void Tahm::loop()
{
	//input->read();



	//if (update) update();
	// 
	
	//input->clear();


	renderer->prepare();

	//if (draw) draw();

	renderer->present();

	SDL_Delay(16);
}

Tahm::~Tahm()
{
	delete window, renderer, input;
}


void Tahm::destroy(void)
{
	SDL_DestroyRenderer(renderer->SDLrenderer);

	SDL_DestroyWindow(window->SDLwindow);

	SDL_Quit();
}