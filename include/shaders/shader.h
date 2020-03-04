#ifndef SHADER_SHADER_H
#define SHADER_SHADER_H

#include <string>
#include "io/file-io.h"
#include "util/gl.h"
#include "util/log.h"

namespace Shader {

	class Shader
	{
	public:
		Shader() {
			this->buildShader();
		};
		~Shader() {};

		void setShaderSource() {
			this->vertexShaderSource = IO::readFile("../assets/shaders/debug-vertex.txt");
			this->fragShaderSource = IO::readFile("../assets/shaders/debug-fragment.txt");
		}

		void buildShader() {

			// Set the vert and fragment source strings
			this->setShaderSource();

			const char* vsh = this->vertexShaderSource.c_str();
			const char* fsh = this->fragShaderSource.c_str();

			GLuint vertexID = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexID, 1, &vsh, NULL);
			glCompileShader(vertexID);
			checkCompileErrors(vertexID, "VERTEX");

			GLuint fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragmentID, 1, &fsh, NULL);
			glCompileShader(fragmentID);
			checkCompileErrors(fragmentID, "FRAGMENT");

			// Create the shader program
			this->shaderProgram = glCreateProgram();

			// Attach the shaders
			glAttachShader(this->shaderProgram, vertexID);
			glAttachShader(this->shaderProgram, fragmentID);

			// Link the program
			glLinkProgram(this->shaderProgram);
			checkCompileErrors(shaderProgram, "SHADER PROGRAM");
		
		}

		GLuint getShaderProgram() const {
			return this->shaderProgram;
		}

		void sendFloat(float val, const char* uniformName) {
			GLint location = glGetUniformLocation(this->shaderProgram, uniformName);
			glUniform1f(location, val);
		}


	private:

		void checkCompileErrors(unsigned int shader, std::string type)
		{
			int success;
			char infoLog[1024];
			if (type != "PROGRAM")
			{
				glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
				if (!success)
				{
					glGetShaderInfoLog(shader, 1024, NULL, infoLog);
					Util::log("ERROR::SHADER_COMPILATION_ERROR of type: ", infoLog);
				}
			}
			else
			{
				glGetProgramiv(shader, GL_LINK_STATUS, &success);
				if (!success)
				{
					glGetProgramInfoLog(shader, 1024, NULL, infoLog);
					Util::log("ERROR::SHADER_LINK_ERROR of type: ", infoLog);
				}
			}
		}



		GLuint shaderProgram = 0;
		std::string vertexShaderSource;
		std::string fragShaderSource;

	};

}

#endif // SHADER_SHADER_H
