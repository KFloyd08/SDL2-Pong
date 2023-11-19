#pragma once

#include "paddle.h"
#include <SDL.h>

class CPU_Paddle : public Paddle {
public:
	using Paddle::Paddle; // Inherits Paddles Constuctor

	void cpu_update(double delta_time, int ball_y);

};