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

			SDL_DestroyWindow(m_window);
			std::cout << "Window Destroyed" << std::endl;

            SDL_GL_DeleteContext(m_context);
			std::cout << "GL Context Destroyed" << std::endl;
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

            SDL_GL_SetAttribute (SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
            SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 3); //OpenGL 3+
            SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 3); //OpenGL 3.3
            m_context = SDL_GL_CreateContext(m_window);
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
        SDL_GLContext m_context;
	};
}

#endif
