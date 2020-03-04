/*
Store all of the OpenGL headers in this file
so that it mostly works in a cross platform way
*/
#ifndef UTIL_GL
#define UTIL_GL

#ifdef _WIN32
    #define GLEW_STATIC
    #include "glew.h"
#elif __APPLE__
    #include "OpenGL/gl3.h"
#endif

#endif // !UTIL_GL
