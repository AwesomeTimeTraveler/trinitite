#include "MainGame.h"
#include <string>
using namespace std;

void fatalError(string errorString){
  cout << errorString << endl;
  cout << "Enter any key to quit..." << endl;
  int tmp;
  cin >> tmp;
  glfwTerminate();
}

MainGame::MainGame(){
  _mainWindow = nullptr; // Initialized main window
  _screenWidth = 800;
  _screenHeight = 600;
  _gameState = GameState::PLAY;
}

MainGame::~MainGame(){

}

void MainGame::run(){
  initSystems();
  gameLoop();
}

void MainGame::initSystems(){\
  // Initialize GLFW
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  _mainWindow = glfwCreateWindow(_screenWidth, _screenHeight, "trinitite", nullptr, nullptr);

  if(_mainWindow == nullptr){
    fatalError("GLFW window could not be created!");
  }

  //Make OpenGL context and store it to window
  glfwMakeContextCurrent(_mainWindow);

  // Initialize GLEW
  glewExperimental = GL_TRUE;
  GLenum error = glewInit();
  if(error != GLEW_OK){
    fatalError("Could not initialize glew!");
  }

  glClearColor(0.0f, 1.0f, 0.0f, 1.0);
}

void MainGame::gameLoop(){
  while(_gameState != GameState::EXIT){
    processInput();
    drawGame();
  }
}

void MainGame::processInput()
{
  glfwPollEvents();
  //double xpos, ypos;
  if(glfwGetKey(_mainWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS){
    _gameState = GameState::EXIT;
  }
  else if(glfwGetKey(_mainWindow, GLFW_KEY_UP) == GLFW_PRESS){
    cout << "UP" << endl;
  }
  else if(glfwGetKey(_mainWindow, GLFW_KEY_DOWN) == GLFW_PRESS){
    cout << "DOWN" << endl;
  }
  else if(glfwGetKey(_mainWindow, GLFW_KEY_LEFT) == GLFW_PRESS){
    cout << "LEFT" << endl;
  }
  else if(glfwGetKey(_mainWindow, GLFW_KEY_RIGHT) == GLFW_PRESS){
    cout << "RIGHT" << endl;
  }
  //glfwGetCursorPos(_mainWindow, &xpos, &ypos);
  //cout << "X: " << xpos << "Y: " << ypos << endl;
}


void MainGame::drawGame(){
  glClearDepth(1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnableClientState(GL_COLOR_ARRAY);


  glfwSwapBuffers(_mainWindow);
}
