//window.cpp

#include "window.h"
#include "../Callback.h"
#include "gfx.h"

#include <stdio.h>
#include <stdlib.h>

struct Window window;


void window_loop() {

    while(!glfwWindowShouldClose(window.handle)) {

      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

        //render here!
        glfwSwapBuffers(window.handle);

        //poll for, and process events
        glfwPollEvents();
    }

    glfwDestroyWindow(window.handle);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

void window_create() {

    glfwSetErrorCallback(glfw_error_callback);


    if(!glfwInit()) {
        throw("failed init");
    }

#ifdef __APPLE__
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    window.handle = glfwCreateWindow(800, 600, "title", nullptr, nullptr);
    if(!window.handle) {
        //window context creation failed
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

   //input key command callback
    glfwSetKeyCallback(window.handle, key_callback);

   //make window context current
   glfwMakeContextCurrent(window.handle);

    //inits glad extension loader
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        fprintf(stderr, "Unable to initialize glad\n");
        glfwDestroyWindow(window.handle);
        glfwTerminate();
    }


    //double buffering the raster of each frame
    glfwSwapBuffers(window.handle);
    glfwSwapInterval(1);
}
