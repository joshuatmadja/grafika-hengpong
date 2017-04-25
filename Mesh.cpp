#include "Mesh.h"
#include <vector.h>

int Mesh::count_mesh = 0;

Mesh::Mesh(Vertex* vertices, unsigned int numVertices) {
    m_drawCount = numVertices;

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;

    positions.reserve(numVertices);
    texCoords.reserve(numVertices);

    for (unsigned int i = 0; i < numVertices; i++) {
        positions.push_back(*vertices[i].getPos());
        texCoords.push_back(*vertices[i].getTexCoords());
    }

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffer);
    glBindBuffer(GL_ARRAY_BUFFER ,m_vertexArrayBuffer[POSITION_V8]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER ,m_vertexArrayBuffer[TEXCOORD_V8]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);

    ++count_mesh;
    cout << "CTOR | Mesh | " << count_mesh << endl;
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &m_vertexArrayObject);

    cout << "DTOR | Mesh | " << count_mesh << endl;
    --count_mesh;
}

void Mesh::DrawPolygon() {
    glBindVertexArray(m_vertexArrayObject);

    glDrawArrays(GL_POLYGON, 0, m_drawCount);
    //glDrawArraysInstanced(GL_POLYGON, 0, m_drawCount, 5);

    glBindVertexArray(0);
}
