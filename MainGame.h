#pragma once

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glx.h>
#include <thread>
#include <iostream>

class MainGame {

public:
  MainGame(); // Constructor
  ~MainGame(); // Destructor

  void run();

  void initSystems(); // Initialize everything, GLEW, GLFW, etc.

private:
  GLFWwindow* _mainWindow;
  int _screenWidth;
  int _screenHeight;

};
