//#if _WIN32
//    #define GLEW_STATIC
//    #include "glew.h"
//    #include "eglew.h"
//#endif

#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Not Initialized!" << std::endl;
		return 1;
	}

	constexpr int WIDTH = 800;
	constexpr int HEIGHT = 600;


	SDL_Window* window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

	SDL_Event event;

	while (1) {

		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}

	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

