#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "texture.h"

using namespace std;
using namespace glm;

int main() {
    Display display(800, 600, "Dragon");
    Vertex head_vertices[] =    {
                                    Vertex(vec3(0, 0, 0)),
                                    Vertex(vec3(-0.25, 0.0, 0)),
                                    Vertex(vec3(-0.25, 0.25, 0)),
                                    Vertex(vec3(0.0, 0.25, 0)),
                                };


    Vertex eye_vertices[] =     {
                                    Vertex(vec3(-0.2, 0.15, 0)),
                                    Vertex(vec3(-0.15, 0.2, 0)),
                                    Vertex(vec3(-0.17, 0.15, 0)),
                                };

    Vertex body_vertices[] =    {
                                    Vertex(vec3(0, 0, 0)), glm::vec2(0.5, 0.5),
                                    Vertex(vec3(0.1, -0.7, 0)), glm::vec2(0.6, -0.2),
                                    Vertex(vec3(-0.1, 0, 0)), glm::vec2(0.4, 0.5)
                                };

    Vertex mouth_vertices[] =   {
                                    Vertex(vec3(-0.25, 0, 0)),
                                    Vertex(vec3(-0.25, 0.13, 0)),
                                    Vertex(vec3(-0.15, 0.05, 0)),
                                };

    Vertex wing_vertices[] =    {
                                    Vertex(vec3(0, 0, 0)),
                                    Vertex(vec3(0.5, 0.5, 0)),
                                    Vertex(vec3(0.375, 0.25, 0)),
                                    Vertex(vec3(0.5, 0, 0)),
                                    Vertex(vec3(0.375, -0.25, 0)),
                                    Vertex(vec3(0.5, -0.5, 0)),
                                    Vertex(vec3(0.055, -0.4, 0)),
                                };

    Vertex hands_vertices[] =   {
                                    Vertex(vec3(0.055, -0.4, 0)),
                                    Vertex(vec3(-0.055, -0.7, 0)),
                                    Vertex(vec3(-0.055, -0.1, 0)),
                                };

    Vertex foots_vertices[] =   {
                                    Vertex(vec3(0, -0.125, 0)),
                                    Vertex(vec3(-0.15, -0.13, 0)),
                                    Vertex(vec3(0, -0.2, 0)),

                                    Vertex(vec3(0, -0.225, 0)),
                                    Vertex(vec3(-0.25, -0.23, 0)),
                                    Vertex(vec3(0, -0.2, 0)),
                                };
    Vertex horns_vertices[] =   {
                                    Vertex(vec3(-0.25, 0.25, 0)),
                                    Vertex(vec3(-0.125, 0.375, 0)),
                                    Vertex(vec3(-0.2, 0.25, 0)),

                                    Vertex(vec3(-0.075, 0.375, 0)),
                                    Vertex(vec3(-0.15, 0.25, 0)),
                                };

    Mesh head(head_vertices, sizeof(head_vertices)/sizeof(head_vertices[0]));
    Mesh eye(eye_vertices, sizeof(eye_vertices)/sizeof(eye_vertices[0]));
    Mesh body(body_vertices, sizeof(body_vertices)/sizeof(body_vertices[0]));
    Mesh mouth(mouth_vertices, sizeof(mouth_vertices)/sizeof(mouth_vertices[0]));
    Mesh wing(wing_vertices, sizeof(wing_vertices)/sizeof(wing_vertices[0]));
    Mesh hands(hands_vertices, sizeof(hands_vertices)/sizeof(hands_vertices[0]));
    Mesh foots(foots_vertices, sizeof(foots_vertices)/sizeof(foots_vertices[0]));
    Mesh horns(horns_vertices, sizeof(horns_vertices)/sizeof(horns_vertices[0]));

    Shader red_shader("./res/redShader");
    Shader green_shader("./res/greenShader");
    Shader white_shader("./res/whiteShader");
    Shader black_shader("./res/blackShader");
    Shader blue_shader("./res/blueShader");
    Texture texture("./res/bricks.jpg");

    while (!display.IsClosed()) {
        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

        green_shader.Bind();
        texture.Bind(0);
//        head.DrawPolygon();
        body.DrawPolygon();
        // hands.DrawPolygon();
        // foots.DrawPolygon();

        // red_shader.Bind();
        // eye.DrawPolygon();
        // horns.DrawPolygon();

        // black_shader.Bind();
        // mouth.DrawPolygon();

        // blue_shader.Bind();
        // wing.DrawPolygon();

        display.Update();
    }

    return 0;
}
