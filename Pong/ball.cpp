#include "ball.h"
#include <SDL.h>
#include <iostream>

Ball::Ball(const Window& window, int x, int y, int w, int h, int r, int g, int b, int a) :
Window(window), _x(x), _y(y), _w(w), _h(h), _r(r), _g(g), _b(b), _a(a)
{
	m_x = static_cast<double>(x);
	m_y = static_cast<double>(y);
}

void Ball::update(double delta_time, int &score) {
	m_x += speed_x * delta_time;
	m_y += speed_y * delta_time;

	_x = m_x;
	_y = m_y;

	if (_y + 10 >= 320 || _y <= 0) {
		speed_y *= -1;
	}

	if (_x + 10 >= 640) {
		speed_y *= -1;
		m_x = (640 / 2) - (10 / 2);
		m_y = (320 / 2) - (10 / 2);

		score += 1;
		std::cout << "Score: " << score << "\n";
	}

	if (_x <= 0) {
		m_x = (640 / 2) - (10 / 2);
		m_y = (320 / 2) - (10 / 2);
		//speed_x *= -1;
	}
}

void Ball::draw() {
	rect = { _x, _y, _w, _h };

	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);
}