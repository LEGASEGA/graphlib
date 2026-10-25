#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdint.h>
#include "graphlib.h"
#include "stdio.h"
#include <stdbool.h>
#include <string.h>

struct G_Window {
    SDL_Window* sdl_win;      
    SDL_Renderer* renderer;   
    int width;
    int height;
    uint32_t* pixels;
    uint32_t* backpixels;
    SDL_Texture* texture;
    bool isdirty;
};


G_Window* Create_Window(int w, int h, const char* title, uint32_t wflags, uint32_t rflags) {
    // 1. Allocate container
    G_Window* win = malloc(sizeof( G_Window));
    if (win == NULL) {
        return NULL;
    } 
    win->height = h;
    win->width = w;
    win->isdirty = 0;
    // 2. Allocate pixel buffer & check
    win->pixels = malloc(win->width * win->height * sizeof(uint32_t));
    if (win->pixels == NULL) {
        free(win);
        return NULL;
    }

    win->backpixels = malloc(win->width * win->height * sizeof(uint32_t));
    if (win->backpixels == NULL) {
        free(win);
        return NULL;
    }
    // 3. Create native window & check
    win->sdl_win = SDL_CreateWindow(title, 0, 0, w, h, wflags);
    if (win->sdl_win == NULL) {
        free(win->pixels);
        free(win);
        return NULL;
    }

    // 4. Create native renderer & check
    win->renderer = SDL_CreateRenderer(win->sdl_win, -1, rflags);
    if (win->renderer == NULL) {
        SDL_DestroyWindow(win->sdl_win);
        free(win->pixels);
        free(win);
        return NULL;
    }
    
    //5. Initialize texture

    win->texture = SDL_CreateTexture(win->renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, win->width, win->height);

    if (win->texture == NULL){
        SDL_DestroyWindow(win->sdl_win);
        SDL_DestroyRenderer(win->renderer);
        free(win->pixels);
        free(win);
        return NULL;
    }


    return win;
}

void Kill_Window(G_Window* win){
    if (win != NULL){
        if (win->texture != NULL){
            SDL_DestroyTexture(win->texture);
        }if (win->renderer != NULL){
            SDL_DestroyRenderer(win->renderer);
        }if (win->sdl_win != NULL){
            SDL_DestroyWindow(win->sdl_win);
        } 
        free(win->pixels);
        free(win->backpixels);
        free(win);
    }
    
}

void Clear_Screen(G_Window* win) {
    memset(win->backpixels, 0, win->width * win->height * 4);        
}

void Resize_Window(G_Window* win, int w, int h){
    if (win != NULL){
        SDL_SetWindowSize(win->sdl_win, w, h);
        win->width = w;
        win->height = h;
    }
}

void Push_Window(G_Window* win){
    memcpy(win->pixels, win->backpixels, win->width * win->height * sizeof(uint32_t));
    if (win->isdirty){SDL_UpdateTexture(win->texture, NULL, win->pixels, win->width * 4);}
    SDL_SetRenderTarget(win->renderer, win->sdl_win);
    SDL_RenderCopy(win->renderer, win->texture,NULL,NULL);
    SDL_RenderPresent(win->renderer);
    win->isdirty = 0;
}

void Draw_Pixel(G_Window* win, int x, int y, Color color){
    win->isdirty = 1;
    if (0 <= x ){
        if (x < win->width){
            if (0 <= y){
                if (y < win->height){
                    win->backpixels[y*win->width + x] = pack_color(color);
                } 
            } 
        }
    }
}

uint32_t pack_color(Color color) {
    return ((uint32_t)color.r)       |
           ((uint32_t)color.g << 8)  |
           ((uint32_t)color.b << 16) |
           ((uint32_t)color.a << 24);
}

void Draw_FillRect(G_Window* win, int x, int y, int w, int h, Color color) {
    win->isdirty = 1;
    // 1. Clip coordinates against window boundaries (win->width, win->height)
    int x0 = x < 0 ? 0 : x;
    int y0 = y < 0 ? 0 : y;
    int x1 = (x + w) > win->width ? win->width : (x + w);
    int y1 = (y + h) > win->height ? win->height : (y + h);

    // If the rectangle is completely off-screen, bail early
    if (x0 >= x1 || y0 >= y1) return;

    // Pre-pack the color once before entering the loops
    uint32_t packed_color = pack_color(color);

    // 2. Row-by-row optimization using direct pointer arithmetic
    for (int cy = y0; cy < y1; cy++) {
        // Calculate the starting memory address for this specific row in win->pixels
        uint32_t* row = win->backpixels + (cy * win->width) + x0;
        
        // Fast horizontal fill across the row
        for (int cx = x0; cx < x1; cx++) {
            *row++ = packed_color;
        }
    }
}

int Poll_Event(G_Event* event){
    SDL_Event sdl_event;
    if (!SDL_PollEvent(&sdl_event)){
        return 0;
    } else{
        switch (sdl_event.type){
            case SDL_QUIT:
                event->type = G_Quit;
                break;
            case SDL_MOUSEMOTION:
                event->type = G_Mouse_Motion;
                event->mouse.x = sdl_event.motion.x;
                event->mouse.y =sdl_event.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                event->type = G_Mouse_Button_Down;
                event->mouse.x = sdl_event.button.x;
                event->mouse.y = sdl_event.button.y;
                event->mouse.button = sdl_event.button.button;
                break;
            case SDL_KEYDOWN:
                event->type = G_Key_Down;
                event->key.scancode = sdl_event.key.keysym.scancode;
                break;
            case SDL_KEYUP:
                event->type = G_Key_Up;
                event->key.scancode = sdl_event.key.keysym.scancode;
                break;
        }
        return 1;
    }
    
}

void Delay(uint32_t time){
    SDL_Delay(time);
}