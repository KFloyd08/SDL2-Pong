#include "window.h"
#include <SDL.h>
#include <iostream>

Window::Window(std::string name, int width, int height):_name(name), _width(width), _height(height) {
	if (!init()) {
		_closed = true;
	}
}

Window::~Window() {
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Window::init() {
	_window = SDL_CreateWindow(_name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN);

	if (_window == NULL) {
		SDL_Log("Error: Failed to create window.\n");
	}

	_renderer = SDL_CreateRenderer(_window, -1, 0);

	return true;
}

void Window::clear() {
	SDL_RenderPresent(_renderer);
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
}

void Window::poll_events(SDL_Event event) {
	switch (event.type) {
	case SDL_QUIT:
		_closed = true;
		break;
	default:
		break;
	}
}