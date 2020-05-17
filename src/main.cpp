
#include "util/gl.h"
#include "SDL.h"
#include "app/window.h"
#include "shaders/shader.h"
#include "core/buffer.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Not Initialized!" << std::endl;
		return 1;
	}

	constexpr int WIDTH = 800;
	constexpr int HEIGHT = 600;
    
    App::Window window("Title", 800, 600);

	Shader::Shader shader;
	Core::Buffer buffer;
	buffer.init();
	buffer.sendData();

    
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    view = glm::lookAt(
        
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, -0.1f),
        glm::vec3(0.0f, 1.0f, 0.0f)

    );

    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);  
    
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f));



	SDL_Event event;

	while (1) {

		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT) {
			break;
		}

		
		shader.use();

        shader.setMat4("model", model);
        shader.setMat4("view", view);
        shader.setMat4("projection", projection);

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2, 0.2, 0.2, 1.0);

		glDrawArrays(GL_TRIANGLES, 0, 3);

        SDL_GL_SwapWindow(window.getWindow());
	}


    SDL_Quit();

	return 0;
}

