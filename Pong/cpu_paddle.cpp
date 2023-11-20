#include "cpu_paddle.hpp"

void CPU_Paddle::cpu_update(double delta_time, int ball_y) {	
	if (_y + _h / 2 > (ball_y - 10) && _y > 0){
		m_y -= 8.0 * delta_time;
		_y = m_y;
	}

	if (_y + _h / 2 <= ball_y + 10 && _y + _h <= 320) {
		m_y += 8.0 * delta_time;
		_y = m_y;
	}
}