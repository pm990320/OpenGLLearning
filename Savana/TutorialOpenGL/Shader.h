#pragma once

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <streambuf>

class Shader
{
private:
	GLuint _shaderID;
	GLenum _type;
	const GLchar* _contents;

public:
	Shader();
	Shader(const GLchar* path, GLenum type);
	virtual ~Shader();
	void compile(const GLchar* contents);
	void loadFromFile(const GLchar* path, GLenum type);
	GLuint get_shaderID();
};
