#include "Sprite.h"
#include "Vertex.h"

#include <cstddef>

Sprite::Sprite(){
  //Always initialize your buffer IDs to 0
  _vboID = 0;
  _vaoID = 0;
}

Sprite::~Sprite(){
  //Remember to delete your buffers when you are done
  if( _vboID != 0){
    glDeleteBuffers(1, &_vboID);
  }

  if( _vaoID != 0){
    glDeleteBuffers(1, &_vaoID);
  }
}

//Initializes the sprite VBO. x, y, width, and height are
//normalized device coordinate space [-1, 1]
void Sprite::init(float x, float y, float width, float height){
  //Set up the private variables
  _x = x;
  _y = y;
  _width = width;
  _height = height;

  //Generate the buffer if it hasn't already been created
  if( _vboID == 0){
    glGenBuffers(1, &_vboID);
  }

  if( _vaoID == 0){
    glGenVertexArrays(1, &_vaoID);
    glBindVertexArray(_vaoID);
  }

  //Interleaving vertex data
  Vertex vertexData[6];

  //First triangle
  vertexData[0].position.x = x + width;
  vertexData[0].position.y = y + height;

  vertexData[1].position.x = x;
  vertexData[1].position.y = y + height;

  vertexData[2].position.x = x;
  vertexData[2].position.y = y;

  //Second triangle
  vertexData[3].position.x = x;
  vertexData[3].position.y = y;

  vertexData[4].position.x = x + width;
  vertexData[4].position.y = y;

  vertexData[5].position.x = x + width;
  vertexData[5].position.y = y + height;


  //Set all vertex colors to some new color
  for(int i = 0; i < 6; i++) {
    vertexData[i].color.r = 255;
    vertexData[i].color.g = 100;
    vertexData[i].color.b = 255;
    vertexData[i].color.a = 255;
  }

  //
  vertexData[1].color.r = 0;
  vertexData[1].color.g = 0;
  vertexData[1].color.b = 255;
  vertexData[1].color.a = 255;

  vertexData[4].color.r = 0;
  vertexData[4].color.g = 255;
  vertexData[4].color.b = 0;
  vertexData[4].color.a = 255;

  //Tell openGL to bind our vertex buffer object
  glBindBuffer(GL_ARRAY_BUFFER, _vboID);
  //Uploads data to the GPU
  //            Type of buffer  size of buffer      type of data
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

  //Unbinds buffer (optional)
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//Draws the sprite to the screen
void Sprite::draw(){
  //Bind the buffer object
  glBindBuffer(GL_ARRAY_BUFFER, _vboID);

  //Tell openGL that we want to use the first
  //attribute array. We only need one array right now
  //Since we are only using position
  glEnableVertexAttribArray(0); //0th index

  //Point opengl to the data in our VBO
  //Position attrib pointer
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, position));
  //Color attrib pointer
  glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void *)offsetof(Vertex, color));

  //Draw the 6 vertices to the screen
  glDrawArrays(GL_TRIANGLES, 0, 6);

  //Disable the vertex attrib array. NOT optional
  glDisableVertexAttribArray(0);

  //Unbind the VBO
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}
