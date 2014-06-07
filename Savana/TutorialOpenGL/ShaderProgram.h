#pragma once

#include "Shader.h"
#include <GL/glew.h>

class ShaderProgram
{
private:
	GLuint _programID;
public:
	ShaderProgram();
	virtual ~ShaderProgram();

	void attach_shader(Shader shader);
	void bind_frag_data_location(GLint col_no, GLchar* name);
	void link();
	void use();

	GLuint get_programID();
};

