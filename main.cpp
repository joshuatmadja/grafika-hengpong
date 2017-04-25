#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"

using namespace std;
using namespace glm;

int main() {
    Display display(750, 750, "Oppo Neo 7");

    Vertex body_vertices[] =    {
                                    Vertex(vec3(-0.5, -0.5, 0), glm::vec2(0, 0)),
                                    Vertex(vec3(0, 0.5, 0), glm::vec2(0.5, 1)),
                                    Vertex(vec3(0.5, -0.5, 0), glm::vec2(1, 0))
                                };

    float scale = 3;

    Vertex phone_front[] = {
                            Vertex(vec3(0.141*scale, -0.281*scale, 0), glm::vec2(0, 1)),
                            Vertex(vec3(-0.141*scale, -0.281*scale, 0), glm::vec2(1, 1)),
                            Vertex(vec3(-0.141*scale, 0.281*scale, 0),  glm::vec2(1, 0)),
                            Vertex(vec3(0.141*scale, 0.281*scale, 0), glm::vec2(0, 0))
                            };
    Vertex phone_back[] = {
                            Vertex(vec3(-0.141*scale, 0.281*scale, 0.015*scale), glm::vec2(1, 0)),
                            Vertex(vec3(0.141*scale, 0.281*scale, 0.015*scale), glm::vec2(0, 0)),
                            Vertex(vec3(0.141*scale, -0.281*scale, 0.015*scale), glm::vec2(0, 1)),
                            Vertex(vec3(-0.141*scale, -0.281*scale, 0.015*scale), glm::vec2(1, 1)),
                            };
    Vertex phone_left[] = {
                            Vertex(vec3(-0.141*scale, 0.281*scale, 0.015*scale), glm::vec2(1, 0)),
                            Vertex(vec3(-0.141*scale, 0.281*scale, 0), glm::vec2(0, 0)),
                            Vertex(vec3(-0.141*scale, -0.281*scale, 0), glm::vec2(0, 1)),
                            Vertex(vec3(-0.141*scale, -0.281*scale, 0.015*scale), glm::vec2(1, 1)),
                            };
    Vertex phone_right[] = {
                            Vertex(vec3(0.141*scale, 0.281*scale, 0), glm::vec2(1, 0)),
                            Vertex(vec3(0.141*scale, 0.281*scale, 0.015*scale), glm::vec2(0, 0)),
                            Vertex(vec3(0.141*scale, -0.281*scale, 0.015*scale), glm::vec2(0, 1)),
                            Vertex(vec3(0.141*scale, -0.281*scale, 0), glm::vec2(1, 1)),
                            };
    Vertex phone_top[] = {
                            Vertex(vec3(-0.141*scale, 0.281*scale, 0), glm::vec2(0, 0)),
                            Vertex(vec3(0.141*scale, 0.281*scale, 0), glm::vec2(0, 0)),
                            Vertex(vec3(0.141*scale, 0.281*scale, -0.015*scale), glm::vec2(0, 0)),
                            Vertex(vec3(-0.141*scale, 0.281*scale, -0.015*scale), glm::vec2(0, 0)),
                            };
    Vertex phone_bottom[] = {
                            Vertex(vec3(-0.141*scale, -0.281*scale, 0), glm::vec2(0, 0)),
                            Vertex(vec3(0.141*scale, -0.281*scale, 0), glm::vec2(0, 0)),
                            Vertex(vec3(0.141*scale, -0.281*scale, -0.015*scale), glm::vec2(0, 0)),
                            Vertex(vec3(-0.141*scale, -0.281*scale, -0.015*scale), glm::vec2(0, 0)),
                            };
    Vertex box[] = {
                    Vertex(vec3(-1, -1, -0.015*scale), glm::vec2(0, 0)),
                    Vertex(vec3(-1, 1, -0.015*scale), glm::vec2(0, 0)),
                    Vertex(vec3(1, 1, -0.015*scale), glm::vec2(0, 0)),
                    Vertex(vec3(1, -1, -0.015*scale), glm::vec2(0, 0)),
                    };


    Mesh body(body_vertices, sizeof(body_vertices)/sizeof(body_vertices[0]));

    Mesh front_phone(phone_front, sizeof(phone_front)/sizeof(phone_front[0]));
    Mesh back_phone(phone_back, sizeof(phone_back)/sizeof(phone_back[0]));
    Mesh left_phone(phone_left, sizeof(phone_left)/sizeof(phone_left[0]));
    Mesh right_phone(phone_right, sizeof(phone_right)/sizeof(phone_right[0]));
    Mesh top_phone(phone_top, sizeof(phone_top)/sizeof(phone_top[0]));
    Mesh bottom_phone(phone_bottom, sizeof(phone_bottom)/sizeof(phone_bottom[0]));
    Mesh box_mesh(box, sizeof(box)/sizeof(box[0]));


//    Shader red_shader("./res/redShader");
//    Shader green_shader("./res/greenShader");
    Shader white_shader("./res/whiteShader");
    Shader black_shader("./res/blackShader");
//    Shader blue_shader("./res/blueShader");
    Shader shader("./res/textureShader");
//    Texture texture("./res/bricks.jpg");
    Texture frontTexture("./res/Phone-front-cropped.png");
    Texture backTexture("./res/Phone-back-cropped.png");
    Texture leftTexture("./res/Phone-left-cropped.png");
    Texture rightTexture("./res/Phone-left-cropped.png");
    Texture topTexture("./res/Phone-topbottom-cropped.png");
    Texture bottomTexture("./res/Phone-topbottom-cropped.png");

    Transform transform;
    float counter = 0.0f;
    int face = 1;

    while (!display.IsClosed()) {

        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
 //           transform.GetPos().x = sinf(counter);

        black_shader.Bind();
        box_mesh.DrawPolygon();


        transform.GetRot().y = counter;

        shader.Bind();
        shader.Update(transform);


        //shader.Bind();
        //shader.Update(transform);
        if (counter <= 1.55f) {
            frontTexture.Bind(0);
            front_phone.DrawPolygon();

            leftTexture.Bind(0);
            left_phone.DrawPolygon();

            rightTexture.Bind(0);
            right_phone.DrawPolygon();

            backTexture.Bind(0);
            back_phone.DrawPolygon();
        } else if (counter > 1.55f && counter <= 3.1f) {
            backTexture.Bind(0);
            back_phone.DrawPolygon();

            rightTexture.Bind(0);
            right_phone.DrawPolygon();

            frontTexture.Bind(0);
            front_phone.DrawPolygon();

            leftTexture.Bind(0);
            left_phone.DrawPolygon();
        } else if (counter > 3.1f && counter <= 4.7f) {
            leftTexture.Bind(0);
            left_phone.DrawPolygon();

            backTexture.Bind(0);
            back_phone.DrawPolygon();

            frontTexture.Bind(0);
            front_phone.DrawPolygon();

            rightTexture.Bind(0);
            right_phone.DrawPolygon();
        } else {
            frontTexture.Bind(0);
            front_phone.DrawPolygon();

            leftTexture.Bind(0);
            left_phone.DrawPolygon();

            backTexture.Bind(0);
            back_phone.DrawPolygon();

            rightTexture.Bind(0);
            right_phone.DrawPolygon();

            if (counter > 6.2f) {
                counter = 0;
            }
        }

/*        if (counter > 1.55f) {
            backTexture.Bind(0);
            back_phone.DrawPolygon();

            rightTexture.Bind(0);
            right_phone.DrawPolygon();

            frontTexture.Bind(0);
            front_phone.DrawPolygon();

            leftTexture.Bind(0);
            left_phone.DrawPolygon();

            if (counter > 3.1f) {
                leftTexture.Bind(0);
                left_phone.DrawPolygon();

                frontTexture.Bind(0);
                front_phone.DrawPolygon();
            }

            if (counter > 4.7f) {
                frontTexture.Bind(0);
                front_phone.DrawPolygon();

                leftTexture.Bind(0);
                left_phone.DrawPolygon();

                backTexture.Bind(0);
                back_phone.DrawPolygon();

                rightTexture.Bind(0);
                right_phone.DrawPolygon();
            }
            if (counter > 6.2f) {
                counter = 0;
            }
        } else {
            frontTexture.Bind(0);
            front_phone.DrawPolygon();

            leftTexture.Bind(0);
            left_phone.DrawPolygon();

            rightTexture.Bind(0);
            right_phone.DrawPolygon();

            backTexture.Bind(0);
            back_phone.DrawPolygon();
        } */
/*        if (face == 1) {
            shader.Bind();
            shader.Update(transform);
            frontTexture.Bind(0);
            front_phone.DrawPolygon();
        } else if (face == 2) {
            shader.Bind();
            shader.Update(transform);
            backTexture.Bind(0);
            back_phone.DrawPolygon();
        } else if (face == 3) {
            shader.Bind();
            shader.Update(transform);
            leftTexture.Bind(0);
            left_phone.DrawPolygon();
        } */

/*        backTexture.Bind(0);
        back_phone.DrawPolygon();

        leftTexture.Bind(0);
        left_phone.DrawPolygon();

        rightTexture.Bind(0);
        right_phone.DrawPolygon();

        topTexture.Bind(0);
        top_phone.DrawPolygon();

        bottomTexture.Bind(0);
        bottom_phone.DrawPolygon(); */
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
        /*if (counter > 1.55f) {
            face = 1;
            if (counter > 4.7f) {
                face = 2;
            }
            if (counter > 6.2f) {
                counter = 0;
            }
        } else {
            face = 2;
        }*/
        counter += 0.01f;
    }

    return 0;
}
