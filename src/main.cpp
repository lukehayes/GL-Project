#ifdef _WIN32
    #define GLEW_STATIC
    #include "glew.h"
#elif __UNIX__
    #include <OpenGL/gl3.h>
#endif

#include <iostream>
#include "SDL.h"
#include "app/window.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Not Initialized!" << std::endl;
		return 1;
	}

	constexpr int WIDTH = 800;
	constexpr int HEIGHT = 600;
    
    App::Window window("Title", 800, 600);

	SDL_GLContext glContext = SDL_GL_CreateContext(window.getWindow());

	SDL_Event event;

	while (1) {

		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT) {
			break;
		}

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0, 1.0, 1.0, 1.0);

        SDL_GL_SwapWindow(window.getWindow());
	}

    SDL_GL_DeleteContext(glContext);

    SDL_Quit();

	return 0;
}

