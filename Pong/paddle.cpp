#include "paddle.h"
#include <SDL.h>

Paddle::Paddle(const Window &window, float x, float y, int w, int h, int r, int g, int b, int a):
Window(window), _x(x), _y(y), _w(w), _h(h), _r(r), _g(g), _b(b), _a(a) 
{

}

void Paddle::draw() const {
	SDL_Rect rect = { int(_x), int(_y), _w, _h };

	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);
}

void Paddle::update(float delta_time) {
	_y += (direction * speed) * delta_time;

	if ((_y < 0) || (_y + 75 > 320)) {
		_y -= (direction * speed) * delta_time;
	}
}

void Paddle::poll_events(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_w:
			direction = -1.0;
			break;
		case SDLK_s:
			direction = 1.0;
			break;
		default:
			break;
		}
	}

	if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym) {
		case SDLK_w:
			direction = 0.0;
			break;
		case SDLK_s:
			direction = 0.0;
			break;
		default:
			break;
		}
	}
}