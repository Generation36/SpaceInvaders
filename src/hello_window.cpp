#include <cstdio>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
  glViewport(0, 0, width, height);
}

int main() {

  glfwInit();
  // hints == window config options
  // hints function as args for glfwCreateWindow
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  // define the window dimensions
  int windowWidth = 800;
  int windowHeight = 600;
  auto window = glfwCreateWindow(windowWidth, windowHeight, "Hello Window", NULL, NULL);

  if (!window) {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return -1;
  }

  // actually "create" the window on the screen
  glfwMakeContextCurrent(window);

  // defines and resets the coordinates for the glfw window -> 
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // allow the window to stay open
  while(!glfwWindowShouldClose(window))
  {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
