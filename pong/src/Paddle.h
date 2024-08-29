#pragma once

/*
		pong++
		Atari's 1972 Pong clone.

		Author: Tamta Asatiani
		tamta@geolab.edu.ge

		-- Paddle Class --

		Represents the paddles that can move up and down
		and reflect the ball in the opposite direction.
*/



#include "../engine.h"
#include "constants.h"

class Paddle {
public:
	int x;
	int y;

	int width;
	int height;

public:
	Paddle(int x, int y, int width, int height);
	void render();

};