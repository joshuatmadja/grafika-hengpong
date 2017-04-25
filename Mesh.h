#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <iostream>

using namespace std;
using namespace glm;

class Vertex {
    public:
        Vertex(const vec3& pos) { this->pos = pos; }
    protected:

    private:
        vec3 pos;
};

class Mesh {
    public:
        Mesh(Vertex* vertices, unsigned int numVertices);
        virtual ~Mesh();

        void DrawPolygon();

    protected:

    private:
        static int count_mesh;

        enum {
            POSITION_V8,

            NUM_BUFFERS
        };

        GLuint m_vertexArrayObject;
        GLuint m_vertexArrayBuffer[NUM_BUFFERS];
        unsigned int m_drawCount;
};

#endif // MESH_H
