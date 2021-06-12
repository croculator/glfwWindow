//window.h
#ifndef WINDOW_H
#define WINDOW_H

#include "gfx.h"
#include "../util/util.h"

struct Window {

    GLFWwindow *handle;
};

typedef void (*FWindow)();

extern struct Window window;

void testFunc();
void window_loop();
void window_create();

#endif
