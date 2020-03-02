#include "io/file-io.h"

#include <iostream>
#include <fstream>
#include <sstream>

namespace IO {

	std::string readFile(const std::string& file) {

		std::stringstream contents;
		std::fstream filestream;

		filestream.open(file, std::ios::in);

		if (filestream.is_open()) {
			std::cout << "File: " << file << " opened." << std::endl;
		}
		else {
			std::cout << "File: " << file << " could not be opened."<< std::endl;
			return "Reading Failed";
		}

		// Lazy way of reading in file contents
		// but it works
		contents << filestream.rdbuf();

		return contents.str();
	}
}
