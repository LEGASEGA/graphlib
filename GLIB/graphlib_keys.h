#ifndef GRAPHLIB_KEYS_H
#define GRAPHLIB_KEYS_H
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


/*
 * This header defines the scancodes used in the library.
 * They map one to one to SDL2 scancodes for compatibility and easy development
 * I know i'm lazy :)
 */

typedef enum{
    SCANCODE_UNKNOWN = 0,


    /*Letters*/
    SCANCODE_A = 4,
    SCANCODE_B,
    SCANCODE_C,
    SCANCODE_D,
    SCANCODE_E,
    SCANCODE_F,
    SCANCODE_G,
    SCANCODE_H,
    SCANCODE_I,
    SCANCODE_J,
    SCANCODE_K,
    SCANCODE_L,
    SCANCODE_M,
    SCANCODE_N,
    SCANCODE_O,
    SCANCODE_P,
    SCANCODE_Q,
    SCANCODE_R,
    SCANCODE_S,
    SCANCODE_T,
    SCANCODE_U,
    SCANCODE_V,
    SCANCODE_W,
    SCANCODE_X,
    SCANCODE_Y,
    SCANCODE_Z,

    /*Numbers*/
    SCANCODE_1,
    SCANCODE_2,
    SCANCODE_3,
    SCANCODE_4,
    SCANCODE_5,
    SCANCODE_6,
    SCANCODE_7,
    SCANCODE_8,
    SCANCODE_9,
    SCANCODE_0,

    /*Special keys*/
    SCANCODE_RETURN,
    SCANCODE_ESCAPE,
    SCANCODE_BACKSPACE,
    SCANCODE_TAB,
    SCANCODE_SPACE,

    /*Operations*/
    SCANCODE_MINUS,
    SCANCODE_EQUALS,
    SCANCODE_LEFTBRACKET,
    SCANCODE_RIGHTBRACKET,

    /*Symbols*/
    SCANCODE_BACKSLASH,
    SCANCODE_NONUSHASH, //Used for SDL compatibility, dont use this

    SCANCODE_SEMICOLON,
    SCANCODE_APOSTROPHE,
    SCANCODE_GRAVE,
    SCANCODE_COMMA,
    SCANCODE_PERIOD,
    SCANCODE_SLASH,

    /*More special keys*/

    SCANCODE_CAPSLOCK,

    SCANCODE_F1,
    SCANCODE_F2,
    SCANCODE_F3,
    SCANCODE_F4,
    SCANCODE_F5,
    SCANCODE_F6,
    SCANCODE_F7,
    SCANCODE_F8,
    SCANCODE_F9,
    SCANCODE_F10,
    SCANCODE_F11,
    SCANCODE_F12,

    SCANCODE_PRINTSCREEN,
    SCANCODE_SCROLLLOCK,
    SCANCODE_PAUSE,
    SCANCODE_INSERT,
    SCANCODE_HOME,
    SCANCODE_PAGEUP,
    SCANCODE_DELETE,
    SCANCODE_END,
    SCANCODE_PAGEDOWN,
    SCANCODE_RIGHT,
    SCANCODE_LEFT,
    SCANCODE_DOWN,
    SCANCODE_UP,

    SCANCODE_NUMLOCKCLEAR
}G_Scancode;
#endif