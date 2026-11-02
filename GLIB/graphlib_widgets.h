#ifndef GRAPHLIB_WIDGETS_H
#define GRAPHLIB_WIDGETS_H

#include "graphlib.h"
#include <stdbool.h>
#include <stdlib.h>
/*
 * graphlib - A simple graphics library built over SDL2.
 * Copyright (C) 2026 LEGASEGA/LJEManim
 * 
 * This library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 * 
 * this library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY;
 * 
 */



typedef enum{
    Button
}G_WidgetType;


typedef struct{
    int x;
    int y;
    
    int w;
    int h;

    G_WidgetType id;
    bool active;
    G_Widget* parent;

    Color color;
}G_Widget;

typedef struct{
    G_Widget* base;
    void (*on_click)(void* data);
} G_Button;

typedef struct {
    G_Widget *elements;
    size_t count;
} G_Widget_Array;

void Draw_Widgets(G_Widget_Array* arr, G_Window* win);
#endif