# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.15)
project ("app" CXX)

# ------------------------------------------------------
# Helper Variables
# ------------------------------------------------------
SET(PROGRAM_NAME "app")

SET(SRC_DIR "src")
SET(SRC_FILE "${SRC_DIR}/main.cpp")
SET(LIBS_DIR "${PROJECT_SOURCE_DIR}/deps/libs")

SET(GLEW_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/deps/libs/GLEW/include/")
SET(GLEW_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/deps/libs/GLEW/libs/")
SET(SDL_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/deps/libs/SDL/include/")
SET(SDL_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/deps/libs/SDL/libs/")

SET(CORE_INCLUDES
	"${PROJECT_SOURCE_DIR}/include"
    "${LIBS_DIR}"
)

# ------------------------------------------------------
# WINDOWS
# ------------------------------------------------------
if (WIN32)

    set(INC_DIRS
		"${GLEW_INC_DIR}"
		"${SDL_INC_DIR}"
        "${CORE_INCLUDES}"
    )

    include_directories(${INC_DIRS})
    link_directories("${SDL_LIB_DIR}")
    link_directories("${GLEW_LIB_DIR}")

    # Add source to this project's executable.
    add_executable ("${PROGRAM_NAME}" "${SRC_FILE}")

    add_subdirectory("${SRC_DIR}/io")

    target_link_libraries(app
        "${SDL_LIB_DIR}SDL2.lib"
        "${SDL_LIB_DIR}SDL2main.lib"
        "${GLEW_LIB_DIR}glew32s.lib"
        "opengl32.lib"
        io
    )

endif(WIN32)


# ------------------------------------------------------
# OSX | LINUX
# ------------------------------------------------------
if(APPLE OR UNIX)

    # Modules Path
    set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

    # Add source to this project's executable.
    add_executable ("${PROGRAM_NAME}" "${SRC_FILE}")


    find_package (SDL2 REQUIRED)
    find_package (OpenGL REQUIRED)
    find_package (GLEW REQUIRED STATIC)

    include_directories(
		"${PROJECT_SOURCE_DIR}/include"
        "${SDL2_INCLUDE_DIR}"
        "${GLEW_INCLUDE_DIRS}"
        "${OPENGL_INCLUDE_DIR}"
		"${PROJECT_SOURCE_DIR}/deps/libs/"
    )

    add_subdirectory("${SRC_DIR}/io")
    target_link_libraries ("${PROGRAM_NAME}" ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} io)
    target_compile_features("${PROGRAM_NAME}" PUBLIC cxx_std_11)




endif(APPLE OR UNIX)

