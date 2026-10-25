#include "graphlib.h"
#include "stdbool.h"
#include <stdio.h>
#include "SDL2/SDL.h"

int main(int argc, char* argv[]) {
    G_Window* win = Create_Window(800, 600, "Rasterizer Cool Demo", 0, 0);
    if (!win) {
        return 1;
    }

    // Movable object starting position
    int x = 350;
    int y = 250;
    
    Color rect_color = { 65, 150, 240, 255 };
    Color line_color = { 240, 190, 60, 255 };
    Color accent_color = { 230, 70, 70, 255 };

    G_Event event;
    bool running = true;

    while (running) {
        while (Poll_Event(&event)) {
            switch (event.type) {
                case G_Quit:
                    running = false;                    
                    break;
                case G_Key_Down:
                    switch (event.key.scancode) {
                        case SDL_SCANCODE_LEFT:
                            x -= 20;
                            break;
                        case SDL_SCANCODE_RIGHT:
                            x += 20;
                            break;
                        case SDL_SCANCODE_UP:
                            y -= 20;
                            break;
                        case SDL_SCANCODE_DOWN:
                            y += 20;
                            break;
                        case SDL_SCANCODE_ESCAPE:
                            running = false;
                            break;
                    }
                    break;
            }
        }

        // Clear the screen to background color
        Clear_Screen(win);

        // 1. Draw a cool border using your new Draw_Line function
        Draw_Line(win, 40, 40, 760, 40, line_color);   // Top
        Draw_Line(win, 760, 40, 760, 560, line_color); // Right
        Draw_Line(win, 760, 560, 40, 560, line_color); // Bottom
        Draw_Line(win, 40, 560, 40, 40, line_color);   // Left

        // 2. Draw diagonal accent lines from corners
        /*Draw_Line(win, 40, 40, 140, 140, accent_color);
        Draw_Line(win, 760, 40, 660, 140, accent_color);
        Draw_Line(win, 40, 560, 140, 460, accent_color);
        Draw_Line(win, 760, 560, 660, 460, accent_color);*/

        // 3. Draw your movable rectangle object
        Draw_FillRect(win, x, y, 100, 100, rect_color);

        // Push everything to the screen window
        Push_Window(win);

        // Cap frame rate roughly to ~60 FPS to prevent 100% CPU usage
        SDL_Delay(16);
    }

    Kill_Window(win);
    return 0;
}