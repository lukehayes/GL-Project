# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.15)
project ("app" CXX)

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
    link_directories(${PROJECT_SOURCE_DIR}/deps/libs/GLEW/libs)

    # Add source to this project's executable.
    add_executable ("${PROGRAM_NAME}" "${SRC_FILE}")

    message(${CMAKE_CURRENT_SOURCE_DIR})
    message(${CMAKE_CURRENT_SOURCE_DIR})

    add_library(SDL2 SHARED IMPORTED)
    set_target_properties(SDL2 PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/deps/libs/SDL/libs/SDL2.lib")

    add_library(SDL2main SHARED IMPORTED)
    set_target_properties(SDL2main PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/deps/libs/SDL/libs/SDL2main.lib")

    add_library(glew STATIC IMPORTED)
    set_target_properties(glew PROPERTIES IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/deps/libs/GLEW/libs/glew32s.lib")

    add_subdirectory("${SRC_DIR}/io")

    target_link_libraries(app 
        "${CMAKE_CURRENT_SOURCE_DIR}/deps/libs/SDL/libs/SDL2.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/deps/libs/SDL/libs/SDL2main.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/deps/libs/GLEW/libs/glew32s.lib"
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

