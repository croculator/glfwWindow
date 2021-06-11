cmake_minimum_required(VERSION 3.1)
project(glfwWindow)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(SOURCES "${SRC_DIR}/main.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)


# GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
set(GLFW_USE_CHDIR OFF CACHE INTERNAL "Make glfwInit chdir to Contents/Resources")
add_subdirectory("${LIB_DIR}/glfw")
target_compile_definitions(${PROJECT_NAME} PUBLIC GLFW_INCLUDE_NONE)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)

# glad
add_subdirectory("${LIB_DIR}/glad")
target_link_libraries(${PROJECT_NAME} PUBLIC optimized glad)
target_link_libraries(${PROJECT_NAME} PUBLIC debug glad-debug)

# GLM
add_subdirectory("${LIB_DIR}/glm")
target_link_libraries(${PROJECT_NAME} PUBLIC glm)
