#ifndef BUFFER_H
#define BUFFER_H

#include "util/gl.h"

namespace Core {
    
    /**
     * A buffer is a combination of a VAO and VBO with
     * the ability to add buffer data to it
     */
    class Buffer {

    public:
        /**
         * Default Constructor
         */
        Buffer() {}

        /**
         * Dtor 
         */
        ~Buffer() {}
    
        /**
         * Initialize a full buffer - Allocate as much memory as we need
         * for use in this application
         *
         * @return void
         */
        void init() {}

    private:

        /**
         * ID for this vertex array
         */
        GLuint m_vao_id;

        /**
         * ID for this vertex buffer
         */
        GLuint m_vbo_id;

        /**
         * How much memory the buffer will take up.
         * This is intended to be sizeof(vertex) * MAX_BUFFER_SIZE
         */
        const int MAX_BUFFER_SIZE = 1000;
    };
}

#endif

