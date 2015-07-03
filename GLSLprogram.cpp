#include "GLSLprogram.h"
#include "errors.h"

#include <fstream>
#include <vector>

GLSLprogram::GLSLprogram() : _numAttributes(0), _shaderProgramID(0), _vertexShaderID(0), _fragmentShaderID(0)
{

}

GLSLprogram::~GLSLprogram()
{
}

void GLSLprogram::compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath)
{
  //Create the vertex shader object and store its ID
  _vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  if( _vertexShaderID == 0){
    fatalError("Vertex shader failed to be created");
  }

  //Create the fragment shader object and store its ID
  _fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
  if( _fragmentShaderID == 0){
    fatalError("Fragment shader failed to be created");
  }

  //Compile each shader
  compileShader(vertexShaderFilePath, _vertexShaderID);
  compileShader(fragmentShaderFilePath, _fragmentShaderID);
}

void GLSLprogram::linkShaders()
{
  //Vertex and fragment shaders are now successfullt compileShader
  //Now, link them together into one program.
  //Get a program object
  _shaderProgramID = glCreateProgram();

  //Atach our shaders to the program
  glAttachShader(_shaderProgramID, _vertexShaderID);
  glAttachShader(_shaderProgramID, _fragmentShaderID);

  //Link the program
  glLinkProgram(_shaderProgramID);

  //Just error checking
  //Not the different functions here: glGetProgram instead of glGetShaderiv
  GLint isLinked = 0;
  glGetProgramiv(_shaderProgramID, GL_LINK_STATUS, (int *)&isLinked);
  if(isLinked == GL_FALSE){
    GLint maxLength = 0;
    glGetProgramiv(_shaderProgramID, GL_INFO_LOG_LENGTH, &maxLength);

    // The maximum lengtrh includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetProgramInfoLog(_shaderProgramID, maxLength, &maxLength, &errorLog[0]);

    // We don't need the program anymore
    glDeleteProgram(_shaderProgramID);
    //Don't leak shaders either
    glDeleteShader(_vertexShaderID);
    glDeleteShader(_fragmentShaderID);

    std::printf("%s\n", &errorLog[0]);
    fatalError("Shader program failed to link");
  }

  //Always detach shaders after a succesful link
  glDetachShader(_shaderProgramID, _vertexShaderID);
  glDetachShader(_shaderProgramID, _fragmentShaderID);
  glDeleteShader(_vertexShaderID);
  glDeleteShader(_fragmentShaderID);
}

//Adds an attribute to our shader. Should be called between compiling and linking
void GLSLprogram::addAttribute(const std::string& attributeName)
{
  //Add 1 to _numAttributes AFTER line runs
  glGetAttribLocation(_shaderProgramID, attributeName.c_str());
  _numAttributes++;
}

//Enable the shader and all of its attributes
void GLSLprogram::enable()
{
  glUseProgram(_shaderProgramID);
  //Enable vertex attributes wth addAttribute
  for(int i = 0; i < _numAttributes; i++){
    glEnableVertexAttribArray(i);
  }
}

//Disable the shader
void GLSLprogram::disable()
{
  glUseProgram(0);
  //Disable vertex attributes
  for(int i = 0; i < _numAttributes; i++){
    glDisableVertexAttribArray(i);
  }
}

//Compiles a single shader file
void GLSLprogram::compileShader(const std::string& filePath, GLuint id)
{
  //Open the file
  std::ifstream vertexFile(filePath);
  if( vertexFile.fail()){
    perror(filePath.c_str());
    fatalError("Failed to open " + filePath);
  }

  //File contents sotres all the text in the file
  std::string fileContent = "";
  //Line is used to grab each line of the file
  std::string line;

  //Get all the lines int the file and add it to the contents
  while(std::getline(vertexFile, line)){
    fileContent += line + "\n"; //Add read line and a new line
  }

  vertexFile.close();

  //Get a pointer to ourile contents
  // C string is an array of char*
  const char* contentPtr = fileContent.c_str();
  //Tell opengl that we want to use fileContents as the shader source
  glShaderSource(id, 1, &contentPtr, nullptr);

  //Compile the vertex shader and check if it succeeds
  glCompileShader(id);

  //Check for errors
  GLint isCompiled = 0;
  glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);
  if(isCompiled == GL_FALSE){
    GLint maxLength = 0;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

    //The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

    //Provide the infolog in whaever manor you deem best
    //exit with failure
    glDeleteShader(id);

    std::printf("%s\n", &errorLog[0]);
    fatalError("Shader" + filePath + " failed to compile");
  }
}
