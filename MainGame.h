#pragma once

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glx.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <thread>
#include <iostream>

#include "Sprite.h"
#include "GLSLprogram.h"

enum class GameState {PLAY, EXIT};

class MainGame {

public:
  MainGame(); // Constructor
  ~MainGame(); // Destructor

  void run();

private:
  void initSystems(); // Initialize everything, GLEW, GLFW, etc.
  void initShaders();
  void gameLoop();
  void processInput();
  void drawGame();
  void shutDown();

  GLFWwindow* _mainWindow;
  int _screenWidth;
  int _screenHeight;
  GameState _gameState;

  Sprite _sprite;

  GLSLprogram _colorProgram;
};
