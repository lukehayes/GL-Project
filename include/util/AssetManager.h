/**
 * AssetManager class represents and easier way to deal with
 * file paths while fetching shader files for example
 */
#ifndef UTIL_ASSET_MANAGER_H
#define UTIL_ASSET_MANAGER_H

#include <string>

namespace Util {

	class AssetManager {

	public:
        AssetManager() {}
        ~AssetManager() {}

        static std::string shaderPath() {
            return "../assets/shaders/";
        }

	private:


    };
}
#endif
