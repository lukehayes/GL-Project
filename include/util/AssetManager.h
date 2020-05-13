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
        
        /**
         * Return the path to the folder where the shaders are located
         *
         * @return std::string
         */
        static std::string shaderPath() {
            return "../assets/shaders/";
        }
        
        /**
         * Return the path of a specific shader file
         *
         * @param std::string shaderFile The shader that we want
         *
         * @return std::string
         */
        static std::string getShaderFile(const std::string& shaderFile) {
            return "../assets/shaders/" + shaderFile;
        }

	private:


    };
}
#endif
