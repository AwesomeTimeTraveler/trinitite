#pragma once


#include <string>
#include <GL/glew.h>

class GLSLprogram
{
public:
  GLSLprogram();
  ~GLSLprogram();

  void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);

  void linkShaders();

  void addAttribute(const std::string& attributeName);

  void enable();
  void disable();

private:

  int _numAttributes;

  void compileShader(const std::string& filePath, GLuint id);

  GLuint _shaderProgramID;

  GLuint _vertexShaderID;
  GLuint _fragmentShaderID;
};
