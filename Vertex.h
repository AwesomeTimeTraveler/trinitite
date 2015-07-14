#pragma once

#include <GL/glew.h>

//in multiples of 4 bytes

//Struct or class inside another struct or class == composition

struct Vertex {
  struct Position { //Position is the type
    float x;
    float y;
  } position; //position is the name of this particulat instance

  struct Color {
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;
  } color;
};
