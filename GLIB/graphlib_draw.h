#ifndef GRAPHLIB_DRAW_H
#define GRAPHLIB_DRAW_H
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
 * 
 */

#include <stdint.h>
#include "graphlib.h"
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

#endif