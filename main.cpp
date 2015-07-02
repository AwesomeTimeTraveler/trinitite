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

  return 0;
}
