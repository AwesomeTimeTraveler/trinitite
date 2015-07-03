#include "Sprite.h"

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

  //This array will hold our vertex data
  //6 vertices, each has an x and a y
  float vertexData[12];

  //First triangle
  vertexData[0] = x + width;
  vertexData[1] = y + height;

  vertexData[2] = x;
  vertexData[3] = y + height;

  vertexData[4] = x;
  vertexData[5] = y;

  //Second triangle
  vertexData[6] = x;
  vertexData[7] = y;

  vertexData[8] = x + width;
  vertexData[9] = y;

  vertexData[10] = x + width;
  vertexData[11] = y + height;

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
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

  //Draw the 6 vertices to the screen
  glDrawArrays(GL_TRIANGLES, 0, 6);

  //Disable the vertex attrib array. NOT optional
  glDisableVertexAttribArray(0);

  //Unbind the V
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}
