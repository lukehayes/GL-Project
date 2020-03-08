#ifndef BUFFER_H
#define BUFFER_H

#include "util/gl.h"
#include <vector>


struct Vertex {
    std::vector<float> positions;
};

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
        void init() {

            glGenVertexArrays(1, &m_vao_id);
            glBindVertexArray(m_vao_id);

            glGenBuffers(1, &m_vbo_id);
            glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);

            glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 10, nullptr, GL_STATIC_DRAW);

        
        }

        void sendData() {

            Vertex a;
            a.positions.push_back(0.0);
            a.positions.push_back(0.5);
            a.positions.push_back(0.0);

            Vertex b;
            b.positions.push_back(-0.5);
            b.positions.push_back(-0.5);
            b.positions.push_back(0.0);

            Vertex c;
            c.positions.push_back(0.5);
            c.positions.push_back(-0.5);
            c.positions.push_back(0.0);
                
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(a.positions[0]) * a.positions.size(),  a.positions.data());
            glBufferSubData(GL_ARRAY_BUFFER, sizeof(float) * 3, sizeof(b.positions[0]) * b.positions.size(),  b.positions.data());
            glBufferSubData(GL_ARRAY_BUFFER, sizeof(float) * 6, sizeof(c.positions[0]) * c.positions.size(),  c.positions.data());

        }

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

