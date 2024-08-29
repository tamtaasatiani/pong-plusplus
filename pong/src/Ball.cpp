#include "Ball.h"

Ball::Ball(float x, float y, int width, int height)
{
	this->x = x;
	this->y = y;

	this->width = width;
	this->height = height;

	this->dx = 0;
	this->dy = 0;
}

void Ball::reset()
{
	x = WINDOW_WIDTH / 2 - width / 2;
	y = WINDOW_HEIGHT / 2 - height / 2;
	dx = 0;
	dy = 0;
}

bool Ball::collides(Paddle paddle)
{
	if ((x > paddle.x + paddle.width) || (paddle.x > x + width))	return false;

	if ((y > paddle.y + paddle.height) || (paddle.y > y + height)) return false;

	return true;
}

void Ball::update()
{
	x = x + dx;
	y = y + dy;
}

void Ball::render()
{
	tahm.graphics->setColor(255, 255, 255);
	tahm.graphics->draw->rect(x, y, width, height);
}