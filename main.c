#include "graphlib.h"
#include "stdbool.h"
#include <stdio.h>
#include "SDL2/SDL.h"

int main(int argc, char* argv[]) {
    G_Window* win = Create_Window(800, 600, "Rasterizer Test", 0, 0);
    if (!win) {
        return 1;
    }
    int x = 150;
    int y = 100;
    Color bg_color = { 30, 30, 35, 255 };
    Color rect_color = { 65, 150, 240, 255 };

    G_Event event;

    bool running = true;
    while (running){
        while (Poll_Event(&event)){
            switch (event.type) {
                case G_Quit:
                    running = 0;                    
                    break;
                case G_Key_Down:
                    switch (event.key.scancode){
                        case SDL_SCANCODE_LEFT:
                            x -= 15;
                            break;
                        case SDL_SCANCODE_RIGHT:
                            x+= 15;
                            break;
                        case SDL_SCANCODE_UP:
                            y-=15;
                            break;
                        case SDL_SCANCODE_DOWN:
                            y+=15;
                            break;
                    }
                    
            }
        }

        Clear_Screen(win);
        Draw_FillRect(win, x, y, 300, 200, rect_color);

        Push_Window(win);
    }
    



    Kill_Window(win);

    return 0;
}