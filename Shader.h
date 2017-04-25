#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <GL/glew.h>

using namespace std;

class Shader {
    public:
        Shader(const string& fileName);
        virtual ~Shader();

        void Bind();

    protected:

    private:
        static int count_shader;
        static const unsigned int NUM_SHADERS = 2;

        GLuint m_program;
        GLuint m_shaders[NUM_SHADERS];
};

#endif // SHADER_H
