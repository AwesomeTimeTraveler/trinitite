#version 130
//The vertex shader operates on each vertex

//Input data from the VBO. Each vertex has 2 floats
//Hence the vec2. 3D would use vec3
in vec2 vertexPosition;

void main(){
  //Set the x,y position on the screen
  gl_Position.xy = vertexPosition;
  //The z position is zero since we are in 2D (currently)
  gl_Position.z = 0.0;

  //Indicate that the coordinates are normalized
  gl_Position.w = 1.0;
}
