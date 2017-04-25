#include "Mesh.h"

int Mesh::count_mesh = 0;

Mesh::Mesh(Vertex* vertices, unsigned int numVertices) {
    m_drawCount = numVertices;

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffer);
    glBindBuffer(GL_ARRAY_BUFFER ,m_vertexArrayBuffer[POSITION_V8]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

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
