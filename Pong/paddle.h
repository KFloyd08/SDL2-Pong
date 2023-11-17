#pragma once

#include "window.h"
#include <SDL.h>

//Inherits window class
class Paddle : public Window {
public:
	enum class Direction {NONE, UP, DOWN};
	Paddle(const Window& window, int x, int y, int w, int h, int r, int g, int b, int a);
	~Paddle() = default;
	void draw();
	void poll_events(SDL_Event event);
	void update(double delta_time);

	int _x, _y;
	int _w, _h;

	SDL_Rect rect;

private:
	
	int _r, _g, _b, _a;
	Direction _direction;
	double m_y;
	const float speed = 1;
};