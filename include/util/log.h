#ifndef UTIL_LOG_H
#define UTIL_LOG_H

#include <iostream>

namespace Util {

	// Log a single message to the console
	template<class T>
	void log(T& msg) {
		std::cout << "Log: " << msg << " " << std::endl;
	}

	// Log a single message with a descriptor to the console
	template<class T, class U>
	void log(U& desc, T& msg) {
		std::cout << "Log: " << desc << " " << msg << " " << std::endl;
	}

}
#endif // !UTIL_LOG_H
