#ifndef APP_WINDOW_H
#define APP_WINDOW_H

#include <iostream>
#include "SDL.h"

namespace App {

	class Window {

	public:

		Window(const char* t, int w, int h) 
			: m_title(t), m_width(w), m_height(h)
		{
			this->createWindow();

			// Check that the window was successfully created
			if (m_window == NULL) {
				// In the case that the window could not be made...
				printf("Could not create window: %s\n", SDL_GetError());
			}
		}

		~Window() {

			std::cout << "Window Destroyed" << std::endl;
			SDL_DestroyWindow(m_window);
		}

		/*
			Window getter
		*/
		void createWindow() {
			this->m_window = SDL_CreateWindow(
					m_title,
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					m_width,
					m_height,
					SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
			);
		}
	
		/*
			Window getter
		*/
		SDL_Window* getWindow() {
			return this->m_window;
		}

	private:
		const char* m_title;
		int m_width;
		int m_height;

		SDL_Window* m_window;
	};
}

#endif
