# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.15)
project ("app")

# ------------------------------------------------------
# Helper Variables
# ------------------------------------------------------
SET(SRC_DIR "src")
SET(SRC_FILE "${SRC_DIR}/main.cpp")
SET(LIBS_DIR "${PROJECT_SOURCE_DIR}/deps/libs")
SET(PROGRAM_NAME "app")

SET(CORE_INCLUDES
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/deps/libs/"
)

# ------------------------------------------------------
# WINDOWS
# ------------------------------------------------------
if (WIN32)

    set(INC_DIRS
        ${PROJECT_SOURCE_DIR}/deps/libs/SDL/include
        ${PROJECT_SOURCE_DIR}/deps/libs/GLEW/include
        ${CORE_INCLUDES}
    )

    include_directories(${INC_DIRS})
    link_directories(${PROJECT_SOURCE_DIR}/deps/libs/SDL/libs)

    # Add source to this project's executable.
    add_executable ("${PROGRAM_NAME}" "${SRC_FILE}")

    target_link_libraries("${PROGRAM_NAME}" SDL2.lib)
    target_link_libraries("${PROGRAM_NAME}" SDL2main.lib)

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

