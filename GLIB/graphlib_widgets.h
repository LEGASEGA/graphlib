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
    Button,
    Panel,
    Image,
}G_WidgetType;

typedef struct G_Widget G_Widget;


struct G_Widget{
    int x;
    int y;
    
    int w;
    int h;

    G_WidgetType id;
    bool active;
    G_Widget* parent;

    Color color;
};

typedef struct{
    G_Widget* base;
    void (*on_click)(void* data);
} G_Button;

typedef struct{
    G_Widget* base;
} G_Panel; //A container made for containing other widgets. thats it's only purpose

typedef struct{
    G_Widget* base;
    Color img;
}G_Image;

typedef struct {
    G_Widget **elements;
    size_t count;
} G_Widget_Array;

int Get_Widget_Absolute_X(G_Widget* widget);
int Get_Widget_Absolute_Y(G_Widget* widget);
void Draw_Widgets(G_Widget_Array* arr, G_Window* win);
#endif