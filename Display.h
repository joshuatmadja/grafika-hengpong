#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <string>

using namespace std;

class Display {
    public:
        Display(int width, int height, const string& title);
        virtual ~Display();

        void Update();
        bool IsClosed();
        void Clear(float r, float g, float b, float a);

    protected:

    private:
        static int count_display;

        SDL_Window* m_window;
        SDL_GLContext m_glContext;
        bool m_isClosed;
};

#endif // DISPLAY_H
