#pragma once

#include "window.h"
#include <SDL.h>

class Ball : public Window{
public:
	Ball(const Window& window, int x, int y, int w, int h, int r, int g, int b, int a);
	
	void draw();
	void update(double delta_time);

	double speed_x = 5;
	double speed_y = 5;

	int _x, _y;
	int _w, _h;

	SDL_Rect rect;

private:
	
	int _r, _g, _b, _a;
	double m_x, m_y;
};