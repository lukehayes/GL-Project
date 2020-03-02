#ifndef IO_H
#define IO_H

#include <string>

namespace IO {
	/**
	* Read in a file and return the contents
	*/
	std::string readFile(const std::string& file);
}

#endif // !IO_H
