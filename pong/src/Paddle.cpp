#include "Paddle.h"

Paddle::Paddle(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;


}

void Paddle::render()
{
	tahm.graphics->setColor(255, 255, 255);
	tahm.graphics->draw->rect(x, y, width, height);
}