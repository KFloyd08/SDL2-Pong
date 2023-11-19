#include "ball.h"
#include <SDL.h>

Ball::Ball(const Window& window, int x, int y, int w, int h, int r, int g, int b, int a) :
Window(window), _x(x), _y(y), _w(w), _h(h), _r(r), _g(g), _b(b), _a(a)
{
	m_x = static_cast<double>(x);
	m_y = static_cast<double>(y);
}

void Ball::update(double delta_time) {
	m_x += speed_x * delta_time;
	m_y += speed_y * delta_time;

	_x = m_x;
	_y = m_y;

	if (_y + 10 >= 320 || _y <= 0) {
		speed_y *= -1;
	}

	if (_x + 10 >= 640 || _x <= 0) {
		speed_x *= -1;
	}
}

void Ball::draw() {
	rect = { _x, _y, _w, _h };

	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);
}