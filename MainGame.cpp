#include "MainGame.h"

using namespace std;

MainGame::MainGame(){
  _mainWindow = nullptr; // Initialized main window
  _screenWidth = 800;
  _screenHeight = 600;
}

MainGame::~MainGame(){

}

void MainGame::run(){
  initSystems();
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
  glfwMakeContextCurrent(_mainWindow);

  // Initialize GLEW
  glewExperimental = GL_TRUE;
  GLenum err = glewInit();
  if(err != GLEW_OK)
  {
    // glewInit failed, something is seriously wrong
    cout << "glewInit failed, aborting. Code " << err << ". " << endl;
  }

  /*
  Main loop,
  swaps buffers on our main context and process events in the queue
  if esc is presseds, closes window
  */
  while(!glfwWindowShouldClose(_mainWindow))
  {
    glfwSwapBuffers(_mainWindow);
    glfwPollEvents();

    if(glfwGetKey(_mainWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
      glfwSetWindowShouldClose(_mainWindow, GL_TRUE);
    }
  }

  glfwTerminate();
}
