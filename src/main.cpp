#ifdef _WIN32
    #define GLEW_STATIC
    #include "eglew.h"
    #include "glew.h"
#elif __APPLE__
    #include <OpenGL/gl3.h>
#endif
#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Not Initialized!" << std::endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow(
            "Game Window",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            800,
            600,
            SDL_WINDOW_OPENGL
    );
    SDL_GLContext glContext = SDL_GL_CreateContext(window);


    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

	SDL_Event event;

	while (1) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0, 1.0, 1.0, 1.0);
        SDL_GL_SwapWindow(window);
	}
    
    SDL_GL_DeleteContext(window);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

