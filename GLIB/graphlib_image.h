#ifndef GRAPHLIB_IMAGE_H
#define GRAHLIB_IMAGE_H

#include "graphlib_draw.h"

typedef struct{
    uint32_t img_data;
    int w;
    int h;
}Image32bpp;

typedef struct{
    uint32_t value;
}Palette; //Have an array of these in indexed images

typedef struct{
    Palette palette;
    uint16_t img_data;
    int w;
    int h;
}ImageIndexed;


#endif