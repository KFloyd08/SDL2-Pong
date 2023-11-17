#include <SDL.h>
#include "window.h"
#include "paddle.h"

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

int FPS = 60;
int LastTick = 0;

void poll_events(Window &window, Paddle &paddle) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		window.poll_events(event);
		paddle.poll_events(event);
	}
}

int main(int argc, char** agrv) {

	const int window_width = 640;
	const int window_height = 320;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_Log("Error initializing SDL.\n");
	}

	Window window("Pong", window_width, window_height);
	Paddle l_paddle(window, 25, (window_height / 2) - (75/2), 15, 75, 255, 255, 255, 255);
	Paddle r_paddle(window, (window_width - (25 + 15)), (window_height / 2) - (75 / 2), 15, 75, 255, 255, 255, 255);

	LastTick = SDL_GetTicks();

	while (!window.isClosed()) {

		int nowTicks = SDL_GetTicks();
		float delta_time = float((nowTicks - LastTick));

		l_paddle.draw();
		r_paddle.draw();
		l_paddle.update(1.0/60.0);
		poll_events(window, l_paddle);
		window.clear();

		LastTick = nowTicks;
	}

	return 0;
}