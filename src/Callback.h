#include <cstdio>

static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "error: %s\n", description);
    throw("glfw error");
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}
