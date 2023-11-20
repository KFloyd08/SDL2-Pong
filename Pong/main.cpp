#include <SDL.h>
#include <iostream>
#include "window.h"
#include "paddle.h"
#include "ball.h"
#include "cpu_paddle.hpp"

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

int FPS = 60;
int LastTick = 0;

bool check_collision(SDL_Rect &rectA, SDL_Rect &rectB) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = rectA.x;
	rightA = rectA.x + rectA.w;
	topA = rectA.y;
	bottomA = rectA.y + rectA.h;

	leftB = rectB.x;
	rightB = rectB.x + rectB.w;
	topB = rectB.y;
	bottomB = rectB.y + rectB.h;

	return !(bottomA < topB || topA > bottomB || rightA < leftB || leftA > rightB);
}

void poll_events(Window &window, Paddle &paddle) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		window.poll_events(event);
		paddle.poll_events(event);
	}
}

void updates(Paddle &paddle, Ball &ball, CPU_Paddle &paddle_two, int &score) {
	double delta_time = (1.0 / 60.0);

	if (check_collision(paddle.rect, ball.rect)) {
		ball.speed_x *= -1.0;
	}

	if (check_collision(paddle_two.rect, ball.rect)) {
		ball.speed_x *= -1.0;
	}

	paddle.update(delta_time);
	ball.update(delta_time, score);
	paddle_two.cpu_update(delta_time, ball._y);
}

int main(int argc, char** agrv) {

	// Window Variables
	const int window_width = 640;
	const int window_height = 320;

	int score = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_Log("Error initializing SDL.\n");
	}

	// Entities
	Window window("Pong", window_width, window_height); // Creates Window
	Paddle l_paddle(window, 5, (window_height / 2) - (75/2), 15, 75, 255, 255, 255, 255); // Creates Left Paddle
	CPU_Paddle r_paddle(window, (window_width - (5 + 15)), (window_height / 2) - (75 / 2), 15, 75, 255, 255, 255, 255); // Creates Right Paddle
	Ball ball(window, (window_width / 2) - (10/2), (window_height / 2) - (10/2), 10, 10, 255, 255, 255, 255); // Creates Ball

	while (!window.isClosed()){
		// Events
		poll_events(window, l_paddle);
		// Updates
		updates(l_paddle, ball, r_paddle, score);
		// Draw
		l_paddle.draw();
		r_paddle.draw();
		ball.draw();
		// Clear Window
		window.clear();
	}

	return 0;
}