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
 * 
 * This header defines the window logic and nothing more. 
 * The rest is defined in the other headers in the folders
 */



#ifndef GRAPHLIB_H
#define GRAPHLIB_H

#include <stdint.h>

//Import the libraries that actually define raylib.
#include "graphlib_keys.h"
#include "graphlibs_events.h"
#include "graphlib_draw.h"
//Window related stuff
typedef struct G_Window G_Window;

G_Window* Create_Window(int w, int h, const char* title, uint32_t wflags, uint32_t rflags);

void Kill_Window(G_Window* win);
void Clear_Screen(G_Window* win);
void Resize_Window(G_Window* win, int w, int h);
void Push_Window(G_Window* win);

#endif