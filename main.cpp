#include <SDL.h>
#include <stdio.h>
#include <GL/gl.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);SDL_Window *window = SDL_CreateWindow(
        "SDL2/OpenGL Demo", 30, 30, 640, 480,
        SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
        SDL_GL_CreateContext(window);
    glClearColor(0,0,1,1);
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }
    float x=0;
    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
                if(event.type==SDL_QUIT)
                    return 1;
        }
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glVertex2f(0,0);
        glVertex2f(0,0.5);
        glVertex2f(0.5,0.5);
        glVertex2f(0.5,0.5);
        glVertex2f(0.5,0.0);
        glVertex2f(0.0,0.0);
        glEnd();

        SDL_GL_SwapWindow(window);
    }
    SDL_Quit();
    return 0;
}
