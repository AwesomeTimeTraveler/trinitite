/*
Graphics pipeline:
{vertices} =>
Vertex shader -> shape assembly -> geometry shader
-> Rasterization -> Fragment Shader -> Tests and blending
*/

#include "MainGame.h"

using namespace std;

int main(int argc, char** argv) {
  MainGame mainGame;
  mainGame.run();

  cout << "Enter any key to shit:" << endl;
  int a;
  cin >> a;

  return 0;
}
