#pragma once


// Main engine class initialization
// 
// 
// FIX: the SDL_Window and Window window is weird, I should fixed that


class Tahm {

private:
	class Window
	{
	private:
		const char* title = "Untitled";

		int width = 400;
		int height = 400;

		int flags = 0;

	public:
		SDL_Window* SDLwindow;

	public: 
		void create(const char* title, int width, int height);
		void init(void);

	};

	class Input
	{
	private:
		unsigned const int KEY_AMOUNT = 122;
		bool keysPressed[];

	public:
		void init();
		void press(int key);
		void clear();




		void read(void);
	};

	class Renderer
	{
	public:
		int flags = SDL_RENDERER_ACCELERATED;
		SDL_Window* SDLwindow;
		SDL_Renderer* SDLrenderer;

	public:
		void create(SDL_Window* SDLwindow);
		void init(void);

		void prepare(void);
		void present(void);
	};


public:
	Window* window;
	Input* input;
	Renderer* renderer;

	bool running;

public:
	~Tahm();


	void init(void);
	void loop();

	void destroy();
};