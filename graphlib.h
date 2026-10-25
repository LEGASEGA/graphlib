/*
 * graphlib - A simple graphics library built over SDL2.
 * Copyright (C) 2026 LEGASEGA/LJEManim
 *
 * This library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See https://www.gnu.org/licenses/lgpl-3.0.html
 */



#ifndef GRAPHLIB_H
#define GRAPHLIB_H

#include <stdint.h>
//Window related stuff
typedef struct G_Window G_Window;

G_Window* Create_Window(int w, int h, const char* title, uint32_t wflags, uint32_t rflags);

void Kill_Window(G_Window* win);
void Clear_Screen(G_Window* win);
void Resize_Window(G_Window* win, int w, int h);
void Push_Window(G_Window* win);

/*Drawing Related things*/
typedef struct{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} Color;

void Draw_Pixel(G_Window* win, int x, int y, Color color); //Draws a pixel to the screen

void Draw_FillRect(G_Window* win, int x, int y, int w, int h, Color color); //Efficiently draws a rectangle to the screen

void Draw_Line(G_Window* win, int startx, int starty, int endx, int endy, Color color);

uint32_t pack_color(Color color); // Converts color struct to uint32_t. Handled for you inside the functions for drawing

/*Events stuff
 * 
 *Defines the event data structures and stuff
 *
 */

typedef enum {
    G_Quit,
    G_App_Terminating,
    G_Key_Down,
    G_Key_Up,
    G_Mouse_Motion,
    G_Mouse_Button_Down
} G_EventType;

typedef struct {
    int x;
    int y;
    int button;
} G_MouseEvent;

typedef struct {
    uint32_t scancode;
} G_KeyEvent;

typedef struct {
    G_EventType type;
    union {
        G_MouseEvent mouse;
        G_KeyEvent key;
    };
}G_Event;


int Poll_Event(G_Event* event);

void Delay(uint32_t time);
#endif