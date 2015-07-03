#version 130
//The fragment shader operates on each pixel in a given polygon

//3 component float vector that gets outputted to the screen
//for each individual pixel
out vec3 color;

void main(){
  //Just hardcode the color to red
  color = vec3(1.0, 0.0, 1.0);
}
