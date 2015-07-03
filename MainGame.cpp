#include "MainGame.h"
#include "errors.h"

#include <string>

using namespace std;

//Constructor, just initializes private member variables
MainGame::MainGame(){
  _mainWindow = nullptr; // Initialized main window
  _screenWidth = 800;
  _screenHeight = 600;
  _gameState = GameState::PLAY;
}

//Destructor
MainGame::~MainGame(){

}

//This runs the game
void MainGame::run(){
  initSystems();

  //Initialize our sprite. (temporary)
  _sprite.init(-1.0f, -1.0f, 1.0f, 1.0f);

  //This only returns when the game ends
  gameLoop();
}

//Initialize GLFW and OpenGL and everything else
void MainGame::initSystems(){
  // Initialize GLFW
  glfwInit();

  //Using OpenGL 3.2
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  //Open a GLFW window
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

  //Set the background color to blue
  glClearColor(0.0f, 0.0f, 1.0f, 1.0);

  initShaders();
}

void MainGame::initShaders(){
  _colorProgram.compileShaders("shaders/colorshader.vert", "shaders/colorshader.frag");
  _colorProgram.addAttribute("vertexPosition");
  _colorProgram.linkShaders();
}

//This is the main game loop of the program
void MainGame::gameLoop(){
  //While loop until we set _gameState to EXIT
  while(_gameState != GameState::EXIT){
    processInput();
    drawGame();
  }
}

//Process input with GLFW (messy, not using callbacks)
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

//Draws the game using OpenGL
void MainGame::drawGame(){
  glClearDepth(1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _colorProgram.enable();

  _sprite.draw();

  _colorProgram.disable();

  glfwSwapBuffers(_mainWindow);
}
