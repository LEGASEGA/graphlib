#ifndef GRAPHLIB_EVENTS_H
#define GRAPHLIB_EVENTS_H
#include <stdint.h>
#include "graphlib.h"

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
    G_Scancode scancode;
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