#pragma once

/*
		pong++
		Atari's 1972 Pong clone.

		Author: Tamta Asatiani
		tamta@geolab.edu.ge

		-- Ball Class --

		Represents the ball bouncing around in the game,
		that collides with paddles and bounces from top and bottom walls,
		scores a point when touching left or right edge.
*/


#include "../engine.h"
#include "Paddle.h"
#include "constants.h"

class Ball {
public:
	float x;
	float y;

	// ball's x and y speed
	float dx;
	float dy;
	
	int width;
	int height;

public:
	Ball(float x, float y, int width, int height);

	void render();
	void update();
	void reset();

	// AABB collision, returns true if ball
	// overlaps with a paddle
	bool collides(Paddle paddle);

};