#pragma once

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glx.h>
#include <thread>
#include <iostream>

enum class GameState {PLAY, EXIT};

class MainGame {

public:
  MainGame(); // Constructor
  ~MainGame(); // Destructor

  void run();


private:
  void initSystems(); // Initialize everything, GLEW, GLFW, etc.
  void gameLoop();
  void processInput();
  void drawGame();
  void shutDown();


  GLFWwindow* _mainWindow;
  int _screenWidth;
  int _screenHeight;
  GameState _gameState;
};
