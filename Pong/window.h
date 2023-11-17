#pragma once

#include <SDL.h>
#include <string>

class Window {
	public:
		Window(std::string name, int width, int height);
		~Window();

		inline bool isClosed() const { return _closed; }

		void clear();
		void poll_events(SDL_Event event);

	private:
		bool init();

	private:
		std::string _name;
		int _width;
		int _height;

		bool _closed = false;

		SDL_Window* _window;
protected:
		SDL_Renderer* _renderer;
};
