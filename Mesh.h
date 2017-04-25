#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <iostream>

using namespace std;
using namespace glm;

class Vertex {
    public:
        Vertex(const vec3& pos, const glm::vec2 texCoord)
        {
            this->pos = pos;
            this->texCoord = texCoord;
        }
        inline glm::vec3* getPos() { return &pos; }
        inline glm::vec3 getTexCoord() { return &texCoord; }
        
    protected:

    private:
        vec3 pos;
        vec2 texCoord;
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
            TEXCOORD_V8,
            NUM_BUFFERS
        };

        GLuint m_vertexArrayObject;
        GLuint m_vertexArrayBuffer[NUM_BUFFERS];
        unsigned int m_drawCount;
};

#endif // MESH_H
