#include "paddle.h"
#include <SDL.h>

Paddle::Paddle(const Window &window, int x, int y, int w, int h, int r, int g, int b, int a):
Window(window), _x(x), _y(y), _w(w), _h(h), _r(r), _g(g), _b(b), _a(a) 
{
	m_y = static_cast<double>(y);
}

void Paddle::draw() const {
	SDL_Rect rect = {_x, _y, _w, _h };

	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);
}

void Paddle::update(double delta_time) {
	if (_direction == Direction::UP) {
		if (m_y > 0) {
			m_y -= 10.0 * delta_time;
			_y = m_y;
		}
	}
	else if (_direction == Direction::DOWN) {
		if (m_y + 75 <= 320) {
			m_y += 10.0 * delta_time;
			_y = m_y;
		}
	}
}

void Paddle::poll_events(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_w:
			_direction = Direction::UP;
			break;
		case SDLK_s:
			_direction = Direction::DOWN;
			break;
		default:
			break;
		}
	}

	if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym) {
		case SDLK_w:
			_direction = Direction::NONE;
			break;
		case SDLK_s:
			_direction = Direction::NONE;
			break;
		default:
			break;
		}
	}
}