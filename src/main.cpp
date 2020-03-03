#ifdef _WIN32
    #define GLEW_STATIC
    #include "glew.h"
#elif __UNIX__
    #include <OpenGL/gl3.h>
#endif

#include <iostream>
#include <vector>
#include <string>
#include "SDL.h"
#include "app/window.h"
#include "shaders/shader.h"

void doGL() {
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	std::vector<float> verts {
	   -1.0f, -1.0f, 0.0f,
	   1.0f, -1.0f, 0.0f,
	   0.0f,  1.0f, 0.0f
	};

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verts.size(), verts.data(), GL_STATIC_DRAW);
}

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Not Initialized!" << std::endl;
		return 1;
	}

	constexpr int WIDTH = 800;
	constexpr int HEIGHT = 600;
    
    App::Window window("Title", 800, 600);

    SDL_GL_SetAttribute (SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 3); //OpenGL 3+
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 3); //OpenGL 3.3
	SDL_GLContext glContext = SDL_GL_CreateContext(window.getWindow());

    int a;
    int b;

    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &a);
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &b);

    std::cout << a << " " << b << std::endl;

    doGL();

	Shader::Shader shader;



	SDL_Event event;

	while (1) {

		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT) {
			break;
		}

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0, 1.0, 1.0, 1.0);

		glUseProgram(shader.getShaderProgram());
		glDrawArrays(GL_TRIANGLES,0, 3);

        SDL_GL_SwapWindow(window.getWindow());
	}

    SDL_GL_DeleteContext(glContext);

    SDL_Quit();

	return 0;
}

