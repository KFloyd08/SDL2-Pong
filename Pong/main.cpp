#include <SDL.h>
#include "window.h"

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

int main(int argc, char** agrv) {

	const int window_width = 640;
	const int window_height = 320;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_Log("Error initializing SDL.\n");
	}

	Window window("Pong", window_width, window_height);

	while (!window.isClosed()) {
		window.poll_events();
		window.draw();
	}

	return 0;
}