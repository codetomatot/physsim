#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
// #include "matrix.h"
#include "libphys.h"

#define PI 3.141592653589793
#define WINDOW_HEIGHT 700
#define WINDOW_WIDTH 900

void create_rect(SDL_Renderer* r, int xpos, int ypos, int w, int h) {
    SDL_Rect border;
    border.x = xpos;
    border.y = ypos;
    border.w = w;
    border.h = h;

    SDL_SetRenderDrawColor(r, 255,255,255,255);
    SDL_RenderDrawRect(r, &border);
    SDL_RenderFillRect(r, &border);
    SDL_SetRenderDrawColor(r, 0,0,0,255);
}


int main() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_Window* win = SDL_CreateWindow("Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL); //turns out top left corner is origin (0,0)
    SDL_Renderer* render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(render,0,0,0,255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);

    gravitational_field g = gravitational_field(9.8);

    int x_c = 0;
    int y_c = 630;
    float accel[2] = {0, 9.8f}; 
    float velocity_t[2] = {100*cos(PI/3), -100*sin(PI/3)};
    kinematics move_rect_test = kinematics(x_c, y_c, accel, 33.333333e-3f, velocity_t);


    bool exit = false;
    printf("ah yes, the path to the swamp has been found\n");
    while(!exit) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_QUIT:
                exit = true;
                break;
            case SDL_KEYDOWN:
                break;
            case SDL_KEYUP:
                break;
            default:
                break;
            }
        }
        create_rect(render, 0, 670, WINDOW_WIDTH, WINDOW_HEIGHT); 
        move_rect_test.linear_move();
        // std::cout << y_c << std::endl;
        create_rect(render, x_c, y_c, 20, 20);  
        if(y_c >= WINDOW_HEIGHT) {
            move_rect_test.terminate_move();
            y_c -= (y_c-WINDOW_HEIGHT)+50;
        }

        SDL_RenderPresent(render);
        SDL_RenderClear(render);
        SDL_Delay(1000/60);
    }

    return 0;
}