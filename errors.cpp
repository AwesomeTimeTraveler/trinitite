#include "errors.h"
#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

void fatalError(string errorString){
  cout << errorString << endl;
  cout << "Enter any key to quit..." << endl;
  int tmp;
  cin >> tmp;
  glfwTerminate();
}
