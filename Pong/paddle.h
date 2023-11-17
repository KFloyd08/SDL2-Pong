#pragma once

#include "window.h"
#include <SDL.h>

//Inherits window class
class Paddle : public Window {
public:
	Paddle(const Window& window, float x, float y, int w, int h, int r, int g, int b, int a);
	
	void draw() const;
	void poll_events(SDL_Event event);
	void update(float delta_time);

private:
	float _x, _y;
	int _w, _h;
	int _r, _g, _b, _a;
	float direction = 0.0;
	const float speed = 1.0;
};