#include "io/file-io.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace IO {

	std::string readFile(const std::string& file) {
		std::stringstream buffer;
		std::ifstream filestream(file);

        buffer << filestream.rdbuf();

        std::string lines(buffer.str());

        return lines;
	}
}
