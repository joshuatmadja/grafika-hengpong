#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <GL/glew.h>
#include "Transform.h"

using namespace std;

class Shader {
    public:
        Shader(const string& fileName);
        virtual ~Shader();

        void Bind();
        void Update(const Transform& transform);

    protected:

    private:
        static int count_shader;
        static const unsigned int NUM_SHADERS = 2;

        enum {
            TRANSFORM_U,
            NUM_UNIFORMS
        };

        GLuint m_program;
        GLuint m_shaders[NUM_SHADERS];
        GLuint m_uniforms[NUM_UNIFORMS];
};

#endif // SHADER_H
