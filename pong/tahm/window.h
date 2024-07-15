#pragma once


class Window
{
private:
	const char* title = "Untitled";

	int width = 400;
	int height = 400;

public:
	void Create(const char* title, int width, int height);
	void initSDL(void);
};



void cleanup(void);