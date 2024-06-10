#include <cstdio>
#include <iostream>
#include <chrono>
#include <thread>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
  glViewport(0, 0, width, height);
}

void applyRandomColor() {
    // apply a random color to the screen
    float redVal = static_cast<float> (rand()) / static_cast<float>(RAND_MAX);
    float blueVal = static_cast<float> (rand()) / static_cast<float>(RAND_MAX);
    float greenVal = static_cast<float> (rand()) / static_cast<float>(RAND_MAX);
    glClearColor(redVal, blueVal, greenVal, 1.0f);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    glClear(GL_COLOR_BUFFER_BIT);
}

void processInput(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  else if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS) 
  {
    applyRandomColor();
  }
  
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
    processInput(window);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
