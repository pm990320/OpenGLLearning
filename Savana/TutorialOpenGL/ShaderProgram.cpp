#include "ShaderProgram.h"


ShaderProgram::ShaderProgram()
{
	_programID = glCreateProgram();
}


ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(_programID);
}


void ShaderProgram::attach_shader(Shader shader){
	glAttachShader(_programID, shader.get_shaderID());
}


void ShaderProgram::bind_frag_data_location(GLint col_no, GLchar* name) {
	glBindFragDataLocation(_programID, col_no, name);
}


void ShaderProgram::link() {
	glLinkProgram(_programID);
}


void ShaderProgram::use() {
	glUseProgram(_programID);
}


GLuint ShaderProgram::get_programID(){
	return _programID;
}