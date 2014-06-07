#include "Shader.h"

Shader::Shader(){
	_type = NULL;
	_shaderID = NULL;
	std::cout << "shader variables created, but not initialised" << std::endl;
}


Shader::Shader(const GLchar* path, GLenum type)
{
	loadFromFile(path, type);
}


Shader::~Shader()
{
	glDeleteShader(_shaderID);
}


void Shader::compile(const GLchar* contents) {
	glShaderSource(_shaderID, sizeof(contents), &contents, 0);
	glCompileShader(_shaderID);

	GLint compileStatus;
	glGetShaderiv(_shaderID, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != 1) {
		std::cout << "The shader did not compile" << std::endl;

		GLint infoLogLength;
		glGetShaderiv(_shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

		char* infoLog = new char[infoLogLength + 1];
		glGetShaderInfoLog(_shaderID, infoLogLength + 1, NULL, infoLog);

		std::cout << infoLog << std::endl;
		delete infoLog;
		throw std::exception{ "Shader failed to compile" };
	}
}


void Shader::loadFromFile(const GLchar* path, GLenum type) {
	_type = type;
	_shaderID = glCreateShader(GL_VERTEX_SHADER);

	std::string str_in;
	std::ifstream in{ path, std::ios::in };
	if (!in)
	{
		in.close();
		throw (errno);
	}
	in.seekg(0, std::ios::end);
	str_in.resize(in.tellg());
	in.seekg(0, std::ios::beg);
	in.read(&str_in[0], str_in.size());
	in.close();

	_contents = str_in.c_str();
	glShaderSource(_shaderID, sizeof(_contents), &_contents, 0);
	glCompileShader(_shaderID);

	GLint compileStatus;
	glGetShaderiv(_shaderID, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != 1) {
		std::cout << "The shader did not compile" << std::endl;

		GLint infoLogLength;
		glGetShaderiv(_shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

		char* infoLog = new char[infoLogLength + 1];
		glGetShaderInfoLog(_shaderID, infoLogLength + 1, NULL, infoLog);

		std::cout << infoLog << std::endl;
		delete infoLog;
		throw std::exception{ "Shader failed to compile" };
	}
}


GLuint Shader::get_shaderID() {
	return _shaderID;
}