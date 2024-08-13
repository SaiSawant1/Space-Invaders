// #include <GL/glext.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GLFW/glfw3.h>
#include <iostream>

void error_callback(int error, const char *description) {
  std::cerr << "Error: %s\n" << description << std::endl;
}

int main() {

  glfwSetErrorCallback(error_callback);

  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
  }

  GLFWwindow *window =
      glfwCreateWindow(640, 480, "Space Invader", nullptr, nullptr);
  if (!window) {
    std::cerr << "Failed to create GLFW Window!" << std::endl;
    glfwTerminate();

    return -1;
  }

  glfwMakeContextCurrent(window);

  int glVersions[2] = {-1, 1};
  glGetIntegerv(GL_MAJOR_VERSION, &glVersions[0]);
  glGetIntegerv(GL_MINOR_VERSION, &glVersions[1]);

  std::cout << "Using OpenGL \n"
            << glVersions[0] << "," << glVersions[1] << std::endl;

  glClearColor(1.0, 0.0, 0.0, 1.0);

  while (!glfwWindowShouldClose(window)) {

    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  glfwDestroyWindow(window);

  glfwTerminate();

  return 0;
}
