# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.7)
project ("app")

# ------------------------------------------------------
# Helper Variables
# ------------------------------------------------------
SET(SRC_DIR "src")
SET(SRC_FILE "${SRC_DIR}/main.cpp")
SET(LIBS_DIR "${PROJECT_SOURCE_DIR}/deps/libs")

SET(CORE_INCLUDES
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/deps/libs/glm"
)

# All of the sub directory names found in the src folder
SET(SRC_LIBS io)


# ------------------------------------------------------
# WINDOWS
# ------------------------------------------------------
if (WIN32)

    message("Running on Windows")

    set(INC_DIRS
        ${PROJECT_SOURCE_DIR}/deps/libs/SDL/include
        ${PROJECT_SOURCE_DIR}/deps/libs/GLEW/include
        ${CORE_INCLUDES}
    )
    
    include_directories(${INC_DIRS})

    link_directories(
        ${PROJECT_SOURCE_DIR}/deps/libs/SDL/libs
        ${PROJECT_SOURCE_DIR}/deps/libs/GLEW/libs
     )

    add_subdirectory("${PROJECT_SOURCE_DIR}/src/io")

    # Add source to this project's executable.
    add_executable (app "${SRC_FILE}")

    target_link_libraries(app SDL2main.lib)
    target_link_libraries(app SDL2.lib io)
    target_link_libraries(app glew32s.lib)

endif(WIN32)

# ------------------------------------------------------
# OSX
# ------------------------------------------------------
if(APPLE)
    message("Running on APPLE")

    # Modules Path
    set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

    # Find SDL2 on OSX - must be at top
    find_package (SDL2 REQUIRED)

    include_directories(
		${PROJECT_SOURCE_DIR}/include
		${SDL2_INCLUDE_DIR}
    )

    add_subdirectory("${PROJECT_SOURCE_DIR}/src/io")

    # Add source to this project's executable.
    add_executable (app "${SRC_FILE}")
    target_link_libraries (app ${SDL2_LIBRARIES} io)

endif(APPLE)


# ------------------------------------------------------
# NEDED FOR WINDOWS AND OSX
# ------------------------------------------------------
# FIND OPENGL
# ------------------------------------------------------
find_package (OPENGL)
if (OPENGL_FOUND)
  include_directories(${OPENGL_INCLUDE_DIR})
  target_link_libraries (app ${OPENGL_LIBRARIES})
endif (OPENGL_FOUND)
