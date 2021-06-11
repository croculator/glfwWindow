#include "gfx/gfx.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <stdio.h>

#include "Callback.h"
using namespace std;

int main() {

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

    GLFWwindow * window = glfwCreateWindow(800, 600, "title", nullptr, nullptr);
    if(!window) {
        //window context creation failed
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    //input key command callback
    glfwSetKeyCallback(window, key_callback);

    //make window context current
    glfwMakeContextCurrent(window);

    //inits glad extension loader
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        fprintf(stderr, "Unable to initialize glad\n");
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    //get current openGL version installed on this computer
//    cout << glGetString(GL_VERSION) << endl;
    
    //double buffering the raster of each frame
    glfwSwapBuffers(window);
    glfwSwapInterval(1);

   while(!glfwWindowShouldClose(window)) {

       //render here!
        glClear(GL_COLOR_BUFFER_BIT);


       //swap front and back buffers
       glfwSwapBuffers(window);
       
       //poll for and process events
       glfwPollEvents();
   }

   glfwDestroyWindow(window);
   glfwTerminate();
   exit(EXIT_SUCCESS);
}
